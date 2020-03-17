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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);

    string a[2];
    int cnt1  = 0, cnt2 = 0, cnt3 = 0;
    for(int j = 0; j < 2; j++)
            cin >> a[j];
        
    int n = a[0].size();
    for ( int j = 0; j < n; j++){
        if ( a[0][j] == a[1][j] && a[0][j] == '#') cnt1++;
        if ( a[0][j] != a[1][j] && a[0][j] == '#') cnt2++;
        if ( a[0][j] != a[1][j] && a[1][j] == '#') cnt3++;
    }
    int cnt4 = n - cnt1 - cnt2 - cnt3;
    if(cnt1 or (cnt2 == 0 or cnt3 == 0)){
        cout << "YES" << endl;
        for(int i = 0; i < cnt2 + cnt1; i++)
            cout << '#';
        for(int i = 0; i < cnt3 + cnt4; i++ )
            cout << '.';
        cout << endl;
        for(int i = 0; i < cnt2; i++)
            cout << '.';
        for(int i = 0; i < cnt3 + cnt1; i++)
            cout << '#';
         for(int i = 0; i < cnt4; i++ )
            cout << '.';
    }else {
        cout << "NO";
    }
}