#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9 ;
int n,m;
LL cost = 0 , w = 0;
vector<pair<int,int>> ans;
vector<pair <pair<int,int>,int> > v;
priority_queue < pair <int,int > > pq;
int main (){
    ios_base :: sync_with_stdio(0);
    cin . tie (0) , cout . tie (0);
    cin >> n >> m ;
    int last = 1 ;
    int other = 1 ;
    ans.resize(m);

    for (int i = 0; i < m ;i++){
        LL u,b;
        cin >> u >> b;
        v . emplace_back(make_pair(u,-b),i);
    }

    for (int i = 1 ;i <= n ;i++){
        pq.push ({-(i+2),i});
    }

    sort(v.begin(), v.end());

    for (auto cur : v) {
        int  b = cur . first . second ;
        int  i = cur . second ;
        if ( b ) {
            ans [i] = {last,last + 1};
            last++;
        }else {
            int nextOther = abs (pq. top () . first) ;
            int other = abs (pq. top () . second) ;
            pq.pop();
            if ( nextOther > last  ){
                cout << -1 << "\n";
                return  0;
            }
            ans[i] = { other , nextOther};
            pq.push( {-(++nextOther),other} );
        }
    }

    for (auto cur : ans )
        cout << cur.first << " " << cur.second << "\n";
}
