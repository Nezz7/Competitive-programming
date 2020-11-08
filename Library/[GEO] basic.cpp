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


 struct Point { 
    int x, y; 
};
  
bool onSegment(Point p, Point q, Point r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
    return false; 
}
 
int orientation(Point p, Point q, Point r) { 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
} 
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) { 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
    if (o1 != o2 && o3 != o4) return true; 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false;
}
 