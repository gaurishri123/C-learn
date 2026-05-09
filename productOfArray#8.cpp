#include <iostream>
using namespace std;

int pow(int arr[], int sz){
    int pro=1;
    for(int i=0; i<sz; i++){
        pro*=arr[i];
    }
    return pro;
}

int main(){
    int arr[]={1,2,3,4,5};
    int sz=5;
    cout<<pow(arr,sz);
    return 0;
}  