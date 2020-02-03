#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5+9;
int nxt[MAXN], a[MAXN], occ[MAXN];
int find_nxt (int x){
    if (nxt[x] == x) return x;
    return nxt[x] = find_nxt(nxt[x]);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> x, occ[x]++;
    for (int i = 0; i < n; i++){
        if (occ[i]) nxt[i] = i;
        else nxt[i] = (i+1)%n;
    }
    for (int i = 0 ; i < n ;i++){
        int x = (n - a[i]) % n;
        x = find_nxt(x);
        if (occ[x]){
            cout << (a[i] + x) % n << " ";
            occ[x]--;
            if (occ[x] == 0) nxt[x]=find_nxt((x+1)%n);
        }
    }
}
