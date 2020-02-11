#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int get_div (LL x){
   set<LL> st;
    for (LL i = 2; i*i <= x ;i++){
        if (x % i == 0){
            st.insert(i);
            st.insert(x/i);
        }
    }
    return st.size();
}
int main (){
    LL x;
    cin >> x;
    set<LL> st;
    for (LL i = 2; i*i <= x ;i++){
        if (x % i == 0){
            st.insert(i);
            st.insert(x/i);
        }
    }
    if (st.size() == 0){
        cout << "1\n0";
        return 0;
    }
    if (st.size() == 1){
        cout << "2";
        return 0;
    }
    if (st.size() == 2){
        LL a = *st.begin();
        auto it = st.begin();
        it ++ ;
        LL b = *(it);
        if (get_div(b) == 1) cout << "1\n"<<b;
        else cout << 2;
        return 0;
    }
    cout << 1 << "\n";
    LL a = *st.begin();
    auto it = st.begin();
    it ++ ;
    LL b = *(it);
    if (get_div (b) == 1) cout << b;
    else cout << a*b << endl;
}
