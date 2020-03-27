#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int q;
    cin >> q;
    while(q--){
            int n;
            cin>>n;
            int a[n];
            vector<int> ans;
            for (int i=1; i<=n; ++i){
                cin>>a[i];
            }
            ans.push_back(1);
            int pos=-1;
            int k=1;
            for (int i=2; i<=n; ++i){
                if (a[i]==a[i-1] && pos==-1){
                    pos=i;
                }
                if (a[i]==a[i-1]) ans.push_back(ans.back());
                else ans.push_back(3-ans.back());
                k=max(k,ans.back());
            }
            if (k==1){
                cout<<1<<endl;
                for (int i:ans) cout<<i<<" ";  cout<<endl;
                continue;
            }
            if (ans.front()==ans.back() && a[1]!=a[n]) k++,ans.back()=3;
            if (k==2){
                cout<<2<<endl;
                for (int i:ans) cout<<i<<" ";  cout<<endl;
                continue;
                }
            vector<int> ans2={1};
            int k2=1;
            for (int i=2; i<=n; ++i){
                if (pos==i){
                    ans2.push_back(3-ans2.back());
                }else{
                    if (a[i]==a[i-1]) ans2.push_back(ans2.back());
                    else ans2.push_back(3-ans2.back());
                }
                k2=max(k,ans2.back());
            }
            if (ans2.front()==ans2.back() && a[1]!=a[n]) k2++,ans2.back()=3;
            cout<<*max_element(all(ans2))<<endl;
            for (int i:ans2) cout<<i<<" ";  cout<<endl;
        }

}