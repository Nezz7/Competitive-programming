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
int is_prime[MAXN];
vector<int> p;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    is_prime[1] = 1;
    for(int i = 2; i < MAXN; i++)
        if(!is_prime[i]){
            p.push_back(i);
            for(int j = 2 * i; j < MAXN; j += i)
                is_prime[j] = 1;
        }
    int x;
    cin >> x;
    int ans = 0;
    while(x >= 4){
        for(auto cur : p){
            if(!is_prime[x - cur]){
                x = (x - cur) - cur;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}