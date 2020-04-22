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
int const MAXN = 2e5 + 9;
LL a[MAXN];
void no (){
    cout << "Impossible";
    exit(0);
}
LL get(LL x){
    return  x  * ( x + 1 )/ 2; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < MAXN; i++){
        a[i] = get(i);
    }
    int a00,a01,a10,a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if ((a00  + a01 + a10 + a11) == 0) {cout << "1"; return 0;}
    int nbr0 = lower_bound(a, a + MAXN, a00) - a;
    if (a[nbr0] != a00)  no();
    int nbr1 = lower_bound(a, a + MAXN, a11) - a;
    if (a[nbr1] != a11)  no();
    if(a00) nbr0++;
    else if((a00 == 0) && (a01 or a10)) nbr0++;
    if(a11) nbr1++;
    else if((a11 == 0) && (a01 or a10)) nbr1++;

    string ans = "";
    while(a10){
        if(a10 >= nbr0){
            if(nbr1){
                ans += "1";
                nbr1--;
            }else no();
            a10 -= nbr0;
            if(!nbr0) no();
        }else {
            if(nbr0) ans+="0",nbr0--;
            else no();
        }
    }
    while(nbr0){
        nbr0--;
        ans+="0";
    }
     while(nbr1){
        nbr1--;
        ans+="1";
    }
    int n = sz(ans);
    int cur = 0;
    for(int i = n - 1; i >= 0 ; i--){
        char c = ans[i];
        if (c == '1') cur++;
        else a01 -= cur;
    }
    if (!a01) cout << ans;
    else no();
}