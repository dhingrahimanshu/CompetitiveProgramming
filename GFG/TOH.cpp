class Solution{
    public:
    long long ans=0;
    long long toh(int N, int from, int to, int aux) {
        if(N==0){
            return ans;
        }
        toh(N-1 , from , aux , to);
        cout << "move disk " << N << " from rod " << from << " to rod " << to <<endl;
        ans++;
        toh(N-1 , aux , to , from);
    }

};
