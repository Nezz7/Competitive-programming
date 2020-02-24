using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LL long long
#define LD long double
#define all(x) x.begin(),x.end()
#define loop(i,start,end) for(int i=start;i<=end;++i)
#define rloop(i,start,end) for(int i=start;i>=end;--i)
//#define int long long                         //***************************************
const int INF = 2e9;
const LL INFLL = 4e18L;
const int MOD = 0;
const int N= 50 +3;
//
struct BIGINT {
	#define base 1'000'000'000
	#define base_digits 9
    vector<int> a;
    int sign;
    int nb_digits(){
        if(a.empty()) return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca) ans++,ca/=10;
        return ans;
    }
    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }

    BIGINT() : sign(1) {}
    BIGINT(long long v) {*this = v;}
    BIGINT(const string &s) {read(s);}
    
	bool is_zero() const {return a.empty() || (a.size() == 1 && !a[0]);}
 
    BIGINT operator-() const {
        BIGINT res = *this;
        res.sign = -sign;
        return res;
    }
    BIGINT abs() const {
        BIGINT res = *this;
        res.sign *= res.sign;
        return res;
    }

	//  OPERATIONS WITH BIGINTs
	void operator=(const BIGINT &v) {
        sign = v.sign;
        a = v.a;
    }
    BIGINT operator+(const BIGINT &v) const {
        if(sign != v.sign) return *this - (-v);
        BIGINT res = v;
        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
            if (i == (int) res.a.size()) res.a.push_back(0);
            res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
            carry = res.a[i] >= base;
            if (carry) res.a[i] -= base;
        }
        return res;
    }
    BIGINT operator-(const BIGINT &v) const {
		if(sign != v.sign) return *this + (-v);
        if (abs() >= v.abs()) {
            BIGINT res = *this;
            for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                carry = res.a[i] < 0;
                if (carry) res.a[i] += base;
            }
            res.trim();
            return res;
        }
        return -(v - *this);
    }
	typedef vector<long long> vll;
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vll p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++) p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back()) res.pop_back();
        return res;
    }
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) res[i + j] += a[i] * b[j];
            return res;
        }
 
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
 
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
 
        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];
 
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];
 
        for (int i = 0; i < (int) r.size(); i++) res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++) res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }
    BIGINT operator*(const BIGINT &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
       
        vll aa(a6.begin(), a6.end());
        vll bb(b6.begin(), b6.end());
       
        while (aa.size() < bb.size()) aa.push_back(0);
        while (bb.size() < aa.size()) bb.push_back(0);
        while (aa.size() & (aa.size() - 1)) aa.push_back(0), bb.push_back(0);
           
        vll c = karatsubaMultiply(aa, bb);
        BIGINT res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
	friend pair<BIGINT, BIGINT> divmod(const BIGINT &a1, const BIGINT &b1) {
        int norm = base / (b1.a.back() + 1);
        BIGINT a = a1.abs() * norm;
        BIGINT b = b1.abs() * norm;
        BIGINT q, r;
        q.a.resize(a.a.size());
 
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
 
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    BIGINT operator/(const BIGINT &v) const {return divmod(*this, v).first;}
    BIGINT operator%(const BIGINT &v) const {return divmod(*this, v).second;}
	void operator+=(const BIGINT &v) {*this = *this + v;}
    void operator-=(const BIGINT &v) {*this = *this - v;}
    void operator*=(const BIGINT &v) {*this = *this * v;}
    void operator/=(const BIGINT &v) {*this = *this / v;}
    void operator%=(const BIGINT &v) {*this = *this % v;}
    
	//  OPERATIONS WITH INTEGERS
	BIGINT operator+(const long long &v) const {return *this + BIGINT(v);}
	void operator+=(const long long &v) {*this = *this + v;}
	BIGINT operator-(const long long &v) const {return *this - BIGINT(v);}
    void operator-=(const long long &v) {*this = *this - v;}
	void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0) sign = -1, v = -v;
        for (; v > 0; v = v / base) a.push_back(v % base);
    }
	void operator*=(long long v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size()) a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        trim();
    }
    BIGINT operator*(long long v) const {
        BIGINT res = *this;
        res *= v;
        return res;
    }
	void operator/=(long long v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
    BIGINT operator/(long long v) const {
        BIGINT res = *this;
        res /= v;
        return res;
    }
	void operator%=(long long v) {*this = *this % v;}
    long long operator%(long long v) const {
        if (v < 0) v = -v;
        long long m = 0;
        for (int i = a.size() - 1; i >= 0; --i) m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }
 
    bool operator<(const BIGINT &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const BIGINT &v) const {return v < *this;}
    bool operator<=(const BIGINT &v) const {return !(v < *this);}
    bool operator>=(const BIGINT &v) const {return !(*this < v);}
    bool operator==(const BIGINT &v) const {return !(*this < v) && !(v < *this);}
    bool operator!=(const BIGINT &v) const {return *this < v || v < *this;}

    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }
 
    long long LL_value() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--) res = res * base + a[i];
        return res * sign;
    }
 
    friend BIGINT gcd(const BIGINT &a, const BIGINT &b) {return b.is_zero() ? a : gcd(b, a % b);}
    friend BIGINT lcm(const BIGINT &a, const BIGINT &b) {return a / gcd(a, b) * b;}
 
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++) x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

	friend istream& operator>>(istream &stream, BIGINT &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const BIGINT &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i) stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
};

