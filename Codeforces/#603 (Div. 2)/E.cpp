#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6+9;
struct nd { int sum, mns,mxs; } Tree[4*MAXN];
void update(int nd, int i, int j, int idx, char c) {
	if(i==j) {
	    if (c == '(' or c == ')')
            Tree[nd].sum = Tree[nd].mns  = Tree[nd].mxs= (c == '(' ? 1 : -1);
        else Tree[nd].sum = Tree[nd].mns  = Tree[nd].mxs = 0;
		return;
	}
	int m = (i+j)/2;
	if(idx<=m) update(2*nd, i, m, idx,c);
	else update(2*nd+1, m+1, j, idx,c);
	Tree[nd].sum = Tree[2*nd].sum + Tree[2*nd+1].sum;
	Tree[nd].mns = min(Tree[2*nd].mns, Tree[2*nd].sum + Tree[2*nd+1].mns);
	Tree[nd].mxs = max(Tree[2*nd].mxs, Tree[2*nd].sum + Tree[2*nd+1].mxs);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
	int n;
	cin >> n;
	int ind = 0;
	for (int i = 0; i < n;i++){
        char c;
        cin >> c;
        if (c == 'R') ind ++;
        else if (c == 'L') ind = max(--ind,0);
        else update(1,0,n-1,ind,c);
        if (!Tree[1].sum && !Tree[1].mns) cout << Tree[1].mxs << " ";
        else cout << -1 << " ";
	}
}
