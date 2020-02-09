#include <bits/stdc++.h>
using namespace std;
string s;
int n, k;
int solve (char c ){
    int ret = 0;
    int cur = 0;
    int start = 0;
    for (int i = 0; i < n ;i++){
            cur+=(s[i]!=c);
            while(cur > k)
                cur-=(s[start]!=c),start++;
            ret = max(ret,i-start+1);
    }
    return ret;
}
int main (){
    cin >> n >> k;
    cin >> s;
    cout << max (solve('a'),solve('b'));
}
