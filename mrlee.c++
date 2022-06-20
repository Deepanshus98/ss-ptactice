Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.
Example of Input
3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0
Example of Output
30
18
CUSTOM - 31 <- 4
*/
#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int N, result;

void minCostMrLee(vector<vector<int>> arr, vector<bool> visited, int count, int cost, int src){
    // Base Case
    if(count == N-1){
    	/* Corner Case if no path exists from last city */
        if(arr[src][0] != 0)
        	result = min(result, cost + arr[src][0]);
        return;
    }
    
    // Main Case
    for(int i=0; i<N; i++){
        if(!visited[i] && arr[src][i] != 0){
            visited[i] = true;
            minCostMrLee(arr, visited, count + 1, cost + arr[src][i], i);
            visited[i] = false;
        }
    }
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> N;
		vector<vector<int>> arr(N,vector<int>(N));
        vector<bool> visited(N);
		
        for(int i=0; i<N; i++){
            visited[i] = false;
			for(int j=0; j<N; j++){
				cin >> arr[i][j];
			}
		}
		
        result = INT_MAX;    
        
        visited[0] = true;
        
        minCostMrLee(arr, visited, 0, 0, 0);
        result != INT_MAX ? cout << result << "\n" : cout << "-1\n";
	}
	return 0;
}
