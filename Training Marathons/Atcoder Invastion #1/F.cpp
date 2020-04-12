#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//
//template<class T> using Tree = tree<T, null_type, less<T>, rb_t_tag,t_order_statistics_node_update>;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;
//const long long mod = 998244353;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// watch this
//using ll = long long;
//typedef long long LL
#define ll long long
const int N = 115;
bool g[N][N], rv[N][N];
bool deg[N];
int id[N], cur;
 
void kill() {
	cout << -1 << endl;
	exit(0);
}
bool vis[N];
int n, m;
vector<pair<int, int> > res;
 
void dfs(int node, int par) {
	if (vis[node])
		return;
	vis[node] = 1;
	for (int i = 1; i <= n; i++) {
		if (!rv[node][i])
			continue;
		dfs(i, node);
	}
	if (deg[node]) {
		if (node == par)
			kill();
		deg[node] = 0;
		deg[par] ^= 1;
		res.push_back(make_pair(par, node));
	}
}
 
void comp(int node) {
	if (id[node])
		return;
	id[node] = cur;
	for (int i = 1; i <= n; i++) {
		if (g[node][i])
			comp(i);
	}
}
 
int main(int argc, char** argv) {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#endif
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		deg[u] ^= 1, deg[v] ^= 1;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	bool odd = 0;
	for (int i = 1; i <= n; i++)
		odd ^= deg[i];
	if (odd)
		kill();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			rv[i][j] = g[i][j] ^ 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		dfs(i, i);
	}
	for (auto e : res){ 
        cout << e.first << ' ' << e.second << endl;
		g[e.first][e.second] = g[e.second][e.first] = 1;
    }
	vector<int> roots;
	for (int i = 1; i <= n; i++) {
		if (id[i])
			continue;
		cur = i;
		roots.push_back(i);
		comp(i);
	}
	if (roots.size() > 1) {
//		cerr << "hi\n";
//		cerr << roots.size() << '\n';
		if (roots.size() > 2) {
			for (int i = 0; i < (int) roots.size(); i++) {
				res.push_back( { roots[i], roots[(i + 1) % roots.size()] });
			}
		} else {
			bool f = false;
			for (int i = 1; i <= n && !f; i++)
				for (int j = 1; j <= n && !f; j++)
					if (id[i] == id[j] && !g[i][j] && i != j)
						for (int k = 1; k <= n && !f; k++)
							if (id[i] != id[k]) {
								res.push_back( { i, k });
								res.push_back( { j, k });
								res.push_back( { i, j });
								f = true;
							}
			for (int i = 1; i <= n && !f; i++)
				for (int j = 1; j <= n && !f; j++)
					if (id[i] == id[j] && i != j)
						for (int k = 1; k <= n && !f; k++)
							if (id[i] != id[k])
								for (int z = 1; z <= n && !f; z++)
									if (id[k] == id[z] && k != z) {
										res.push_back( { i, k });
										res.push_back( { i, z });
										res.push_back( { j, k });
										res.push_back( { j, z });
										f = true;
									}
			for (int i = 1; i <= n && !f; i++)
				for (int j = 1; j <= n && !f; j++)
					if (id[i] == id[j] && i != j && rv[i][j])
						for (int k = 1; k <= n && !f; k++)
							if (id[k] != id[i]) {
								auto it = find(begin(res), end(res),
										make_pair(i, j));
								if (it == res.end())
									it = find(begin(res), end(res),
											make_pair(j, i));
								res.erase(it);
								res.push_back( { i, k });
								res.push_back( { j, k });
								f = true;
							}
			if (!f)
				kill();
		}
	}
	cout << res.size() << '\n';
	for (auto e : res) {
		if (e.second < e.first)
			swap(e.first, e.second);
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}