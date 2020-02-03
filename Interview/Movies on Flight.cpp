#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,d;
    cin>>n>>d;
    int  a[n];
    for (int i=0;i<n;i++) cin>> a[i];
    int f1=0;
    int f2=0;
    sort(a,a+n);
    for (int i=0;i<n;i++){
            int L = 0,R = n-1;
            int cur_ans = -1;
            while(L<=R){
                int mid = (L+R)/2;
                if (a[mid] + a[i] < d-30 && i != mid){
                    cur_ans = mid;
                    L = mid+1;
                }else R = mid-1;
            }
            cout<<a[i]<<" "<<a[cur_ans]<<endl;
            if (cur_ans != -1 && a[i]+a[cur_ans]>=f1+f2){
                if (f1+f2 == a[cur_ans]+a[i] && max(f1,f2) < max(a[i],a[cur_ans])){
                    f1=a[i];
                    f2=a[cur_ans];
                }else {
                    if (a[i]+a[cur_ans]>f1+f2){
                          f1=a[i];
                          f2=a[cur_ans];
                    }

                }
            }

    }
    cout<<f1<<" "<<f2<<endl;
}
