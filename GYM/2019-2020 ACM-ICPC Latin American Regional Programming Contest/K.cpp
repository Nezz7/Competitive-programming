#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <assert.h>
using namespace std;
template<typename...T>void read(T&...x){((cin>>x),...);}template<typename...T>void write(T...x){((cout<<x),...);}
void __print(long long x){cerr<<x;}void __print(int x){cerr<<x;}
void __print(char x){cerr<<'\''<<x<<'\'';}void __print(const string &x){cerr<<'"'<<x<<'"';}
void __print(bool x){cerr<<(x?"true":"false");}void _print(){cerr<<"\n";}
template<typename T,typename U>void __print(const pair<T,U>&x){cerr<<'{';__print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>void __print(const T&x){int f=0;cerr<<'{';for(auto&i:x)cerr<<(f++?",":""),__print(i);cerr<<"}";}
template<typename T,typename...U>void _print(T t,U...u){__print(t);if(sizeof...(u))cerr<<", ";_print(u...);}
#define dbg(x ...) cerr << "!?  " << # x << " = "; _print(x) 
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LL long long
#define all(x) x.begin(),x.end()
#define loop(i,start,end) for(int i=start;i<=end;++i)
#define rloop(i,start,end) for(int i=start;i>=end;--i)
//#define int long long
//***********************************************************************************************************
const int N=  +3;
 
int32_t main(){ FAST 
	string s; read(s);
	
	vector<int> ans={1};
	loop(i,1,size(s)-1) if(s[i]!=s[i-1]){
		vector<int> tans1=ans;
		tans1.insert(begin(tans1),0);
 
		vector<int> tans2=ans;
		tans2.push_back(0);
		for(int &x: tans2) x*=-(2*i+1);
 
		for(int j=0; j<size(tans1); ++j) tans1[j]+=tans2[j];
 
		ans = tans1;
	}
 
	write(size(ans)-1, "\n");
	reverse(all(ans));
	for(int x: ans) write(x," ");
	write("\n");
}