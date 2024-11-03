class Solution{
    public:
    int countSetBits(int n)
    {
        int pow = 2;
        int ans = 0;
        
        for (int i = 0; i < 30; i++) {
            int cycle = (n + 1) / pow;
            int setBits = cycle * (pow / 2);
            int temp = max(0, (n + 1 - (cycle * pow)) - (pow / 2));
            ans += (setBits + temp);
            pow *= 2;
        }
        
        return ans;
    }
};
