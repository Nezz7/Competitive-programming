#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string,LL> mp;
    for (int i = 0; i < n; i++){
        string s, c;
        LL  x;
        cin >> s >>  c >> x;
        if (s[0] == 'W' && mp[c]>= x){
              mp[c]-=x;
        }
        if (s[0] == 'D'){
            mp[c]+=x;
        }
    }
    string s;
    cin >> s;
    cout << mp[s];
}
