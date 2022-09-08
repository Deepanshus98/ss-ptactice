#include<iostream>
#define ac <bits/stdc++.h>
#include ac
using namespace std;
int grid[15][15];
int X[4]={1,-1,0,0};
int Y[4]={0,0,-1,1};
struct Node{
    int x;
    int y;
};
Node bk;                
Node aj;
int x,y;
Node grr,grx;
int sol(int r, int c, int grid[][15])
{ 
    queue<Node> QG,QE;
      
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j] == 3)
            {
                aj.x=i;
                aj.y=j;
                QE.push(aj);
                if(i==0 || j==0 || (i==r-1) || j==c-1)
                    return 1;
            }
            else if(grid[i][j] == 2)
                bk.x=i;
                bk.y=j;
                QG.push(bk);
          
        }
    }
    if(QE.size() == 0)
        return -1;
    int ans = 1;
    while(!QE.empty())
    {
        ans++;
        int lG = QG.size(), lE = QE.size();
        //GAS spread 
        for(int i=0;i<lG;i++)
        {
            Node rty = QG.front();
            x=rty.x;
            y=rty.y;
            QG.pop();
              
            for(int j=0;j<4;j++)
            {
                int xx = x+X[j], yy = y+Y[j];
                if(xx<r && xx>=0 && yy>=0 && yy<c && (grid[xx][yy]==0 || grid[xx][yy]==3) )
                {
                    grid[xx][yy] = 2;
                    grr.x=xx;
                    grr.y=yy;
                    QG.push(grr);
                }
            }
        }
        //ETHAN spread
        for(int i=0;i<lE;i++)
        {
            Node rtx = QE.front();
            x=rtx.x;
            y=rtx.y;
            QE.pop();
              
            for(int j=0;j<4;j++)
            {
                int xx = x+X[j], yy = y+Y[j];
                if(xx<r && xx>=0 && yy>=0 && yy<c && (grid[xx][yy]==0) )
                {
                    grid[xx][yy] = 3;
                    grx.x=xx;
                    grx.y=yy;
                    QE.push(grr);
                    if(xx == 0 || xx == r-1 || yy == 0 || yy == c-1)
                    {
                        return ans;
                    }
                }
                  
            }
        }
    }
      
    return -1;
      
}
  
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int r,c;
        cin>>r>>c;
          
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>grid[i][j];
         
                  
        int ans = sol(r,c,grid);
         
            cout<<ans<<endl;
    }
    return 0;
}
