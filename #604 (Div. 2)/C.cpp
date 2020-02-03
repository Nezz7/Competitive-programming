#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int occ[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i],occ[a[i]]++;
        if( n < 6){
            cout <<"0 0 0"<< "\n";
            for (int i = 0; i < n; i++)
            occ[a[i]]--;
            continue;
        }
        int g = occ[a[0]], b = 0, s = 0;

        b = n/2 - 1;
        if (a[b] == a[b+1]){
            while (b > 0 && a[b] == a[n/2-1])
                b--;
        }
        int L  = b;
        if (a[b] == a[0]){
             cout <<"0 0 0"<< "\n";
             for (int i = 0; i < n; i++)
            occ[a[i]]--;
            continue;
        }
        s = b + 1 - g - occ[a[b]];
        b = occ[a[b]];
        while(g >= b ) b+= occ[a[L-b]];
        s = L + 1 - g - b;
        bool cond = true;
        if (s <= 0 or g >= s) cond = false;
        if (!cond) cout <<"0 0 0"<< "\n";
        else  cout << g << " " << s << " " << b << "\n";
          for (int i = 0; i < n; i++)
            occ[a[i]]--;
    }
}
