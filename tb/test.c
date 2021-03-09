int func(int a, int b){
    int i;
    int y = 0;
    int s = 4;
    for(i = 0; i < 5; i = i + 1){
        s = s + a + 1;
        y = a + b;
    }
    return s + y;
}

