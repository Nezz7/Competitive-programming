#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        map<string,int>mp;
        string a[n];
        for (int i = 0; i < n;i++)
            cin >> a[i],mp[a[i]]++;
        int ans = 0;
        for (auto cur : mp){
            ans+=cur.second-1;
        }
        cout << ans << "\n";
        for (int i =0; i < n ;i++){
            mp[a[i]]--;
            int k = a[i][0] - '0';
            k += mp[a[i]];
            k %= 10;
            a[i][0] = k + '0';
            while (mp[a[i]] != 0){
                k++;
                k %=10;
                a[i][0] = k + '0';
            }
            mp[a[i]] = 1;
            cout << a[i] << "\n";
        }

    }

}


