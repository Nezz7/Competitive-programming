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
struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};
int cnt[MAXN];
int minPos[MAXN],maxPos[MAXN],last[MAXN],a[MAXN];
int cur = 0;
void remove(int idx){
   if(cnt[a[idx]] == 1) cur--;
   cnt[a[idx]] --;
} 
void add(int idx){
   if(cnt[a[idx]] == 0) cur++;
   cnt[a[idx]]++;
}    
int get_answer(){
   return cur;
}  

int block_size = 700;
struct Query {
   int l, r, idx;
   Query(int _l, int _r , int _idx) : l(_l),r(_r),idx(_idx){}
   bool operator<(Query other) const{
      return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
   }
};

void mo_s_algorithm(vector<Query> &queries) {
   sort(queries.begin(), queries.end());
   int cur_l = 0;
   int cur_r = -1;
   for (Query q : queries) {
      while (cur_l > q.l) {
         cur_l--;
        add(cur_l);
      }
      while (cur_r < q.r) {
         cur_r++;
         add(cur_r);
      }
      while (cur_l < q.l) {
         remove(cur_l);
         cur_l++;
      }
      while (cur_r > q.r) {
         remove(cur_r);
         cur_r--;
      }
      maxPos[q.idx] = max(get_answer(),maxPos[q.idx]);
   }
}
int main(){
   ios_base::sync_with_stdio (0),cin.tie(0);
   int n,m;
   cin >> n >> m;
   for(int i = 1; i <= n; i++) minPos[i] = maxPos[i] = i,last[i] = -1;
   for(int i = 0; i < m; i++){
      cin >> a[i];
      minPos[a[i]] = 1;
   }
   BIT tree(n + 1);
   vector<Query> queries;
   for(int i = 0; i < m; i++){
      int x = a[i];
      if(last[x] == -1){
         maxPos[x] += tree.sum(x, n);
         tree.add(x,1);
         last[x] = i;
      }else {
       queries.emplace_back(Query(last[x],i,x));
       last[x] = i;
      }
   }
   for(int i = 1; i <= n; i++){
      if(last[i] == -1) maxPos[i] += tree.sum(i, n);
      else queries.emplace_back(Query(last[i],m - 1,i));
      
   }
   mo_s_algorithm(queries);
   for(int i = 1; i <= n; i++){
      cout << minPos[i] << ' ' << maxPos[i] << endl;
   }
}