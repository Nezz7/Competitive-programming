#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 5000;
char a[MAXN][MAXN];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, -1};
int cur = 1, w, h;
/*
 * Skill Count:
 * A: 12
 * B: 60
 * C: 189
 * D: 400
 * E: 200
 * F: 144
 * 
 * Company Count:
 * A: 5
 * B: 100
 * C: 120
 * D: 350
 * E: 600
 * F: 150
 * */
map<string,int> id;
struct Developer {
    string c;
    LL b;
    int n, id;
    bitset<500> s;
};

struct Manager {
    string c;
    LL b;
    int id;
};



LL wp (Developer &a, Developer& b){
    LL  un = a.s.count() + b.s.count();
    bitset<500> c = a.s & b.s;
    LL inter = c.count();
    return inter  * (un - 2 * inter);
}


LL tp (Developer &a, Developer& b){
	return (a.c == b.c ? a.b * b.b : 0) + wp(a, b);
}
LL tp (Manager &a, Manager& b){
	return (a.c == b.c ? a.b * b.b : 0);
}

bool vis[MAXN][MAXN];
Developer devs[100123];
Manager managers[100123];
// number of dev 
int nd;
// number of Mangers
int nm;

void dfs(int x, int y) {
	if(x < 0 || x >= h) return;
	if(y < 0 || y >= w) return;
	if(a[x][y] == '#') return;
	if(vis[x][y]) return;
	vis[x][y] =  true;
	
	for(int i = 0; i < 4; ++ i) {
		int xx = x + dx[i], yy = y + dy[i];
		dfs(xx, yy);
	}
}

void solve_1() {
    int cc = 0;
    for (int i  = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
			if(a[i][j] == '#') continue;
			if(!vis[i][j]) dfs(i, j), cc++;
		}
	}
	cout << cc << '\n';
}
/*
 * rand ideas:
 * sort by company
 * sort by number of skills
 * sort by points
 * */

void solve_rand() {
	sort(devs, devs + nd, [&](Developer &a, Developer& b) {
		if(a.c == b.c) return a.s.count() > b.s.count();
		return a.c > b.c;
	});
	sort(managers, managers + nm, [&](Manager &a, Manager& b) {
		if(a.c == b.c) return a.b > b.b;
		return a.c > b.c;
	});
	for(int i = 0; i < nd - 1; ++ i) {
		if(nd >= 100 && i%(nd/100) == 0) cerr << (double)i * 100/ nd << '\n';
		int best_idx = i, best_score = -1;
		for(int j = i + 1; j < nd; ++ j) {
			int curr_score = tp(devs[i], devs[j]);
			if(curr_score > best_score) best_idx = j, best_score = curr_score;
		}
		swap(devs[i + 1], devs[best_idx]);
	}
	for(int i = 0; i < nm - 1; ++ i) {
		if(nm >= 100 && i%(nm/100) == 0) cerr << (double)i * 100/ nm << '\n';
		int best_idx = i, best_score = -1;
		for(int j = i + 1; j < nm; ++ j) {
			int curr_score = tp(managers[i], managers[j]);
			if(curr_score > best_score) best_idx = j, best_score = curr_score;
		}
		swap(managers[i + 1], managers[best_idx]);
	}
	// for(int i = 0; i < nd - 1; ++ i) cout << tp(devs[i], devs[i + 1]) << '\n';
	// cout << "HERE\n";
	vector<pair<int, int> > answer_devs(nd, {-1, -1});
	vector<pair<int, int> > answer_managers(nm, {-1, -1});
	int idx_devs = 0, idx_managers = 0;
	string current_company;
	function<void(int, int)> dfs = [&](int x, int y) {		
		if(x < 0 || x >= h) return;
		if(y < 0 || y >= w) return;
		if(a[x][y] == '#') return;
		if(vis[x][y]) return;
		vis[x][y] =  true;
		if(a[x][y] == '_' && idx_devs < nd) {
			answer_devs[devs[idx_devs].id] = {x, y};
			idx_devs++;
		}
		if(a[x][y] == 'M' && idx_managers < nm) {
			answer_managers[managers[idx_managers].id] = {x, y};
			idx_managers++;
		}
		for(int i = 0; i < 4; ++ i) {
			int xx = x + dx[i], yy = y + dy[i];
			dfs(xx, yy);
		}
	};
	
    for (int i  = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
			if(a[i][j] == '#') continue;
			if(!vis[i][j]) dfs(i, j);
		}
	}
	if(1) {
		for(int i = 0; i < nd; ++ i) {
			if(answer_devs[i].first == -1) cout << "X\n";
			else cout << answer_devs[i].second << " " << answer_devs[i].first << '\n';
		}
		for(int i = 0; i < nm; ++ i) {
			if(answer_managers[i].first == -1) cout << "X\n";
			else cout << answer_managers[i].second << " " << answer_managers[i].first << '\n';
		}
	}
}

int main(){
    // ios_base::sync_with_stdio (0),cin.tie(0);
    freopen("log.out", "w", stderr);
    cin >> w >> h;
    for (int i  = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    cin >> nd;
    for (int i = 0; i < nd; i++){
            cin >> devs[i].c >> devs[i].b >> devs[i].n;
            devs[i].id = i;
            for (int j = 0; j < devs[i].n; j++){
                string x;
                cin >> x;
                if (!id[x]){
                    id[x] = cur;
                    cur++;
                }
                devs[i].s[id[x]] = 1;
            }
    }
    cin >> nm;
    for (int i = 0; i < nm; i++){
		managers[i].id = i;
        cin >> managers[i].c >> managers[i].b;
    }
    solve_rand();
}
#include bits/stdc++.h
using namespace std;
int main(){

}
