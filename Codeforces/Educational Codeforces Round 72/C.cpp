#include <bits/stdc++.h>
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
int nxt[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    string s;
       cin >> s;
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '1') nxt[i] = i;
			else nxt[i] = (i == 0? -1 : nxt[i - 1]);		
		int res = 0;
		for(int r = 0; r < s.size(); ++r){
			int sum = 0;
			for(int l = r; l >= 0 && r - l < 20; --l){
				if(s[l] == '0') continue;
				sum += 1 << (r - l);
				if(sum <= r - (l == 0? -1 : nxt[l - 1]))
					++res;
			}
		}
		cout << res << endl;
    }
}