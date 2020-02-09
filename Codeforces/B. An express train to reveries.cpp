#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1500;
int a[MAXN], b[MAXN], p[MAXN];
int n;
vector <int> d;
int occ[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n ;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++){
        if (a[i] == b[i]) p[i] = a[i], occ[a[i]] = 1;
        else d.push_back(i);
    }
    if (d.size() == 1){
            cout << "here";
        for (int i = 1; i <= n; i++)
            if (!occ[i])
                p[d[0]]=i;
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        return 0;
    }
    int idx = 0;
     for (int i = 1; i <= n; i++)
            if (!occ[i]){
                p[d[idx]]=i;
                idx++;
            }
    int da = 0, db = 0;
    for (int i = 0 ; i < n ;i++){
            da += (p[i]!= a[i]);
            db += (p[i]!= b[i]);
    }

    if (db > 1 or da > 1) swap(p[d[0]],p[d[1]]);
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        return 0;

}
