class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream s(date);
        string temp,ans;

        while(getline(s, temp, '-')) {
            bitset <16> a(stoi(temp));
            string uf = a.to_string();
            reverse(uf.begin(), uf.end());
            while(uf.size() && uf.back() == '0') uf.pop_back();
            reverse(uf.begin(), uf.end());
            ans += uf + '-';
        }
        ans.pop_back();
        return ans;
    }
};
