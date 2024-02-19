class Solution{
public:
    int minValue(string s, int k){
        vector<int> hash(26 ,0);
        for(auto & it : s){
            hash[it-'a']++;
        }
        priority_queue <int> pq;
        for(auto & it : hash){
            if(it==0)continue;
            pq.push(it);
        }
        while(pq.size() && k){
            int a = pq.top();pq.pop();
            a--;
            if(a){
                pq.push(a);
            }
            k--;
            // cout << a <<endl;
        }
        int ans =0;
        while(pq.size()){
            int a = pq.top(); pq.pop();
            // cout << a <<endl;
            ans += (a*a);
        }
        
        return ans;
    }
};
