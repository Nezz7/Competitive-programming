#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("ouput","w" ,stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        long long int x,y,a,b;
        cin >> x >> y;
        a = (x + y) / 2;
        b = (x - a);
        if ((x + y) % 2 or a < 0 or b < 0  or (x)!=(a+b) or y!=(abs(a-b))){
            cout << "impossible\n";
        }else cout << max(a,b) << " " << min(b,a) << "\n";
    }

}
