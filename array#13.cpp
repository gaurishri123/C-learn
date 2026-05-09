//optimal solution of sorted union array
#include <bits/stdc++.h>
using namespace std;

vector<int> sorted_array(vector<int> a, vector<int> b){
    int n1=a.size();
    int n2=b.size();
    int i=0; //initialising i
    int j=0; //initialisinh j

    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }else{
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

        }
    }

    //when i is exhausted and j is left
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
    }

    //when j is exhausted and i is left
    while(i<n1){
        if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
    }

    return unionArr;
}

int main(){
    int n1;
    cin>>n1;
    int n2;
    cin>> n2;
    vector<int> a(n1);
    for(int i=0; i<n1; i++){
        cin>>a[i];
    }
    vector<int> b(n2);
    for(int i=0; i<n2; i++){
        cin>>b[i];
    }

    vector<int> result = sorted_array(a,b);
    for(int x:result){
        cout<<x<<" ";
    }
    return 0;
}