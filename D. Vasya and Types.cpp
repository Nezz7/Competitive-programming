#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;

string get_type(string s){
    //cout<<s<<endl;
    if (mp.count(s)) return mp[s];
    int n = s.size();
    if (s[0] == '&' &&  s[n-1]=='*') return get_type(s.substr(1,n-2));
    if (s[0] == '&'){
            string ret =get_type(s.substr(1,n-1));
            int sz = ret.size();
            if (ret == "void" or ret == "errtype" ) return "errtype";
            else {
                    if (ret[sz-1]=='*') return ret.substr(0,sz-1);
                    return s[0]+ret;
            }
    }
    if (s[n-1] == '*') {
            string ret  = get_type(s.substr(0,n-1));
            if (ret[0] == '&') return ret.substr(1,n-1);
            if ( ret == "errtype" ) return "errtype";
            return get_type(s.substr(0,n-1))+s[n-1];
    }
    return "errtype";
}

void add_type(string u, string v){
    mp[v]=get_type(u);
}
int main (){
    mp["void"]="void";
    mp["&void"]="errtype";
    mp["errtype"]="errtype";
    //cout<<get_type("&void*")<<endl;
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int q;
    cin>>q;
    while (q--){
        string fun,u,v;
        cin>>fun;
        if (fun=="typedef"){
            cin>>u>>v;
            add_type(u,v);
        }else{
            cin>>u;
            cout<<get_type(u)<<"\n";
        }
    }


}
