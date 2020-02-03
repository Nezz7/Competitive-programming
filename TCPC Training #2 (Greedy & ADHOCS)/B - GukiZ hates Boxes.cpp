#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5+99;
LL n, m;
LL a[MAXN];
bool check (LL time){
    LL need = 0;
    LL last = 0;
    LL res = 0;
    LL man = 0;
    for (int i  = 0; i < n; i++){
        if (a[i] == 0) continue;
        if (time <= i+1) return false;
        LL cur = time - i - 1;
        LL x = a[i];
        if (res && man){
            if (res > i - last){
                res -= (i-last);

            }
        }
        need += (x + cur - 1)/ cur;
    }
    //cout << need << endl;
    return need <= m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL low = 0, hight = 1e18;
    LL ans = 0;
    //*check(4);
    while (low < hight){
        LL mid = (low + hight)/2;
        if (check (mid)){
            //cout << "here";
            ans = mid;
            hight = mid - 1;
        }else low = mid + 1;
    }
    cout << ans << endl;
}
