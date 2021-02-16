/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y"

  #include "../include/pkg.hpp"

  #include <cassert>

  extern BranchNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
  //to allow file input to AST
  extern FILE *yyin;

#line 127 "src/c_parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ASSIGNMENT_OP = 258,
    RIGHT_SHIFT_OP = 259,
    LEFT_SHIFT_OP = 260,
    INC_OP = 261,
    DEC_OP = 262,
    PTR_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    LE_OP = 266,
    GE_OP = 267,
    EQ_OP = 268,
    NE_OP = 269,
    INT_CONSTANT = 270,
    FLOAT_CONSTANT = 271,
    STRING_LITERAL = 272,
    T_VOID = 273,
    T_CHAR = 274,
    T_SHORT = 275,
    T_INT = 276,
    T_LONG = 277,
    T_FLOAT = 278,
    T_DOUBLE = 279,
    T_SIGNED = 280,
    T_UNSIGNED = 281,
    T_TYPEDEF = 282,
    T_EXTERN = 283,
    T_STATIC = 284,
    T_AUTO = 285,
    T_REGISTER = 286,
    T_CONST = 287,
    T_VOLATILE = 288,
    T_STRUCT = 289,
    T_UNION = 290,
    T_GOTO = 291,
    T_BREAK = 292,
    T_CONTINUE = 293,
    T_CASE = 294,
    T_DEFAULT = 295,
    T_SWITCH = 296,
    T_IF = 297,
    T_ELSE = 298,
    T_RETURN = 299,
    T_WHILE = 300,
    T_DO = 301,
    T_FOR = 302,
    T_SIZEOF = 303,
    T_ENUM = 304,
    TYPEDEF_NAME = 305,
    T_IDENTIFIER = 306,
    ENUMERATION_CONSTANT = 307,
    NOELSE = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src/c_parser.y"

  Node *node;
  BranchNode *bnode;
  ExpressionNode *enode;
  double number;
  std::string *string;
  identifier_list *idlist;
  Pointer *ptrNode;

#line 202 "src/c_parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    74,    67,     2,
      60,    61,    72,    70,    57,    71,    77,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    54,
      69,    59,    68,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    65,    56,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    69,    70,    74,    75,    76,    80,    84,
      85,    89,    90,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   109,   110,   111,   115,   116,
     120,   121,   125,   126,   130,   131,   132,   136,   137,   138,
     142,   143,   148,   149,   153,   154,   158,   159,   163,   164,
     168,   169,   170,   171,   172,   173,   174,   178,   179,   183,
     184,   185,   189,   190,   194,   198,   199,   203,   204,   208,
     209,   213,   214,   218,   219,   224,   225,   229,   230,   234,
     235,   236,   240,   241,   242,   243,   244,   248,   249,   250,
     254,   255,   256,   260,   261,   262,   263,   267,   268,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     286,   287,   288,   289,   290,   291,   292,   293,   297,   298,
     299,   300,   304,   305,   306,   310,   314,   315,   319,   323,
     324,   328,   329,   330,   334,   335,   339,   340,   344,   345,
     349,   350,   354,   355,   356,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   374,   375,   376,   377,   378,   379,
     383,   384,   388,   389,   393,   394,   398,   399,   403,   404,
     405,   409,   410,   411,   412,   416,   417,   418,   422,   423,
     424,   425
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ASSIGNMENT_OP", "RIGHT_SHIFT_OP",
  "LEFT_SHIFT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "INT_CONSTANT", "FLOAT_CONSTANT",
  "STRING_LITERAL", "T_VOID", "T_CHAR", "T_SHORT", "T_INT", "T_LONG",
  "T_FLOAT", "T_DOUBLE", "T_SIGNED", "T_UNSIGNED", "T_TYPEDEF", "T_EXTERN",
  "T_STATIC", "T_AUTO", "T_REGISTER", "T_CONST", "T_VOLATILE", "T_STRUCT",
  "T_UNION", "T_GOTO", "T_BREAK", "T_CONTINUE", "T_CASE", "T_DEFAULT",
  "T_SWITCH", "T_IF", "T_ELSE", "T_RETURN", "T_WHILE", "T_DO", "T_FOR",
  "T_SIZEOF", "T_ENUM", "TYPEDEF_NAME", "T_IDENTIFIER",
  "ENUMERATION_CONSTANT", "NOELSE", "';'", "'{'", "'}'", "','", "':'",
  "'='", "'('", "')'", "'['", "']'", "'?'", "'|'", "'^'", "'&'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept",
  "root", "translation_unit", "external_declaration",
  "typedef_declaration", "declaration", "declaration_specifier_list",
  "declaration_specifiers", "struct_or_union_specifier",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "init_declarator_list",
  "init_declarator", "declarator", "direct_declarator", "initialiser_list",
  "initialiser", "assignment_operator", "constant_expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "constant", "expression", "function_definition", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list", "pointer",
  "argument_expression_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "labeled_statement",
  "jump_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    59,   123,   125,    44,    58,    61,
      40,    41,    91,    93,    63,   124,    94,    38,    62,    60,
      43,    45,    42,    47,    37,   126,    33,    46
};
# endif

