#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    int x;
    cin >> x;
    int y = x;
    int c = 0;
    int p = -1;
    while (y > 0) {
        y/=10;
        p++;
        c = c * 10 + 1;
    }
    //cout << c  << " " << p << endl;
    int ans = x /c + p * 9;
    cout << ans << "\n";
    }
}
