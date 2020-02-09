#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL ans;
int const MAXN = 1e5+9;
int a[MAXN];
LL n, m;
bitset<20> msk[MAXN];
set<pair<int,int>> st[20];
LL get_num (LL len){
    return len  * (len + 1) / 2;
}
void one_to_zero (int bit, int i){
    auto it = st[bit].upper_bound({i,1e9});
    it--;
    int l = it-> first, r = it->second;
    ans -= (1LL << bit) * get_num(r-l+1);
    st[bit].erase({l,r});
    if (l <= i - 1){
        st[bit].insert({l,i-1});
        ans += (1LL << bit) * get_num(i-l);
    }
    if (i + 1 <= r){
        st[bit].insert({i+1,r});
        ans += (1LL << bit) * get_num(r-i);
    }
}
void zero_to_one (int bit, int i){
    auto it = st[bit].lower_bound({i,1e9});
    auto itt = it;
    if (it != st[bit].begin())
    itt--;
    int l = itt->first;
    int r = itt->second;
    int l2 = it -> first;
    int r2 = it->second;
    if (it == st[bit].end()) l2 = r2 = 1e9;
    if (it == itt) l = r = -1e9;
    if (l2 == i +1 && r == i-1){
        // 11111011111
        st[bit].erase({l,r});
        st[bit].erase({l2,r2});
        ans -= (1LL << bit) * get_num(r-l+1);
        ans -= (1LL << bit) * get_num(r2-l2+1);
        st[bit].insert({l,r2});
        ans += (1LL << bit) * get_num(r2-l+1);
        return;

    }
    if (r < i - 1){
        //10000111
        if (l2 == i+1){
            st[bit].erase({l2,r2});
            ans -= (1LL << bit) * get_num(r2-l2+1);
            st[bit].insert({i,r2});
            ans += (1LL << bit) * get_num(r2-i+1);
        }else {
            st[bit].insert({i,i});
            ans += (1LL << bit) * get_num(1);
        }
        return ;
    }
    if (r == i -1){
        st[bit].erase({l,r});
        ans -= (1LL << bit) * get_num(r-l+1);
        st[bit].insert({l,i});
        ans += (1LL << bit) * get_num(i-l+1);
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        msk[i] = a[i];
    }
    for (int j = 0; j < 20; j++){
        int len = 0, start = 0;
        for (int i = 0; i < n; i++){
            if (msk[i][j] == 0 && len)
            st[j].insert({start,start+len-1});
            if (msk[i][j] == 1){
                if (len == 0) start = i;
                len ++;
            }
            if (msk[i][j] == 0) len = 0,start = 0;
        }
        if (len) st[j].insert({start,start+len-1});
    }
    for (int i = 0; i < 20; i++){
        for (auto cur : st[i]) ans += (1LL << i ) * get_num(cur.second-cur.first + 1);
    }
    while (m--){
        int id , val;
        cin >> id >> val;
        id -- ;
        bitset<20> cur = val;
        for (int i = 0; i < 20;i++){
             if (msk[id][i] == 0 && cur[i] == 1 ) zero_to_one(i,id);
             if (msk[id][i] == 1 && cur[i] == 0 ) one_to_zero(i,id);
        }
        msk[id] = cur;
        cout<< ans << "\n";
    }
}
