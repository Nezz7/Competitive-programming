#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
vector<int> p;
struct suffixAutomaton{
    static int const M = 26; // Careful ! size of alphabet
	struct state{
		int len;		// length of longest string in this class
		int link;		// pointer to suffix link
		int nxt[M]; 	// adjacency list
		LL cnt;			// number of times the strings in this state occur in the original string
		bool terminal;	// by default, empty string is a suffix
						// a state is terminal if it corresponds to a suffix
        int first_pos;
        bool is_clone;
        vector<int> inv_link;
		state(){
			len = 0, link = -1, cnt = 0;
            is_clone = false;
            first_pos = 0;
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
        for (int v = 1; v < sz; v++)  st[st[v].link].inv_link.push_back(v);

	}

	void addChar(int c){
		int cur = sz++; assert(cur < MAXN*2);
		st[cur].len = st[last].len + 1;
        st[cur].first_pos = st[cur].len - 1;
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
		st[clone].first_pos = st[q].first_pos;
        st[clone].is_clone = true;
		st[clone].len = st[p].len + 1;
		st[clone].cnt = 0;				// cloned states initially have cnt = 0
		while(p != -1 and st[p].nxt[c] == q){
			st[p].nxt[c] = clone;
			p = st[p].link;
		}
		st[q].link = st[cur].link = clone;
	}

	int contains(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].nxt[t[i] - offset];
			if(cur == -1) return cur;
		}
		return cur;
	}
    void all_occurrences(int v, int P_length) {
        if (!st[v].is_clone){
            int x = st[v].first_pos - P_length + 1;
            p.push_back(x);
        }
        for (int u : st[v].inv_link)
            all_occurrences(u, P_length);
    }
    int solve(string & s,int k){
        p.clear();
        int v = contains(s);
        if(v == -1){
            return -1 ;
        }
        all_occurrences(v,s.size());
        int len = s.size();
        if(sz(p) < k) return -1;
		for(auto cur : p) cout << cur << ' ';
		cout << endl;
        int ret = 1e9;
        for(int i = 0; i + k - 1 < sz(p); i++){
            ret = min(ret,p[i+k-1] + len - p[i]);
        }
        return ret ;
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    suffixAutomaton sa(s);
    int q;
    cin >> q;
    while(q--){
        int k;
        string p;
        cin >> k >> p;
    	cout << sa.solve(p,k) << endl;
    }
}