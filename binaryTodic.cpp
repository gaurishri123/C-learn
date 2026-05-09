#include <iostream>
using namespace std;

int binaryTodecimal(int binary){
    int ans=0;
    int pow=1;

    while(binary>0){

        int rem= binary%10;
        ans+=(rem*pow);
        
        binary/=10;
        pow*=2;

    }

    return ans;

}

int main(){
    int binary=1010;

    cout<<binaryTodecimal(binary)<<endl;

    


    return 0;
}