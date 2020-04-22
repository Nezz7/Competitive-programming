#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,1,-1,-1,0,1};
bool valid(int x, int y){
    return x >= 0 && x < 500 && y >= 0 && y < 500;
}
class ThreeNeighbors {
public:
	vector <string> construct(int N) {
        vector<string> a;
        a.resize(50);
        for(int i = 0; i < 50;i++)
            for(int j = 0; j < 50; j++)
                a[i].push_back(0);
        int cnt = N;
        for (int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                if(a[i][j] == 0){
                    int cur = 0;
                    int emp = 0;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(!valid(x,y)) continue;
                        if(a[x][y] == 'X') cur++;
                        if(a[x][y] == 0) emp++;
                    }
                    if(cnt == 0){
                        a[i][j] = 'X';
                        continue;
                    }
                    if (cur > 3) {
                        a[i][j] = '.';
                        continue;
                    }
                    if(cur == 3 && emp == 0){
                        a[i][j] ='.';
                        cnt --;
                        continue;
                    }  
                    if(cur  < 3 && 3 - cur <= emp){
                        cnt--;
                        a[i][j] = '.'   ;
                        for(int k = 0; k < 8; k++){
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(valid(x,y) && a[x][y] == 0){
                                if(cur < 3){
                                    cur++;
                                    a[x][y] = 'X';
                                }else {
                                    a[x][y] = '.';
                                }
                            }
                        }
                    
                    }
                }else if (a[i][j] == '.'){
                        int cur = 0;
                        int emp = 0;
                        for(int k = 0; k < 8; k++){
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(!valid(x,y)) continue;
                            if(a[x][y] == 'X') cur++;
                            if(a[x][y] == 0) emp++;
                        }
                        if (!cnt){
                            if( cur == 3 && emp == 0) cerr << "err";
                            if (cur == 3 && emp){
                                for(int k = 0; k < 8; k++){
                                    int x = i + dx[k];
                                    int y = j + dy[k];
                                    if(!valid(x,y)) continue;
                                    if(a[x][y] == 0) a[x][y] = 'X';
                                }
                            }
                            continue;
                        }
                        if(cur == 3){
                            cnt --;
                            for(int k = 0; k < 8; k++){
                                    int x = i + dx[k];
                                    int y = j + dy[k];
                                    if(!valid(x,y)) continue;
                                    if(a[x][y] == 0) a[x][y] = 'X';
                            }
                            continue;
                        }
                        if(cur  < 3 && 3 - cur <= emp){
                            for(int k = 0; k < 8; k++){
                                int x = i + dx[k];
                                int y = j + dy[k];
                                if(valid(x,y) && a[x][y] == 0){
                                    if(cur < 3){
                                        cur++;
                                        a[x][y] = 'X';
                                    }else {
                                        a[x][y] = '.';
                                    }
                                }
                            }
                            cnt--;  
                    }
                }
            }
        }
        return a;
	}
};