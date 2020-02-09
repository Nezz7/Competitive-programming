#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 4e5+9;
LL last[MAXN];
LL get(int i){
    int r = 0;
    while (i > 0){
        i /= 10;
        r++;
    }
    return r;
}
LL go (LL i , int id){
        vector<int> v;
        while(i > 0){
            v.push_back(i % 10);
            i/= 10;
        }
        int n = v.size();
    return v[n - id];

}
LL a [MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    for (int i = 1; i < MAXN; i++){
        last[i] = last[i-1] + get (i);
        a[i] = a[i-1] + last[i];
    }
    int T;
    cin >> T;
    while (T--){
        int x;
        cin >> x;
        int L = 0, R = MAXN-1;
        int ans = 0;
        while (L <= R){
            int mid = (L + R) / 2;
            if (x <= a[mid]){
                ans = mid;
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        LL d = x - a[ans-1];
        L = 0, R = MAXN-1;
        ans = 0;
        while (L <= R){
            int mid = (L + R) / 2;
            if (d <= last [mid]){
                ans = mid;
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        d = d - last[ans-1];
        cout << go (ans,d) << "\n";

    }
}
