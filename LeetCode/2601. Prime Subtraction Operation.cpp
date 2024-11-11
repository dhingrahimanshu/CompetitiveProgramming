bool flag = true;
vector<int>isPrime;
vector<int> primes;
class Solution {
public:

    void sieve() {
        isPrime.resize(1011, 0);
        isPrime[1] = 1;
        for (int i = 2; i < 1010;i++) {
            if (isPrime[i]) continue;
            primes.push_back(i);
            for (int j = 2*i; j < 1010; j+=i) {
                isPrime[j] = 1;
            }
        }
    }    
    bool primeSubOperation(vector<int>& nums) {
        if (flag) {
            sieve();
            flag = false;
        }
        

        int n = (int) nums.size();

        for (int i = n-2; i>=0; i--) {
            if (nums[i] >= nums[i+1]) {
                int req = nums[i] - nums[i+1];
                int indx = (upper_bound(primes.begin(), primes.end(), req) - primes.begin());
                if (primes[indx] >= nums[i]) {
                    return false;
                }
                nums[i] -= primes[indx];
            }
        }

        return true;
    }
};
