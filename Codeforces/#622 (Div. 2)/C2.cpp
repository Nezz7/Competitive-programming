#include <bits/stdc++.h>
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
int const MAXN = 2e6 + 9;
LL a[MAXN],L[MAXN],R[MAXN];
LL suff[MAXN], pref[MAXN];
int n;

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack <int> st;
    for (int i = 0; i < n; i++){
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            L[i] = st.top();
        else L[i] = -1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n-1; i >= 0; i--){
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            R[i] = st.top();
        else R[i] = -1;
        st.push(i);
    }

    for (int i = 0; i < n; i++){
        if (L[i] == -1) pref[i] = (i+1) * a[i];
        else pref[i] = pref[L[i]] + (i - L[i]) *  a[i];
    }
    for (int i = n - 1; i >= 0; i--){
        if (R[i]  == -1 ) suff[i] = (n-i) * a[i];
        else suff[i] = suff[R[i]] + (R[i] - i) * a[i];
    }
    int ans = 0;
    
    for (int i = 0; i < n; i++){
        if (pref[i] + suff[i]  -  a[i] > pref[ans] + suff[ans]    - a[ans])
                ans = i;
    }
    for (int i = ans - 1; i >= 0; i--)
        a[i] = min(a[i],a[i+1]);
    for (int i = ans + 1;  i < n ; i++)
        a[i] = min(a[i],a[i-1]);
    for (int i = 0; i <n; i++) cout << a[i] << " ";

    
}