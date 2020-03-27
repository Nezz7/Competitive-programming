int a[MAXN],st[MAXN][K];
int lg[MAXN];

int f(int a, int b){
    // define function
}
int get (int L, int R){
    int j = lg[R - L + 1];
    return f(st[L][j], st[R - (1 << j) + 1][j]);
}
LL query(int L, int R){
    LL ret = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            ret = f(ret,st[L][j]);
            L += 1 << j;
        }
    }
    return ret;
}
void init (){
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i/2] + 1;
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j < K; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = f(st[i][j - 1],st[i + (1 << (j - 1)) ][j - 1]);
        }
    }
}