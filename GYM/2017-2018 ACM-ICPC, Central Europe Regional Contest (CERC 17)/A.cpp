class SegmentTree {
    #define l(i) (i<<1)
    #define r(i) ((i<<1)|1)
	public:
	int n; vector<int> st, en; vector<int> val, lz;
	SEGTREE(){}
	SEGTREE(int _n) {
		n = 1<<(int)ceil(log2(_n));
        int sz = n*2;
		st.assign(sz, 0);
        en.assign(sz, 0);
		val.assign(sz, 0);
        lz.assign(sz, 0);
		build(1, 1, n);
	}
	inline LL value(int i) {
        return val[i]+lz[i];
    }
	inline void build(int i, int _st, int _en) {
		st[i] = _st; en[i] = _en;
		if (st[i]==en[i]) return;
		int mid = (st[i]+en[i])/2;
		build(l(i), st[i], mid);
        build(r(i), mid+1, en[i]);
		updateUP(i);
	}
	inline int query_max(const int& qL, const int& qR, int i = 1) {
		if (en[i] < qL || qR < st[i]) return 0;
		if (qL <= st[i] && en[i] <= qR) return value(i);
		propagateDOWN(i);
		int ans = max(query_max(qL,qR,l(i)) , query_max(qL,qR,r(i)));
		updateUP(i);
		return ans;
	}
	inline void add(const int& qL,const int& qR,const int& qVal,int i = 1) {
		if (en[i] < qL || qR < st[i]) return;
		if (qL <= st[i] && en[i] <= qR) { lz[i] += qVal; return; }
		propagateDOWN(i);
		add(qL,qR,qVal,l(i));
        add(qL,qR,qVal,r(i));
		updateUP(i);
	}
	inline void setVal(const int& qI, const int& qVal){
		add(qI,qI,qVal-query_max(qI,qI));
	}
};