//left and right rotating the array by d places
#include <bits/stdc++.h>
using namespace std;
void left_rotate(vector<int> &arr, int n, int d){
    d=d % n;  // if d is larger than the size of the array
    
    int temp[d];//declaring temp array of size d
    
    //making a temporary array and filling it up with d elements
    for(int i=0; i<d; i++){
        temp[i]=arr[i];
    }

    for(int i=d; i<n; i++){
        arr[i-d]=arr[i]; //shifting the array to the left
    }

    for(int i=n-d; i<n; i++){
        arr[i]=temp[i-(n-d)];  //filling up the temp array made before to the remaining places

    }
}

int main(){
    int n;
    cin>>n;
    int d;
    cin>>d;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    left_rotate(arr,n,d);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
    

}

//right rotation
#include<bits/stdc++.h>
using namespace std;

void rightRotation(vector<int> &arr, int n, int d){
    d=d%n;
    vector<int> temp(d);

    //storing
    for(int i=n-d; i<n; i++){
        temp[i-(n-d)]=arr[i];
    }

    //shifting
    for(int i=n-d; i>=0; i--){
        arr[i+d]=arr[i]; //to avoid rte run loop from i=n-1; i>=d; i-- --> arr[i]=arr[i-d]
    }

    //putting the temp array to the beginning
    for(int i=0; i<d; i++){
        arr[i]=temp[i];
    }
    
}