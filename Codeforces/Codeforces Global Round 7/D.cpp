#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int F[10][MAXN];
void pre (string & p,int k){
    int n=p.size();
    for (int i=1,j=0;i<n;i++){
        while (j>0 && p[i]!=p[j]) j=F[k][j-1];
        if (p[i]==p[j]) F[k][i]=++j;
        else F[k][i]=j;
    }
}
bool cond(string &s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1 - i]) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        if (cond(s)){
            cout << s << endl;
            continue;
        }
        int n = s.size();
        string r = s;
        reverse(all(r));
        string p = s + "#" + r;
        pre(p,0);
        int mx = 0;
        for(int i = n +1; i < 2*n +1; i++){
            if(F[0][i] <= F[0][i-1]) break;
            if(!F[0][i]) break;
            mx = max(F[0][i],mx);
        }
        string l = s.substr(0,mx) ;
        string rl = l; 
        reverse(all(rl));
        string suff = s.substr(n-mx,mx);
        if(suff != rl){
            l = "";
            rl = "";
        }
        mx = l.size();
        string nw = s.substr(mx,n - 2*mx);
        string rnw = nw;
        reverse(all(rnw));
        string pf = nw + "8" + rnw;
        string sf = rnw + "8" + nw;
        int m = sz(pf) - 1;
        pre(pf,1);
        pre(sf,2);
        string x;
        if(F[1][m] > F[2][m]){
            x = nw.substr(0,F[1][m]);
        }else  x = nw.substr(sz(nw)-F[2][m],F[2][m]);
        cout << l  << x << rl << endl;
    }
}
