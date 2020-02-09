#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5+9;
int p[MAXN];
LL sum[MAXN], a[MAXN];
vector<int> primes;
LL get_sum (LL x){
    LL d = x/2;
    LL ret = (1 + d)*d;
    if (x%2 == 0) ret-=d;
    return ret;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),  cout.tie(0);
    p[0]=1;
    p[1]=1;
    for (int i = 2; i < MAXN; i++){
        if (!p[i]){
            for (int j = i; j < MAXN; j+=i)
                p[j] = i;
        }
    }
    int n;
    cin>> n;
    for (int i = 0; i < n; i++){
        cin >>a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    LL x = sum [n];
    if ( x == 1 ){
        cout << -1;
        return 0;
    }
    while (x > 1){
        int d = p[x];
        primes.push_back(d);
        while (x % d == 0)
            x /= d;
    }
    LL ans = 1e18;
    int last = 0;
    for (int j = 0; j < primes.size(); j++){
            int d = primes [j];
            LL cur = 0;
            int last = 0;
            LL o = 0;
            LL z = 0;
            for (int i = 1; i <= n; i++){
                if (sum[i] == sum[last]){
                        last++;
                        continue;
                }
                if (a[i - 1] ==  1) o++;
                else if (o < d - o) z+=o;
                else z+= d - o;
                if (sum[i] % d == 0){
                    LL c = sum[i]-sum[last];
                    cur += get_sum(sum[i]-sum[last])+z;
                    o = 0;
                    z = 0;
                    last = i;
                }
            }
            ans = min (ans, cur);
    }
    cout << ans ;
}

