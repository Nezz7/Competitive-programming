#include <bits/stdc++.h>
using namespace std;
int main (){
        int a [5];
        for (int i = 0 ; i < 5 ; i++)
                a[i] = i;
        map<int,int>occ;
        int n =0,mx = 0;
        for (int i = 0; i < 1005 ; i++)
             occ[i[a-1000]]++,cout<<i[a-1000];;
        for (auto cur : occ){
            if (mx > cur.second){
                n = cur.first;

                x = cur.second;
            }
        }
        cout << n << " " << mx;
}
