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

int const block_size = 700;
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