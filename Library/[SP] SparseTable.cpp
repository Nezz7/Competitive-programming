struct SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
    int l;
    int f(int a, int b){
       // define function
    }
    SparseTable(int * a,int n){
        l = ceil(log2(n + 1));
        lg.assign(n+1,0);
        st.assign(n+1,vector<int> (l + 1));
        lg[1] = 0;
        for (int i = 2; i < n; i++)
            lg[i] = lg[i/2] + 1;
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; j < l; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = f(st[i][j - 1],st[i + (1 << (j - 1)) ][j - 1]);
        
    }    
    int get (int L, int R){
        int j = lg[R - L + 1];
        return f(st[L][j], st[R - (1 << j) + 1][j]);
    }
    LL query(int L, int R){
        LL ret = 0;
        for (int j = l; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                ret = f(ret,st[L][j]);
                L += 1 << j;
            }
        }
        return ret;
    }
};
