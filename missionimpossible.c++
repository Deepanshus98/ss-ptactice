#include<iostream>
#define ac <bits/stdc++.h>
#include ac
using namespace std;
char grid[15][15];
int X[4]={-1,1,0,0};
int Y[4]={0,0,-1,1};

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
        queue<pair<int,int>> QG,QE;
      
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 'S')
                {
                
                    QE.push({i,j});
                }
                else if(grid[i][j] == '*')
                    QG.push({i,j});
              
            }
        }
        int ans = 0;
        while(!QE.empty())
        {
            ans++;
            int lG = QG.size(), lE = QE.size();
            //GAS spread 
            for(int i=0;i<lG;i++)
            {
                int b=QG.front().first;
                int f=QG.front().second;
                cout<<"gas1"<<b<<f<<endl;
                QG.pop();
                  
                for(int j=0;j<4;j++)
                {
                    
                    int kk = b+X[j], tt = f+Y[j];
                    
                    if(kk<r && kk>=0 && tt>=0 && tt<c && grid[kk][tt]!='d' && grid[kk][tt]!='X' && grid[kk][tt]!='E')
                    {
                        
                        grid[kk][tt] = 'E';
                        QG.push({kk,tt});
                    }
                }
            }
            //ETHAN spread
            for(int i=0;i<lE;i++)
            {
                int e=QE.front().first;
                int l=QE.front().second;
                cout<<"ethan"<<e<<l<<endl;
                QE.pop();
                  
                for(int j=0;j<4;j++)
                {
                    int ss = e+X[j], gg = l+Y[j];
                    if(grid[ss][gg]=='d')
                        {
                             cout<<ans;
                             return 0;;
                        }
                    
                    if(ss<r && ss>=0 && gg>=0 && gg<c && grid[ss][gg]=='.' )
                    {
                        QE.push({ss,gg});
                        
                    }
                      
                }
            }
    }
         
        cout<<-1<<endl;
    }
    return 0;
}

