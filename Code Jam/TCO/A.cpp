
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
int const MAXN = 500 + 9;
char a[MAXN][MAXN];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,1,-1,-1,0,1};
bool valid(int x, int y){
    return x >= 0 && x < 500 && y >= 0 && y < 500;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < 500; i++){
        for(int j = 0; j < 500; j++){
            if(a[i][j] == 0){
                int cur = 0;
                int emp = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(!valid(x,y)) continue;
                    if(a[x][y] == 'X') cur++;
                    if(a[x][y] == 0) emp++;
                }
                if(cnt == 0){
                    a[i][j] = 'X';
                    continue;
                }
                if (cur > 3) {
                    a[i][j] = '.';
                    continue;
                }
                if(cur == 3 && emp == 0){
                    a[i][j] ='.';
                    cnt --;
                    continue;
                }  
                if(cur  < 3 && 3 - cur <= emp){
                    cnt--;
                    a[i][j] = '.'   ;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(valid(x,y) && a[x][y] == 0){
                            if(cur < 3){
                                cur++;
                                a[x][y] = 'X';
                            }else {
                                a[x][y] = '.';
                            }
                        }
                    }
                
                }
            }else if (a[i][j] == '.'){
                    int cur = 0;
                    int emp = 0;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(!valid(x,y)) continue;
                        if(a[x][y] == 'X') cur++;
                        if(a[x][y] == 0) emp++;
                    }
                    if (!cnt){
                        if( cur == 3 && emp == 0) cerr << "err";
                        if (cur == 3 && emp){
                            for(int k = 0; k < 8; k++){
                                int x = i + dx[k];
                                int y = j + dy[k];
                                if(!valid(x,y)) continue;
                                if(a[x][y] == 0) a[x][y] = 'X';
                            }
                        }
                        continue;
                    }
                    if(cur == 3){
                        cnt --;
                        for(int k = 0; k < 8; k++){
                                int x = i + dx[k];
                                int y = j + dy[k];
                                if(!valid(x,y)) continue;
                                if(a[x][y] == 0) a[x][y] = 'X';
                        }
                        continue;
                    }
                    if(cur  < 3 && 3 - cur <= emp){
                        for(int k = 0; k < 8; k++){
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(valid(x,y) && a[x][y] == 0){
                                if(cur < 3){
                                    cur++;
                                    a[x][y] = 'X';
                                }else {
                                    a[x][y] = '.';
                                }
                            }
                        }
                        cnt--;  
                }
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}