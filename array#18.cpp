//finding missing number (optimal solution #2)
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &arr, int N){
    int n= N-1;
    int xor1=0;   //for example missing number is 3 from 1 to 5
    int xor2=0;
    for(int i=0; i<n; i++){
        xor2=xor2^arr[i]; //1^2^4^5
        xor1= xor1^(i+1);//1^2^3^4
    }
    xor1= xor1^N; //xor1^5
    return xor1^xor2;
}

int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N-1; i++){
        cin>>arr[i];
    }
    int result= missingNumber(arr,N);
    cout<<result;
    return 0;
    
}