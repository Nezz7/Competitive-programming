#include <bits/stdc++.h>
 using  namespace std;
typedef long  long LL;
 const  int maxn = 1e4 + 5 ;

struct edge {
     int  from , to, len, id;
    edge ( int a = 0 , int b = 0 , int c = 0 , int d = 0 ) {
         from = a, to = b, len = c, id = d;
    }
    bool  operator <( const edge & e) const {
         return len < e.len;
    }
};

int indegree [maxn];
 bool visit [maxn];
edge store [maxn];
priority_queue <edge> pq;

void init () {
    memset (visit, false , sizeof (visit));
    memset (indegree, 0 , sizeof (indegree));
     while (pq.size ()) pq.pop ();
}

int main () {
     int T;
    scanf ( "%d" , & T);
     while (T-- ) {
         int n, k;
        LL sum = 0 ;
        init ();
        scanf ( "%d%d" , & n, & k);
         int  from , to, len;
         for ( int i = 0 ; i <n- 1 ; ++ i) {
            scanf ( "%d%d%d" , & from , & to, & len);
            store [i] = edge ( from , to, len, i);
            sum += len;
            indegree [ from ] += 1 ;
            indegree [to] += 1 ;
        }
        for ( int i = 0 ; i <n- 1 ; ++ i) {
            edge & e = store [i];
             if (indegree [e. from ] == 1 || indegree [e.to] == 1 ) {
                pq.push (e);
                visit [e.id] = true ;
            }
        }
        LL ans = 0 ;
         for ( int i = 0 ; i <k; ++ i) {
            edge e = pq.top ();
            pq.pop ();
            --indegree [e. from ];
             -- indegree [e.to];
            ans += e.len;
             for ( int j = 0 ; j <n- 1 ; ++ j) {
                 if (visit [j]) continue ;
                edge ee = store [j];
                 if (indegree [ee. from ] == 1 || indegree [ee.to] == 1 ) {
                    pq.push (ee);
                    visit [ee.id] = true ;
                }
            }
        }
        ans = sum- ans;
        ans *= 2 ;
        printf ( "%lld\n" , ans);
    }
    return 0;
}
