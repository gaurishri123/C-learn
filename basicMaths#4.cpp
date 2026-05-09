#include <iostream>
using namespace std;
//armstrong number
int main(){
    int n;
    int dup=n;
    cin>>n;
    int sum=0;
    while(n>0){
        int lastDigit=n%10;
        sum=sum+(lastDigit*lastDigit*lastDigit);
        n=n/10;

    }if(dup==sum){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;

}