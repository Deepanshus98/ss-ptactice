#include<iostream>
using namespace std;
#define MAX 100000
bool arr[10];
  
int helper(int num){
    int temp = num;
    bool numPresent = true;
    int count = 0;
    while (temp > 0){
        int digit = temp % 10;
        temp = temp / 10;
        count++;
        if (arr[digit] == false){
            numPresent = false;
            break;
        }
    }
    if (numPresent)
        return count;
  
    int ans=MAX;
    count=0;
    for (int i = 2; i*i <= num; i++){
        if (num%i == 0){
            int a = helper(num / i);
            int b = helper(i);
            if (a<MAX && b<MAX){
                count= a + b + 1;
                if(count<ans){
                    ans=count;
                }
            }           
        }
    }
    return ans;
}
  
int main(int argc, char** argv){
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;
    int num;
    for (test_case = 1; test_case <= T; ++test_case){
        for (int i = 0; i < 10; i++){
            cin >> arr[i];
        }
  
        cin >> num;
        int res = 0;
        res = helper(num) + 1;
        if (res > MAX)
            res = -1;
        cout << "#" << test_case << " " << res << endl;
    }
  
    return 0;
}
