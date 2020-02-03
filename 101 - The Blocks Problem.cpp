#include <bits/stdc++.h>
using namespace std;
int nxt[100];
void print (int a){
    string c = " " ;
    if (nxt[a] == -1) c = "";
    if (a >= 25)
        cout << a - 25 << ":" << c;
    else  cout << a << c;
    if (nxt[a] == -1) return;
    print(nxt[a]);
}
void clr (int a,int start){
    if (a != start)
    nxt[a+25]= a;
    if (nxt[a] == -1) return;
    clr(nxt[a],start);
    nxt[a] = -1;
}
int last (int a){
    if (nxt[a] == -1) return a;
    return last(nxt[a]);
}
bool valid(int a,int b){
    if (nxt[a] == -1) return true;
    if (nxt[a] == b) return false;
    return valid(nxt[a],b);
}
int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        nxt[i] = -1,nxt[i+25] = i;
    string s;
    while (cin >> s && s!="quit"){
        int a,b;
        string s2;
        cin >> a >> s2 >> b;
        if (!valid(a,b) or !valid(b,a) or a == b) continue;

        if (s == "move"){
            clr (a,a);
            if (s2 == "onto"){
                clr(b,b);
            }
            for (int  i = 0; i <n; i++){
                if (nxt[i+25] == a) nxt[i+25] = -1;
                if (nxt[i] == a) nxt[i] = -1;
            }
            nxt[last(b)] = a;
        }else {
             if (s2 == "onto"){
                clr(b,b);
            }
            for (int  i = 0; i <n; i++){
                if (nxt[i+25] == a) nxt[i+25] = -1;
                if (nxt[i] == a) nxt[i] = -1;
            }
            nxt[last(b)] = a;
        }
    }
    for (int i = 0; i <n ;i++){
        print(i+25);
        cout << "\n";
    }

}
