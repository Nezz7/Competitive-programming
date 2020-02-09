#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0 ;i < n ;i++)
        cin >> a[i];
    vector <pair <int,int> > ans;
    int d = *max_element(a,a+n) - *min_element(a,a+n);
    while (d!=0 && k){
        k--;
        int imin = min_element(a,a+n)- a;
        int imax = max_element(a,a+n)- a;

        a[imax]--;
        a[imin]++;
        ans.emplace_back(imax,imin);
        d = *max_element(a,a+n) - *min_element(a,a+n);
    }
    cout << d << " " << ans.size() << " \n";
    for (auto cur : ans)
        cout << cur.first + 1 << " " << cur . second +1 << "\n";

}
