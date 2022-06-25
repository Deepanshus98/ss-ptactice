#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};

int n, sX, sY, tX, tY; 
int mat[105][105], dis[105][105], vis[105][105];


int dirX[] = {1,0,-1,0};
int dirY[] = {0,1,0,-1};

bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}

void calculateFrogJump(){
    queue<Point> myq;
    Point e;
	e.x = sX;
	e.y = sY;
	vis[sX][sY] = 1;
	dis[sX][sY] = 0;
    myq.push(e);
	while(!myq.empty()){
	    Point b;
	    b=myq.front();
	    myq.pop();
		int p = b.x;
		int q = b.y;
		for(int i=0; i<4; i++){
			int newX = p + dirX[i];
			int newY = q + dirY[i];

			if(isValid(newX, newY) && mat[newX][newY] == 1 && vis[newX][newY] == 0){
				/* Horizontal Cost */
				
				if(i == 0 || i == 2){
					dis[newX][newY] = dis[p][q];
 				}
				else if(i == 1 || i == 3){
					dis[newX][newY] = 1 + dis[p][q];
				}
				Point e;
            	e.x = newX;
            	e.y = newY;
            	vis[newX][newY] = 1;
                myq.push(e);
			}
		}
	}
	cout << dis[tX][tY];
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
			vis[i][j] = 0;
			dis[i][j] = 0;
		}
	}

	cin >> sX >> sY >> tX >> tY;

	calculateFrogJump();
	return 0;
} 
