#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int const MANX = 1e6;
int main (){
    int T;
    cin>>T;

    while (T--){
        int n,k,d;
        cin>>n>>k>>d;
        int start=0;
        int a[n];
        for (int i=0;i<n;i++)
            cin>>a[i];
        set<int> st;
        map<int,int> mp;
        for (int i=0;i<d;i++)
            st.insert(a[i]),mp[a[i]]++;
        int mn=st.size();
        for (int i=d;i<n;i++){
                mp[a[start]]--;
                if (mp[a[start]]==0) st.erase(a[start]);
                start++;
                st.insert(a[i]);
                mp[a[i]]++;
                mn=min(mn,(int)st.size());
        }
        cout<<mn<<"\n";

    }

}
