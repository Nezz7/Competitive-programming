#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
string solve (int i,int number,string cur){
        if (i==s.size()) return cur;
        if (s[i]==']'){
             string ret=cur;
             return ret;
        }
        if (isdigit(s[i])){
              number*=10;
              number+=s[i]-'0';
              return solve(i+1,number,cur);
        }
        if (s[i]=='['){
            string cc=solve(i+1,0,"");
            string ret="";
             for (int i=0;i<number;i++){
                 ret+=cc;
             }
             return cur+ret+solve(mp[i]+1,0,"");
        }
        cur+=s[i];
        return solve(i+1,number,cur);
}
int main (){
     cin>>s;
     stack<int> st;
     for (int i=0;i<s.size();i++){
            if (s[i]=='[')
                st.push(i);
            if (s[i]==']'){
                int x=st.top();
                mp[x]=i;
                st.pop();
            }
     }
  string ret=solve(0,0,"");
     cout<<"ret="<<ret<<"\n";

}
