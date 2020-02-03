#include <bits/stdc++.h>
using namespace std;
set<int> card[2];
int const MAXN = 1e5+9;
char a[MAXN];
int main (){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]-='0';
        card[a[i]].insert(i);
    }

    bool win = false;
    bool lose = false;
    bool equality = false;
    if (n == k) win = true;
    for (int i = 0; i < k; i++){
        card[a[i]].erase(i);
    }
    int start = 0;
    for (int i = k; i <= n; i++){
        // win 0;
        if (card[1].size() == 0) win = true;
        else {
            auto it = card[1].end();
            it -- ;
            int mx = *it;
            int mn = *(card[1].begin());
            int len = mx - mn + 1;
            if(len <= k) lose = true;
            else equality = true;
        }
        // win 1
        if (card[0].size() == 0) win = true;
        else {
            auto it = card[0].end();
            it -- ;
            int mx = *it;
            int mn = *(card[0].begin());
            int len = mx - mn + 1;
            if(len <= k) lose = true;
            else equality = true;
        }
        if (i< n){
            card[a[start]].insert(start);
            start ++;
            card[a[i]].erase (i);
        }
    }
    if (win ) cout << "tokitsukaze";
    else if (equality) cout << "once again";
    else if (lose) cout << "quailty";
}
