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
int get_max(int lvl){
    if(21 <= lvl && lvl <= 25) return 2;
    if(16 <= lvl && lvl <= 20) return 3;
    if(11 <= lvl && lvl <= 15) return 4;
    if(1 <= lvl && lvl <= 10) return 5;
    return 0;
}
int get_bonus(int cur, int lvl){
    return  (cur >= 3 && 6 <= lvl && lvl <= 25);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int cur = 0;
    int points = 0;
    int lvl = 25;
    for(auto c : s){
        if(c == 'W'){
            cur++;
            if(points == get_max(lvl)){
                lvl --;
                points = 1 + get_bonus(cur,lvl);
            }else if (points  + 1 + get_bonus(cur,lvl) == get_max(lvl) + 1){
                lvl --;
                points = 1;
            }else points +=  1 + get_bonus(cur,lvl);
        }else {
            cur = 0;
            if ( .vpp.c1 <= lvl && lvl <= 20){
                points --;
                if(lvl == 20 && points == -1){
                    points = 0;
                }
                if(points == -1){
                    lvl ++;
                    points = get_max(lvl) - 1; 
                }
            }
        }
        if(lvl == 0) break;
    }
    if(!lvl){
        cout << "Legend";
    }else cout << lvl;
}