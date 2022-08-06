/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.
Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them
Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1
Output - 
1
2
2
12
15
4
*/

#include <bits/stdc++.h>
using namespace std;

struct E{
    int x,y;
}elem[5];

int n,num,dist[20][20];
bool M[20][20];


bool isValid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && M[x][y]==1)
        return 1;
    return 0;
}

void bfs(int x,int y){
    queue<E> q;
    bool vis[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            vis[i][j] = 0;
        }
    E n;
    n.x = x;
    n.y = y;
    vis[x][y] = 1;
    dist[x][y] = 0;
    q.push(n);
    int xx[] = {1,0,0,-1};
    int yy[] = {0,1,-1,0};
    while(!q.empty()){
       	E n = q.front();
       	q.pop();
       	//cout<<n.x<<" "<<n.y<<endl;
        //cout<<"bug"<<endl;
        for(int i=0;i<4;i++){
            int xnew = n.x+xx[i];
            int ynew = n.y+yy[i];
            if(isValid(xnew, ynew) && !vis[xnew][ynew]){
                //cout<<"bug"<<endl;
                dist[xnew][ynew] = dist[n.x][n.y]+1;
                E nn;
                nn.x = xnew, nn.y = ynew;
                vis[nn.x][nn.y] = 1;
                q.push(nn);
            }
        }
    }


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>M[i][j];
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>elem[i].x>>elem[i].y;
    int res=999999;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]==1){
                bfs(i,j);
                int ans = 0;
                for(int k=0;k<num;k++){
                    ans = max(ans,dist[elem[k].x][elem[k].y]);
                }
                res = min(res,ans);
            }
        }
    }
    cout<<res<<endl;
	return 0;
}
