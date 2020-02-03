#include<bits/stdc++.h>
using namespace std;
int main (){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        int o = 0, c = 0, mn = 0, mark =0;

        for (int j  = i; j < n ;j++){
            if(s[j] == '(') o++;
            if(s[j] == ')') c++;
            if(s[j] == '?') mark++;
            int sum = o - c;
            if (mark > sum && mark > 0) sum++,o++,mark--;
            if(sum < 0) break;
            if ((j-i+1)%2 == 0 && mark>=sum) ans++;
            }

    }
    cout << ans;

}
