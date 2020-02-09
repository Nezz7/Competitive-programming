#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < n; i++){
        int x = ans.size();
        if (x%2 == 0){
            int j = i +1;
            while (j < n && s[i] == s[j])
                j++;
            ans +=s[i];
            i = j - 1;
        }else ans+=s[i];
    }
    int m = ans.size();
    if (m&1) m--;
    cout << n - m << "\n";
    for (int i = 0; i < m; i++)
        cout << ans[i];


}
