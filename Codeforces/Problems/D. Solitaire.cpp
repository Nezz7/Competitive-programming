#include <bits/stdc++.h>
using namespace std;
    int n,m;
    string card[20][20];
    set<string> st;
    int j1x = -1,j2x = -1,j1y,j2y;
    vector<pair<int,int >> v;
    vector<string> jok;
    string j1 = "",j2 = "";
    char ran[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' , 'A'};
    char suit[] = {'C','D','H','S'};
    bool inter (int i, int j, int x, int y){

        return (i <=  x && x <=  i+2 && j <=  y && y <=  j+2) or (i <=  x+2 && x+2 <=  i+2 && j <=  y && y <=  j+2) or (i <=  x && x <=  i+2 && j <=  y+2 && y+2 <=  j+2) or (i <=  x+2 && x+2 <=  i+2 && j <=  y+2 && y+2 <=  j+2);
    }
    string random_card(){
        string card = "";
        for (int i = 0;i<13;i++)
            for (int j = 0;j<4;j++){
                string cur = "ab";
                        cur[0] = ran[i];
                        cur[1] = suit[j];
                if (!st.count(cur)) return cur;
            }
    }
    bool can (int x,int y){
        j1 = "NO";
        j2 = "NO";
        set<char> r;
        set<char> s;
        r.clear();
        s.clear();
        bool j1b = false,j2b = false;
        bool dif_r = true,dif_s = true;
        for (int i = 0;i<3;i++)
            for (int j = 0;j<3;j++){
                if(card[x+i][y+j]  ==  "J1") {j1b = true; continue;}
                if(card[x+i][y+j]  ==  "J2") {j2b = true; continue;}
                if (r.count(card[x+i][y+j][0])) {dif_r = false; break;}
                else r.insert(card[x+i][y+j][0]);
            }

        if (dif_r){
            if (j1b){
                for (int i = 0;i<13;i++){
                    for (int j = 0;j<4;j++){
                        string cur = "ab";
                        cur[0] = ran[i];
                        cur[1] = suit[j];
                        if (!st.count(cur) && cur!= j2 && !r.count(ran[i])) j1 = cur, r.insert(ran[i]);
                        if (j1!= "NO") break;
                    }
                if (j1!= "NO") break;
                }
                if (j1  ==  "NO") dif_r = false;
            }
            if (j2b){
                for (int i = 0;i<13;i++){
                      for (int j = 0;j<4;j++){
                         string cur = "ab";
                        cur[0] = ran[i];
                        cur[1] = suit[j];
                        if (!st.count(cur) && j1!= cur && !r.count(ran[i])) j2 = cur, r.insert(ran[i]);
                        if (j2!= "NO") break;
                    }
                if (j2!= "NO") break;
                }
                if (j2  ==  "NO") dif_r = false;
            }
            if (dif_r) return true;
        }
        j1 = "NO",j2 = "NO";
        for (int i = 0;i<3;i++)
            for (int j = 0;j<3;j++){
                if(card[x+i][y+j]  ==  "J1") {j1b = true; continue;}
                if(card[x+i][y+j]  ==  "J2") {j2b = true; continue;}
                if (s.count(card[x+i][y+j][1])){dif_s = false; break;}
                else s.insert(card[x+i][y+j][1]);
            }
     if (dif_s){
            if (j1b){
                for (int i = 0;i<13;i++){
                       string cur = "ab";
                        cur[0] = ran[i];
                        cur[1] = card[x][y][1];
                        if (!st.count(cur) && j2!= cur ) j1 = cur;
                        if (j1!= "NO") break;
                    }

                if (j1  ==  "NO") dif_s = false;
            }
            if (j2b){
                        for (int i = 0;i<13;i++){
                          string cur = "ab";
                          cur[0] = ran[i];
                        cur[1] = card[x][y][1];
                        if (!st.count(cur) && j1!= cur ) j2 = cur;
                        if (j2!= "NO") break;
                    }

                if (j2  ==  "NO") dif_s = false;
            }
        }
        return dif_s  or dif_r;
    }
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i<n;i++)
        for (int j = 0;j<m;j++) {
            cin >> card[i][j],st.insert(card[i][j]);
            if(card[i][j]  ==  "J1") j1x = i,j1y = j;
            if(card[i][j]  ==  "J2") j2x = i,j2y = j;
        }
    for (int i = 0;i<n-2;i++)
        for (int j = 0;j<m-2;j++)
            if (can(i,j)){
                v.emplace_back(i,j);
                jok.push_back(j1+j2);
            }
    for (int i = 0;i<v.size();i++){
        for (int j = i+1;j<v.size();j++){
            if (!inter(v[i].first,v[i].second,v[j].first,v[j].second)){
                string joke1 = "",joke2 = "";
                if (jok[i][0]  ==  'N' && jok[j][0]  ==  'N' && jok[i][2]  ==  'N'&& jok[j][2]  ==  'N'){
                        joke1  =  random_card();
                        st.insert(joke1);
                        joke2  =  random_card();
                        st.insert(joke2);
                }else if (jok[i][0]  ==  'N' && jok[j][0]  ==  'N'){
                       if (jok[i][2]  ==  'N')
                        joke2 = jok[j].substr(2,2);
                        else joke2 = jok[i].substr(2,2);
                        st.insert(joke2);
                        joke1  =  random_card();
                        st.insert(joke1);
                }else if (jok[i][2]  ==  'N' && jok[j][2]  ==  'N'){
                     if (jok[i][0]  ==  'N')
                        joke1 = jok[j].substr(0,2);
                        else joke1 = jok[i].substr(0,2);
                        st.insert(joke1);
                        joke2  =  random_card();
                        st.insert(joke2);
                }else {
                    if (jok[i][0]  ==  'N')
                        joke1 = jok[j].substr(0,2);
                        else joke1 = jok[i].substr(0,2);
                      if (jok[i][2]  ==  'N')
                        joke2 = jok[j].substr(2,2);
                        else joke2 = jok[i].substr(2,2);

                }
                if (joke1  ==  joke2) continue;
                cout << "Solution exists.\n";
                if (j1x  ==  -1 && j2x  ==  -1){
                    cout << "There are no jokers.\n";
                }else if (j1x!= -1 && j2x!= -1){
                    cout << "Replace J1 with " << joke1 << " and J2 with " << joke2 << ".\n";
                }else if (j1x!= -1){
                    cout << "Replace J1 with " << joke1 << ".\n";
                }else  cout << "Replace J2 with " << joke2 << ".\n";
                cout << "Put the first square to (" << v[i].first+1 << ", " << v[i].second+1 << ").\n";
                cout << "Put the second square to (" << v[j].first+1 << ", " << v[j].second+1 << ").\n";
                return 0;
            }
        }
    }
        cout << "No solution.";
}
