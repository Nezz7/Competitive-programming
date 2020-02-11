#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
int F[MAXN];
string s;
string pre (string p){
    int n=p.size();
    for (int i=1,j=0;i<n;i++){
        while (j>0 && p[i]!=p[j]) j=F[j-1];
        if (p[i]==p[j]) F[i]=++j;
        else F[i]=j;
    }
    if (F[n-1]){
        n -= F[n-1];
        if ((int) p.size() % (n) == 0) return p.substr(0,n);
    }
    return p;
}
int main(){
    string a,b;
    cin >> a >> b;
    string p = pre(a);
    string s = pre(b);
    if (s != p){
        cout << 0;
        return 0;
    }
    int n = a.size();
    int m = b.size();
    int k = p.size();
    int ans = 0;
    for (int i = k; i <=min(n,m);i+=k){
        ans+=(m % i == 0 && n % i == 0);
    }
    cout << ans;
}

