#include <iostream>
using namespace std;

int decTobinary(int binary){
    int ans=0;
    int pow=1;
    

    while( binary>0){
        int rem= binary%10;
        ans+= rem*pow;
        binary/=10;
        pow*=2;
        
        
    }
    return ans;


}

int main(){
    int binary= 1100101;

    cout<< decTobinary(binary) << endl;

    return 0;
}