#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int const MANX = 1e6;
int main (){
    int a,b;
    cin>>a>>b;
   for (ll i=1;i<500;i++){
        ll x=a-i*b;
        if (x<=0 or x>1e10){
            cout<<-1;
            return 0;
        }
        if (__builtin_popcount(x)<=i){
            cout<<i<<endl;
            return 0;
        }
   }

}
