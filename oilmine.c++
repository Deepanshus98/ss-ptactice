#include <bits/stdc++.h>
using namespace std;

int companies, mines, ANS;


void calculateOilMines(int i, vector<int> oilMines, vector<int> visited, int minV, int maxV, int sum,
                        int nodes, int &ANS){
    // Base Case
    if(visited[i]){
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);

        if(nodes == companies - 1){
            ANS = min(ANS, newMax - newMin);
        }
        return;
    }

    // Main Case
    visited[i] = 1;
    int j = (i + 1) % mines;

    calculateOilMines(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ANS);

    int newMin = min(sum, minV);
    int newMax = max(sum, maxV);

    calculateOilMines(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ANS);

    visited[i] = 0;
    return;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		cin >> companies >> mines;
		vector<int> oilMines(mines+1);
		vector<int> visited(mines + 1);

		for(int i=0; i<mines; i++){
            cin >> oilMines[i];
            visited[i] = 0;
        }
			
        ANS = INT_MAX;    
        for(int i=0; i<mines; i++)
            calculateOilMines(i, oilMines, visited, INT_MAX, INT_MIN, 0, 0, ANS);  

		cout << ANS <<endl;		
	}
	return 0;
}
