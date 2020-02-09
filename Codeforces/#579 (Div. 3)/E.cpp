#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e6;
int a [MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    set<int> st;
    for (int i = 0; i < MAXN; i++){
        for (int j = -1; j < 2; j++){
            if (a[i] && i + j > 0 && st.count(i+j) == 0){
                st.insert(i+j);
                a[i]--;
            }
        }
    }
    cout << st.size();



}
