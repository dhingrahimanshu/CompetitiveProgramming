class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char lastTaken = 'd';
        priority_queue <pair<int,char>> pq;

        vector<int> arr= {a, b, c};

        for (int i = 0;i<3;i++) {
            if (arr[i]) {
                pq.push({arr[i], (char)i + 'a'});
            }
        }
        

        string ans;
        while(pq.size()) {
            pair<int,char> node = pq.top();
            // cout << pq.size() << ' ' << node.second << ' ' << lastTaken << endl;
            if (pq.size() == 1 && node.second == lastTaken) {
                break;
            }
            pq.pop();
            int shouldTake = 2;
            if (node.second == lastTaken) {
                pair<int,char> node2 = pq.top(); pq.pop();
                pq.push(node);
                node = node2;
                shouldTake = 1;
            }
            int taken = min(shouldTake, node.first);
            node.first -= taken;
            if (node.first) {
                pq.push(node);
            }
            lastTaken = node.second;

            string st(taken, node.second);
            ans += st;
        }
        return ans;
    }
};
