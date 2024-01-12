class Solution
{
    public:
    void reverse(queue<int> &q , int k){
        if(k==0)return ;
        int data = q.front(); 
        q.pop();
        reverse(q , k-1);
        q.push(data);
    }
    queue<int> modifyQueue(queue<int> q, int k) {
        reverse(q ,k);
        for(int i =0 ;i<q.size() - k;i++){
            int data = q.front();
            q.pop();
            q.push(data);
        }
        return q;
    }
};
