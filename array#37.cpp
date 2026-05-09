//rearranging the array by sign
//if number of positives are not equal to number of negatives
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &arr, int n){
    vector<int> pos,neg;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size()>neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[i*2]=pos[i];
            arr[(i*2)+1]=neg[i];
        }
        int index= neg.size()*4;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index]=pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[i*2]=pos[i];
            arr[(i*2)+1]=neg[i];
        }
        int index= pos.size()*4;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index]=neg[i];
            index++;
        }
        
    }

    return arr;


}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> result= rearrange(arr,n);
    for(int x:result) {
        cout<<x<<" ";
    }
    return 0;
}