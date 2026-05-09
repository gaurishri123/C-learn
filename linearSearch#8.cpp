#include <iostream>
using namespace std;

 int linearSearch(int arr[], int sz, int target){
    for(int i=0; i<sz; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
 }
 

int main(){
    int arr[]={74,23,54,65,23};
    int sz=5;
    int target=65;
    cout<<linearSearch(arr,sz,target)<<endl;

   return 0;
}