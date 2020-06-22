#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    map<int,int> mp;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a + n);
    for (int i = 0; i < n-1; i++)
        mp[a[i+1]-a[i]]++;
    if (n == 1){
        cout << -1;
        return 0;
    }
    set<int> ans;
    if (n == 2){
        if ((a[1]-a[0])%2==0)  ans.insert(a[0] + (a[1]-a[0])/2);
        ans.insert(a[0]-(a[1]-a[0]));
        ans.insert(a[1]+(a[1]-a[0]));
        cout << ans.size() << "\n";
        for (auto cur : ans)
            cout << cur << " ";
        cout << endl;
        return 0;
    }
    if (mp.size()> 2){
        cout << 0;
        return 0;
    }
    if (mp.size() == 1){
        int d = (mp.begin())->first;
        ans.insert(a[0]- d);
        ans.insert(a[n-1]+ d);
                cout << ans.size() << "\n";
        for (auto cur : ans)
            cout << cur << " ";
        cout << endl;
        return 0;
    }
    bool cond = false;
    int d,x;

    auto it = mp.begin();
    x = it->first;

    it++;
    d = it->first;
    if (it -> second == 1) cond = true;
    if (!cond or d != x * 2){
        cout << 0;
    }else {
        cout << 1 << endl;
        for (int i = 0; i < n-1;i++){
            if (a[i+1] - a[i] == d){
                cout << a[i] + x ;
                return  0;
            }
        }
    }
}
