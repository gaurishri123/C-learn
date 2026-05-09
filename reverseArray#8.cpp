#include <iostream>
using namespace std;


int reverse(int arr[], int sz){
    int start=0, end= sz-1;
    while(start<end){
        
        swap(arr[start],arr[end]);
        start++;
        end--;
    
    }
}

int main(){
    int arr[]={23,43,55,65,31};
    int sz=5;
    reverse(arr, sz);

    for(int i=0;i<sz;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}
