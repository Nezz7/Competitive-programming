#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int q;
unordered_map<ll, ll> mp;
inline ll lca(ll v, ll u, ll w = 0){
	ll ans = 0;
	while(v != u){
		if(v < u)	swap(v, u);
		if(mp.find(v) != mp.end())	ans += mp[v];
		mp[v] += w;
		v/=2;
	}
	return ans;
}
int main(){
	cin >> q;
	while(q--){
		int type;
		ll v, u;
		cin >> type >> v >> u;
		if(type == 1){
			ll w;
			cin >> w;
			lca(v, u, w);
		}
		else
			cout << lca(v, u) << '\n';
	}
	return 0;
}
