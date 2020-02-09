#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int T;
    cin >> T;
    while (T -- ){
        map <char,int> occ;
        int a, b, c, n;
        string str;
        cin >> n;
        cin >> a >> b >> c;
        cin >> str;
        for (int i = 0 ;i < n ;i++){
            occ[str[i]]++;
        }
        int win = ((n+1)/2);
        int p = min(occ['R'],b);
        int r = min (occ['S'],a);
        int s = min (occ['P'],c);
        int mx_score =  p + r + s;
        if (mx_score >= win ){
            cout << "YES\n";
            int pp = 0, rr = 0,  ss = 0;
            for (int i = 0 ; i < n ;i++){
                if (str[i] == 'R' && pp < p){
                    cout << "P";
                    pp++;
                    continue ;
                }
                if (str[i] == 'S' && rr < r ){
                    cout << "R";
                    rr++;
                     continue ;

                }
                if (str[i] == 'P' && ss < s){
                    cout << "S";
                    ss++;
                    continue ;
                }
                 if (s < c){
                    cout << 'S';
                    c--;
                    continue;
                 }
                    if (r < a){
                    cout << 'R';
                    a--;
                    continue;
                 }
                    if (p < b){
                    cout << 'P';
                    b--;
                    continue;
                 }
            }
            cout<< "\n";
        }else cout<< "No \n";
    }
}
