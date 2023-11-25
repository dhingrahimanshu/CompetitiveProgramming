class Solution{
	public:
	void shuffleArray(int arr[],int n)
	{   
	    if(n==2)return;
	    int m = n/2;
	    
	    for(int i =1 ;i<n;i++){
	        int curpos = i;
	        int curnum = arr[i];
    	    while(curnum>0){
    	       if(curpos<m){
    	           int temp = arr[2*curpos];
    	           arr[2*curpos] = -curnum;
    	           curnum = temp;
    	           curpos*=2;
    	       }else{
    	           int temp = arr[2*(curpos-m) +1];
    	           arr[2*(curpos-m) +1] = -curnum;
    	           curnum = temp;
    	           curpos = 2*(curpos-m) +1;
    	       }
    	    }
	    }
	    for(int i=0 ;i<n;i++){
	        arr[i] = abs(arr[i]);
	    }
	}
};
