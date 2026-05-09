//Finding the sorted Union (brute force approach)
#include <bits/stdc++.h>
using namespace std;

vector <int> sortedArray(vector<int> a, vector<int> b){
    int n1= a.size();
    int n2= b.size();

    set<int> st;

    for(int i=0; i<n1; i++){
        st.insert(a[i]);
    }

    for(int i=0; i<n2; i++){
        st.insert(b[i]);
    }

    vector<int> temp;  /*set is converted into vector because function 
                            return type is vector*/

    for(auto it:st){
        temp.push_back(it);
    }

    return temp;
}

int main(){
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    vector<int> a(n1);
    for(int i=0; i<n1; i++){
        cin>>a[i];
    }
    vector<int> b(n2);
    for(int i=0; i<n2; i++){
        cin>>b[i];
    }
    vector<int> v=sortedArray(a,b);
    for(int x:v){
        cout<<x<<" ";
    }
    
    return 0;

}