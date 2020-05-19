#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> squares;
int N, A[101010];
long long int cnt[20202020];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i <= 3162; i++){
        squares.push_back(i * i);
    }

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        int sum = 0;
        long long int res = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            for(auto sq : squares){
                if(sum == sq)res++;
                int x = sum - sq + 1e7;
                if(x >= 0)
                    res += cnt[x];
            }
            int x = sum + 1e7;
            cnt[x]++;

        }
        sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            int x = sum + 1e7;
            cnt[x] = 0;
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
}