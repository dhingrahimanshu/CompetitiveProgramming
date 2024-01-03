class Solution{
public:
    stack<int>uf;
    void Reverse(stack<int> &St){
        if(St.size()==0){
            St = uf;
            return;
        }
        uf.push(St.top()); St.pop();
        Reverse(St);
    }
};
