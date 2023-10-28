class Solution
{
public:
	int is_bleak(int n)
	{
	    for(int i = n;i>=max(n-20 ,0) ; i--){
	        
	        if((i +  __builtin_popcount(i))==n){
	            return 0;
	        }
	    }
	    
	    return 1;
	}
};
