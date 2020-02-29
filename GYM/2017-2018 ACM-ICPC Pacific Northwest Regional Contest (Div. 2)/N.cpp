#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
string s;
bool is_pal(int ss, int e){
    int i = ss;
    int j = e;
    while (i < j){
        if (s[i] == s[j]){
            i++;
            j--;
        }else return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> s;
    bool cond = true;
    int n = s.size();
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (is_pal (i,j) && (j - i + 1)%2 == 0 ) cond = false;
        }
    }
    if (cond ) cout << "Odd.";
    else cout << "Or not.";

}