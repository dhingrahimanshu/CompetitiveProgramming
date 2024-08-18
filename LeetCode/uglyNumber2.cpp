class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;

        int nextTwo = 0, nextThree =0, nextFive = 0;
        // int nextMultipleOfTwo = 2, nextMultipleOfThree = 3, nextMultipleOfFive 5;
        for(int i = 1;i<n;i++){
            int a = uglyNumbers[nextTwo] * 2;
            int b = uglyNumbers[nextThree] * 3;
            int c = uglyNumbers[nextFive] * 5;
            int curUgly = min({a,b,c});
            
            if(a == curUgly){
                uglyNumbers[i] = a;
                nextTwo++;
            }
            if(b == curUgly){
                uglyNumbers[i] = b;
                nextThree++;
            }
            if((c == curUgly)){
                uglyNumbers[i] = c;
                nextFive++;
            }
        }

        return uglyNumbers[n-1];
    }
};
