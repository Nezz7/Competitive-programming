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
vector<pair<int,string>> out;
void print(){
    cout << "YES" << endl;
    int cnt = 0;
    for(auto cur : out){
        if(cur.first) cnt++;
    }
    cout << cnt << endl;
    for(auto cur : out){
        if(cur.first)
        cout << cur.first << ' ' <<  cur.second << endl;
    }
    exit(0);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    if(k > 4 * n * m - 2 * n - 2 * m){
        cout << "NO" << endl;
        return 0;
    }
    if(k > m - 1){
        k-= m-1;
        out.emplace_back(m - 1,"R");
    }else{
        out.emplace_back(k,"R");
        print();
    }
    if(k > m - 1){
        k-= m-1;
        out.emplace_back(m - 1,"L");
    }else{
        out.emplace_back(k,"L");
        print();
    }
    for(int i = 0; i < n - 1; i++){
        k--;
        out.emplace_back(1,"D");
        if(!k) print();
        if(k > (m-1) * 3){
            k-= (m-1)*3;
            out.emplace_back((m-1),"RUD");
        }else{
            if(k%3 == 0){
                if(k/3)
                out.emplace_back(k/3 ,"RUD");
            }else{
                if(k/3)
                out.emplace_back(k/3 ,"RUD");
                if(k % 3 == 1){
                    out.emplace_back(1,"R");
                }else {
                     out.emplace_back(1,"RU");
                }
            }
            print();
        }
        if(k > m - 1){
            k-= m-1;
            out.emplace_back(m - 1,"L");
        }else{
            out.emplace_back(k,"L");
            print();
        }
    }
      if(k > n - 1){
        assert(1 == 3);
        k-= n-1;
        out.emplace_back(m - 1,"R");
    }else{
        out.emplace_back(k,"U");
        print();
    }
    assert(1 == 2);
}