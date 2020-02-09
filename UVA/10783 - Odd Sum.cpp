#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int c = 0;
    while (n--){
        long long int a,b;
        c++;
        cin >> a >> b;
        cout << "Case "<<c<<": ";
        if (a%2 == 0) a++;
        if (b%2 == 0) b--;
        if (b < a){
            cout << "0" << endl;
            continue;
        }
        long long int ans = ((a+b) * ((b/2) - (a/2)+1))/2;
        cout << ans << "\n";
    }
}
