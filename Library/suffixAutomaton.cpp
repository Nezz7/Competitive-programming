using pii = pair<int,int>;
int const MAXN = 2e6 + 9;
struct suffixAutomaton{
    static int const M = 26; // Careful ! size of alphabet
	struct state{
		int len;		// length of longest string in this class
		int link;		// pointer to suffix link
		int nxt[M]; 	// adjacency list
		LL cnt;			// number of times the strings in this state occur in the original string
		bool terminal;	// by default, empty string is a suffix
						// a state is terminal if it corresponds to a suffix
		state(){
			len = 0, link = -1, cnt = 0;
			terminal = false;
			for(int i = 0; i < M; i++) nxt[i] = -1;
		}
	};

    vector<state>st;
	int sz, last, l;
	char offset = 'a';	// Careful!

	suffixAutomaton(string &s){
		int l = s.length();
        st.resize(2 * l);
		for(int i = 0; i < 2*l; i++) st[i] = state();
		sz = 1, last = 0;
		st[0].len = 0;
		st[0].link = -1;
		for(int i = 0; i < l; i++)
			addChar(s[i] - offset);
		for(int i = last; i != -1; i = st[i].link) st[i].terminal = true;
	}

	void addChar(int c){
		int cur = sz++; assert(cur < MAXN*2);
		st[cur].len = st[last].len + 1;
		st[cur].cnt = 1;

		int p = last;
		while(p != -1 and st[p].nxt[c] == -1){
			st[p].nxt[c] = cur;
			p = st[p].link;
		}
		last = cur;
		if(p == -1){
			st[cur].link = 0; return;
		}
		int q = st[p].nxt[c];
		if(st[q].len == st[p].len + 1){
			st[cur].link = q; return;
		}
		int clone = sz++;
		for(int i = 0; i < M; i++) st[clone].nxt[i] = st[q].nxt[i];
		st[clone].link = st[q].link;
		st[clone].len = st[p].len + 1;
		st[clone].cnt = 0;				// cloned states initially have cnt = 0
		while(p != -1 and st[p].nxt[c] == q){
			st[p].nxt[c] = clone;
			p = st[p].link;
		}
		st[q].link = st[cur].link = clone;
	}

	bool contains(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].nxt[t[i] - offset];
			if(cur == -1) return false;
		}
		return true;
	}

	// alternatively, compute the number of paths in a DAG
	// since each substring corresponds to one unique path in SA
	LL numberOfSubstrings(){
		LL res = 0;
		for(int i = 1; i < sz; i++) res += st[i].len - st[st[i].link].len;
		return res;
	}

	void numberOfOccPreprocess(){
		vector<pii> v;
		for(int i = 1; i < sz; i++) v.push_back(make_pair(st[i].len, i));

		sort(v.begin(), v.end(), greater<pii>());

		for(int i = 0; i < sz-1; i++){
			int suf = st[v[i].second].link;
			st[suf].cnt += st[v[i].second].cnt;
		}
	}

	LL numberOfOcc(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].nxt[t[i] - offset];
			if(cur == -1) return 0;
		}
		return st[cur].cnt;
	}
    int dfs (int i, int pos){
        if (pos == p.size()) return 1;
        char c = p[pos] - offset;
        if (i == 0  && st[0].nxt[c] == -1) return -1e9;
        if (st[i].nxt[c] == -1) return 1 + dfs(0,pos); 
        int go = st[i].nxt[c];
        return  dfs(go,pos+1); 
    }
    
};