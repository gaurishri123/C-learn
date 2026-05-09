#include <iostream>
//for INT_MAX
#include <limits.h>

using namespace std;
int main(){
    int marks[]={23,43,55,23,56};
    int size=5;
    //INT_MAX is for -infinity
    
    int largest= INT_MIN;
    


    for(int i=0;i<size;i++){
        if(marks[i]>largest){
            largest=i;//printing the index of the largest number
        }
    }
    cout<<largest<<endl;
    
        
  


   



    return 0;
    
}