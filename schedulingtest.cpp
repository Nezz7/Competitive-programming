#include <bits/stdc++.h>
using namespace std;
/***
    Variables Names :
    Cr : Regular hour capacity
    Co : Over time capacity
    I  : Type of treatment
    Wi : The average demand
    Ti : Wait time target
    Ci : Wait time penalty
    h  : Over time cost
    M  : Length of the booking horizon
    mat: matrix [Cr+Co][M] the current planning
    ri : r[i][j] length of the jth appointment of type i
    li : the number of appointment of type i
    a  : a[i] the number of customers of type i already waiting
    d  : jth day
    N  : Cr+Co
    rh : hours left in the jth + i day Regular time only
    oh : hours left in the jth+ i day Over time only
    waiting : client [Type] [id]  number of days waiting the ith client waiting
    Priority :
    Cost
    Urgent
***/
int const MAXN=1000;
int Cr,Co,I,h,M,N,d,nc;
/**
    mat [Hour] [Day]
    waiting [Type] [id] = number of days waiting
**/
int mat[MAXN][MAXN],waiting[MAXN][MAXN],W[MAXN][MAXN];
int T[MAXN],C[MAXN],r[MAXN][MAXN],l[MAXN],rh[MAXN],oh[MAXN],a[MAXN];
//int ct[MAXN],cd[MAXN],cr[MAXN],ch[MAXN];
int nc2,limit;
int random(int l, int r){
  return l + (rand() % r);
}
void delete_first_element(int t[],int sz){
    //delete the first element from an array
    for (int i=0;i<sz-1;i++)
            t[i]=t[i+1];
    t[sz - 1] = 0;
}
void print (int t[],int n,string name){
    //print table
    cout<<name<<" : ";
    for (int i=0;i<n;i++)
        cout<<t[i]<<" ";
    cout<<endl;
}
void print_planning (){
    //print planning
    for (int i=0;i<N;i++){
        printf ("|");
        for (int j=0;j<M;j++)
            printf ("%2d |",mat[i][j]);
        printf("\n");
    }
}
void print_client_waiting(){
    //print the table presenting the number of client waiting of each type
    printf ("Client Waiting : \n");
    for (int i=0;i<I;i++){
        printf ("%d of Type %d : ",a[i],i+1);
        for (int j=0; j<a[i];j++)
            printf ("%2d ",waiting[i][j]);
        printf ("\n");
    }
}
void print_client_sequence(){
    //print the sequence of each type
    printf ("Client Sequence : \n");
    for (int i=0;i<I;i++){
        printf("Type %d :",i+1);
        for (int j=0;j<l[i];j++)
            printf ("%2d ",r[i][j]);
        printf ("\n");
    }
}

void updating_waiting_client(){
    //updating waiting clients' days
    printf ("Updating waiting clients' days...\n");
    for (int i=0;i<I;i++)
        for (int j=0; j<a[i];j++)
           waiting[i][j]++;
}
void add_client(){
    //add client of each day
    printf ("Adding Client ...\n");
    for (int i=0;i<I;i++)
        a[i]+=W[d][i];
}
int count_rg (int j){
    //Counts the number of free hours in the Jth day (Regular Hour only)
    int ret=0;
    for (int i=0;i<Cr;i++)
        if (!mat[i][j]) ret++;
    return ret;
}
int count_ov (int j){
    //Counts the number of free hours in the Jth day (Overtime Hour only)
    int ret=0;
    for (int i=Cr;i<N;i++)
        if (!mat[i][j]) ret++;
    return ret;
}
void count_hours(){
    //Counts the number of free Regular and Overtime hour for all the days
    printf ("Counting Available Hours ...\n");
    for (int i=0;i<M;i++)
        rh[i]=count_rg(i);
    for (int i=0;i<M;i++)
        oh[i]=count_ov(i);
}
bool availble_rh(int client,int day){
  // return true if we can schedule the client in the regular hours of dth day
 for (int i=0;i<l[client];i++)
        if (rh[i+day]<r[client][i]) return false;
 return true;
}
bool availble_oh(int client,int day){
 // return true if we can schedule the client in the overtime hours of dth day
 for (int i=0;i<l[client];i++)
        if (oh[i+day]<r[client][i]) return false;
 return true;
}
void schedule_rh (int client,int day){
   //schedule the client in the regular hours of dth day
    for (int j=0;j<l[client];j++){
        int cur=r[client][j];
        rh[j+day]-=r[client][j];
        int i=0;
        while (i<Cr && cur){
            if (!mat[i][j+day]) mat[i][j+day]=client+1,cur--;
            i++;
        }
    }
}
bool existing_rh (int client, int day, int start){
    // function to verify if the appointment exist in the regular hour
    for (int j=start; j<l[client];j++){
        int cur=r[client][j];
        for (int k=0;k<Cr;k++){
            if (!cur) break;
            if(mat[k][j+day-start]==client+1) cur--;
        }
        if (cur) return false;
    }
    return true;
}
void schedule_oh (int client,int day){
    //schedule the client in the overtime hours of dth day
    for (int j=0;j<l[client];j++){
        int cur=r[client][j];
        oh[j+day]-=r[client][j];
        int i=Cr;
        while (i<N && cur){
            if (!mat[i][j+day]) mat[i][j+day]=client+1,cur--;
            i++;
        }
    }
}
bool existing_oh (int client, int day, int start){
    // function to verify if the appointment exist in the over time hour
    for (int j=start; j<l[client];j++){
        int cur=r[client][j];
        for (int k=Cr;k<N;k++){
            if (!cur) break;
            if(mat[k][j+day-start]==client+1) cur--;
        }
        if (cur) return false;
    }
    return true;
}
int get_longest(int day){
    //return the type of client that must be scheduled in the over time hours
    int mx=0;
    int ret=-1;
    for (int i=0;i<I;i++)
        if (a[i] && l[i]>mx && availble_oh(i,day)){
                mx=l[i];
                ret=i;
        }
    return ret;
}
void sort_waiting(){
    //sort waiting
    for (int i=0;i<I;i++){
         sort(waiting[i],waiting[i]+a[i]);
         reverse(waiting[i],waiting[i]+a[i]);
    }
}
int get_next(int day){
    // return the type of the next client that have the highest priority to get an appointment
    printf ("\tGet_NEXT : \n");
    int mx=-1;
    int cost=0;
    vector<pair<int,int>> clients;
    for (int i=0;i<I;i++){
        printf ("\t   Type %d :",i+1);
        if (a[i]==0){
            printf("No Patient waiting !\n");
            continue;
        }
        if (availble_rh(i,day)) clients.emplace_back((I- i) * C[i],i);
    }
    sort(clients.rbegin(),clients.rend());
    printf ("Clients after sorting with fucntion priority x Cost :");
    for (auto cur : clients){
        cout << cur.first << " " << cur.second << endl;
    }
    if (clients.size() == 0){
        printf("\tRegular Hours are not enough \n");
        return -1;
    }
    return clients[0].second;
}

