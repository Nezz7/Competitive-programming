#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        LL x;
        cin >> x;
        set<int> st;
        st.insert(0);
        for (LL i = 1; i*i <= x; i++){
            st.insert(i);
            st.insert(x/i);
        }
        cout << st.size() << "\n";
        for(auto cur : st)
            cout << cur <<" ";
        cout << endl;
    }

}
