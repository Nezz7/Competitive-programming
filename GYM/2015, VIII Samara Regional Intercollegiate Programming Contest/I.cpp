#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
vector<pair<int,int>> arr;
vector<string> names;
int x, y;
string dir;
void solve(int name, int dx, int dy){
    int cur_x = x, cur_y = y;
    if(dir == "LEFT" or dir == "RIGHT"){
        if(dir == "RIGHT"){
            cur_x += (abs(y - dy) + 1)/2;
            if(dx <= x)
                arr.emplace_back(abs(cur_x - dx) + (abs(y - dy) + 1)/2, name);
            else arr.emplace_back((abs(cur_x - dx) + 2)/3 + (abs(y - dy) + 1)/2, name);
        }else {
            cur_x -= (abs(y - dy) + 1)/2;
            if(dx >= x)
                arr.emplace_back(abs(cur_x - dx) + (abs(y - dy) + 1)/2, name);
            else arr.emplace_back((abs(cur_x - dx) + 2)/3 + (abs(y - dy) + 1)/2, name);
        }
    }else {
        if(dir == "UP"){
            cur_y += (abs(x - dx) + 1)/2;
            if(dy <= y)
                arr.emplace_back(abs(cur_y - dy) + (abs(x - dx) + 1)/2, name);
            else  arr.emplace_back((abs(cur_y - dy) + 2) / 3 +(abs(x - dx) + 1)/2, name);

        }else {
             cur_y -= (abs(x - dx) + 1)/2;
            if(dy > y)
                arr.emplace_back(abs(cur_y - dy) + (abs(x - dx) + 1)/2, name);
            else  arr.emplace_back((abs(cur_y - dy) + 2) / 3 + (abs(x - dx) + 1)/2, name);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> x >> y;
    cin >> dir;
    int n;
    cin >> n;
    int i = 0;
    while(n--){
        string name;
        int dx, dy;
        cin >> name >> dx >> dy;
        solve(i, dx, dy);
        i++;
        names.push_back(name);
    }
    sort(all(arr));

    cout << names[arr[0].second] << endl;
}