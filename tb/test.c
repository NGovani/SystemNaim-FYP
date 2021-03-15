int foo(int g){
    int x;
    x = g + 4;
    return g;
}


int func(int a, int b){
    int i;
    int y = 0;
    int s = 4;
    for(i = 0; i < 5; i = i + 1){
        s = s + a + b;
        y = foo(2) + y;
    }
    return s + y;
}

