//finding missing number in an array (optimal solution #1)
#include <bits/stdc++.h>
using namespace std;

int missingNumber(int arr[],int n){
    int sum=n*(n+1)/2;
    int s2=0;
    for(int i=0; i<n-1;i++){  /*i<n-1 since the array size is n
                                and we usually put <n elements but here 
                                we can put only n-1 elements since 1 element 
                                is missing*/
        s2+=arr[i];

    }
    return sum-s2;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    int result= missingNumber(arr,n);
    cout<<result;
    return 0;
}