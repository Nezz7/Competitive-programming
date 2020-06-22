#include <bits/stdc++.h>
using namespace std;
int main (){
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    int a[n];
    unordered_set<int> st;
    for (int i = 0; i < n ; i++)
        cin >> a[i],st.insert(a[i]);
    bool x_placed = false;
    bool y_placed = false;
    for (int i = 0 ; i < n ;i++){
        if (!x_placed && st.count(a[i]+x)){
            x_placed  = true;
        }
        if (!y_placed && st.count(a[i]+y)){
            y_placed  = true;
        }
    }
    if (x_placed && y_placed){
        cout << "0\n";
        return 0;
    }
    if (!x_placed && !y_placed){
        int d = y - x;
        for (int i = 0; i < n ;i++){
            if (a[i] >= x && st.count(a[i]+d)){
                cout<<"1\n";
                cout<< a[i] - x;
                return 0;
            }
            if (a[i] + y <= l && st.count(a[i]+d)){
                cout<<"1\n";
                cout<< a[i] + y;
                return 0;
            }
        }

        for (int i = 0; i < n ;i++){
            if (st.count(a[i]+y+x) or st.count(a[i]+y) ){
                cout<<"1\n";
                cout<< a[i]  + x;
                return 0;
            }
        }
    }
    vector <int> ans;
    if (!x_placed){
        if (a[0]+ x <=l) ans.push_back(a[0]+x);
        else ans.push_back(0),ans.push_back(x);
    }
    if (!y_placed){
        if (a[0]+ y <=l) ans.push_back(a[0]+y);
        else if (ans.size() && ans[0]+ y <=l ) ans.push_back(ans[0]+ y);
        else ans.push_back(0),ans.push_back(y);
    }
    cout << ans.size() << "\n";
    for (auto cur : ans ) cout << cur << " ";
}
