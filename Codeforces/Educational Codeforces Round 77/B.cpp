#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie(0) , cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL a,b;
        cin >> a >> b;
        if ( a == 0 && b == 0){
            cout << "YES\n";
            continue;
        }
        if (a == 0 or b == 0){
            cout << "NO\n";
            continue;
        }
        if ((a + b) % 3){
            cout << "NO\n";
        }else{
            int d = (a+b)/3;
            if (a >= d && b >= d)
                            cout << "YES\n";
            else cout << "NO\n";
        }

    }
}
