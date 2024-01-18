//User function Template for C++

class Solution{
    public:
    
    int min_sprinklers(int gallery[], int n){
        vector<pair<int,int>> arr;
        bool flag = false;
        for(int i=0 ;i<n;i++){
            if(gallery[i]==-1)continue;
            int x= max(0 , i - gallery[i]);
            int y = min(n-1 ,i + gallery[i]);
            if(y==n-1){
                flag = true;
            }
            arr.push_back({x ,y});
        }
        sort(arr.begin() , arr.end() );
        // cout << flag <<endl;
        if(arr[0].first>0 ||flag==false)return -1;
        
        int ans =0;
        int prev =0, j =0;
        for(int i =0 ;i<n;){
            if(arr[j].first > i)return -1;
            prev=i;
            while(j<(int)arr.size() && arr[j].first<=prev){
                i = max(i , 1 +arr[j].second);
                j++;
            }
            ans++;
        }
        return ans;
        
    }
};
