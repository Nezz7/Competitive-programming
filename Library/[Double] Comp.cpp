inline bool EQ(const LD &a, const LD &b){return fabs(a-b) < EPS;}
inline bool LT(const LD &a, const LD &b){return fabs(a-b) > EPS && a < b;}
inline bool GT(const LD &a, const LD &b){return fabs(a-b) > EPS && a > b;}
#define LTE(a,b) (!GT(a,b))
#define GTE(a,b) (!LT(a,b))