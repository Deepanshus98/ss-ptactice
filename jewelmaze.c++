#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#define MAX 21
using namespace std;

int n, ans;

bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}
int dirX[] = {1,0,-1,0};
int dirY[] = {0,1,0,-1};
void jewelMaze(vector<vector<int>> &maze, int x, int y, int value, vector<vector<int>> &visited,vector<vector<int>> &path){
	if(x == n-1 && y == n-1){
		if(value >= ans){
			ans = value;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++)
				    if(visited[i][j]){
				    	path[i][j] = 3;
					}
					else{
						path[i][j] = maze[i][j];
					}	
			}
		}
		return;
	}
	for(int i=0; i<4; i++){
		int newX = x + dirX[i];
		int newY = y + dirY[i];
		if(isValid(newX, newY)){
			if(visited[newX][newY] == 0 && maze[newX][newY] == 0){
				visited[newX][newY] = 1;
				jewelMaze(maze, newX, newY, value, visited, path);
				visited[newX][newY] = 0;
			}
			if(visited[newX][newY] == 0 && maze[newX][newY] == 2){
				visited[newX][newY] = 1;
				jewelMaze(maze, newX, newY, value+1, visited, path);
				visited[newX][newY] = 0;
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		vector<vector<int>> maze(n+1,vector<int>(n+1));
		vector<vector<int>> visited(n+1,vector<int>(n+1));
		vector<vector<int>> path(n+1,vector<int>(n+1));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> maze[i][j];
				visited[i][j] = 0;
				path[i][j] = 0;
			}
		}
		ans = INT_MIN;
		int sX = 0, sY = 0;
		visited[sX][sY] = 1;
		if(maze[sX][sY] == 2)
			jewelMaze(maze, sX, sY, 1, visited, path);
		else
			jewelMaze(maze, sX, sY, 0, visited, path);	
		cout << "Jewel collected : " << ans << endl;
		cout << "Path traversed --> " << endl;
		for(int i=0; i<n; i++){
		    for(int j=0; j<n; j++)
			    cout << path[i][j] << " ";	
		    cout << endl;
	}
		cout << endl;
	}
	return 0;
}
