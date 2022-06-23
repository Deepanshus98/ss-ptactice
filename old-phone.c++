#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int>working;
vector<int>operations;
int answer=INT_MAX;
int n,m,o;
int eval(int prev,int curr,int op){
	if(prev==-10000000){
		return curr;
	}
	
	if(op==1){
		return prev+curr;
	}
	if(op==2){
		return prev-curr;
	}
	if(op==3){
		return prev*curr;
	}
	if(op==4){
		if(curr==0){
			return -1;
		}
		else{
			return prev/curr;
		}
	}
	return 0;
}
bool isDone(int prev,int curr,int Operation,int target){
	if(Operation==4 && curr==0){
		return false;
	}
	if(eval(prev,curr,Operation)==target)
		return 1;
	return false;
}
void findMinTouch(int prev,int curr,int ooperation,int tou,int t)
{   if(ooperation!=-1 && curr!=-10000000)
{
	bool k=isDone(prev,curr,ooperation,t);
	if(k && tou<o  )
	{
		if(answer>tou+1)
		answer=tou+1;
	}
}
if(prev==t && tou<o && ooperation !=-1 && curr==-10000000)
{
	answer=min(answer,tou);
}
if(ooperation==-1 && curr==t && tou<o )
{
	answer=min(answer,tou);
}
if(tou>o) return ;
for(int i=0;i<m;i++)
{
	if(curr==-10000000)
	break;
	if(curr==0 && ooperation==4) continue;
	int val=eval(prev,curr,ooperation);
	findMinTouch(val,-10000000,operations[i],tou+1,t);
}
for(int i=0;i<n;i++)
{
	if(curr==-10000000)
	{
		findMinTouch(prev,working[i],ooperation,tou+1,t);
	}
	else
	{
		int val=abs(curr);
		val=val*10+working[i];
		if(curr<0){
			val*=-1;
		}
		findMinTouch(prev,val,ooperation,tou+1,t);
	}
}
}
int main(){
	int t;
	cin>>t;
	int count = 0;
	while(t--){
		answer=INT_MAX;
		cin>>n>>m>>o;
		working.resize(n + 2);
		for(int i=0;i<n;i++){
			cin>>working[i];
		}
		operations.resize(m + 2);
		for(int i=0;i<m;i++){
			cin>>operations[i];
		}
		int target;
		cin>>target;
		
		findMinTouch(-10000000,-10000000,-1,0,target);
		count++;
		cout<<"#" << count << ": " << answer<<endl;
	}
	return 0;
}
