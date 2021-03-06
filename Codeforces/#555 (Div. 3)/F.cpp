#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 9;
int occ[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n ; i++)
        cin >> x , occ[x]++;
    int mx = 0;
    int ans_start = 0;
    int cur = 0;
    int cur_start = 0;
    for (int i = 1; i < MAXN;i++){
        if (occ[i] == 0){
            if (cur > mx){
                ans_start = cur_start;
                mx = cur;
            }
            cur = 0;
            continue;
        }
        if (occ[i] >= 2 ){
            if (cur == 0) cur_start = i;
            cur += occ[i];
        }else {
             if (cur && cur + occ[i] > mx){
                ans_start = cur_start;
                mx = cur + occ[i];
            }
            cur = occ[i];
            cur_start = i;
        }
        if (cur > mx){
                ans_start = cur_start;
                mx = cur;
            }
    }
    deque<int> dq;
    for (int i = ans_start; i < MAXN ;i++){
        if (occ[i] == 0 or dq.size() == mx) break;
        dq.push_front(i);
        occ[i]--;
        while (occ[i]){
            occ[i]--;
            dq.push_back(i);
        }
    }
    cout << mx << "\n";
    for (auto cur : dq ){
        cout << cur << " ";
    }
}
