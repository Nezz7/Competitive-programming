 struct Point {
    LL x,y,id;
 };
 bool collinear (Point a, Point b, Point c){
     // area of triangle * 0.5
     // det matrix 3x3 (a,b,c) last line 1 1 1
    return (a.x * (b.y - c.y) - b.x * (a.y - c.y) + c.x * (a.y - b.y)) == 0;
 }
 bool cmp (Point a, Point b){
     //max point in line a[n-1] min point a[0]
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
 }