#define YYPACT_NINF (-185)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     951,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
     825,   -24,     0,  -185,  -185,   -14,   -39,    35,   951,  -185,
    -185,  -185,   970,  -185,  -185,  -185,    36,   -19,  -185,    22,
    1076,    49,   825,    65,     5,    16,  -185,  -185,  -185,  -185,
    -185,    70,  -185,    21,   258,  -185,  1139,   484,   -19,    76,
     825,   878,   391,  -185,     5,    81,    92,  -185,  -185,  -185,
     -14,   546,  -185,   744,   744,  -185,  -185,  -185,    99,   112,
     806,    88,   113,   120,   560,   121,   382,   124,   819,   128,
    -185,  -185,  -185,   444,   806,   806,   806,   806,   806,   806,
    -185,   970,  -185,  -185,    11,   176,   123,   125,   129,   137,
       1,    94,    89,    64,  -185,    13,   127,  -185,  -185,   140,
    -185,  -185,   320,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  1013,   136,   141,  -185,    39,  -185,  -185,   138,  -185,
    -185,  -185,  1190,  -185,   806,    74,  -185,   142,  -185,  -185,
     107,   806,  -185,     5,  -185,   143,   546,  -185,  -185,   806,
    -185,  -185,  -185,  -185,   145,   382,   806,   806,  -185,   152,
     806,   162,   622,   444,  -185,   382,  1094,   147,   148,  -185,
    -185,  -185,  -185,  -185,  -185,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,  -185,  -185,   806,  -185,  -185,   159,
     635,   806,   160,  -185,  -185,  -185,   896,   652,  -185,    -3,
    -185,    23,  -185,   825,   163,  -185,  -185,  -185,  -185,  -185,
     -22,   806,  -185,  -185,  -185,   115,  -185,   382,  -185,   154,
     155,  -185,   156,   165,   622,   158,  -185,  1031,    85,  -185,
    -185,   806,   176,   169,   123,   125,   129,   137,     1,     1,
      94,    94,    94,    94,    89,    89,    64,    64,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,    40,   157,  -185,  -185,   167,
     171,  -185,   170,    23,  1157,   714,  -185,  -185,  -185,  -185,
    -185,   470,  -185,   382,   382,   382,   806,   727,  -185,  -185,
     806,   806,  -185,  -185,  -185,  -185,  -185,  -185,   174,  -185,
     173,  -185,  -185,  -185,   187,  -185,   177,   382,   185,  -185,
    -185,  -185,  -185,   382,   194,  -185,   382,  -185,  -185,  -185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,    24,    50,     0,   136,     0,     2,     3,
       7,     6,     0,    11,    22,    23,     0,    49,     5,     0,
       0,    27,     0,    39,     0,     0,   137,     1,     4,     9,
      12,     0,    44,    47,     0,   127,     0,     0,    48,     0,
       0,     0,     0,    28,     0,    42,     0,    40,    51,    10,
       0,     0,   126,     0,     0,   122,   123,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     124,   166,   160,     0,     0,     0,     0,     0,     0,     0,
     164,     0,   125,    65,    67,    69,    71,    73,    75,    77,
      79,    82,    87,    90,    93,    97,    99,   110,   119,     0,
     165,   155,     0,   162,   156,   157,   158,   154,   159,   134,
      56,   133,     0,   128,   129,     0,   118,    52,     0,    64,
      97,     8,     0,    30,     0,     0,    32,    36,    25,    29,
       0,     0,    37,     0,    45,    47,     0,    46,    61,     0,
     100,   101,   179,   178,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,   108,     0,   140,     0,     0,   102,
     104,   105,   103,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    62,     0,   116,   117,     0,
       0,     0,     0,   167,   161,   163,     0,     0,   131,   142,
     132,   143,    54,     0,     0,    55,    53,    26,    34,    31,
       0,     0,    38,    43,    41,     0,    57,     0,   177,     0,
       0,   181,     0,     0,     0,     0,   175,     0,   142,   141,
     121,     0,    70,     0,    72,    74,    76,    78,    80,    81,
      85,    86,    83,    84,    89,    88,    91,    92,    94,    95,
      96,    66,   115,   112,   138,     0,     0,   114,   150,     0,
       0,   146,     0,   144,     0,     0,   130,   135,    33,    35,
      59,     0,   176,     0,     0,     0,     0,     0,   109,    98,
       0,     0,   113,   111,   151,   145,   147,   152,     0,   148,
       0,    60,    58,   170,   169,   171,     0,     0,     0,    68,
     139,   153,   149,     0,     0,   173,     0,   168,   172,   174
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,   231,  -185,   -33,    42,    -4,  -185,   200,
     -42,  -185,    37,  -185,   201,   116,  -185,   196,    -7,   -27,
    -185,  -140,  -185,   -63,   -57,   -46,  -185,    83,    84,    82,
      87,    90,    -5,   -77,    -9,     3,   -23,   -44,  -185,  -185,
    -185,   -34,  -185,   -43,  -185,    54,  -185,   -11,  -185,   105,
     -99,  -184,   -62,     2,  -185,   150,  -153,  -185,  -185,  -185,
    -185
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,   121,    23,    24,    52,
      53,   135,   136,    25,    56,    57,    41,    42,    26,    27,
     225,   147,   196,   128,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   130,   106,   107,
     108,   109,    28,   269,   123,   124,   125,    29,   265,   168,
     270,   211,   110,   111,   112,   113,   114,   115,   116,   117,
     118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     105,   129,    48,   122,   148,    36,   226,   154,    35,   234,
     139,    90,   183,   184,   161,    43,   194,   105,    40,   150,
     151,   175,   210,    49,   129,   273,    40,    31,    45,    14,
     105,    32,   105,    16,   164,    37,   134,    14,    15,   105,
     159,    46,    22,    47,   137,    62,    15,    40,    14,   167,
      16,    33,    30,   145,   273,    34,    55,   206,    16,   207,
      22,   169,   170,   171,   172,   173,   174,   239,   105,   185,
     186,   218,   195,    14,    51,   176,    44,    58,   223,    90,
      61,   287,    15,   274,   145,   275,    91,    40,   129,   148,
     139,    44,    51,   228,    51,   129,   214,   291,   187,   188,
     215,   292,   105,   236,    50,   105,   250,   251,   252,   253,
     209,   105,   105,   105,   208,   167,   105,    40,   105,   105,
      54,   105,   229,   230,    59,   166,   232,    60,   219,   167,
     131,   220,   105,   197,   198,   199,   191,   192,   193,   261,
     141,   302,   243,   264,   272,   237,   155,   207,   142,   143,
     181,   182,   105,   152,    91,   238,   105,   105,   279,   189,
     190,   129,    40,   222,   143,   282,   153,   266,   258,   259,
     260,   280,   281,   156,    51,   129,   248,   249,   254,   255,
     157,   160,    48,   105,   162,   177,   165,   200,   178,   201,
     105,   179,   256,   257,   203,   209,   180,   212,   213,    35,
     221,   216,    61,   227,   202,   166,   231,   233,   240,   241,
     262,   267,   300,   137,   277,   283,   284,   285,   289,   288,
     293,   303,   304,   305,   148,   286,   238,   290,   294,   129,
     313,   298,   295,   296,   310,   311,   312,   105,   314,   105,
     105,   105,   105,   105,   309,   315,   316,   105,   318,    38,
     132,   317,   306,   308,   319,   140,   144,   278,   242,   224,
     245,   244,   205,   105,    63,    64,   246,   276,   235,   105,
     247,     0,   105,    65,    66,    67,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    12,    13,    79,
      80,     0,    81,    44,    82,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,    84,    63,    64,    85,    86,
      87,     0,     0,    88,    89,    65,    66,    67,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,    77,    78,    12,
      13,    79,    80,     0,    81,    44,   204,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,    84,    63,    64,
      85,    86,    87,     0,     0,    88,    89,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    68,
      69,    70,    71,    72,    73,    11,    74,    75,    76,    77,
      78,     0,     0,    79,    80,     0,    81,    44,     0,     0,
      12,    13,    83,     0,     0,     0,     0,   138,     0,    84,
      63,    64,    85,    86,    87,     0,     0,    88,    89,    65,
      66,    67,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    63,    64,    11,     0,
       0,     0,     0,     0,     0,    65,    66,    67,     0,     0,
      63,    64,    78,    12,    13,   126,    80,     0,     0,    65,
      66,    67,     0,     0,    83,     0,     0,     0,     0,     0,
       0,    84,     0,     0,    85,    86,    87,     0,    78,    88,
      89,   126,    80,     0,     0,   146,   301,     0,     0,     0,
      83,     0,    78,     0,     0,   126,    80,    84,     0,     0,
      85,    86,    87,     0,    83,    88,    89,   127,     0,     0,
       0,    84,    63,    64,    85,    86,    87,     0,     0,    88,
      89,    65,    66,    67,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,   126,    80,     0,
       0,   146,     0,     0,     0,     0,    83,     0,    78,     0,
       0,   126,    80,    84,   158,     0,    85,    86,    87,     0,
      83,    88,    89,     0,     0,     0,     0,    84,    63,    64,
      85,    86,    87,     0,     0,    88,    89,    65,    66,    67,
       0,    63,    64,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      78,     0,     0,   126,    80,     0,    81,     0,     0,     0,
       0,     0,    83,    78,     0,     0,   126,    80,     0,    84,
       0,     0,    85,    86,    87,    83,   263,    88,    89,     0,
      78,     0,    84,   126,    80,    85,    86,    87,     0,     0,
      88,    89,    83,     0,     0,   271,     0,     0,     0,    84,
      63,    64,    85,    86,    87,     0,     0,    88,    89,    65,
      66,    67,     0,    63,    64,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    78,     0,     0,   126,    80,     0,     0,     0,
       0,     0,     0,     0,    83,    78,     0,   299,   126,    80,
       0,    84,     0,     0,    85,    86,    87,    83,   307,    88,
      89,     0,    78,     0,    84,   126,    80,    85,    86,    87,
       0,     0,    88,    89,   149,     0,     0,     0,     0,     0,
       0,    84,    63,    64,    85,    86,    87,     0,     0,    88,
      89,    65,    66,    67,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,    78,     0,     0,   126,    80,    11,
       0,     0,     0,     0,     0,     0,    83,    78,     0,     0,
     126,    80,     0,    84,    12,    13,    85,    86,    87,   163,
       0,    88,    89,     0,     0,     0,    84,     0,     0,    85,
      86,    87,     0,     0,    88,    89,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,     0,     0,    12,    13,    14,
      11,     0,   133,     0,     0,     0,   134,     0,    15,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     0,     0,     0,   206,   268,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,    13,    14,     0,    11,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,     0,    16,    39,     0,     0,     0,     0,     0,
      15,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    16,     0,     0,     0,     0,    11,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    12,    13,    14,    11,     0,     0,     0,     0,
       0,     0,     0,   206,     0,   207,     0,     0,     0,     0,
      12,    13,     0,     0,     0,    16,     0,     0,     0,     0,
       0,   237,   268,   207,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    16,     0,     0,     0,     0,     0,     0,
      11,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,     0,    12,    13,    14,    11,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,    16,     0,
       0,     0,     0,     0,   237,     0,   207,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    16,     0,     0,     0,
       0,     0,     0,    11,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,    12,    13,
     119,    11,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,     0,     0,     0,    12,    13,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,   297,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,     0,   217
};

