//to upsolve

#include <bits/stdc++.h>
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
int n;
int a[MAXN];
bool check (int x){
    map<int,int> mp;
    LL nbr = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < x) mp[-a[i]]++;   
        if(a[i] == x) nbr++;
        if(a[i] - x > 31) return true;
        if(a[i] > x) nbr += (1LL << (a[i] - x));
    }
    int maxi = 0;
    for(auto cur : mp) maxi = max(cur.second,maxi);
    return maxi <= nbr;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxi = max(maxi,a[i]);
    }
    int goal = 1;
    int lo = 1, hi = maxi;
    while(lo <= hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)){
            goal = mid;
            lo = mid + 1;
        }else hi = mid - 1;
    }
    cout << goal;
    
}