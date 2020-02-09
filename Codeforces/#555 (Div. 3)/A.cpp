#include <bits/stdc++.h>
using namespace std;
int f (int x){
    x ++;
    if (x % 10 == 0){
        while(x % 10 == 0) x/=10;
        return x;
    }
    return x;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int nxt = f(n);
    set<int> st;
    st.insert(n);
    st.insert(nxt);
    while (true){
        n = nxt;
        nxt = f(n);
        if (st.count(nxt)) break;
        st.insert(nxt);
    }
    cout << st.size();
}