BIGINT _fact[N];
BIGINT fact(int x){return _fact[x];}
BIGINT _cnk[N][N];
BIGINT cnk(int n, int k){return _cnk[n][k];}

BIGINT _f[N][N][N];
BIGINT f(int n, int m, int x){
	BIGINT& ans = _f[n][m][x];
	if(ans != -1) return ans;

	if(m > 0) ans = f(n-m,0,x-m) * cnk(x,m);
	else if(x == 0) ans = fact(n);
	else{
		ans = f(n-1,0,x-1) * (n-x);
		if(x >= 2) ans += f(n-1,0,x-2) * (x-1);
	}
	return ans;
}

int32_t main(){ FAST 
	_fact[0]=1;
	for(int i=1; i<=N-1; ++i) _fact[i] = _fact[i-1] * i;

	_cnk[0][0]=1;
	for(int i=1; i<=N-1; ++i){
		_cnk[i][0]=1;
		for(int j=1; j<=i; ++j) _cnk[i][j] = _cnk[i-1][j-1] + _cnk[i-1][j];
	}

	int n,m; BIGINT k; cin>>n>>m>>k;
	
	loop(i,0,N-1) loop(ii,0,N-1) loop(iii,0,N-1) _f[i][ii][iii] = -1;
	if(k > f(n,m,n)){cout<<"-1\n"; return 0;}

	set<int> s; loop(i,1,n) s.insert(i);
	set<int> can_fix; loop(i,1,n) can_fix.insert(i);

	int cur_n = n;
	int cur_m = m;
	int cur_x = n;
	loop(cnt,1,n){
		int choose = -1;

		loop(i,1,n) if(s.count(i)){
			int nxt_n = cur_n - 1;
			int nxt_m = cur_m - (i == cnt);
			int nxt_x = cur_x - can_fix.count(i) - can_fix.count(cnt) + (i == cnt);

			if(nxt_m >= 0 && nxt_x >= 0){
				if(k <= f(nxt_n,nxt_m,nxt_x)){
					s.erase(i);
					can_fix.erase(i);
					can_fix.erase(cnt);
					cur_n = nxt_n;
					cur_m = nxt_m;
					cur_x = nxt_x;
					choose = i;
					break;
				}
				else k -= f(nxt_n,nxt_m,nxt_x);
			}
		}
		
		assert(choose != -1);

		cout<<choose<<" ";
	}
	cout<<endl;
}