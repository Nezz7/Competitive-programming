#include <bits/stdc++.h>
using namespace std;
int n, m;
int const MAXN = 200;
char a[MAXN][MAXN];
int mn[MAXN],mx[MAXN];
int ans = 0;
bool cond [MAXN];
int last = 0;
void go (int i , int j){
    if (i == last + 1) return;
    int to = j;
    if (!cond[i+1] && !cond [i]){
        ans++;
        go (i+1,to);
        return;
    }
    if (i % 2 == 0){
         if (cond[i] && j != mn[i]){
            ans+=abs(j-mn[i]);
            j = mn[i];
         }
        to = max(mx[i],mx[i+1]);
        ans+= abs(to-j);
        ans++;
        go(i+1,to);
    }else {
        if (cond [i] && j != mx[i]){
            ans+=abs(j-mx[i]);
            j = mx[i];
         }
        if (cond [i+1]){
            if (cond [i])
                to = min(mn[i],mn[i+1]);
            else to = mn[i+1];
            ans+= abs(j - to);
        }else {
            if (cond [i]){
                to = mn [i];
                 ans+= abs(j - to);
            }
        }
        ans++;
        go (i+1,to);
    }

}
int main (){
    memset(mn,-1,sizeof mn);
    memset(cond,false,sizeof cond);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (a[i][j] =='W'){
                    cond[i]= true;
                    last = i;
                    if (mn[i] == -1)
                        mn[i] = j;
                    mx[i]= j;
                }
        }
        //cout << mn[i] << "  " << mx[i] << endl;
    }
    cond[n] = true;
    mn[n] = mn[n-1];
    mx[n] = mx[n-1];
    go(0,0);
    cout << ans - 1;
}
