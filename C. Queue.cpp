#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    vector<pair<int,string>> v(n);
    vector<int> a;
    int ans [n+1];
    for (int i = 0; i < n; i++){
        cin >> v[i].second >> v[i].first;
    }
    sort (v.begin(),v.end());
   for (int i = 0; i < n; i++){
        if (v[i].first > i){
            cout << -1 ;
            return 0;
        }
        a.insert(a.begin() + i - v[i].first, i);
   }
    for (int i = 0; i < n; i++)
        ans[a[i]] = i + 1;
    for (int i = 0; i < n; i++){
        cout <<  v[i].second << " " << ans[i] << "\n";
    }
}
