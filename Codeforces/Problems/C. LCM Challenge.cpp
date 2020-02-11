 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int p[MAXN];
 vector<pair<int,int>> de;
 vector<pair<int,int>> divc[6];
 LL a[3];
 void get (int x){
    de.clear();
    while (x > 1){
        int cur  = 0;
        int d = p[x];
        while (x % d == 0){
            x /= d;
            cur ++;
        }
        de.emplace_back(d,cur);
    }
 }
 int get_nbr (){
        int p = 1;
        for (auto cur : de){
            for(int i = 0; i < cur.second; i++)
                p*=cur.first;
        }
        return p;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (!p[i]){
            for (int j = i; j<= n; j+=i)
                p[j] = i;
        }
    }
    a[0] = a[1] = a[2] = 1;
    for (int i = n; i >= 2 ; i--){
            int x = i;
            int maxi = 0;
            int idmaxi = 0;
            for (int k = 0; k < 3 ;k++){
                get(x);
                sort(rall(de));
                for (int j = 0; j < 3 ; j++){
                  int id = 0;
                  if (j == k) continue;
                  if (divc[j].size() == 0) continue;
                  for (auto cur : divc[j]){
                        if (cur.first > de[id].first) continue;
                        while (id < de.size() && cur.first < de[id].first )  id++;
                        if (id >= de.size()) break;
                        if (cur.first == de[id].first){
                            if (cur.second >= de[id].second)
                                de[id].second = 0;
                            else de[id].second -= cur.second;
                        }
                  }
                }
                int b = get_nbr();
                if (maxi < b && b > a[k]) idmaxi = k,maxi =b;
            }

            if (maxi > a[idmaxi]){
                    a[idmaxi] = maxi;
                    get(maxi);
                    divc[idmaxi]= de;
                }
    }
   cout << a[0] << " " << a[1]  << " "  << a[2] << endl;
  for (int i = 0; i < 3 ; i++){
        cout << a[i]<< ": "<< endl;
  for (auto cur : divc[i]){
    cout << cur.first << " " << cur.second << endl;
  }
  cout << endl;
  }
    cout << a[0] * a[1] * a[2];
 }