pair<int,int> get_hours(int client,int day){
    // return pair where first represent the number of hour of regular and second represents the over time
    int rg=0,ov=0;
    for (int i=0;i<Cr;i++)
        rg+=(mat[i][day]==client);
    for (int i=Cr;i<N;i++)
        ov+=(mat[i][day]==client);
    return make_pair(rg,ov);
}
void scheduling(int day){
    srand (time(0));
    printf  ("----------------------------------------------------\n");
    printf ("\t\tScheduling day %d\n",day+1);
    printf  ("----------------------------------------------------\n");
    add_client();
    sort_waiting();
    print (W[d],I,"The Average Demand ");
    print_client_waiting();
    printf("\nRegular time Scheduling ...\n");
    int i = get_next(day);
    while (i!=-1){
        printf ("  --> Scheduling Client %d ...\n",i+1);
        schedule_rh(i,day);
        delete_first_element(waiting[i],a[i]);
        a[i]--;
        i=get_next(day);
    }
    printf("\nOver time Scheduling ...\n");
    int lg=get_longest(day);
    if (lg==-1)
        printf ("\tOvertime Hours are not enough\n");
    while (oh[d] && lg!=-1){
        printf ("  --> Scheduling Client %d after time ...\n",lg+1);
        schedule_oh(lg,day);
        delete_first_element(waiting[lg],a[lg]);
        a[lg]--;
        lg=get_longest(day);
    }
    printf("\n");
    printf ("\nPlanning of the %dth day :\n",day+1);
    print_planning();
    updating_waiting_client();
}
void solve (){
    srand (time(0));
    printf  ("----------------------------------------------------\n");
    printf  ("\t\tGeneral Information \n");
    print (T,I,"Wait Time Target ");
    print (C,I,"Wait Time Penalty ");
    count_hours();
    while (d<limit){
        scheduling(d);
        d++;
    }
}

void input (){
        freopen("input.txt","r",stdin);
        cin>>Cr>>Co>>h>>M>>I;
        N=Cr+Co;
        limit=M;
        for (int d=0;d<M;d++)
          for (int i=0;i<I;i++){
             W[d][i]=random(0,4);
        }

        for (int i=0;i<I;i++)
            cin>>T[i];
        for (int i=0;i<I;i++)
            cin>>C[i];
        for (int i=0;i<I;i++){
            cin>>l[i];
            for (int j=0;j<l[i];j++)
                cin>>r[i][j];
        }
        for (int i=0;i<I;i++){
            cin>>a[i];
         for (int j=0; j<a[i];j++)
            cin>>waiting[i][j];
        }
        cin>>d;
        d--;
        for (int i=0;i<Cr+Co;i++)
            for (int j=0;j<M;j++)
                cin>>mat[i][j];
        /*cin>>nc;
        for (int i=0;i<nc;i++){
            cin>>ct[i]>>cd[i]>>cr[i]>>ch[i];
            ct[i]--,cd[i]--,cr[i]--;
        }
        cin>>nc2;
        for (int i=nc;i<nc+nc2;i++){
            cin>>ct[i]>>cr[i]>>ch[i];
            ct[i]--,cd[i]=d,cr[i]--;
        }*/
        M+=*max_element(l,l+I-1);
}
int main (){
    srand((unsigned)time(NULL));
    input();
    solve();
}

