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
 int const MAXN = 3e5 + 9;
 int g[MAXN][10];
 int const M = 1 << 8;
 int masks[M];
 int idx1,idx2;
 int n, m;
 bool check (int x){
    memset(masks,-1,sizeof(masks));
    for(int i = 0; i < n; i++){
        int msk = 0;
        for(int j = 0; j < m; j++){
            if(g[i][j] >= x) msk |= (1 << j);
        }
        masks[msk] = i;
     }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(masks[i] != -1 &&  masks[j] != -1){
                int ad = i | j ;
                if(ad == ((1 << m) - 1)){
                    idx1 = masks[i];
                    idx2 = masks[j];
                    return true;
                }
            }
        }
    }
    return false;
}
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
             cin >> g[i][j];
        }
    }
    int low = 0, hi = 1e9;
    int ans = 0;
    while(low <= hi){
        int mid = (low + hi + 1)/2;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }else hi = mid - 1;
    }
    check(ans);
    idx1++,idx2++;
    cout << idx1 << " " << idx2 << endl;
 }
