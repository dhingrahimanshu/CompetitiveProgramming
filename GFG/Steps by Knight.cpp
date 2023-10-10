class Solution 
{
    public:
    
    bool isvalid(int x, int y , int n){
        if(x<0 || y<0 || x>=n || y>=n)return false;
        return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int n = N;
	    queue<pair<int,int>> pending;
	    
	    int ans =0;
	    pending.push({KnightPos[0]-1 , KnightPos[1]-1});
	    pair<int,int> target = {TargetPos[0] -1 , TargetPos[1]-1};
	    if(KnightPos[0]-1 == target.first && KnightPos[1]-1 == target.second)return 0;
	    vector<pair<int,int>> movements = {{2 , -1} , {2 , 1} , {-2 , 1} , {-2 , -1} , {1 , 2} , {-1 , 2} , {1 , -2} ,{-1 , -2}};
	    vector<vector<int>> vis;
	    vis.resize(n , vector<int>(n ,0));
	    while((int)pending.size()){
	        ans++;
	        int temp = (int)pending.size();
	        for(int i=0 ;i<temp;i++){
	            pair<int,int> co = pending.front();
	            pending.pop();
	            for(int j =0 ;j<8;j++){
	                int x = co.first + movements[j].first;
	                int y = co.second + movements[j].second;
	                if(isvalid(x , y , n)==0)continue;
	                if(vis[x][y])continue;
	                if(x==target.first && y==target.second)return ans;
	                pending.push({x ,y});
	                vis[x][y]=1;
	            }
	        }
	    }
	    return ans;
	}
};
