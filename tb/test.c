int hls_test_func_a(int g){
    int x;
    int i;
    x = g + 4;
    for(i = 0; i < 50; i = i + 1){   
        x = x + 3;
    }
    return x;
}

int hls_test_func_b(int g){
    int z;
    int i;
    z = g + 3;
    for(i = 0; i < 50; i = i + 1){   
        z = g + 2;
    }
    return z;
}

int hls_test_top(int a, int b){
    int i;
    int s = 4;
    int holda;
    int holdb;
    //split{
        holda = hls_test_func_a(4);
        holdb = hls_test_func_b(3);
    //}
    s = s + a + b;
    return holda + holdb + s;
}