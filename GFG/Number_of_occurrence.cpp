class Solution{
public:	
	int lower_bound(int arr[] , int n , int x){
	    int lo= 0 , hi =n;
	    int ans = n;
	    while(lo<=hi){
	        int mid = (lo + hi)/2;
	        if(arr[mid]>=x){
	            ans = min(ans , mid);
	            hi = mid -1;
	        }else{
	            lo = mid+1;
	        }
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    
	    int a = lower_bound(arr , n , x);
	    int b = lower_bound(arr , n , x+1)-1;
	    return b-a+1;
	}
};
