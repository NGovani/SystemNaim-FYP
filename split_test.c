int hls_test_func_a(int g){
    int x;
    x = g + 4;
    x = x * 3;
    return x;
}

int hls_test_func_b(int g){
    int z;
    z = g + 3;
    z = g * 2;
    return z;
}



int hls_test_top(int a, int b){
    int i;
    int y = 0;
    int s = 4;
    int holda;
    int holdb;
    split{
        holda = hls_test_func_a(4);
        holdb = hls_test_func_b(3);
    }
    for(i = 0; i < 5; i = i + 1){
        s = s + a + b;
        y = hls_test_func(2) + y;
    }
    return s + y;
}
