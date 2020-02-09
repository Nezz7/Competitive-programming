#include <bits/stdc++.h>
#define lon
using namespace std;
int main (){
    int n;
    cin>>n;
    int a[n];
    int p = 0 , ng = 0;
    for (int i=0;i<n;i++){
        cin>>a[i];
    if (a[i]%2 && a[i] > 0 ) ip++;
    if (a[i]%2 == 0 && a[i] > 0 ) pp++;
    if (a[i]%2 == 0 && a[i] < 0 ) pn++;
    if (a[i]%2 && a[i] < 0 ) in++;
    }
    int lost = ip;
    int win ;
    if (ip)
    win = in - ip*2;
    else win = in/2;
    for (int i = 0 ;i<n;i++){
        if (a[i]>0) a[i]=a[i]/2;
        else  if (win a[i]=ceill(a[i]/2.0)

    }

}
