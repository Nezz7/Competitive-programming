 struct BIT {
    #define T //define type
    vector<T> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
