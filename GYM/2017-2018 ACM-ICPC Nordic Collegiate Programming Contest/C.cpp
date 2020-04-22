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
set<int> ang[4][400];
int c[4][MAXN];
int id[MAXN];
int get_left (int i, int col){
    int x = c[col][i];
    if(sz(ang[col][x]) == 2){
        for(auto cur : ang[col][x]){
            if(cur != i) return cur;
        }
    }
    if(sz(ang[col][x]) >= 3){
        return -1;
    }
    for (int x = (c[col][i] - 1 + 360) % 360; x != c[col][i]; x = (x - 1 + 360) % 360){
        if(sz(ang[col][x])){
            return *(ang[col][x].begin());
        }
    }
    return -1;
}
int get_right (int i, int col){
    int x = c[col][i];
    if(sz(ang[col][x]) == 2){
        for(auto cur : ang[col][x]){
            if(cur != i) return cur;
        }
    }
    if(sz(ang[col][x]) >= 3){
        return -1;
    }
    for (int x = (c[col][i] + 1 + 360) % 360; x != c[col][i]; x = (x + 1 + 360) % 360){
        if(sz(ang[col][x])){
            return *(ang[col][x].begin());
        }
    }
    return -1;
}
int get (int i){
    int ret = 0;
    for (int j = 0; j < 3; j++){
        if(sz(ang[j][c[j][i]]) > 1) continue;
        int l = get_left(i,j);
        if (l == -1) continue;
        int r = get_right(i,j);
        int x = 0;
        if(c[j][l] >= c[j][r]) x += 360 - (c[j][l] - c[j][r]);
        else x += c[j][i] - c[j][l] + (c[j][r] - c[j][i]);
        ret += x;
    }
    return ret;
}
void del(int i){
    for(int j = 0; j < 3; j++)
        ang[j][c[j][i]].erase(i);
}
void add(int i){
      for(int j = 0; j < 3; j++)
        ang[j][c[j][i]].insert(i);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> c[0][i] >> c[1][i] >> c[2][i] >> id[i];
        ang[0][c[0][i]].insert(i);
        ang[1][c[1][i]].insert(i);
        ang[2][c[2][i]].insert(i);
    }
    set <pair<pair<int,int>,int>> st;
    for(int i = 0; i < n; i++){
        int x = get(i);
        st.insert({{x,-id[i]},i});
    }
    while (!st.empty()){
        auto u = *(st.begin());
        int i = u.second;
        cout << -u.first.second << endl;
        for (int j = 0; j < 3; j++){
            int l = get_left(i,j);
            int r = get_right(i,j);
            if ( l != -1){
                int cnt = get(l);
                st.erase({{cnt,-id[l]},l});
            }
            if ( r != -1){
                int cnt = get(r);
                st.erase({{cnt,-id[r]},r});
            }
            del(i);
            if ( l != -1){
                int cnt = get(l);
                st.insert({{cnt,-id[l]},l});
            }
            if ( r != -1){
                int cnt = get(r);
                st.insert({{cnt,-id[r]},r});
            }
            add(i);
        }
        del(i);
        st.erase(u);
    }

}