class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(auto & it : chalk)sum+=it;
        k%=sum;
        vector<long long> temp(chalk.size(), 0);
        temp[0] = chalk[0];
        for(int i = 1;i<temp.size(); i++){
            temp[i] += temp[i-1] + chalk[ii];
        }
        long long index = upper_bound(temp.begin(), temp.end(), k) - temp.begin();
        return index;
    }
};
