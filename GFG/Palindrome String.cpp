//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    
	    for(int i =0 ;i<S.size()/2;i++){
	        if(S[i]!=S[S.size() - i - 1])return false;
	    }
	    
	    return true;
	}

};
