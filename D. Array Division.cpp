#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+8;
long long int a[MAXN];
long long int sum = 0;
set<long long int> idxL,idxR;
void YES (){
    cout<<"YES";
    exit(0);
}
void NO (){
    cout<<"NO";
    exit(0);
}
int main (){
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];

    }

    long long int sumL = 0 , sumR = 0;
    for (int i=0; i < n;i++){
         sumL += a[i];
         idxL.insert(a[i]);
         sumR = sum - sumL;
         if (sumR == sumL ) YES();
         long long int dif = sumL - sumR ;
         if (dif < 0 or dif % 2 ) continue;
         if (idxL.count(dif/2)) YES();
    }
    sumR = 0;
    for (int i=n-1 ; i >=0 ;i--){
         sumR += a[i];
         sumL = sum - sumR;
         idxR.insert(a[i]);
         if (sumR == sumL ) YES();
         long long int dif = sumR - sumL ;
         if (dif < 0 or dif % 2 ) continue;
         if (idxR.count(dif/2)) YES();
  }
  NO();
}
