#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define oo 0x3f3f3f3f
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,cs=1;
    while(cin>>n && n)
    {
        vector<vector<ld>>FW(101,vector<ld>(101, 1e10));
        map<string,int>mp;
        map<int,string>rmp;
        int nxt = 1;
 
        for(int i=1; i<=n; i++)
        {
            int x,y,idx,idy;
            string a,b;
            cin>>x>>a>>b>>y>>b;
            if(!mp.count(a))mp[a]=nxt++,rmp[nxt-1]=a;
            if(!mp.count(b))mp[b]=nxt++,rmp[nxt-1]=b;
            idx=mp[a];
            idy=mp[b];
            FW[idx][idy] = (ld)1.0*y/x;
            FW[idy][idx] = (ld)1.0*x/y;
        }
 
        for(int i=1; i<nxt; i++)FW[i][i] = 1;
 
        for(int k=1; k<nxt; k++)
        for(int i=1; i<nxt; i++)
        for(int j=1; j<nxt; j++)
            FW[i][j] = min(FW[i][j], FW[i][k] * FW[k][j]);
 
        int need,idNeed;
        string a;
        cin>>need>>a;
        idNeed = mp[a];
 
        string res="";
        ll pay = -1;
        ld cost = 1e200;
 
        for(int j=1; j<nxt; j++)
            if(j != idNeed)
        {
            ld currencyUsed = FW[j][idNeed] * ceil(-1e-6 + FW[idNeed][j] * need);
 
            if(currencyUsed < cost && ceil(-1e-6 + FW[idNeed][j] * need) <= 100000)
            {
                cost = currencyUsed;
                pay = ceil(-1e-6 + FW[idNeed][j] * need);
                res = rmp[j];
            }
        }
 
        //assert(pay >= 0);
 
        cout<<"Case "<<cs++<<": "<<pay<<" "<<res<<"\n";
    }
}