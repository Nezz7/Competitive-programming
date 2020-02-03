#include <bits/stdc++.h>
using namespace std;
int const MAXN = 3e5+9;
int a[MAXN];
int minPos[MAXN];
int maxPos[MAXN];
bool add (int x,int y){
    return maxPos[x]<minPos[y];
}
int main (){
    int q;
    cin>>q;
    while (q--){
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i],minPos[i]=n+9,maxPos[i]=0;
        for (int i=0;i<n;i++){
            minPos[a[i]]=min(minPos[a[i]],i);
            maxPos[a[i]]=max(maxPos[a[i]],i);
        }
        int start=1;
        for (int i=2;i<=n;i++){
            if (add(i-1,i))
        }


    }



}
