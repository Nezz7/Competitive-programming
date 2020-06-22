#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6+9;
int nxt [MAXN+9];
int find_next (int x){
    if (x > MAXN ) return MAXN;
    if (nxt[x] == x) return x;
    return nxt[x]=find_next(nxt[x]);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin .tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s = "";
    for (int i = 0 ; i < MAXN+9;i++)
        s += "A",nxt[i]=i;
    int slen = 0;
    while (n--){
        string t;
        int k;
        cin>> t >> k;
        int len = t.size();
        for (int i = 0; i < k; i++){
            int x;
            cin >> x;
            x--;
            for (int j = nxt[x] ; j < x + len ;){
                    cout << j << endl;
                s[j] = t[j-x];
                nxt[j]=find_next(x+len);
                j = find_next(j+1);
            }

            slen = max(slen, x + len);
        }
    }
    for (int i = 0 ; i < slen ;i++)
        if(s[i] == 'A') cout << 'a';
        else cout << s[i];

}
