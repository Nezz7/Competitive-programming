#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define long long long
const int N =  14  +3;
long d[N][N];
long L;
bool visited[1<<N];
 
bool possible;
vector<pair<long,pair<int,int>>> s1;
inline void getAns(vector<int>&vv, bool b){
    if(possible) return;
    long res1 = 0;
    int u1 = vv.front();
    int v1 = vv.back();
 
    for(int i=0; i+1<(int)vv.size(); ++i) res1+=d[vv[i]][vv[i+1]];
 
    if(!b) s1.push_back({res1,{u1,v1}});
    else{
        for(auto ele: s1){
            long res2 = ele.first;
            int u2 = ele.second.first;
            int v2 = ele.second.second;
            if(res1+res2 > L) break;
            if(res1+res2 + d[u1][u2] + d[v1][v2] == L) possible=true;
            if(res1+res2 + d[u1][v2] + d[v1][u2] == L) possible=true;
            if(possible) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout<<fixed<<setprecision(16);
    int n; cin>>n;
    cin>>L;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) cin>>d[i][j];
    possible = false;
    
    int nbTake = n/2;
    for(int msk=0; msk<(1<<n); ++msk) if(__builtin_popcount(msk)==nbTake){
        if(visited[msk]) continue;
        if(visited[((1<<n)-1)^msk]) continue;
        visited[msk] = true;
        visited[((1<<n)-1)^msk] = true;
 
        vector<int> v1, v2;
        for(int i=1; i<=n; ++i){
            if((1<<(i-1))&msk) v1.push_back(i);
            else v2.push_back(i);
        }
 
        s1.clear();
 
        do{ getAns(v1,0); }while(next_permutation(all(v1)));
        sort(all(s1));
        do{ getAns(v2,1); }while(next_permutation(all(v2)));
    }
 
    if(possible) cout<<"possible\n";
    else cout<<"impossible\n";
}