#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    string s,cc="";
    for (int i=0;i<n;i++) {cin>>s;if (i==0) cc=s; else cc+=" "+s;}
    int m;
    cin>>m;
    int maj=0;
    int pos=0;
    char ans[5000];
    while (m--){
        string ch;
        cin>>ch;
        if (ch=="CapsLock"){
            maj=1-maj;
            continue;
        }else if (ch=="Backspace"){
            pos--;
            pos=max(pos,0);
            continue;
        }else if (ch=="Space") ans[pos]=' ';
        else {
            if (maj==1){
                    ans[pos]=toupper(ch[0]);
            }else ans[pos]=ch[0];
        }
        pos++;
    }
    for (int i=0;i<min(pos,(int)cc.size());i++){
            if (ans[i]!=(cc[i])) {cout<<"Incorrect"; return 0;}
    }
    if (pos==(int)cc.size()) cout<<"Correct";
    else cout<<"Incorrect";

}
