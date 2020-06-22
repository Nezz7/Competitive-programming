#include <bits/stdc++.h>
using namespace std;
int main (){
     string s;
     cin >> s;
     int cur = 0;
     int ans =0;
     int n = s.size();
     for (int i = n-1; i >=0; i--){
        int a = s[i] - '0';
        a ^=cur;
        cout << a;
        if (a == 1) cur^=1,ans++;
        ans++;
     }
     cout<<endl << ans;
}
