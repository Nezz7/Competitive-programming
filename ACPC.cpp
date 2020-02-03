#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main(){
    while (true){
    int p ;
    cin >> p ;
    multiset<int> ans;
    for (int i = 1; i < p;i++){
        int last  = 1;
        set<int> st;
        while (true){
            last = (last * i)% p;
            if (st.count(last)) break;
            st.insert(last);
        }
       ans.insert(st.size());
    }
    int sum = 0;
    for (auto cur : ans){
        cout << cur <<  " ";
        sum +=cur;
    }
    cout << " = " << sum << endl;
    }
}
