#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 9;
int p[MAXN];
int find_set(int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}
int w,g,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) p[i] = i;
    string s;
    cin >> s;
    for (int i =0; i < n ;i++){
        w += (s[i] == 'W');
        g += (s[i] == 'G');
        b += (s[i] == 'B');
    }
    while (m--){
        int l,r;
        cin >> l >> r;
        l--,r--;

        for (int i  = find_set(l); i <= r;){
            if (s[i] =='W'){
                w--;
                b++;
            }else if (s[i] == 'B'){
                b--;
                g++;
            }else {
                g--;
                w++;
            }
            p[i] = find_set(i+1);
            i = find_set (i+1);
            }
        cout << w << " " << g << " " << b << "\n";
    }
}
