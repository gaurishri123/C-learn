//FINDING THE Nth SQUARE ROOT OF A NUMBER
#include<bits/stdc++.h>
using namespace std;

//function to find the multiplication of a number m times
//example=double number=2, m=3 therefore ans=2*2*2 that is 8
double multiply(double number, int m){
    double ans=1.0;
    for(int i=i; i<=m; i++){
        ans=ans*number;

    }
    return ans;
}


//supppose n=27 and m=3 so we have to find the 3rd root of 27 which is 3
double getNthRoot(int n, int m){
    double low=1;
    double high=n;
    double eps=1e-6; //6 decimal places
    
    //this while loop stops when the answer is accurate upto 5 decimal places
    /*that is if the difference between high and low is greater after 
    5 decimal places that is the difference lies at the 6th decimal place, the loop stops*/

    while((high-low)>eps){
        double mid=(low+high)/2.0;
        if(multiply(mid,m)<n){
            low=mid;
        }
        else{
            high=mid;
        }
    }  
    cout<<low<<" "<<high<<endl;

}

/*in this code we are trimming down the search space and at one point
 the search space will be so small that the difference will be 
  accourate till 5 decimal places*/ 