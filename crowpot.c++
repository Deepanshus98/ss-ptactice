/*
Problem Statement

There are N pots. Every pot has some water in it. They may be partially
filled. So there is a Overflow Number O associated with every pot which tell how many minimum stone pieces are require for that pot to overflow. So if for a pot O-value is 5 it means minimum 5 stone pieces should be put in that pot to make it overflow.

Initially a crow watched those pots and by seeing the water level he anticipated O-value correctly for every pot (that is he knew O1 to On). But when he came back in evening he found that every pot is painted from outside and he is not able to know which pot has what O-value. The Crow wants some K pots to overflow so that he can serve his child appropriately. For overflowing the pots he needs to search for the stones in forest (assume that every stone has same size).

He wants to use minimum number of stones to overflow the K pots. But he doesn't know now which pot has what O-value. So the task is to find out the minimum number of stones that the crow requires to make the K pots overflow in the worst case.

Input Specification:

A array O corresponding to O-value of N pots {O1, O2, ....... , On}
Number of pots
K -value ( number of pots which the crow wants to overflow)
Output Specification:

Minimum number of stones required to make K pots overflow in worst case or -1 if input is invalid.

Example:

Let's say there are two pots:

Pot 1 has O value of 5 , O1= 5
Pot 2 has O value of 58, O2= 58
Let's say the crow wants to make one of the pots overflow. If he knows which pot has what O-value he would simply search for 5 stones and put them in pot 1 to make it overflow. But in a real case he doesn't know which pot has what O-value so just 5 stones may not always work. However he does know that one pot has O-value 5 and other has 58. So even in the worst case he can make one of the pot overflow just by using 10 stones. He would put 5 stones in one pot if it doesn't overflow he would try the remaining 5 in the other pot which would definitely overflow because one of the pot has O-value of 5. So the answer for above question is minimum 10 stones even in worst case.
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
long long solve(int arr[], int n, int p)
{
    long long ans = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=p;j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int z=1; z<=p;z++)
        {
            if(z==1)
            {
                dp[i][z] = (n-i+1)*arr[i];
                continue;
            }
            for(int k = i+1;k<=n;k++)
            {
                dp[i][z] = min(dp[i][z], dp[k][z-1] + arr[i]*(k-i));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans = min(ans, dp[i][p]);
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int over[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>over[i];
        }
        sort(over+1, over+n+1);
        cout << solve(over, n, k)<<endl;
    }
    return 0;
}
