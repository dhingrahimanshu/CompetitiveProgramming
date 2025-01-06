
Daily Coding Challenge Completed!

Completion Streak:
91
Days
Consistency is key, see you tomorrow!
leetcoin
LeetCode Logo
Problem List
91

avatar
Premium
Debugging...
Debugging...







Run
Description
Description
Accepted
Editorial
Editorial
Solutions
Solutions
Submissions
Submissions
Code
Testcase
Testcase
Test Result
C++
Auto





202122191817232428292526273031
            if (boxes[i] == '1') {
                ballsLeft++;
                ballsRight--;
            }

            scoreLeft += ballsLeft;
            scoreRight -= ballsRight;

        }


Saved
Upgrade to Cloud Saving
Accepted
Runtime: 0 ms
Case 1
Case 2
Input
boxes =
"110"
Output
[1,1,3]
Expected
[1,1,3]
Contribute a testcase
All Submissions

Accepted
95 / 95 testcases passed
himanshu dhingra
himanshu dhingra
submitted at Jan 06, 2025 07:12

Editorial

Solution
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
11.98
MB
Beats
76.52%
Analyze Complexity
Code
C++
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector <int> ans(n, 0);

        int ballsLeft = 0, ballsRight = 0, scoreLeft = 0, scoreRight = 0;

        for (int i = n - 1; i>=0; i--) {
            scoreRight += ballsRight;
            if (boxes[i] == '1') {
                ballsRight++;
            }
        }

        for (int i = 0; i < n; i++) {
            ans[i] =  scoreRight + scoreLeft;

            

            if (boxes[i] == '1') {
                ballsLeft++;
                ballsRight--;
            }

            scoreLeft += ballsLeft;
            scoreRight -= ballsRight;

        }

        return ans;
    }
};
View more
More challenges
1217. Minimum Cost to Move Chips to The Same Position
2850. Minimum Moves to Spread Stones Over Grid
Write your notes here
Select related tags
0/5

Tag
