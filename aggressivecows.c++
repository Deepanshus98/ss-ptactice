#include <bits/stdc++.h>
using namespace std;
bool comperator(int m,int n,int k,int arr[]){
    int largest=0;
    int count=1;
    for(int i=1;i<n;++i){
        if(arr[i]-arr[largest]>=m){
            largest=i;
            ++count;
            if(count==k){
                return true;
        }
        }
        
    }
    return false;
}
int main()
{   int t;
    cin>>t;
    for(int i=0;i<t;++i){
        int n,k;
        cin>>n>>k;
        int arr[100000];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);
        int l=arr[0];
        int r=arr[n-1]-arr[0]+1;
        while(r-l>0){
            int m=(l+r+1)/2;
            if(comperator(m,n,k,arr)){
                l=m;
            }
            else{
                r=m-1;
            }
            
        }
        cout<<l<<'\n';
        
        
    }

    return 0;
}
