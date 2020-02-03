#include <bits/stdc++.h>
using namespace std;
double xmax[20], ymax[20], xmin[20], ymin[20];

bool inside (int i, double x ,double y){
    return (xmin[i] < x && x < xmax[i]) &&  (ymin[i] < y && y < ymax[i]);
}
int main(){
    char c ;
    int i = 0;
    while (cin >> c && c!='*'){
        cin >> xmin[i] >> ymax[i] >> xmax[i] >> ymin[i];
        i++;
    }
    double x , y;
    int p = 0;
    while (cin >> x >> y && x != 9999.9 && y!=9999.9){
        p++;
        bool cond = false;
        for (int j = 0; j < i; j++){
            if (inside(j,x,y)){
                printf ("Point %d is contained in figure %d\n",p,j+1);
                cond = true;
            }
        }
        if (cond == false ){
            printf ("Point %d is not contained in any figure\n",p);
        }
    }
}
