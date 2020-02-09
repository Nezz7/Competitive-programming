#include <bits/stdc++.h>
using namespace std;
map<int,int> L,R;
set<int> tree;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n , x;
    cin >> n >> x;
    tree.insert(x);
    for (int i = 1; i < n; i++){
        cin >> x;
        auto it = tree.upper_bound(x);
        if (it != tree.end() && L[*it]==0){
            cout << *it << " ";
            L[*it] = 1;
        }else {
            it--;
            R[*it] = 1;
            cout << *it << " ";
        }
        tree.insert(x);
    }
}
