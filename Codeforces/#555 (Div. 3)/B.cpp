#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[10];
    for (int i = 1 ; i <= 9; i++)
        cin >> a[i];
    bool start = false;
    for (int i = 0; i < n ;i++){
        int cur = s[i]-'0';
        if (a[cur] == cur ) continue;
        if (a[cur] > cur){
            s[i]=a[cur]+'0';
            start = true;
        }else if (start )  break;
    }
    cout << s << "\n";
}
