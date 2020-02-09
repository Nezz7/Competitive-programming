#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5+9;
string s;
int n;
int nxt[MAXN];
int a[MAXN];
void add (string str,int p){
    int id = 0;
    for (int i = 0; i < p ; i++)
        id = nxt[id];
    int tmp = nxt[id];
    nxt[id] = n + 1;
    s += str;
    for (int i = n + 1; i < s.size();i++)
        nxt[i] = i + 1;
    inv[n] = s.size();
    n = s.size();
    nxt[n] = tmp;
}
void print (int l, int r){
    int sz =  r - l +1;
    int id = 0;
    for (int i = 0; i <= l ; i++)
        id = nxt[id];
    while (sz--){
      cout << s[id-1];
       id = nxt[id];
    }
    cout << "\n";
}
int main (){
    ios_base:: sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> s;
    n = s.size();
    inv[0] = n;
    for (int i = 0; i < n; i++)
        nxt[i] = i+1;
    nxt[n] = n;
    string t;
    while (cin >> t && t!="END"){
        string str;
        int p;
        if (t == "I"){
            cin >> str >> p;
            add (str,p);
        }else {
            int l,r;
            cin >> l >> r;
            print(l,r);
        }
    }
}
