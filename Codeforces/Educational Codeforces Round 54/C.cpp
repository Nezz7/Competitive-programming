#include <bits/stdc++.h>
#define f first
#define s second
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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    cout << setprecision(20);
    while(T--){
        int d;
        cin >> d;
        int b = -d, c = d;
        double a = 1;
        int delta = b *b - 4 * a * c;
        if (delta < 0){
            cout << "N"  << endl;
        }else {
            cout << "Y ";
            double rd = sqrt(delta);
            double x2 = (-b - rd) / 2*a;
            double x1 = (-b + rd) / 2*a;
            cout << x1 << " " << x2 << endl;
        }
    }
}