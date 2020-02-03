#include <bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        int f,s;
        for(auto cur : nums)
            mp[cur]++;
        for(auto cur : nums){
            int x=target-cur;
            if (x==cur && mp[x]>1){f=x,s=cur; break;}
            if (mp[x]){ f=x,s=cur; break;}
        }
        for (int i=0;i<nums.size();i++){
             if (nums[i]== f or nums[i]==s) ans.push_back(i);
             if (ans.size()==2) return ans;
            }
    }
int main (){
    vector<int> v;
    int n;
    cin>>n;
    int t;
    cin>>t;
    int x;
    for (int i =0;i<n;i++) cin>>x,v.push_back(x);
    v=twoSum(v,t);
    for (auto cur : v) cout<<cur<<" ";
}
