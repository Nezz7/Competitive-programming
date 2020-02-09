#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n ; i++){
        int x;
        cin >> x;
        while (x > 1){
            if (x % 2 == 0) x/=2;
            else if (x % 3 == 0) x/=3;
            else break;
        }
        st.insert(x);
    }
    if(st.size() == 1) cout << "Yes";
    else cout << "No";

}
