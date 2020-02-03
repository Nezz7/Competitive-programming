 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int go (vector<int> v){
    int ret =0;
    for (int i = 0; i < sz(v); i++){
        int mn = v[i];
        int mx=v[i];
        for (int j = i; j < sz(v); j++){
             mx = max(mx,v[j]);
             mn = min(mn,v[j]);
             if (mx-mn == (j-i)) ret++;
        }
    }
    return ret;
 }
 int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    int ans = 0;
    for (int i= 1; i <=10;i++){
     n= i;
    vector<int> v;
    vector<int> r;
    for (int  i = 1; i <=n ;i++)
         v.pb(i);
    do{
        r.pb(go(v));

    }while (next_permutation(all(v)));
    sort(all(r));
   int s = 0;
    map<int,int>mp;
   for (auto cur : r) mp[cur] ++,s+=cur;
   cout << s <<",";
    }
 }
