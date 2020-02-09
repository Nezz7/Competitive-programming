#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
vector<char> out;
char a[200][200];
int m[100];
int k,r,c;
void go (int i ,int j,int id){
    if (j == -1) j = 0;
    else if (j == c) j = c-1;
    if (id == k){
        id --;
        if (i % 2 == 0)
        for (int u = j; u < c; u ++){
            a[i][u] = out[id];
        }
        else {
             for (int u = j; u >= 0; u --){
                a[i][u] = out[id];
            }
        }
        i++;
        for (int u = i; u < r ; u++ ){
            for (int v = 0; v < c; v ++){
                a[u][v] = out[id];
            }
        }
        return ;
    }
    if (i % 2 == 0){
        for (int u = j; u < c ; u++){
            if (a[i][u] == 'R'){
                m[id]--;
            }
            a[i][u] = out[id];
            if (m[id] == 0){
                if (u == c -1) i++;
                go(i, u + 1, id + 1);
                return;
            }
        }
        go (i+1,c,id);
    }else {
        for (int u = j; u >= 0; u--){
            if (a[i][u] == 'R'){
                m[id]--;
            }
            a[i][u] = out[id];
            if (m[id] == 0){
                if (u == 0 ) i++;
                go(i, u -1 , id + 1);
                return;
            }
        }
        go(i + 1, -1, id);
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 26 ;i++){
        out.push_back('a' + i);
    }
    for (int i = 0; i < 26 ;i++){
        out.push_back('A' + i);
    }
    for (int i = 0; i < 10 ;i++){
        out.push_back('0' + i);
    }
    int T;
    cin >> T;
    while (T--){
        cin >> r >> c >> k;
        int riz = 0;
        for (int i = 0; i < r ; i++) {
            for (int j = 0; j < c ; j++){
                cin >> a[i][j];
                if (a[i][j] == 'R') riz++;
            }
        }
        int get = riz/k;
        int l = riz % k;
        for (int i = 0; i < k ;i++)
            m[i] = get;
        for (int i = 0; i < l ;i++)
            m[i]++;

        go(0,0,0);
        for (int i = 0; i < r ; i++) {
            for (int j = 0; j < c ; j++)
                cout<< a[i][j];
           cout<<"\n";
      }
    }
}
