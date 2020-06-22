#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e3 +9 ;
double const pi = acos(-1);
LL x[MAXN], y[MAXN], r[MAXN];
bool in (int i , int j){
    long long int dist =  x[i]-x[j];
    dist = dist*dist + (y[i]-y[j])*(y[i]-y[j]);
    return dist < (r[i] + r[j])*(r[i] + r[j]);
}
int main (){
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i] >> r[i];
        v.push_back({r[i],i});
    }
    sort(v.rbegin(),v.rend());
    vector<int> g1,g2;
    LL R = 0;
    for (int i =0; i <n ;i++){
        int id = v[i].second;
        int cur1 =1;
        for (int j = 0; j < g1.size(); j++){
            cur1+=in(g1[j],id);
        }
        int cur2 =1;
        for (int j = 0; j < g2.size(); j++){
            cur2+=in(g2[j],id);
        }
        if (cur1 % 2){
            g1.push_back(id);
            R+=r[id]*r[id];
        }else {
            if (cur2%2){
                R+=r[id]*r[id];
            } else {
                R-=r[id]*r[id];
            }
            g2.push_back(id);
        }
    }
    cout <<setprecision(10)<< pi*R;
}
