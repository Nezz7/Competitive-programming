#include <bits/stdc++.h>
using namespace std;
int p[3000];
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie (0);
    int n;
    cin >> n ;
    for (int i = 2 ; i <= n ; i++){
        if (!p[i]){
            for (int j = i ; j <= n ; j+=i)
                p[j] = i;
        }
    }
    set<int> st;
    for (int i = 2 ;i <= n ; i++){
            int x = i;
            int cnt = 0;
            while (x > 1){
                int d = p[x];
                cnt++;
                while (x % d == 0)
                    x /= d;
            }
            if (cnt == 1){st.insert(i);}
    }
    cout << st.size() <<"\n";
    for (auto cur : st)
        cout << cur << " ";
}
