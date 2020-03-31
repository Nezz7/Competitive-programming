/*
we will solve it using inclusion exclusion, find number of subsets with gcd != 1 then subtract it from N choose 4.
fix the gcd (g) from larger to smaller, find count of numbers divisible by g,
add count of subsets could be formed by these numbers,and subtract this count from all divisors of g
so that we will not count it again for them.
Complexity O(N.sqrt(N)),sqrt(N) for finding divisors.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e4+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=5e-6;

int n,fr[N];
ll C[N],sv[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    C[4]=1;
    for(int i=5;i<N;i++)C[i]=C[i-1]*1LL*i/(i-4);
    while(cin>>n&&!cin.eof()){
        int mx=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            fr[a]++;
            mx=max(mx,a);
        }
        ll cnt=0;
        for(int i=mx;i>1;i--){
            int h=0;
            for(int j=i;j<=mx;j+=i)h+=fr[j];
            sv[i]+=C[h];
            cnt+=sv[i];
            for(int j=2;j*j<=i;j++){
                if(i%j)continue;
                sv[j]-=sv[i];
                if(j*j!=i)sv[i/j]-=sv[i];
            }
        }
        for(int i=1;i<=mx;i++)fr[i]=sv[i]=0;
        cout<<C[n]-cnt<<'\n';
    }
    return 0;
}
