#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin  >> s;
    map<char,int>mp;
    for (auto c : s){
        mp[c]++;
    }
    for (auto cur : mp){
        cout << cur.first <<" " << cur.second << endl;
    }
    int ans = 0;
    vector<char> v;
    for (auto cur : mp){
        if (cur.second % 2) ans++,v.push_back(cur.first);
    }
    int n = s.size();
    string a ="";
    if (n % 2){
        if (ans == 1 or ans  == 3){
            cout << "Yes\n";
            if (ans  == 1){
                if ((mp['a'] % 2 == 0) ){
                    for (auto cur : mp){
                        if (cur.second % 2) mp[cur.first]--;
                    }
                    for (auto cur : mp){
                        for (int i = 0; i < cur.second/2; i++)
                            a += cur.first;
                    }

                    string r = a;
                    reverse (r.begin(),r.end());
                    cout << a + 'a' + r;
                }else {
                    char cc;
                    for (char c = 'z'; c>= 'a'; c--){
                        if (mp[c]){
                            mp[c]--;
                            if (c == 'a'){
                            cc = 'b';
                            }else cc = 'a';
                            mp[cc]++;
                            break;
                        }
                    }
                      for (char c = 'z'; c>= 'a'; c--){
                        if (mp[c] % 2) cc = c;

                    }
                     for (auto cur : mp){
                        for (int i = 0; i < cur.second/2; i++)
                            a+=cur.first;
                    }

                    string r = a;
                    reverse (r.begin(),r.end());
                    cout << a + cc + r;
                }
            }else {
                mp[v[0]]++;
                mp[v[2]]--;
                for (auto cur : mp){
                    for (int i = 0; i < cur.second/2; i++)
                        a+=cur.first;
                }
                string r = a;
                reverse (r.begin(),r.end());
                cout << a + v[1] + r;
            }

        }else cout << "No";
    }else {
        if (ans == 2){
            cout << "Yes\n";
                mp[v[0]]++;
                mp[v[1]]--;
                for (auto cur : mp){
                    for (int i = 0; i < cur.second/2; i++)
                        a+=cur.first;
                }
                string r = a;
                reverse (r.begin(),r.end());
                cout << a  + r;
        }else cout << "No";
    }
}

