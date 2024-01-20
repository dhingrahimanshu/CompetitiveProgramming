class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        bool flag = next_permutation(s.begin() , s.end());
        if(flag){
            long long a = stoll(s);
            if(a>=(1ll<<32 -1))return-1;
            return a;
        }
        
        return -1;
    }
};
