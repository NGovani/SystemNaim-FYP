int hls_test_func(int g){
    int x;
    x = g + 4;
    x = x * 3;
    return x;
}


int hls_test_top(int a, int b){
    int i;
    int y = 0;
    int s = 4;
    for(i = 0; i < 5; i = i + 1){
        s = s + a + b;
        y = hls_test_func(2) + y;
    }
    return s + y;
}

