int minimumoperationpalindrome(int arr[],int n){
    int n=arr.size()-1;
    int ans=0;
    for(int i=0;i<n;i<=j){
    if(arr[i]==arr[j]){
        i++;j++;
    }else if(arr[i]>arr[j]){
        j--;
        arr[j]+=arr[j+1];
        ans++;
    }else{
        i++;
        a[i]+=arr[i-1];
        ans++;
    }return ans;
}}