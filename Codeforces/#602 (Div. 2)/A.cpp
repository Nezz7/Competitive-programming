#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set  st;
int n,
int  get_prev (int x){
    int i = st.order_of_key(x);
    auto it = st.find_by_order(i-1);
    if (i - 1 < 0) return 0;
    return *it;
}

int main (){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int m;
        cin >> m;
        int L =1e9;
        int R =0;
        while (m--){
            int l,r;
                cin >> l >> r;
               L = min(L,r);
               R = max(R,l);
    }
       if (L > R ) R= L;
         cout << abs(R-L) << endl;
    }
}
