#include <iostream>
using namespace std;

int dicTobinary(int decno){
    int ans=0;
    int pow=1;

    while(decno>0){

        int rem= decno%2;
        decno/=2;

        ans+= (rem*pow);
        pow*=10;

    }

    return ans;

}

int main(){
    int decno=10;

    cout<<dicTobinary(decno)<<endl;

    


    return 0;
}