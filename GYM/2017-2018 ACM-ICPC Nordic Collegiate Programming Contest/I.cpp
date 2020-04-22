#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#define dump(x ...) cerr  <<  "|| "  <<  # x  <<  "  =  ", _dump(x) 
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 2e9;
const int N = 500;
int n;
vector<int> adj[N +3], adj2[N +3];
int vis[N +3], dist[N +3];
map<int,string> str;
map<string,int> id;
int curLen = INF; vector<int> curCycle;
 
void updateCycle(int source, int tail){
	curLen = 0;
	curCycle.clear();
 
	curCycle.emplace_back(tail);
	++curLen;
	while(tail != source){
		int prv = -1;
		for(int u=1; u<=n; ++u) if(dist[u] == dist[tail]-1 && find(all(adj[u]), tail) != end(adj[u])){
			prv = u;
		}
		assert(prv != -1);
 
		tail = prv;
		curCycle.emplace_back(tail);
		++curLen;
	}
	++curLen;
 
	assert(curLen == size(curCycle)+1);
	reverse(all(curCycle));
}
 
void findCycle(int source){
	for(int u=1; u<=n; ++u){
		vis[u] = false;
		dist[u] = INF;
		adj2[u] = adj[u];
	}
 
	queue<pii> q;
	q.push({source, 0});
	vis[source] = true;
	dist[source] = 0;
	while(!empty(q)){
		int cur, d;
		tie(cur, d) = q.front();
		q.pop();
 
		for(int nxt: adj[cur]) if(!vis[nxt]){
			auto it = find(all(adj2[cur]), nxt);
			assert(it != end(adj2[cur]));
			adj2[cur].erase(it);
 
			q.push({nxt, d + 1});
			vis[nxt] = true;
			dist[nxt] = d + 1;
		}
	}
 
	for(int tail=1; tail<=n; ++tail) if(dist[tail] != INF){
		auto it = find(all(adj2[tail]), source);
		if(it == end(adj2[tail])) continue;
 
		int len = dist[tail] + 1;
		if(len < curLen) updateCycle(source, tail);
	}
 
}
 
int main(){ FAST
	cin >> n;
 
	for(int i=1; i<=n; ++i){
		string s; cin >> s;
		str[i] = s;
		id[s] = i;
	}
 
	for(int i=1; i<=n; ++i){
		string s; int nbLines; cin >> s >> nbLines;
		dump(nbLines);
		int u = id[s];
 
		for(int line=1; line<=nbLines; ++line){
			string nxt;
			cin >> nxt;
			// dump(nxt);
			assert(nxt == "import");
 
			while(true){
				cin >> nxt;
				// dump(nxt);
				if(nxt.back() == ','){
					nxt.pop_back();
					adj[u].emplace_back(id[nxt]);
				}
				else{
					adj[u].emplace_back(id[nxt]);
					// dump("break");
					break;
				}
			}
		}
	}
 
	for(int source=1; source<=n; ++source){
		findCycle(source);
	}
 
	if(curLen == INF) cout << "SHIP IT" << ln;
	else{
		assert(curLen == size(curCycle)+1);
		for(int x: curCycle) cout << str[x] << __;
		cout << ln;
	}
}