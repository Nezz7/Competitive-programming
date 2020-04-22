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
int const MAXN = 1e5 + 9;
LL a[MAXN];
void get (LL x){
     for(int i = 0; i < MAXN; i++){
        int idx = lower_bound(a,a+MAXN,a[i] - x) - a;
        if(a[i] -  a[idx] == x) {
            cout << sqrt(a[i]) << ' ' << sqrt(a[idx]) << endl;
            return ;
        }
    }
    if ( x & 1){
        cout <<  "Spinster Number." << endl;
        return ;
    }
    cout << "Bachelor Number." << endl;
}

   
int cntBachelor(long long n1) {
    if(n1 < 0)  n1 = -n1;
    if(n1 < 2)  return 0;
    return (n1-2)/4+1;
}
int main() {
     for(LL i = 0; i < MAXN; i++){
        a[i] = i * i;
    }
    char cmd[50];
    long long n1, n2;
    while(gets(cmd)) {
        if(sscanf(cmd,"%lld %lld", &n1, &n2) == 2) {
            long long i, j, t1, t2;
            if(n1 > n2) swap(n1, n2);
            if(n1 < 0 && n2 > 0) {
                t1 = cntBachelor(n1);
                t2 = cntBachelor(n2);
                j = t1+t2;
            } else {
                if(n1 < 0)  n1 = -n1, n2 = -n2;
                t1 = cntBachelor(abs(n1)-1);
                t2 = cntBachelor(n2);
                j = t2-t1;
            }
            printf("%lld\n", j);
        } else {
            sscanf(cmd, "%lld", &n1);
            get(n1);
        }
    }
    return 0;
}