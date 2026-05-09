//3 sum
//returning a list of list where the sum of three elements in each list is zero
//all the lists should be unique; no duplicates

//BRUTE FORCE
//Time complexity b0(n^3)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());

                    //set stores all the unique elements
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//BETTER SOLUTION
//hashing 
//Time complexity b0(n^2)

vector<vector<int>> threeSum2(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashset;  //making the hashset empty after each movement of i
        for(int j=i+1; j<n; j++){
            int third=-(arr[i]+arr[j]);

            //finding third element in hashset
            if(hashset.find(third)!=hashset.end()){ 
                vector<int> temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            //inserting j in hashset after all the checks and then moving
            hashset.insert(arr[j]);

        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//OPTIMAL SOLUTION

vector<vector<int>> threeSum3(vector<int> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        
        //checks if the previous element is not the same as current
        //continue means the code will not proceed further and will do i++

        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }

            else{
                vector<int> temp={arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }
    }
    return ans;
}