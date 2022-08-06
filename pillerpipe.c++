#/*
You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2..
Then pillars can be,
p1 = 3 unit… Choosing element (3) from array,
Similarly p2 = 3 choosing (2 + 1) from array.
Since, two pillars are equal, we can put board on it…
But we have two maximise the height of the pillars,
And if we check for other heights, we can see p1 = 6 p2 = 4 + 2 which is greater than 3 ( the previous height)..
We have to see if we can further maximize the height… Yes it can be 8.
I.e. p1 = 6 + 2 = 8. p2 = 4 + 3 + 1 = 8.
Both pillars are equal and banner can be placed… And since this is the maximum height attainable for two pillars, we print the answer as 8. In case, there is no combination possible, print 0 (zero).

INPUT :
1
5
1 2 3 4 6
First line is  T  number of test cases to be followed.
Second line of input is number of different pillars.
Third line of input is  different available heights of pillars.
Note : heights of given pillars can be same .. I.e. array can have same elements repeated.

Output.
8
*/
include <bits/stdc++.h>
using namespace std;

int n, maxi = INT_MIN;

void solve(vector<int> arr, vector<int> vis, int p1, int p2)
{
    if( p1 == p2 )
    {
        maxi = max( maxi, p1 );    
    }
    
    for(int i = 0; i < n; i++ )
    {
        if(!vis[i])
        {
            vis[i] = 1;
             solve( arr, vis, p1 + arr[i], p2 );
             solve( arr, vis, p1, p2 + arr[i] );
            vis[i] = 0;
        }
    }
    
    
    
}
int main()
{
    int t, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        
        vector<int> arr;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i ++ )
        {
            cin >> x;
            arr.push_back(x);
        }
       
        solve(arr, vis, 0, 0);
        cout << " Maximum sum possible "<< maxi << endl;
    }
    
}
