//Check if one string is the rotation of the another
#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE SOLUTION

//Generating all the rotations one by one and comparing them with goal

bool rotation(string &s, string &goal){
    if(s.length()!=goal.length()){
        return false;
    }
    for(int i=0; i<s.length(); i++){
        string rotated=s.substr(i)+s.substr(0,i);//this swaps the string length till i to the last of the string
        if(rotated==goal){
            return true;
        }
    }
    return false;
}

//OPTIMAL SOLUTION

bool rotateString(string &s, string &goal){
    if(s.length()!=goal.length()){
        return false;
    }

    string doubleds=s+s;
    //string::npos means not found
    //this statement returns true if the goal is found and false if not found
    
    return doubleds.find(goal)!=string::npos;
}