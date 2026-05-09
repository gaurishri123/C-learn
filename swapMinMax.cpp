#include <iostream>
#include <limits.h>
using namespace std;

void reverse(int arr[], int sz){
    int largest= INT_MIN;
    int smallest= INT_MAX;

    for(int i=0; i<sz; i++){
        largest= max(arr[i], largest);
        smallest= min(arr[i], smallest);
    }


}
int main(){
    
}