/**
 *    author:  NEZZ
**/
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rep2(i,a,b) for (int i=a;i>=b;i--)
#define mod 1000000007
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vl vector <ll>
#define vll vector < pll >
#define vii vector < pii >
#define pb push_back
#define mk make_pair
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define input freopen("intput","r",stdin)
#define output freopen("output","w",stdout)
#define fastIO ios_base::sync_with_stdio (0),cin.tie(0)
#define debug input,output


using namespace std;
void affiche (int t[],int n){ rep (i,0,n) cout<<t[i]<<" ";cout<<endl;}
void afficheV (vi t){rep (i,0,sz(t))cout<<t[i]<<" ";cout<<endl;}

int main (){
 fastIO;
 int a,b;
 cin >> a >> b;
 int ans = 0;
 for (LL i = a; i <= b; i++){
     int cnt = 0;
     for (LL j = 1; j*j <= i; j++){
         if (i % j == 0){
             cnt++;
             if (i/j != j) cnt++;
         }
     }
     if (cnt & 1) ans++;
 }
 cout <<    ans;

}
