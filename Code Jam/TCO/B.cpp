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


class AveragePrice {
public:
	double nonDuplicatedAverage(vector<int> prices){
        set<int> st;
        long long int sum = 0;
        for(auto cur : prices){
            st.insert(cur);
        }
        for(auto cur : st){
            sum += cur;
        }
        return (double) sum / (double) st.size();
	}
};