#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie(0) , cout.tie(0);
    int n;
    cin >>n;
    while (n--){
        LL c , s;
        cin >> c >> s;
        vector<LL> v;
        for(int i = 0; i <c;i++)
            v.push_back(s/c);
        for (int i = 0; i <s%c;i++)
            v[i]++;
        LL ans =0;
        for (int i =0; i < v.size();i++)
            ans +=v[i]*v[i];
        cout << ans<< endl;
    }

}
