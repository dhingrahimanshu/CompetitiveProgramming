class Solution{
public:
	static bool mycmp(string & s , string &s2){
	    return (s + s2) > (s2 + s);
	}
	string printLargest(int n, vector<string> &arr) {
	    string ans;
	    sort(arr.begin() , arr.end() , mycmp);
	    for(auto & it : arr){
	        ans +=it;
	    }
	    return ans;
	}
};
