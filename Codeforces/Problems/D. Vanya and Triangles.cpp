#include <bits/stdc++.h>
#define LL long
using namespace std;
 struct Point {
    LL x,y,id;
 };
 bool collinear (Point a, Point b, Point c){
     // area of triangle * 0.5
     // det matrix 3x3 (a,b,c) last line 1 1 1
    return (a.x * (b.y - c.y) - b.x * (a.y - c.y) + c.x * (a.y - b.y)) == 0;
 }
int main (){
    ios_base::sync_with_stdio(0);
    LL n;
    cin >> n;
    Point p[n];
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    LL ans = 0;
    for (int i = 0; i < n - 2; i++){
        for (int j= i+1; j < n - 1; j++)
            for (int k = j+1; k < n; k++)
                if (collinear(p[i],p[j],p[k]) == false) ans++;
    }
    cout << ans;
}
