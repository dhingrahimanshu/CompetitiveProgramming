class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int i =0 , j =0;
	    
	    while(j<n){
	        while(i<n && arr[i]){
	            i++;
	        }
	        j = max(j , i);
	        while(j<n && arr[j]==0){
	            j++;
	        }
	        if(j>=n)break;
	        swap(arr[i] , arr[j]);
	        
	    }
	}
};