static const yytype_int16 yycheck[] =
{
      44,    47,    29,    46,    61,    16,   146,    70,    15,   162,
      52,    44,    11,    12,    76,    22,     3,    61,    22,    63,
      64,    10,   121,    30,    70,   209,    30,    51,    26,    51,
      74,    55,    76,    72,    78,     0,    58,    51,    60,    83,
      74,    60,     0,    62,    51,    43,    60,    51,    51,    83,
      72,    51,    10,    60,   238,    55,    51,    60,    72,    62,
      18,    84,    85,    86,    87,    88,    89,   166,   112,    68,
      69,   134,    59,    51,    32,    64,    55,    61,   141,   112,
      59,   234,    60,    60,    91,    62,    44,    91,   134,   146,
     132,    55,    50,   155,    52,   141,    57,    57,     4,     5,
      61,    61,   146,   165,    55,   149,   183,   184,   185,   186,
     121,   155,   156,   157,   121,   149,   160,   121,   162,   163,
      55,   165,   156,   157,    54,    83,   160,    57,    54,   163,
      54,    57,   176,     6,     7,     8,    72,    73,    74,   196,
      59,   281,   176,   200,   207,    60,    58,    62,    56,    57,
      13,    14,   196,    54,   112,   166,   200,   201,   221,    70,
      71,   207,   166,    56,    57,   227,    54,   201,   191,   192,
     193,    56,    57,    60,   132,   221,   181,   182,   187,   188,
      60,    60,   209,   227,    60,     9,    58,    60,    65,    62,
     234,    66,   189,   190,    54,   206,    67,    61,    57,   206,
      58,    63,    59,    58,    77,   163,    54,    45,    61,    61,
      51,    51,   275,   220,    51,    61,    61,    61,   241,    61,
      63,   283,   284,   285,   281,    60,   237,    58,    61,   275,
      43,   274,    61,    63,   291,    61,    63,   281,    61,   283,
     284,   285,   286,   287,   290,   307,    61,   291,    54,    18,
      50,   313,   286,   287,   316,    54,    60,   220,   175,   143,
     178,   177,   112,   307,     6,     7,   179,   213,   163,   313,
     180,    -1,   316,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,     6,     7,    70,    71,
      72,    -1,    -1,    75,    76,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,     6,     7,
      70,    71,    72,    -1,    -1,    75,    76,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    37,
      38,    39,    40,    41,    42,    34,    44,    45,    46,    47,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    -1,
      49,    50,    60,    -1,    -1,    -1,    -1,    56,    -1,    67,
       6,     7,    70,    71,    72,    -1,    -1,    75,    76,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,     6,     7,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
       6,     7,    48,    49,    50,    51,    52,    -1,    -1,    15,
      16,    17,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    71,    72,    -1,    48,    75,
      76,    51,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    -1,    48,    -1,    -1,    51,    52,    67,    -1,    -1,
      70,    71,    72,    -1,    60,    75,    76,    63,    -1,    -1,
      -1,    67,     6,     7,    70,    71,    72,    -1,    -1,    75,
      76,    15,    16,    17,    -1,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    48,    -1,
      -1,    51,    52,    67,    54,    -1,    70,    71,    72,    -1,
      60,    75,    76,    -1,    -1,    -1,    -1,    67,     6,     7,
      70,    71,    72,    -1,    -1,    75,    76,    15,    16,    17,
      -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      48,    -1,    -1,    51,    52,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    48,    -1,    -1,    51,    52,    -1,    67,
      -1,    -1,    70,    71,    72,    60,    61,    75,    76,    -1,
      48,    -1,    67,    51,    52,    70,    71,    72,    -1,    -1,
      75,    76,    60,    -1,    -1,    63,    -1,    -1,    -1,    67,
       6,     7,    70,    71,    72,    -1,    -1,    75,    76,    15,
      16,    17,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    48,    -1,    63,    51,    52,
      -1,    67,    -1,    -1,    70,    71,    72,    60,    61,    75,
      76,    -1,    48,    -1,    67,    51,    52,    70,    71,    72,
      -1,    -1,    75,    76,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,     6,     7,    70,    71,    72,    -1,    -1,    75,
      76,    15,    16,    17,    -1,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    48,    -1,    -1,    51,    52,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    48,    -1,    -1,
      51,    52,    -1,    67,    49,    50,    70,    71,    72,    60,
      -1,    75,    76,    -1,    -1,    -1,    67,    -1,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    49,    50,    51,
      34,    -1,    54,    -1,    -1,    -1,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      49,    50,    51,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    72,    54,    -1,    -1,    -1,    -1,    -1,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    34,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    49,    50,    51,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    49,    50,    51,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    49,    50,
      51,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    49,    50,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    34,    49,    50,    51,    60,    72,    79,    80,    81,
      82,    83,    84,    85,    86,    91,    96,    97,   120,   125,
      84,    51,    55,    51,    55,    96,   125,     0,    81,    54,
      85,    94,    95,    96,    55,   131,    60,    62,    97,    96,
      55,    84,    87,    88,    55,    51,    92,    93,    61,    54,
      57,    59,   131,     6,     7,    15,    16,    17,    37,    38,
      39,    40,    41,    42,    44,    45,    46,    47,    48,    51,
      52,    54,    56,    60,    67,    70,    71,    72,    75,    76,
      83,    84,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    51,
      61,    84,   121,   122,   123,   124,    51,    63,   101,   103,
     115,    54,    87,    54,    58,    89,    90,    96,    56,    88,
      92,    59,    56,    57,    95,    96,    55,    99,   102,    60,
     115,   115,    54,    54,   101,    58,    60,    60,    54,   119,
      60,   130,    60,    60,   115,    58,    84,   119,   127,   114,
     114,   114,   114,   114,   114,    10,    64,     9,    65,    66,
      67,    13,    14,    11,    12,    68,    69,     4,     5,    70,
      71,    72,    73,    74,     3,    59,   100,     6,     7,     8,
      60,    62,    77,    54,    56,   133,    60,    62,    96,   125,
     128,   129,    61,    57,    57,    61,    63,    56,   101,    54,
      57,    58,    56,   101,    93,    98,    99,    58,   130,   119,
     119,    54,   119,    45,   134,   127,   130,    60,   125,   128,
      61,    61,   105,   119,   106,   107,   108,   109,   110,   110,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   102,    51,    61,   102,   126,   119,    51,    61,   121,
     128,    63,   101,   129,    60,    62,   123,    51,    90,   101,
      56,    57,   130,    61,    61,    61,    60,   134,    61,   114,
      58,    57,    61,    63,    61,    61,    63,    61,   121,    63,
     101,    56,    99,   130,   130,   130,   119,    61,   119,   103,
     102,    61,    63,    43,    61,   130,    61,   130,    54,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   110,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   112,   113,   113,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   118,   118,   118,   119,   120,   120,   121,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   137,   137,   137,   138,   138,
     138,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     4,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     2,
       2,     3,     1,     3,     2,     3,     1,     4,     5,     2,
       1,     3,     1,     3,     1,     3,     3,     1,     2,     1,
       1,     3,     3,     4,     4,     4,     3,     1,     3,     3,
       4,     1,     1,     1,     1,     1,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     4,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       1,     4,     3,     4,     3,     3,     2,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     2,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     2,     1,     1,     1,     2,     7,     5,
       5,     5,     7,     6,     7,     3,     4,     3,     2,     2,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 66 "src/c_parser.y"
                       {/*$1 = new translation_unit();*/ g_root = (yyvsp[0].bnode);}
#line 1814 "src/c_parser.tab.cpp"
    break;

  case 3:
#line 69 "src/c_parser.y"
                                        {(yyval.bnode) = new translation_unit((yyvsp[0].node));}
#line 1820 "src/c_parser.tab.cpp"
    break;

  case 4:
#line 70 "src/c_parser.y"
                                                         { (yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1826 "src/c_parser.tab.cpp"
    break;

  case 5:
#line 74 "src/c_parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1832 "src/c_parser.tab.cpp"
    break;

  case 6:
#line 75 "src/c_parser.y"
                                                {(yyval.node) = (yyvsp[0].node);}
#line 1838 "src/c_parser.tab.cpp"
    break;

  case 7:
#line 76 "src/c_parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1844 "src/c_parser.tab.cpp"
    break;

  case 8:
#line 80 "src/c_parser.y"
                                                                    {(yyval.node) = new typedef_declaration((yyvsp[-2].bnode),(yyvsp[-1].node));}
#line 1850 "src/c_parser.tab.cpp"
    break;

  case 9:
#line 84 "src/c_parser.y"
                                                {(yyval.node) = new declaration((yyvsp[-1].bnode));}
#line 1856 "src/c_parser.tab.cpp"
    break;

  case 10:
#line 85 "src/c_parser.y"
                                                                       {(yyval.node) = new declaration((yyvsp[-2].bnode),(yyvsp[-1].bnode));}
#line 1862 "src/c_parser.tab.cpp"
    break;

  case 11:
#line 89 "src/c_parser.y"
                                                {(yyval.bnode) = new declaration_specifier_list((yyvsp[0].node));}
#line 1868 "src/c_parser.tab.cpp"
    break;

  case 12:
#line 90 "src/c_parser.y"
                                                                    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1874 "src/c_parser.tab.cpp"
    break;

  case 13:
#line 94 "src/c_parser.y"
                                                                {(yyval.node) = new declaration_specifiers("void");}
#line 1880 "src/c_parser.tab.cpp"
    break;

  case 14:
#line 95 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("char");}
#line 1886 "src/c_parser.tab.cpp"
    break;

  case 15:
#line 96 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("short");}
#line 1892 "src/c_parser.tab.cpp"
    break;

  case 16:
#line 97 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("int"); }
#line 1898 "src/c_parser.tab.cpp"
    break;

  case 17:
#line 98 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("long");}
#line 1904 "src/c_parser.tab.cpp"
    break;

  case 18:
#line 99 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("float");}
#line 1910 "src/c_parser.tab.cpp"
    break;

  case 19:
#line 100 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("double");}
#line 1916 "src/c_parser.tab.cpp"
    break;

  case 20:
#line 101 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("signed");}
#line 1922 "src/c_parser.tab.cpp"
    break;

  case 21:
#line 102 "src/c_parser.y"
                                                        {(yyval.node) = new declaration_specifiers("unsigned");}
#line 1928 "src/c_parser.tab.cpp"
    break;

  case 22:
#line 103 "src/c_parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1934 "src/c_parser.tab.cpp"
    break;

  case 23:
#line 104 "src/c_parser.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1940 "src/c_parser.tab.cpp"
    break;

  case 24:
#line 105 "src/c_parser.y"
                                                        {(yyval.node) = new TypdefSpecifier(*((yyvsp[0].string)));}
#line 1946 "src/c_parser.tab.cpp"
    break;

  case 25:
#line 109 "src/c_parser.y"
                                                                                        {(yyval.node) = new struct_specifier((yyvsp[-1].bnode));}
#line 1952 "src/c_parser.tab.cpp"
    break;

  case 26:
#line 110 "src/c_parser.y"
                                                                        {(yyval.node) = new struct_specifier(*((yyvsp[-3].string)), (yyvsp[-1].bnode));}
#line 1958 "src/c_parser.tab.cpp"
    break;

  case 27:
#line 111 "src/c_parser.y"
                                                                                                        {(yyval.node) = new struct_specifier(*((yyvsp[0].string)));}
#line 1964 "src/c_parser.tab.cpp"
    break;

  case 28:
#line 115 "src/c_parser.y"
                                                                                                                {(yyval.bnode) = new struct_declaration_list((yyvsp[0].node));}
#line 1970 "src/c_parser.tab.cpp"
    break;

  case 29:
#line 116 "src/c_parser.y"
                                                                                {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1976 "src/c_parser.tab.cpp"
    break;

  case 30:
#line 120 "src/c_parser.y"
                                                                                                {(yyval.node) = new struct_declaration((yyvsp[-1].bnode));}
#line 1982 "src/c_parser.tab.cpp"
    break;

  case 31:
#line 121 "src/c_parser.y"
                                                                        {(yyval.node) = new struct_declaration((yyvsp[-2].bnode), (yyvsp[-1].bnode));}
#line 1988 "src/c_parser.tab.cpp"
    break;

  case 32:
#line 125 "src/c_parser.y"
                                                                                                                {(yyval.bnode) = new struct_declarator_list((yyvsp[0].node));}
#line 1994 "src/c_parser.tab.cpp"
    break;

  case 33:
#line 126 "src/c_parser.y"
                                                                                {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2000 "src/c_parser.tab.cpp"
    break;

  case 34:
#line 130 "src/c_parser.y"
                                                                                                        {(yyval.node) = new struct_declarator((yyvsp[0].enode));}
#line 2006 "src/c_parser.tab.cpp"
    break;

  case 35:
#line 131 "src/c_parser.y"
                                                                                        {(yyval.node) = new struct_declarator((yyvsp[-2].node), (yyvsp[0].enode));}
#line 2012 "src/c_parser.tab.cpp"
    break;

  case 36:
#line 132 "src/c_parser.y"
                                                                                                                {(yyval.node) = new struct_declarator((yyvsp[0].node));}
#line 2018 "src/c_parser.tab.cpp"
    break;

  case 37:
#line 136 "src/c_parser.y"
                                                                                                {(yyval.node) = new EnumConstants((yyvsp[-1].bnode));}
#line 2024 "src/c_parser.tab.cpp"
    break;

  case 38:
#line 137 "src/c_parser.y"
                                                                                {(yyval.node) = new EnumDeclaration(*((yyvsp[-3].string)), (yyvsp[-1].bnode));}
#line 2030 "src/c_parser.tab.cpp"
    break;

  case 39:
#line 138 "src/c_parser.y"
                                                                                                        {(yyval.node) = new EnumSpecifier(*((yyvsp[0].string)));}
#line 2036 "src/c_parser.tab.cpp"
    break;

  case 40:
#line 142 "src/c_parser.y"
                                                                                                                        {(yyval.bnode) =  new enumerator_list((yyvsp[0].node));}
#line 2042 "src/c_parser.tab.cpp"
    break;

  case 41:
#line 143 "src/c_parser.y"
                                                                                                {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2048 "src/c_parser.tab.cpp"
    break;

  case 42:
#line 148 "src/c_parser.y"
                                                                                                                {(yyval.node) = new enumerator(*((yyvsp[0].string)));}
#line 2054 "src/c_parser.tab.cpp"
    break;

  case 43:
#line 149 "src/c_parser.y"
                                                                                        {(yyval.node) = new enumerator(*((yyvsp[-2].string)), (yyvsp[0].enode));}
#line 2060 "src/c_parser.tab.cpp"
    break;

  case 44:
#line 153 "src/c_parser.y"
                                                                                                                {(yyval.bnode) = new init_declarator_list((yyvsp[0].node));}
#line 2066 "src/c_parser.tab.cpp"
    break;

  case 45:
#line 154 "src/c_parser.y"
                                                                                        {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2072 "src/c_parser.tab.cpp"
    break;

  case 46:
#line 158 "src/c_parser.y"
                                                 {(yyval.node) = new init_declarator((yyvsp[-2].node), (yyvsp[0].node));}
#line 2078 "src/c_parser.tab.cpp"
    break;

  case 47:
#line 159 "src/c_parser.y"
                                                         {(yyval.node) = new init_declarator((yyvsp[0].node));}
#line 2084 "src/c_parser.tab.cpp"
    break;

  case 48:
#line 163 "src/c_parser.y"
                                                {(yyval.node) = new declarator((yyvsp[0].node), (yyvsp[-1].ptrNode));}
#line 2090 "src/c_parser.tab.cpp"
    break;

  case 49:
#line 164 "src/c_parser.y"
                                                {(yyval.node) = (yyvsp[0].node);}
#line 2096 "src/c_parser.tab.cpp"
    break;

  case 50:
#line 168 "src/c_parser.y"
                                                                                                        {(yyval.node) = new direct_declarator(*((yyvsp[0].string)));}
#line 2102 "src/c_parser.tab.cpp"
    break;

  case 51:
#line 169 "src/c_parser.y"
                                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 2108 "src/c_parser.tab.cpp"
    break;

  case 52:
#line 170 "src/c_parser.y"
                                                                                        {(yyval.node) = new ArrayDeclaration((yyvsp[-2].node));}
#line 2114 "src/c_parser.tab.cpp"
    break;

  case 53:
#line 171 "src/c_parser.y"
                                                                        {(yyval.node) = new ArrayDeclaration((yyvsp[-3].node), (yyvsp[-1].enode));}
#line 2120 "src/c_parser.tab.cpp"
    break;

  case 54:
#line 172 "src/c_parser.y"
                                                                        {(yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-1].bnode));}
#line 2126 "src/c_parser.tab.cpp"
    break;

  case 55:
#line 173 "src/c_parser.y"
                                                                        {(yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-1].idlist));}
#line 2132 "src/c_parser.tab.cpp"
    break;

  case 56:
#line 174 "src/c_parser.y"
                                                                                        {(yyval.node) = new FunctionDeclaration((yyvsp[-2].node));}
#line 2138 "src/c_parser.tab.cpp"
    break;

  case 57:
#line 178 "src/c_parser.y"
                                                                                        {(yyval.bnode) = new initialiser_list((yyvsp[0].node));}
#line 2144 "src/c_parser.tab.cpp"
    break;

  case 58:
#line 179 "src/c_parser.y"
                                                                {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2150 "src/c_parser.tab.cpp"
    break;

  case 59:
#line 183 "src/c_parser.y"
                                                                        {(yyval.node) = new ObjectInitialiser((yyvsp[-1].bnode));}
#line 2156 "src/c_parser.tab.cpp"
    break;

  case 60:
#line 184 "src/c_parser.y"
                                                                {(yyval.node) = new ObjectInitialiser((yyvsp[-2].bnode));}
#line 2162 "src/c_parser.tab.cpp"
    break;

  case 61:
#line 185 "src/c_parser.y"
                                                                        {(yyval.node) = new initialiser((yyvsp[0].enode));}
#line 2168 "src/c_parser.tab.cpp"
    break;

  case 62:
#line 189 "src/c_parser.y"
                                                        {(yyval.string) = new std::string("="); }
#line 2174 "src/c_parser.tab.cpp"
    break;

  case 63:
#line 190 "src/c_parser.y"
                                        {(yyval.string) = (yyvsp[0].string); }
#line 2180 "src/c_parser.tab.cpp"
    break;

  case 64:
#line 194 "src/c_parser.y"
                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2186 "src/c_parser.tab.cpp"
    break;

  case 65:
#line 198 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2192 "src/c_parser.tab.cpp"
    break;

  case 66:
#line 199 "src/c_parser.y"
                                                                                {(yyval.enode) = new assignment_expression((yyvsp[-2].enode), *(yyvsp[-1].string), (yyvsp[0].enode));}
#line 2198 "src/c_parser.tab.cpp"
    break;

  case 67:
#line 203 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2204 "src/c_parser.tab.cpp"
    break;

  case 68:
#line 204 "src/c_parser.y"
                                                                                        {(yyval.enode) = new conditional_expression((yyvsp[-4].enode),(yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2210 "src/c_parser.tab.cpp"
    break;

  case 69:
#line 208 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2216 "src/c_parser.tab.cpp"
    break;

  case 70:
#line 209 "src/c_parser.y"
                                                                                        {(yyval.enode) = new LogicalOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2222 "src/c_parser.tab.cpp"
    break;

  case 71:
#line 213 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2228 "src/c_parser.tab.cpp"
    break;

  case 72:
#line 214 "src/c_parser.y"
                                                                                        {(yyval.enode) = new LogicalAndOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2234 "src/c_parser.tab.cpp"
    break;

  case 73:
#line 218 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2240 "src/c_parser.tab.cpp"
    break;

  case 74:
#line 219 "src/c_parser.y"
                                                                                                {(yyval.enode) = new InclusiveOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2246 "src/c_parser.tab.cpp"
    break;

  case 75:
#line 224 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2252 "src/c_parser.tab.cpp"
    break;

  case 76:
#line 225 "src/c_parser.y"
                                                                                                {(yyval.enode) = new ExclusiveOrOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2258 "src/c_parser.tab.cpp"
    break;

  case 77:
#line 229 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2264 "src/c_parser.tab.cpp"
    break;

  case 78:
#line 230 "src/c_parser.y"
                                                                                                        {(yyval.enode) = new AndOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2270 "src/c_parser.tab.cpp"
    break;

  case 79:
#line 234 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2276 "src/c_parser.tab.cpp"
    break;

  case 80:
#line 235 "src/c_parser.y"
                                                                                                {(yyval.enode) = new EqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2282 "src/c_parser.tab.cpp"
    break;

  case 81:
#line 236 "src/c_parser.y"
                                                                                                {(yyval.enode) = new NotEqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2288 "src/c_parser.tab.cpp"
    break;

  case 82:
#line 240 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2294 "src/c_parser.tab.cpp"
    break;

  case 83:
#line 241 "src/c_parser.y"
                                                                                                {(yyval.enode) = new GreaterThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2300 "src/c_parser.tab.cpp"
    break;

  case 84:
#line 242 "src/c_parser.y"
                                                                                                {(yyval.enode) = new LessThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2306 "src/c_parser.tab.cpp"
    break;

  case 85:
#line 243 "src/c_parser.y"
                                                                                                {(yyval.enode) = new LessThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2312 "src/c_parser.tab.cpp"
    break;

  case 86:
#line 244 "src/c_parser.y"
                                                                                                {(yyval.enode) = new GreaterThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2318 "src/c_parser.tab.cpp"
    break;

  case 87:
#line 248 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2324 "src/c_parser.tab.cpp"
    break;

  case 88:
#line 249 "src/c_parser.y"
                                                                                        {(yyval.enode) = new LeftShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2330 "src/c_parser.tab.cpp"
    break;

  case 89:
#line 250 "src/c_parser.y"
                                                                                        {(yyval.enode) = new RightShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2336 "src/c_parser.tab.cpp"
    break;

  case 90:
#line 254 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2342 "src/c_parser.tab.cpp"
    break;

  case 91:
#line 255 "src/c_parser.y"
                                                                                                {(yyval.enode) = new AddOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2348 "src/c_parser.tab.cpp"
    break;

  case 92:
#line 256 "src/c_parser.y"
                                                                                                {(yyval.enode) = new SubOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2354 "src/c_parser.tab.cpp"
    break;

  case 93:
#line 260 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2360 "src/c_parser.tab.cpp"
    break;

  case 94:
#line 261 "src/c_parser.y"
                                                                                                {(yyval.enode) = new MultOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2366 "src/c_parser.tab.cpp"
    break;

  case 95:
#line 262 "src/c_parser.y"
                                                                                                {(yyval.enode) = new DivOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2372 "src/c_parser.tab.cpp"
    break;

  case 96:
#line 263 "src/c_parser.y"
                                                                                                {(yyval.enode) = new ModulusOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2378 "src/c_parser.tab.cpp"
    break;

  case 97:
#line 267 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2384 "src/c_parser.tab.cpp"
    break;

  case 98:
#line 268 "src/c_parser.y"
                                                                        {(yyval.enode) = new cast_expression((yyvsp[-2].node), (yyvsp[0].enode));}
#line 2390 "src/c_parser.tab.cpp"
    break;

  case 99:
#line 272 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2396 "src/c_parser.tab.cpp"
    break;

  case 100:
#line 273 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new PreIncOp((yyvsp[0].enode));}
#line 2402 "src/c_parser.tab.cpp"
    break;

  case 101:
#line 274 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new PreDecOp((yyvsp[0].enode));}
#line 2408 "src/c_parser.tab.cpp"
    break;

  case 102:
#line 275 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new RefOp((yyvsp[0].enode));}
#line 2414 "src/c_parser.tab.cpp"
    break;

  case 103:
#line 276 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new PtrOp((yyvsp[0].enode));}
#line 2420 "src/c_parser.tab.cpp"
    break;

  case 104:
#line 277 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new UAddOp((yyvsp[0].enode));}
#line 2426 "src/c_parser.tab.cpp"
    break;

  case 105:
#line 278 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new USubOp((yyvsp[0].enode));}
#line 2432 "src/c_parser.tab.cpp"
    break;

  case 106:
#line 279 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new BitwiseNotOp((yyvsp[0].enode));}
#line 2438 "src/c_parser.tab.cpp"
    break;

  case 107:
#line 280 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new LogicalNotOp((yyvsp[0].enode));}
#line 2444 "src/c_parser.tab.cpp"
    break;

  case 108:
#line 281 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new SizeOf((yyvsp[0].enode));}
#line 2450 "src/c_parser.tab.cpp"
    break;

  case 109:
#line 282 "src/c_parser.y"
                                                                                                                {(yyval.enode) = new SizeOf((yyvsp[-1].node));}
#line 2456 "src/c_parser.tab.cpp"
    break;

  case 110:
#line 286 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = (yyvsp[0].enode);}
#line 2462 "src/c_parser.tab.cpp"
    break;

  case 111:
#line 287 "src/c_parser.y"
                                                                                                        {(yyval.enode) = new array_call((yyvsp[-3].enode), (yyvsp[-1].enode));}
#line 2468 "src/c_parser.tab.cpp"
    break;

  case 112:
#line 288 "src/c_parser.y"
                                                                                                                {(yyval.enode) = new function_call((yyvsp[-2].enode), NULL);}
#line 2474 "src/c_parser.tab.cpp"
    break;

  case 113:
#line 289 "src/c_parser.y"
                                                                                        {(yyval.enode) = new function_call((yyvsp[-3].enode), (yyvsp[-1].bnode));}
#line 2480 "src/c_parser.tab.cpp"
    break;

  case 114:
#line 290 "src/c_parser.y"
                                                                                                        {(yyval.enode) = new DotMemberOp((yyvsp[-2].enode), *((yyvsp[0].string)));}
#line 2486 "src/c_parser.tab.cpp"
    break;

  case 115:
#line 291 "src/c_parser.y"
                                                                                                        {(yyval.enode) = new PtrMemberOp((yyvsp[-2].enode), *((yyvsp[0].string)));}
#line 2492 "src/c_parser.tab.cpp"
    break;

  case 116:
#line 292 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new PostIncOp((yyvsp[-1].enode));}
#line 2498 "src/c_parser.tab.cpp"
    break;

  case 117:
#line 293 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = new PostDecOp((yyvsp[-1].enode));}
#line 2504 "src/c_parser.tab.cpp"
    break;

  case 118:
#line 297 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = new primary_expression(*((yyvsp[0].string)));}
#line 2510 "src/c_parser.tab.cpp"
    break;

  case 119:
#line 298 "src/c_parser.y"
                                                                                                                                        {(yyval.enode) = new constantNode((yyvsp[0].number));}
#line 2516 "src/c_parser.tab.cpp"
    break;

  case 120:
#line 299 "src/c_parser.y"
                                                                                                                                {(yyval.enode) = new stringNode(*((yyvsp[0].string)));}
#line 2522 "src/c_parser.tab.cpp"
    break;

  case 121:
#line 300 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[-1].enode);}
#line 2528 "src/c_parser.tab.cpp"
    break;

  case 122:
#line 304 "src/c_parser.y"
                                                                                                                                {(yyval.number) = (yyvsp[0].number);}
#line 2534 "src/c_parser.tab.cpp"
    break;

  case 123:
#line 305 "src/c_parser.y"
                                                                                                                                {(yyval.number) = (yyvsp[0].number);}
#line 2540 "src/c_parser.tab.cpp"
    break;

  case 124:
#line 306 "src/c_parser.y"
                                        {}
#line 2546 "src/c_parser.tab.cpp"
    break;

  case 125:
#line 310 "src/c_parser.y"
                                                                                                                        {(yyval.enode) = (yyvsp[0].enode);}
#line 2552 "src/c_parser.tab.cpp"
    break;

  case 126:
#line 314 "src/c_parser.y"
                                                                                                                        {(yyval.node) = new function_definition((yyvsp[-2].bnode), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2558 "src/c_parser.tab.cpp"
    break;

  case 127:
#line 315 "src/c_parser.y"
                                                                                                                                                {(yyval.node) = new function_definition((yyvsp[-1].node), (yyvsp[0].node));}
#line 2564 "src/c_parser.tab.cpp"
    break;

  case 128:
#line 319 "src/c_parser.y"
                                                                                                {(yyval.bnode) = (yyvsp[0].bnode);}
#line 2570 "src/c_parser.tab.cpp"
    break;

  case 129:
#line 323 "src/c_parser.y"
                                                                                        {(yyval.bnode) = new parameter_list((yyvsp[0].node));}
#line 2576 "src/c_parser.tab.cpp"
    break;

  case 130:
#line 324 "src/c_parser.y"
                                                                        {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2582 "src/c_parser.tab.cpp"
    break;

  case 131:
#line 328 "src/c_parser.y"
                                                                                {(yyval.node) = new parameter_declaration((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2588 "src/c_parser.tab.cpp"
    break;

  case 132:
#line 329 "src/c_parser.y"
                                                                        {(yyval.node) = new parameter_declaration((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2594 "src/c_parser.tab.cpp"
    break;

  case 133:
#line 330 "src/c_parser.y"
                                                                                        {(yyval.node) = new parameter_declaration((yyvsp[0].bnode));}
#line 2600 "src/c_parser.tab.cpp"
    break;

  case 134:
#line 334 "src/c_parser.y"
                                                                                                {(yyval.idlist) = new identifier_list(*((yyvsp[0].string)));}
#line 2606 "src/c_parser.tab.cpp"
    break;

  case 135:
#line 335 "src/c_parser.y"
                                                                                {(yyval.idlist) = (yyvsp[-2].idlist); (yyval.idlist)->push(*((yyvsp[0].string)));}
#line 2612 "src/c_parser.tab.cpp"
    break;

  case 136:
#line 339 "src/c_parser.y"
                                                                                                                {(yyval.ptrNode) = new Pointer();}
#line 2618 "src/c_parser.tab.cpp"
    break;

  case 137:
#line 340 "src/c_parser.y"
                                                                                                {(yyval.ptrNode) = (yyvsp[0].ptrNode); (yyval.ptrNode)->inc();}
#line 2624 "src/c_parser.tab.cpp"
    break;

  case 138:
#line 344 "src/c_parser.y"
                                                                                                        {(yyval.bnode) = new argument_expression_list((yyvsp[0].enode));}
#line 2630 "src/c_parser.tab.cpp"
    break;

  case 139:
#line 345 "src/c_parser.y"
                                                                        {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].enode));}
#line 2636 "src/c_parser.tab.cpp"
    break;

  case 140:
#line 349 "src/c_parser.y"
                                                                                                        {(yyval.node) = new type_name((yyvsp[0].bnode));}
#line 2642 "src/c_parser.tab.cpp"
    break;

  case 141:
#line 350 "src/c_parser.y"
                                                                                {(yyval.node) = new type_name((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2648 "src/c_parser.tab.cpp"
    break;

  case 142:
#line 354 "src/c_parser.y"
                                                                                                                        {(yyval.node) = new abstract_pointer((yyvsp[0].ptrNode));}
#line 2654 "src/c_parser.tab.cpp"
    break;

  case 143:
#line 355 "src/c_parser.y"
                                                                                                {(yyval.node) = new abstract_declarator((yyvsp[0].node));}
#line 2660 "src/c_parser.tab.cpp"
    break;

  case 144:
#line 356 "src/c_parser.y"
                                                                                        {(yyval.node) = new abstract_declarator((yyvsp[0].node), (yyvsp[-1].ptrNode));}
#line 2666 "src/c_parser.tab.cpp"
    break;

  case 145:
#line 360 "src/c_parser.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 2672 "src/c_parser.tab.cpp"
    break;

  case 146:
#line 361 "src/c_parser.y"
                                                                                                                                {(yyval.node) = new AbstractArray();}
#line 2678 "src/c_parser.tab.cpp"
    break;

  case 147:
#line 362 "src/c_parser.y"
                                                                                                        {(yyval.node) = new AbstractArray(NULL, (yyvsp[-1].enode));}
#line 2684 "src/c_parser.tab.cpp"
    break;

  case 148:
#line 363 "src/c_parser.y"
                                                                                                {(yyval.node) = new AbstractArray((yyvsp[-2].node), NULL);}
#line 2690 "src/c_parser.tab.cpp"
    break;

  case 149:
#line 364 "src/c_parser.y"
                                                                                {(yyval.node) = new AbstractArray((yyvsp[-3].node), (yyvsp[-1].enode));}
#line 2696 "src/c_parser.tab.cpp"
    break;

  case 150:
#line 365 "src/c_parser.y"
                                                                                                                                {/*TODO: do it later.*/}
#line 2702 "src/c_parser.tab.cpp"
    break;

  case 151:
#line 366 "src/c_parser.y"
                                                                                                        {/*TODO: do it later.*/}
#line 2708 "src/c_parser.tab.cpp"
    break;

  case 152:
#line 367 "src/c_parser.y"
                                                                                                {/*TODO: do it later.*/}
#line 2714 "src/c_parser.tab.cpp"
    break;

  case 153:
#line 368 "src/c_parser.y"
                                                                                {/*TODO: do it later.*/}
#line 2720 "src/c_parser.tab.cpp"
    break;

  case 154:
#line 374 "src/c_parser.y"
                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2726 "src/c_parser.tab.cpp"
    break;

  case 155:
#line 375 "src/c_parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2732 "src/c_parser.tab.cpp"
    break;

  case 156:
#line 376 "src/c_parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2738 "src/c_parser.tab.cpp"
    break;

  case 157:
#line 377 "src/c_parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2744 "src/c_parser.tab.cpp"
    break;

  case 158:
#line 378 "src/c_parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2750 "src/c_parser.tab.cpp"
    break;

  case 159:
#line 379 "src/c_parser.y"
                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2756 "src/c_parser.tab.cpp"
    break;

  case 160:
#line 383 "src/c_parser.y"
                                                                                        {(yyval.node) = new compound_statement();}
#line 2762 "src/c_parser.tab.cpp"
    break;

  case 161:
#line 384 "src/c_parser.y"
                                                                        {(yyval.node) = new compound_statement((yyvsp[-1].bnode));}
#line 2768 "src/c_parser.tab.cpp"
    break;

  case 162:
#line 388 "src/c_parser.y"
                                                                                        {(yyval.bnode) = new block_item_list((yyvsp[0].node));}
#line 2774 "src/c_parser.tab.cpp"
    break;

  case 163:
#line 389 "src/c_parser.y"
                                                                {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2780 "src/c_parser.tab.cpp"
    break;

  case 164:
#line 393 "src/c_parser.y"
                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2786 "src/c_parser.tab.cpp"
    break;

  case 165:
#line 394 "src/c_parser.y"
                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2792 "src/c_parser.tab.cpp"
    break;

  case 166:
#line 398 "src/c_parser.y"
                                                                                                {(yyval.node) = new expression_statement();}
#line 2798 "src/c_parser.tab.cpp"
    break;

  case 167:
#line 399 "src/c_parser.y"
                                                                                {(yyval.node) = new expression_statement((yyvsp[-1].enode));}
#line 2804 "src/c_parser.tab.cpp"
    break;

  case 168:
#line 403 "src/c_parser.y"
                                                                    {(yyval.node) = new IfStatement((yyvsp[-4].enode), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2810 "src/c_parser.tab.cpp"
    break;

  case 169:
#line 404 "src/c_parser.y"
                                                                        {(yyval.node) = new IfStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2816 "src/c_parser.tab.cpp"
    break;

  case 170:
#line 405 "src/c_parser.y"
                                                                                {(yyval.node) = new SwitchStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2822 "src/c_parser.tab.cpp"
    break;

  case 171:
#line 409 "src/c_parser.y"
                                                                                                                                        {(yyval.node) = new WhileStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2828 "src/c_parser.tab.cpp"
    break;

  case 172:
#line 410 "src/c_parser.y"
                                                                                                                                {(yyval.node) = new DoStatement((yyvsp[-5].node), (yyvsp[-2].enode));}
#line 2834 "src/c_parser.tab.cpp"
    break;

  case 173:
#line 411 "src/c_parser.y"
                                                                                                                {(yyval.node) = new ForStatement((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2840 "src/c_parser.tab.cpp"
    break;

  case 174:
#line 412 "src/c_parser.y"
                                                                                                {(yyval.node) = new ForStatement((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].enode), (yyvsp[0].node));}
#line 2846 "src/c_parser.tab.cpp"
    break;

  case 175:
#line 416 "src/c_parser.y"
                                                                                        {(yyval.node) = new LabelStatement(*((yyvsp[-2].string)), (yyvsp[0].node));}
#line 2852 "src/c_parser.tab.cpp"
    break;

  case 176:
#line 417 "src/c_parser.y"
                                                                        {(yyval.node) = new CaseStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2858 "src/c_parser.tab.cpp"
    break;

  case 177:
#line 418 "src/c_parser.y"
                                                                                        {(yyval.node) = new DefaultStatement((yyvsp[0].node));}
#line 2864 "src/c_parser.tab.cpp"
    break;

  case 178:
#line 422 "src/c_parser.y"
                                                                                                {(yyval.node) = new ContinueStatement();}
#line 2870 "src/c_parser.tab.cpp"
    break;

  case 179:
#line 423 "src/c_parser.y"
                                                                                                {(yyval.node) = new BreakStatement();}
#line 2876 "src/c_parser.tab.cpp"
    break;

  case 180:
#line 424 "src/c_parser.y"
                                                                                                {(yyval.node) = new ReturnStatement();}
#line 2882 "src/c_parser.tab.cpp"
    break;

  case 181:
#line 425 "src/c_parser.y"
                                                                                        {(yyval.node) = new ReturnStatement((yyvsp[-1].enode));}
#line 2888 "src/c_parser.tab.cpp"
    break;


#line 2892 "src/c_parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 428 "src/c_parser.y"


BranchNode *g_root;

Node *parseAST(char* fileName)
{
  	g_root=0;
	yyin = fopen(fileName, "r");
  	yyparse();
  	fclose(yyin);
  	return g_root;
}
