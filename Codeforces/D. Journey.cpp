#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int k;
    if ((m % 2  == 0  && n != 1 )or (n % 2 == 0 && m != 1)) k =0;
    else k = 1;
    if (n  == 1 && m==2) k = 0;
    if (n  == 2 && m==1) k = 0;
if (!k){
        cout << 0 << endl;
    if (m % 2 == 0){
        for (int i = 0; i < m ;i++)
            cout <<  1 << " " << i + 1 << "\n";
        int d =0;
        for (int j = m ; j > 0 ; j --){
            if (!d){
                for (int i = 2; i <= n ; i++)
                    cout << i << " "  <<j << "\n";
            }
            else{
                  for (int i = n; i > 1 ; i--)
                    cout << i << " "  << j<< "\n";
            }
            d^=1;
        }
        cout << 1 << " " << 1;
    }else {
         for (int i = 0; i < m ;i++)
            cout <<  1 << " " << i + 1 << "\n";
        int d =0;
        for (int i = 2 ; i <= n ; i++){
            if (!d){
                for (int j = m; j > 1 ; j--)
                    cout << i << " "  <<j << "\n";
            }
            else{
                  for (int j = 2; j <= m ; j++)
                    cout << i << " "  << j<< "\n";
            }
            d^=1;
        }
        for (int i = n; i > 0 ; i--)
            cout << i << " " << 1 << "\n";

    }
    return 0;
}
    vector<pair<int,int>> out;
    for (int i = 0; i < m ;i++){
         out . emplace_back(1,i+1);
    }
    int d =0;
    for (int j = m ; j > 0 ; j --){
        if (!d){
            for (int i = 2; i <= n ; i++)
               out . emplace_back(i,j);
        }
        else{
              for (int i = n; i > 1 ; i--)
                out . emplace_back(i,j);

        }
        d^=1;
    }
    int  c = out.size();
    cout << 1 << "\n";
    cout << out[c-1].first << " " << out[c-1].second << " 1 1\n";
    for (auto cur : out) cout << cur.first << " " << cur.second << "\n";
    cout << 1 << " " << 1;
}
