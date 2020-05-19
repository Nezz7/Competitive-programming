#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
LL get(LL s, LL e){
    return (s +  e) * (e - s + 1) /2;
}
LL odd (LL s, LL e){
    if(!(e & 1)) e--;
    return (e + s) * (e - s + 2) / 4;
}
LL even (LL s, LL e){
    if((e & 1)) e--;
    return (e + s) * (e - s + 2) / 4;
}
void solve(int t){
    LL l, r;
    cin >> l >> r;
    LL i = 0;
    while(abs(l - r) >= i + 1){
        LL low = i, hi = 2e9;
        LL to = i;
        while(low <= hi){
            LL mid = (low + hi + 1) / 2;
            if(get(i,mid) <= abs(l -r)){
                to = mid;
                low = mid + 1;
            }else hi = mid - 1;
        }
        if(l >= r){
            l -= get(1,to);
            i = to;
        }else {
            r -= get(1,to);
            i = to;
        }
    }
    LL last = i;
    if(l >= r){
        if(i & 1){
            LL low = i + 1, hi = 2e9;
            LL to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(even(i + 1,mid)<= l){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 1) to--;
            LL x = to;
            low = i + 2, hi = 2e9;
            to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(odd(i +2,mid) <= r){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 0) to--;
            LL y = to;
            if( i < max(x,y))
             if(x - y >= 1){
                l -= even(i + 1, y + 1);
                r -= odd(i + 2, y);
                i = y + 1;
            }else {
                l -= even(i + 1, y - 1);
                r -= odd(i + 2, y); 
                i = y;
            }
        }else {
            LL low = i + 1, hi = 2e9;
            LL to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(odd(i + 1,mid) <= l){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 0) to--;
            LL x = to;
            low = i + 2, hi = 2e9;
            to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(even(i + 2,mid) <= r){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 1) to--;
            LL y = to;
            if( i < max(x,y))
            if(x - y >= 1){
                l -= odd(i + 1, y + 1);
                r -= even(i + 2, y);
                i = y + 1;
            }else {
                l -= odd(i + 1, y - 1);
                r -= even(i + 2, y); 
                i = y;
            }
        }
    }else {
        if(i & 1){
            LL low = i + 1, hi = 2e9;
            LL to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(even(i + 1,mid)<= r){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 1) to--;
            LL x = to;
            low = i + 2, hi = 2e9;
            to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(odd(i +2,mid) <= l){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 0) to--;
            LL y = to;
            if( i < max(x,y))
            if(x - y >= 1){
                r -= even(i + 1, y + 1);
                l -= odd(i + 2, y);
                i = y + 1;
            }else {
                r -= even(i + 1, y - 1);
                l -= odd(i + 2, y); 
                i = y;
            }
        }else {
            LL low = i + 1, hi = 2e9;
            LL to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(odd(i + 1,mid) <= r){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 0) to--;
            LL x = to;
            low = i + 2, hi = 2e9;
            to = i;
            while(low <= hi){
                LL mid = (low + hi + 1) / 2;
                if(even(i + 2,mid) <= l){
                    to = mid;
                    low = mid + 1;
                }else hi = mid - 1;
            }
            if(to % 2 == 1) to--;
            LL y = to;
            if( i < max(x,y))
            if(x - y >= 1){
                r -= odd(i + 1, y + 1);
                l -= even(i + 2, y);
                i = y + 1;
            }else {
                r -= odd(i + 1, y - 1);
                l -= even(i + 2, y); 
                i = y ;
            }
        }
    }

    cout << "Case #"<< t <<": " << i << ' ' << l << ' ' << r << endl; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}