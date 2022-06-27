/*
There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)

Distance between consecutive spots = distance between gate and nearest spot = 1 m

Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

image

Input Format

Number of fishing spots, N Position of the gates, Gi, 1 < i < 3 Number of fishermen at each gates, G_n_i

Constraints

1 <= N <= 10 1 <= G_i <= N 1 <= G_n_i <= 15

Output Format

Output single integer

Sample Input 0

10
4 6 10
5 2 2
Sample Output 0

18
*/
#include<iostream>
using namespace std;
int ans=100000;

void calculate(int j,int* gate,int* person,bool* vis,int* prem,int dis,int n){
    if(j==3){
        if(dis<ans) ans=dis;
        //cout << prem[0] << " " << prem[1] << " " << prem[2] << " " << ans << endl;
        return;
    }
    int i=prem[j];
    int p=person[i];
    int left=gate[i];
    int right=gate[i]+1;
    for(int k=0;k<p;k++){
        while(left>=0 && vis[left]){
            left--;
            if(left==-1) break;
        }
        while(right<n && vis[right]){
            right++;
            if(right==n) break;
        }
        if(left==-1 && right==n) return;
        else if(left==-1){
            dis+=right-gate[i]+1;
            vis[right]=true;
            right++;
        }else if(right==-1){
            dis+=gate[i]-left+1;
            vis[left]=true;
            left--;
        }else if(k==p-1 && gate[i]-left==right-gate[i]){
            bool tempvis[n];
            for(int l=0;l<n;l++) tempvis[l]=vis[l];
            dis+=right-gate[i]+1;
            vis[right]=true;
            calculate(j+1,gate,person,vis,prem,dis,n);
            dis-=right-gate[i]+1;
            dis+=gate[i]-left+1;
            tempvis[left]=true;
            calculate(j+1,gate,person,tempvis,prem,dis,n);
        }else if(gate[i]-left<right-gate[i]){
            dis+=gate[i]-left+1;
            vis[left]=true;
            left--;
        }else if(gate[i]-left>=right-gate[i]){
            dis+=right-gate[i]+1;
            vis[right]=true;
            right++;
        }
    }
    calculate(j+1,gate,person,vis,prem,dis,n);
}

int main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        // int a[n];
        int g[3],p[3];
        for(int i=0;i<3;i++){
            cin >> g[i] ;
            g[i]--;
        }
    for(int i=0;i<3;i++){
            cin >> p[i] ;
            // g[i]--;
        }
    
        bool vis[n];
        int premu[3];
        premu[0]=0,premu[1]=1,premu[2]=2;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        premu[0]=0,premu[1]=2,premu[2]=1;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        premu[0]=1,premu[1]=0,premu[2]=2;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        premu[0]=1,premu[1]=2,premu[2]=0;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        premu[0]=2,premu[1]=1,premu[2]=0;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        premu[0]=2,premu[1]=0,premu[2]=1;
        for(int i=0;i<n;i++) vis[i]=false;
        calculate(0,g,p,vis,premu,0,n);
        cout << ans << endl;
    // }
}
