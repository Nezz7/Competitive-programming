#include <bits/stdc++.h>
using namespace std;
int const MAXN = 5003;
int dp[MAXN][MAXN];
vector<int> a;
int n;
int solve (int i, int j){
    if (i == n) return 0;
    int & ret = dp[i][j];
    if (ret != -1) return ret;
    if (i != j){
        if (a[i] <=  a[j]) return -1e9;
    }
    return ret = max(solve(i+1,j),1 + solve(i+1,i));
}
int main (){
    int T;
    cin >> T;
        cin.ignore();
    cin.ignore();
    while (T--){
       a.clear();
       string s;
        while (getline(cin, s) && s != "")
        {
            stringstream ss(s);
            int missle;

            ss >> missle;
            a.push_back(missle);
        }
        n = a.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n;j++)
                dp[i][j] = -1;
        }
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = solve(0,0);
        cout << ans << "\n";

    }

}
