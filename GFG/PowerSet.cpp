class Solution{
	public:
	    vector<string> ans;
	    static bool mysrt(string & s , string &s2){
	        int n = min(s.size() , s2.size());
	        for(int i =0;i<n;i++){
	            if(s[i] < s2[i]){
	                return 1;
	            }else if(s[i] >  s2[i]){
	                return 0;
	            }
	        }
	        return s.size() < s2.size();
	    }
	    void helper(string &s , int i , string &t){
	        if(i == (int)s.size()){
	            if(t.size() ==0 )return;
	            ans.push_back(t);
	            return ;
	        }
	        helper(s , i+1 , t);
	        t += s[i];
	        helper(s , i+1 , t);
	        t.pop_back();
	        
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    string t;
		    helper(s , 0 , t);
		    sort(ans.begin() , ans.end() , mysrt);
		    return ans;
		}
};
