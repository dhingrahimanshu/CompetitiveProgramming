vector<int> pendulumArrangement(int arr[], int n) {
    vector<int> ans;
    sort(arr, arr+n);
    int o = n-1;
    if(n%2==0){
        o--;
    }
    for(int i = o;i>0;i-=2){
        ans.push_back(arr[i]);
    }
    
    ans.push_back(arr[0]);
    for(int i = 1;i<n;i+=2){
        ans.push_back(arr[i]);
    }
    return ans;
}
