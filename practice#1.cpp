//SEARCHING ELEMENTS IN A ROTATED SORTED ARRAY WITHOUT DUPLICATES

int binarySearch(int arr[], int n, int target){
    int low=0; 
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        
}