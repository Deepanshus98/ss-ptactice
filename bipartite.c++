#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> arr;
bool bipartite(int i,int colour[]){
    bool flag=true;
    for(int j=0;j<n;j++){
        if(arr[i][j]==1){
            if(colour[j]==-1){
                colour[j]=1-colour[i];
                flag=flag&bipartite(j,colour);
                
                
            }
            else if(colour[j]==colour[i]){
                    return false;
                
            }
        }
    }
    return flag;
}
int main(){
    cin>>n;
    int colour[n];
    arr.assign(100,vector<int>(100,0));
    for(int i=0;i<n;i++){
        colour[i]=-1;
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(colour[i]==-1){
            colour[i]=0;
            if(!bipartite(i,colour)){
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    for(int j=0;j<n;j++){
        if(colour[j]==0){
            cout<<j<<" ";
            
        }
    }
    return 0;
    
}
