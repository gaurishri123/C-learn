//Minimise the maximum lenght between the gas stations 
//There are k gas stations
//coordinates of gas stations are given in an array
//The elements of the array are sorted


#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach

/*Here we are running the second loop from i=0 to i=n-1 since we are counting
gaps not the elements in the array*/ 

long double minimiseTheMaximum(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);
    for(int gasStations=1; gasStations<=k; gasStations++){
        long double maxSection=-1;
        int maxInd=-1;
        for(int i=0; i<n-1; i++){
            long double diff= arr[i+1]-arr[i];
            long double sectionLength= diff/((long double) (howMany[i]+1));
            if(sectionLength>maxSection){
                maxSection=sectionLength;
                maxInd=i;  // the maxInd is the index of the sections
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns=-1;
    for(int i=0; i<n-1; i++){
        long double diff= arr[i+1]-arr[i];
        long double sectionLength=diff/((long double)(howMany[i]+1));
        maxAns=max(maxAns,sectionLength);
    }
    return maxAns;
}

//Better Solution
//Using priority queue data structure
//Priority queue has the time complexity of long N

long double minimiseTheMaximum2(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double, int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStation=1; gasStation<=k; gasStation++){
        auto tp=pq.top();pq.pop();
        int secInd=tp.second;
        howMany[secInd]++;
        long double iniDiff=arr[secInd+1]-arr[secInd];
        long double newSecLength=iniDiff/(long double)(howMany[secInd]+1);
        pq.push({newSecLength,secInd});
    }
    return pq.top().first;
}