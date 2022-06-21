#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int row,col,X,Y,L;
int ma[1000][1000],visited[1000][1000];
struct node{
    int x,y,l;
};
bool valid(int x,int y)
{
    return (x>=0 && x<row && y>=0 && y<col);
}
bool left(int x,int y){
    return (ma[x][y]==1 || ma[x][y]==3 || ma[x][y]==6 || ma[x][y]==7);
}
bool right(int x,int y){
    return (ma[x][y]==1 || ma[x][y]==3 || ma[x][y]==4 || ma[x][y]==5);
}
bool up(int x,int y){
    return (ma[x][y]==1 || ma[x][y]==2 || ma[x][y]==4 || ma[x][y]==7);
}
bool down(int x,int y){
    return (ma[x][y]==1 || ma[x][y]==2 || ma[x][y]==6 || ma[x][y]==5);
}
int solve(int x,int y,int l){
    int ans = 0;
    queue<node> q;
    node k={x,y,l};
    q.push(k);
    visited[x][y]=1;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int l = cur.l;
        if(l==0) continue;
        ans++;
        if(valid(x,y-1) && left(x,y) && right(x,y-1) && visited[x][y-1]==0){
            q.push({x,y-1,l-1});
            visited[x][y-1]=1;
        }
        if(valid(x,y+1) && right(x,y) && left(x,y+1) && visited[x][y+1]==0){
            q.push({x,y+1,l-1});
            visited[x][y+1]=1;
        }
        if(valid(x-1,y) && up(x,y) && down(x-1,y) && visited[x-1][y]==0){
            q.push({x-1,y,l-1});
            visited[x-1][y]=1;
        }
        if(valid(x+1,y) && down(x,y) && up(x+1,y) && visited[x+1][y]==0){
            q.push({x+1,y,l-1});
            visited[x+1][y]=1;
        }
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>row>>col>>X>>Y>>L;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>ma[i][j];
                visited[i][j]=0;
            }
        }
        if(ma[X][Y]>0){
            cout<<solve(X,Y,L)<<endl;
        }
        else cout<<0<<endl;
 
    }
}
