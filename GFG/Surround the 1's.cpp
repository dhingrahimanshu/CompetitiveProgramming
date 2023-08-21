class Solution {
public:
    bool isvalid(int i , int j , int n , int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    int Count(vector<vector<int> >& matrix) {
        int ans =0;
        int n = (int) matrix.size();
        int m = (int) matrix[0].size();
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ; j<m;j++){
                int count=0;
                if(matrix[i][j]==0)continue;
                for(int k =-1;k<=1;k++){
                    for(int q =-1;q<=1;q++){
                        int x = i+k;
                        int y = j +q;
                        if(!isvalid(x ,y ,n , m))continue;
                        count+=(matrix[x][y]%2==0);
                    }
                }
                if(count && count%2==0)ans++;
            }
        }
        return ans;
        
    }
};
