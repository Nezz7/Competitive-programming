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
    machines: matrix [Cr+Co][M] the current planning
    ri : r[i][j] length of the jth appointment of type i
    li : the number of appointment of type i
    a  : a[i] the number of patients of type i already waiting
    d  : jth day
    N  : Cr+Co
    regular_hours : hours left in the jth + i day Regular time only
    overtime_hours : hours left in the jth+ i day Over time only
    waiting : patient [Type] [id]  number of days waiting the ith patient waiting
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
int machines[2][MAXN][MAXN],waiting[MAXN][MAXN];
int T[MAXN],C[MAXN],r[MAXN][MAXN],l[MAXN],regular_hours[2][MAXN],overtime_hours[2][MAXN],a[MAXN],W[MAXN];
//int ct[MAXN],cd[MAXN],cr[MAXN],ch[MAXN];
int nc2,limit;
int total_cost;
int random(int l, int r){
  return l + (rand() % r);
}
void delete_first_element(int t[],int sz){
    //delete the first element from an array
    for (int i = 0; i < sz - 1; i++)
            t[i] = t[i+1];
            t[sz-1] = 0;
}
void print (int t[],int n,string name){
    //print table
    cout << name << " : ";
    for (int i = 0; i < n; i++)
        cout << t[i] << " ";
    cout << endl;
}
void print_planning (int nbr){
    //print planning
    for (int i = 0; i < N; i++){
        printf ("|");
        if(i == Cr){
            for (int j = 0; j < M-1; j++)
                printf("----");
            printf ("---|");
            printf("\n");
            printf ("|");
        }
        for (int j = 0; j < M; j++)
            printf ("%2d |",machines[nbr][i][j]);
        printf("\n");
    }
}
void print_client_waiting(){
    //print the table presenting the number of patient waiting of each type
    printf ("Patient Waiting : \n");
    for (int i = 0 ; i < I; i++){
        printf ("%d of Type %d : ",a[i],i + 1);
        for (int j = 0; j < a[i]; j++)
            printf ("%2d ",waiting[i][j]);
        printf ("\n");
    }
}
void print_client_sequence(){
    //print the sequence of each type
    printf ("Patient Sequence : \n");
    for (int i = 0; i < I; i++){
        printf("Type %d :",i+1);
        for (int j = 0; j < l[i]; j++)
            printf ("%2d ",r[i][j]);
        printf ("\n");
    }
}

