class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second; 
            }
    
            return a.first > b.first; 
        }
    };
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

        int n = (int) nums.size();
        int q = (int) queries.size();
        
        int ans = 0;

        sort(queries.begin(), queries.end());
        
        int j = 0;
        int pow = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for (int i = 0; i < n; i++) {

            
            while(pq.size() && pq.top() <= i) {
                pq.pop();
            }
            
            while(pq2.size() && pq2.top() <= i) {
                pq2.pop();
                pow--;
            }

            
            while(j < q && queries[j][0] <= i) {
                pq.push(queries[j][1] + 1);
                j++;
            }

            

            while (pow < nums[i] && pq.size()) {
                int ending = pq.top(); 
                if (ending <= i) break;
                pq.pop();
                pq2.push(ending);
                pow++;
                ans++;
            }
            
            if (pow < nums[i]) {
                // cout << "UF" << endl;
                return -1;
            }
            
        }
        
        return q - ans;
    }
};
