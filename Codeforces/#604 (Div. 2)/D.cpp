#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    deque<int> dq;
    /*if (a + b + c + d == 1){
        cout << "YES\n";
        if (a) cout << 0;
        else if (b) cout << 1;
        else if (c) cout << 2;
        else cout <<3;
        return 0;
    }*/
    while (b && a){
        dq.push_front(1);
        dq.push_front(0);
        a--;
        b--;
    }
    while (a){
         dq.push_back(0);
        a--;
    }
    while (c && d){
        dq.push_back(2);
        dq.push_back(3);
        d--;
        c--;
    }
    while (d){
        dq.push_front(3);
        d--;
    }
    if (a or d){
        cout << "NO";
        return 0;
    }
    if (abs(b-c) > 1){
         cout << "NO";
        return 0;
    }
    if (b > c){
        while (b && c){
            dq.push_front(1);
            dq.push_front(2);
            b--;
            c--;
        }
         dq.push_front(1);
    }else {
     while (b && c){
            dq.push_back(2);
            dq.push_back(1);
            b--;
            c--;
        }
        if (c) dq.push_back(2);
    }
    int cond = true;
    int i = 0;
    int last;
    for (auto cur : dq){
        if (i  == 0){
            last = cur;
        }else {
            if (abs(cur - last) != 1) cond = false;
        }
        i++;
        last = cur;
    }
    if (cond){
        cout << "YES\n";
        for (auto cur : dq){
            cout << cur << " ";
        }
    }else cout << "NO";

}