void updating_waiting_client(){
    //updating waiting Patients' days
    printf ("Updating waiting Patients' days...\n");
    for (int i = 0 ; i < I; i++)
        for (int j = 0 ; j < a[i]; j++)
           waiting[i][j]++;
}
void add_client(){
    //add patient of each day
    printf ("Adding Patient ...\n");
    for (int i = 0; i < I ; i++)
        a[i] += W[i];
}
int count_rg (int j,int nbr){
    //Counts the number of free hours in the Jth day (Regular Hour only)
    int ret = 0;
    for (int i = 0;i < Cr;i++)
        if (!machines[nbr][i][j]) ret++;
    return ret;
}
int count_ov (int j,int nbr){
    //Counts the number of free hours in the Jth day (Overtime Hour only)
    int ret=0;
    for (int i = Cr;i < N;i++)
        if (!machines[nbr][i][j]) ret++;
    return ret;
}
void count_hours(int nbr){
    //Counts the number of free Regular and Overtime hour for all the days
    printf ("Counting Available Hours ...\n");
    for (int i = 0; i < M ; i++)
        regular_hours[nbr][i] = count_rg(i,nbr);
    for (int i = 0; i < M; i++)
        overtime_hours[nbr][i] = count_ov(i,nbr);
}
bool availble_regular_hours(int client,int day,int nbr){
  // return true if we can schedule the Patient in the regular hours of dth day
 for (int i = 0; i < l[client]; i++)
        if (regular_hours[nbr][i + day] < r[client][i]) return false;
 return true;
}
bool availble_overtime_hours(int client,int day,int nbr){
 // return true if we can schedule the client in the overtime hours of dth day
 for (int i = 0;i < l[client]; i++)
        if (overtime_hours[nbr][i + day] < r[client][i]) return false;
 return true;
}
void schedule_regular_hours (int client,int day,int nbr){
   //schedule the Patient in the regular hours of dth day in the idx machine
    for (int j = 0; j < l[client]; j++){
        int cur = r[client][j];
        regular_hours[nbr][j + day] -= r[client][j];
        int i =0;
        while (i < Cr && cur){
            if (!machines[nbr][i][j + day]) machines[nbr][i][j + day] = client + 1,cur--;
            i++;
        }
    }
}
bool existing_regular_hours (int client, int day, int start,int nbr){
    // function to verify if the appointment exist in the regular hour
    for (int j= start; j < l[client]; j++){
        int cur = r[client][j];
        for (int k = 0;k < Cr; k++){
            if (!cur) break;
            if(machines[nbr][k][j + day- start] == client + 1) cur--;
        }
        if (cur) return false;
    }
    return true;
}
void schedule_overtime_hours (int client,int day,int nbr){
    //schedule the client in the overtime hours of dth day
    for (int j = 0; j < l[client]; j++){
        int cur = r[client][j];
        overtime_hours[nbr][j + day] -= r[client][j];
        int i = Cr;
        while (i < N && cur){
            if (!machines[nbr][i][j + day]) machines[nbr][i][j + day] = client + 1,cur--;
            i++;
        }
    }
}
bool existing_overtime_hours (int client, int day, int start,int nbr){
    // function to verify if the appointment exist in the over time hour
    for (int j = start; j< l[client]; j++){
        int cur = r [client][j];
        for (int k = Cr; k < N ;k++){
            if (!cur) break;
            if(machines[nbr][k][j + day - start] == client + 1) cur--;
        }
        if (cur) return false;
    }
    return true;
}
int get_longest(int day,int nbr){
    //return the type of Patient that must be scheduled in the over time hours
    int mx = 0;
    int ret = -1;
    for (int i = 0;i < I; i++)
        if (a[i] && l[i] > mx && availble_overtime_hours(i,day,nbr)){
                mx = l[i];
                ret = i;
        }
    return ret;
}
void sort_waiting(){
    //sort waiting
    for (int i = 0; i < I; i++){
         sort(waiting[i],waiting[i]+a[i]);
         reverse(waiting[i],waiting[i]+a[i]);
    }
}
int get_next(int day,int nbr){
    // return the type of the next client that have the highest priority to get an appointment
    printf ("\tGet_NEXT : \n");
    int mx = -1;
    int cost = 0;
    int total_cost_day = 0;
    vector<pair<int,pair<int,int >>  > clients;
    for (int i = 0;i < I; i++){
        if (a[i] == 0){
            continue;
        }
        int cost = max((I- i) * C[i]* (waiting[i][0] - T[i]),0);
        if (availble_regular_hours(i,day,nbr)){
            clients.push_back({cost,{l[i],i}});
        }
    }
    sort(clients.rbegin(),clients.rend());
    printf ("Clients after sorting with funtion priority x Cost :\n");
    for (auto cur : clients){
        cout  << "\t Type " <<  cur.second.second + 1   << " : " << max(cur.first,0) << endl;
    }
    if (clients.size() == 0){
        printf("\tRegular Hours are not enough \n");
        return -1;
    }
    total_cost +=  clients[0].first;
    cout << " Total cost :" << total_cost << endl;
    return clients[0].second.second;
}
pair<int,int> get_hours(int client,int day,int nbr){
    // return pair where first represent the number of hour of regular and second represents the over time
    int rg = 0,ov = 0;
    for (int i = 0; i < Cr; i++)
        rg += (machines[nbr][i][day] == client);
    for (int i = Cr; i < N; i++)
        ov += (machines[nbr][i][day] == client);
    return make_pair(rg,ov);
}
void scheduling(int day){
    srand (time(0));
    printf  ("----------------------------------------------------\n");
    printf  ("\t\tScheduling day %d\n",day+1);
    printf  ("----------------------------------------------------\n");
    add_client();
    sort_waiting();
    print (W,I,"The Average Demand ");
    print_client_waiting();
    printf("\nRegular time Scheduling ...\n");
    for(int nbr = 0; nbr < 2; nbr++){
        printf("MACHINE %d :\n",nbr+1);
        int i = get_next(day,nbr);
        while (i != -1){
            printf ("  --> Scheduling Patient %d ...\n",i+1);
            schedule_regular_hours(i,day,nbr);
            delete_first_element(waiting[i],a[i]);
            a[i]--;
            i = get_next(day,nbr);
        }
    }
    printf("\nOver time Scheduling ...\n");
    for(int nbr = 0; nbr < 2; nbr++){
        printf("MACHINE %d :\n",nbr+1);
        int lg = get_longest(day,nbr);
        if (lg == -1)
            printf ("\tOvertime Hours are not enough\n");
        while (overtime_hours[nbr][d] && lg !=- 1){
            printf ("  --> Scheduling Patient %d after time ...\n",lg+1);
            schedule_overtime_hours(lg,day,nbr);
            delete_first_element(waiting[lg],a[lg]);
            a[lg]--;
            lg=get_longest(day,nbr);
        }
    }
    printf("\n");
    printf ("\nPlanning of the %dth day :\n",day+1);
    for(int nbr = 0; nbr < 2; nbr++){
        printf("MACHINE %d :\n",nbr+1);
        print_planning(nbr);
        printf("\n");
    }
    updating_waiting_client();  
}
void solve (){
    srand (time(0));
    printf  ("----------------------------------------------------\n");
    printf  ("\t\tGeneral Informachinesion \n");
    print (T,I,"Wait Time Target ");
    print (C,I,"Wait Time Penalty ");
    for(int nbr = 0; nbr < 2; nbr++)
        count_hours(nbr);
    
    while (d < limit){
        scheduling(d);
        d ++;
    }
}

void input (){
        freopen("input.txt","r",stdin);
        cin  >> Cr >> Co >> h >> M >> I;
        N = Cr + Co;
        limit = M;
        //for (int d=0;d<M;d++)
        for (int i = 0; i < I; i++){
             //W[d][i]=random(0,4);
             W[i] = random(0,4);
        }
        for (int i = 0; i < I; i++)
            cin >> T[i];
        for (int i = 0; i < I; i++)
            cin >> C[i];
        for (int i = 0; i < I; i++){
            cin >> l[i];
            for (int j = 0; j < l[i]; j++)
                cin >> r[i][j];
        }
        for (int i = 0; i < I; i++){
            cin >> a[i];
            for (int j = 0; j < a[i]; j++)
                cin >> waiting[i][j];
        }
        cin >> d;
        d--;
        for(int k = 0; k < 2; k++)
            for (int i = 0; i < Cr + Co; i++)
                for (int j = 0 ; j < M; j++)
                    cin >> machines[k][i][j];
        M += *max_element(l,l+I-1);
}
int main (){
    //srand((unsigned)time(NULL));
    input();
    solve();
}
