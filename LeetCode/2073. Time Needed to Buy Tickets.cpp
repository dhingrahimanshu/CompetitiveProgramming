class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue <pair<int,int>> q;

        for(int i =0;i< (int) tickets.size();i++){
            q.push({tickets[i] , i});
        }
        int ans =0;
        while(1){
            ans++;
            pair <int,int> f = q.front();
            q.pop();
            f.first--;
            if(f.first == 0){
                if(f.second == k){
                    return ans;
                }
            }else{
                q.push(f);
            }
        }
        return 0;
    }
};
