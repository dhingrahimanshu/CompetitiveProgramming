class segTree{
public:
    vector<int> seg;
    int size;

    segTree(){
        int n = 2e4 +1;
        size = 1;
        while(size<n){
            size*=2;
        }
        seg.resize(2*size , 0);
    }
    void set(int node , int index , int st , int en){
        if(st+1 == en){
            seg[node]++;
            return;
        }
        int mid = (st + en)/2;
        if(index < mid){
            set(2*node +1 , index , st , mid);
        }else{
            set(2*node +2 , index ,mid  , en);
        }
        seg[node] = seg[2*node +1] + seg[2*node +2];
    }
    int sum(int node, int l ,int r , int st ,int en){
        if(st>=l && en<=r){
            return seg[node];
        }
        if(l>=en || r<=st)return 0;
        int mid = (st + en)/2;
        return sum(2*node +1 , l , r , st , mid) + sum(2*node +2 , l , r , mid , en);
    }
    int sum(int r){
        return sum(0 , 0 , r , 0, size);
    }
    void set(int index){
        set(0,index , 0 , size);
    }
};


class Solution {
public:

    vector<int> countSmaller(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans;
        for(auto & it : nums){
            it+= 10000;
        }
        segTree ob;
        for(int i =n-1;i>=0;i--){
            ob.set(nums[i]);
            ans.push_back(ob.sum(nums[i]));
        }
        reverse(ans.begin() , ans.end());
        int uf =0;
        for(int i= 5;i<n;i++){
            if(nums[i]<=nums[4])uf++;
        }cout << uf <<endl;
        return ans;
    }
};
