#include <bits/stdc++.h>
using namespace std;

int n;

int solve(vector<int> arr, int start, int end, int times)
{
    int count = 0;
     for(int i = start; i < end; i ++ )
     {
         int temp = i;
         
         int digitCount[10] = {0};
         
         while(temp)
         {
             digitCount[temp%10] ++ ;
             temp /= 10;
         }
         int curCount = 0;
         
         for( int i = 0; i < n ; i ++ )
         {
             curCount += digitCount[arr[i]];
         }
         if( curCount >= times)
            count++;
     }
     return count;
}

int main()
{
    int t, start, finish, times;
    
    vector<int> arr;
    cin >> t;
    
    while(t--)
    {
        cin >> start >> finish >> times;
        cin >> n; 
        int x;
        for(int i = 0; i < n ; i ++ )
        {
            cin >> x;
            arr.push_back(x);
        }
        cout<<"Number of omnious numbers : " << solve( arr, start, finish, times);
    }
}
