%option noyywrap
%option stack
%x COMMENT_BLOCK

%{
    //#include "../../debugging/lexer/c_lexer.hpp" //for testing purposes? this makes it stop breaking
    #include "c_parser.tab.hpp"

    #include <sstream>
    #include <stdlib.h>
    #include <iostream>

    extern void yyerror(const char *); 
    static void comment(void);
    int store_typedef();
    void create_typedef();
    int check_type();
%}


IDENTIFIER          [_a-zA-Z][_a-zA-Z0-9]*

ASSIGNMENT_OPERATOR (("<<"|">>"|[*\/%+\-&^|])"=")
INTEGERSUFFIX       ([uU][lL]|[lL][uU]|[uUlL])
FLOATINGSUFFIX      ([fFlL])
EXPONENTSUFFIX      ([Ee][+-]?[0-9]+)
BASE2EXSUFFIX       ([Pp][+-]?[0-9]+)

NONZERO             [1-9]
DEC                 [0-9]
OCTAL               [0-7]
HEX                 [a-fA-F0-9]
HEXPREFIX           (0[xX])
WHITESPACE          [ \t\r\n]+ 

%%


"/*"            { yy_push_state(COMMENT_BLOCK); }
<COMMENT_BLOCK>"*/" { yy_pop_state(); } //make it go to prev state not initial
<COMMENT_BLOCK>\n   { }
<COMMENT_BLOCK>.    { }

"//"[^\n]*  {} //one-line comment

"void"		{ctx.declaration = 1; return T_VOID; }
"char"		{ctx.declaration = 1; return T_CHAR; }
"short"		{ctx.declaration = 1; return T_SHORT; }
"int"		{ctx.declaration = 1; return T_INT; }
"long"		{ctx.declaration = 1; return T_LONG; }
"float"		{ctx.declaration = 1; return T_FLOAT; }
"double"	{ctx.declaration = 1; return T_DOUBLE; }
"signed"	{ctx.declaration = 1; return T_SIGNED; }
"unsigned"	{ctx.declaration = 1; return T_UNSIGNED; }
"struct"    {ctx.declaration = 1; return T_STRUCT; }
"enum"      {ctx.declaration = 1; return T_ENUM;}

"goto"		{ return T_GOTO; }
"break"		{ return T_BREAK; }
"continue"	{ return T_CONTINUE; }
"case"		{ return T_CASE; }
"default"	{ return T_DEFAULT; }
"switch"	{ return T_SWITCH; }
"if"	    { return T_IF; }
"else"		{ return T_ELSE; }
"return"	{ return T_RETURN; }
"while"		{ return T_WHILE; }
"do"		{ return T_DO; }
"for"		{ return T_FOR; }
"sizeof"    { return T_SIZEOF; }
"split"     { return T_SPLIT;}
"split_fpga" {return T_SPLIT_FPGA;}


{ASSIGNMENT_OPERATOR} { yylval.string = new std::string(yytext); return T_ASSIGNMENT_OP; }

">>"					{ return RIGHT_SHIFT_OP; }
"<<"					{ return LEFT_SHIFT_OP; }
"++"					{ return INC_OP; }
"--"					{ return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"			        { return AND_OP; }
"||"			        { return OR_OP; }
"<="			        { return LE_OP; }
">="			        { return GE_OP; }
"=="			        { return EQ_OP; }
"!="			        { return NE_OP; }
";"		                { return ';'; }
","					    { return ','; }
":"					    { return ':'; }
"="					    { return '='; }
"."					    { return '.'; }
"&"					    { return '&'; }
"!"					    { return '!'; }
"~"					    { return '~'; }
"-"					    { return '-'; }
"+"					    { return '+'; }
"*"					    { return '*'; }
"/"					    { return '/'; }
"%"					    { return '%'; }
"<"					    { return '<'; }
">"					    { return '>'; }
"^"					    { return '^'; }
"|"					    { return '|'; }
"?"					    { return '?'; }
"{"			            { ctx.incScope(); return '{'; }
"}"     		        { ctx.decScope(); return '}'; }
"("					    { return '('; }
")"					    { return ')'; }
"["				        { return '['; }
"]"			            { return ']'; } 

{IDENTIFIER}	{return check_type();} //Store variable names in bindings

{HEXPREFIX}{HEX}+{INTEGERSUFFIX}?                               {yylval.number=strtod(yytext, 0); return INT_CONSTANT; }
{NONZERO}{DEC}*{INTEGERSUFFIX}?                                 {yylval.number=strtod(yytext, 0);  return INT_CONSTANT; }
"0"{OCTAL}*{INTEGERSUFFIX}?                                     {yylval.number=strtod(yytext, 0); return INT_CONSTANT; }

{DEC}+{EXPONENTSUFFIX}{FLOATINGSUFFIX}?                         {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}
{DEC}*"."{DEC}+{EXPONENTSUFFIX}?{FLOATINGSUFFIX}?               {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}
{DEC}+"."{EXPONENTSUFFIX}?{FLOATINGSUFFIX}?                     {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}+{BASE2EXSUFFIX}{FLOATINGSUFFIX}?               {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}*"."{HEX}+{BASE2EXSUFFIX}{FLOATINGSUFFIX}?      {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}+"."{BASE2EXSUFFIX}{FLOATINGSUFFIX}?            {yylval.number=strtod(yytext, 0); return FLOAT_CONSTANT;}


(\"[^\n\"]*\")                                                  {return STRING_LITERAL;}



{WHITESPACE} { ; }

%%

int store_typedef(){
    yylval.string = new std::string(yytext);
    ctx.temp_typedef = *yylval.string;
    return T_IDENTIFIER;
}

void create_typedef(){
    yylval.string = new std::string(yytext);
    ctx.type_defs[ctx.scopeLevel].push_back(ctx.temp_typedef);
}

int check_type(){
    yylval.string = new std::string(yytext);
    if(std::find(ctx.type_defs[ctx.scopeLevel].begin(),ctx.type_defs[ctx.scopeLevel].end(), *yylval.string) != ctx.type_defs[ctx.scopeLevel].end()){
        return TYPEDEF_NAME;
    } else{
        return T_IDENTIFIER;
    }
}

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}


