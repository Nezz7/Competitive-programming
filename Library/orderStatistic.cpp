#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
using namespace __gnu_pbds;
int const MAXN = 2e6 + 9;


typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set  st;

int get_next(int x){
    int i = st.order_of_key(x);
    auto it = st.find_by_order(i);
    if (it == st.end()) return n+1;
    return *it;
}
int  get_prev (int x){
    int i = st.order_of_key(x);
    auto it = st.find_by_order(i-1);
    if (i - 1 < 0) return 0;
    return *it;
}