#include <iostream>
//for INT_MAX
#include <limits.h>

using namespace std;
int main(){
    int marks[]={23,43,55,23,56};
    int size=5;
    //INT_MAX is for +infinity
    int smallest= INT_MAX;
    int largest= INT_MIN;
    


    for(int i=0;i<size;i++){
        if(marks[i]<smallest){
            smallest=marks[i];
        }
    }
    cout<<smallest<<endl;
    
        
  


   



    return 0;
    
}