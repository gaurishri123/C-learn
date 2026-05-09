//RETURN THE REPEATING AND MISSING NUMBERS WHEN AN INTEGER VALUE IS GIVEN
//In this question, only one number will be missing and one number will be repeating

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION

vector<int> missingRepeating(vector<int> &arr, int n){
    int missing=-1;
    int repeating=-1;
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[j]==i){
                cnt++;
            }
        }
        if(cnt==2) repeating=i;
        else if(cnt==0) missing=i;

        if(missing != -1 && repeating!=-1){
            break;     
        }

    }
    return {missing,repeating};
}

//BETTER APPROACH
//Using a hash array of size n+1 and then iterating through it

vector<int> missingRepeating2(vector<int> &arr, int n){
    int hash[n+1]={0}; //assigning every element in hash array to be zero
    for(int i=0; i<n; i++){
        hash[arr[i]]++;  //this will increase the count of elements appearing in the hash array from 0
    }
    int missing=-1, repeating=-1;

    //iterating through the hasharray

    for(int i=1; i<=n; i++){
        if(hash[i]==2) repeating=i;
        else if(hash[i]==0) missing=i;

        if(missing!=-1 && repeating!=-1){
            break;
        }
    }
    return{repeating,missing};
}

//OPTIMAL SOLUTION
//MATHS USE

vector<int> missingRepeating(vector<int> &arr, int n){
    //x=repeating
    //y=missing
    //two equations two variables
    //S-Sn=x-y;
    //S2-S2n= x^2-y^2
    
    long long Sn= (n*(n+1))/2;
    long long S2n= (n*(n+1)*(2*n+1))/6;
    long long S=0;
    long long S2=0;
    for(int i=0; i<n; i++){
        S+=arr[i];
        S2+=((long long)arr[i]* (long long)arr[i]);
    }
    long long val1=S-Sn; //x-y
    long long val2=S2-S2n; //x^2-y^2= (x+y)(x-y)
    val2=val2/val1; //x+y
    long long x= val1+val2/2;
    long long y= x-val1;
    return {(int) x, (int) y};

}