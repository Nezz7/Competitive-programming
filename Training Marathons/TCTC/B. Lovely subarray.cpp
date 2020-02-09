#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n ;
    set<int> st;
    int a[n];
    for (int i = 0; i < n;i ++)
        cin >> a[i],st.insert(a[i]);
    int sz = st.size();
    int len = 0;
    int start = 0;
    int ans  = n;
    map<int,int> mp;
    for (int i = 0; i < n;i++){
        if (mp[a[i]] == 0) len ++;
        mp[a[i]]++;
        while (mp[a[start]]> 1 && start <= i) mp[a[start]]--,start++;
        if (len == sz){
          ans = min (ans,i - start +1);
        }
    }
    cout << ans;
}
