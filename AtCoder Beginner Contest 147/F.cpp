#include<bits/stdc++.h>
using namespace std;
const int maxn = 200500;
set < int > L[22], R[22];
int a[maxn];
bool in[22][maxn], st[22][maxn], ed[22][maxn];
long long cnt(long long l, long long r){
    long long len = r - l + 1;
    return len * (len + 1) / 2LL;
}
int n, m;
int b[maxn], tmp[maxn];
long long brute(){
    long long ans = 0;
    for(int i = 0 ; i < n ; ++i)
        tmp[i] = a[i], ans += a[i];
    for(int i = 1 ; i < n ; ++i){
        for(int j = 0 ; j < n - i ; ++j)
            ans += b[j] = (a[j] & a[j + 1]);
        for(int j = 0 ; j < n - i ; ++j)
            a[j] = b[j];
    }
    for(int i = 0 ; i < n ; ++i)
        a[i] = tmp[i];
    return ans;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i];
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; (1 << j) <= a[i] ; ++j)
            if(a[i] & (1 << j))
                in[j][i] = true;
    long long ans = 0;
    for(int j = 0 ; j < 20 ; ++j)
        for(int i = 0 ; i < n ; ++i){
            if(!in[j][i]) continue;
            int k = i;
            while(k < n && in[j][k]) ++k;
            L[j].insert(-i);
            R[j].insert(k - 1);
            st[j][i] = true;
            ed[j][k - 1] = true;
            ans += (1ll << j) * 1LL * cnt(i, k - 1);
            i = k - 1;
        }
    //cout << ans << '\n';
    while(m--){
        int i, x;
        cin >> i >> x;
        i--;
        a[i] = x;
        for(int j = 0 ; j < 20 ; ++j)
            if((1 << j) & x){
                if(in[j][i]) continue;
                in[j][i] = true;
                if(i == 0){
                    if(i != n - 1){
                    if(st[j][i + 1]){
                    int l = i + 1;
                    int r = *R[j].upper_bound(i);
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    st[j][i + 1] = false;
                    L[j].erase(-i - 1);
                    st[j][i] = true;
                    L[j].insert(-i);
                    ans += (1ll << j) * 1LL * cnt(i, r);
                    continue;
                }
                    }

                st[j][i] = ed[j][i] = true;
                L[j].insert(-i);
                R[j].insert(i);
                ans += (1 << j);
                continue;
                }
                if(i == n - 1){
                    if(ed[j][i - 1]){
                    int l = *L[j].upper_bound(-i);
                    l *= -1;
                    int r = i - 1;
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    ed[j][i - 1] = false;
                    ed[j][i] = true;
                    R[j].erase(i - 1);
                    R[j].insert(i);
                    ans += (1ll << j) * 1LL * cnt(l, i);
                    continue;
                    }
                    st[j][i] = ed[j][i] = true;
                    L[j].insert(-i);
                    R[j].insert(i);
                    ans += (1 << j);
                continue;
                }
                if(ed[j][i - 1] && st[j][i + 1]){
                    int l = *L[j].upper_bound(-i);
                    l *= -1;
                    int r = *R[j].upper_bound(i);
                    ans -= (1ll << j) * 1LL * cnt(l, i - 1) + (1ll << j) * 1LL * cnt(i + 1, r);
                    R[j].erase(i - 1);
                    L[j].erase(- i - 1);
                    st[j][i + 1] = ed[j][i - 1] = false;
                    ans += (1ll << j) * 1LL * cnt(l, r);
                    continue;
                }
                if(st[j][i + 1]){
                    int l = i + 1;
                    int r = *R[j].upper_bound(i);
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    st[j][i + 1] = false;
                    L[j].erase(-i - 1);
                    st[j][i] = true;
                    L[j].insert(-i);
                    ans += (1ll << j) * 1LL * cnt(i, r);
                    continue;
                }
                if(ed[j][i - 1]){
                    int l = *L[j].upper_bound(-i);
                    l *= -1;
                    int r = i - 1;
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    ed[j][i - 1] = false;
                    ed[j][i] = true;
                    R[j].erase(i - 1);
                    R[j].insert(i);
                    ans += (1ll << j) * 1LL * cnt(l, i);
                    continue;
                }
                st[j][i] = ed[j][i] = true;
                L[j].insert(-i);
                R[j].insert(i);
                ans += (1 << j);
            }else{
                if(!in[j][i]) continue;
                in[j][i] = false;
                if(st[j][i] && ed[j][i]){
                    L[j].erase(-i);
                    R[j].erase(i);
                    st[j][i] = ed[j][i] = false;
                    ans -= (1 << j);
                    continue;
                }
                if(st[j][i]){
                    L[j].erase(-i);
                    int l = i;
                    int r = *R[j].upper_bound(i);
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    ans += (1ll << j) * 1LL * cnt(l + 1, r);
                    st[j][i] = false;
                    st[j][i + 1] = true;
                    L[j].insert(-i - 1);
                    continue;
                }
                if(ed[j][i]){
                    R[j].erase(i);
                    R[j].insert(i - 1);
                    int l = *L[j].upper_bound(-i);
                    l *= -1;
                    int r = i;
                    ans -= (1ll << j) * 1LL * cnt(l, r);
                    ans += (1ll << j) * 1LL * cnt(l, r - 1);
                    ed[j][i] = false;
                    ed[j][i - 1] = true;
                    continue;
                }
                int l = *L[j].upper_bound(-i);
                l *= -1;
                int r = *R[j].upper_bound(i);
                ans -= (1ll << j) * 1LL * cnt(l, r);
                ans += (1ll << j) * 1LL * cnt(l, i - 1);
                ans += (1ll << j) * 1LL * cnt(i + 1, r);
                ed[j][i - 1] = st[j][i + 1] = true;
                L[j].insert(-i - 1);
                R[j].insert(i - 1);
            }
        cout << ans  << '\n';
    }
    return 0;
}
