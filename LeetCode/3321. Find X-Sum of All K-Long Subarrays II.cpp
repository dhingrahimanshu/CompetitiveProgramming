class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        int n = (int)nums.size();

        map <long long,long long> freq;
        set <pair<long long,long long>> st, st2;
        for (int i = 0;i<k;i++) {
            freq[nums[i]]++;
        }
        for (auto & it : freq) {
            st.insert({it.second, it.first});
        }

        while (st.size() > x) {
            st2.insert(*st.begin());
            st.erase(st.begin());
        }

        
        long long sum = 0;
        for (auto & it : st) {
            // cout << it.first << ' ' << it.second << endl;
            sum += it.first * it.second;
        }

        while(st2.size() && ((*st2.rbegin()).first >= (*st.begin()).first)) {
                auto it1 = st.begin();
                auto it2 = prev(st2.end());
                if (((*it2).first > (*it1).first)) {
                    sum += (*it2).second * (*it2).first;
                    sum -= (*it1).second * (*it1).first;

                    st.insert({{(*it2).first, (*it2).second}});
                    st2.insert({(*it1).first, (*it1).second});

                    st.erase(it1);
                    st2.erase(it2);

                    
                } else { 
                    
                    if ((*it2).second > (*it1).second) {
                        sum += (*it2).second * (*it2).first;
                        sum -= (*it1).second * (*it1).first;

                        st.insert({{(*it2).first, (*it2).second}});
                        st2.insert({(*it1).first, (*it1).second});

                        st.erase(it1);
                        st2.erase(it2);

                        
                    } else {
                        break;
                    }
                }
            }

        ans.push_back(sum);

        for (int i = k; i<n;i++) {
            long long rem_element = nums[i-k];
            long long ins_element = nums[i];

            if (st.find({freq[rem_element], rem_element}) != st.end()) {
                // cout << "Hello " << rem_element << ' ';
               auto it = st.find({freq[rem_element], rem_element});
                st.erase(it);
                if (freq[rem_element] - 1 > 0) {
                    st.insert({freq[rem_element] - 1, rem_element});
                }
                
                freq[rem_element]--;
                sum -= rem_element;

            } else if(st2.find({freq[rem_element], rem_element}) != st2.end()) {
                auto it = st2.find({freq[rem_element], rem_element});
                st2.erase(it);
                if (freq[rem_element] - 1 > 0) {
                    st2.insert({freq[rem_element] - 1, rem_element});
                }
                
                freq[rem_element]--;
                
            } 
            // for (auto & it : st) {
            //     cout << it.first << ' ' << it.second << endl;
            // }
            // cout << endl;
            if (st.size() < x || st.find({freq[ins_element], ins_element}) != st.end()) {

                if (st.find({freq[ins_element], ins_element}) == st.end()) {
                    st.insert({freq[ins_element] + 1, ins_element});

                    if (st2.find({freq[ins_element], ins_element}) != st2.end()) {
                        st2.erase({freq[ins_element], ins_element});
                    }
                    sum += (freq[ins_element] + 1) * ins_element;
                } else {
                    auto it = st.find({freq[ins_element], ins_element});

                    st.erase(it);

                    st.insert({freq[ins_element] + 1, ins_element});
                    sum += ins_element;
                }
                
                freq[ins_element]++;
                
            } else {
                if (st2.find({freq[ins_element], ins_element}) == st2.end()) {
                    st2.insert({1, ins_element});
                    freq[ins_element]++;
                } else {
                    auto it = st2.find({freq[ins_element], ins_element});
                    st2.erase(it);
                    st2.insert({freq[ins_element] + 1, ins_element});
                    freq[ins_element]++;
                }
                
            }

            while(st.size() < x && st2.size()) {
                auto a = *prev(st2.end());
                st.insert({a.first, a.second});
                sum += a.first * a.second;
                st2.erase(a);
            }
            

            while(st2.size() && ((*st2.rbegin()).first >= (*st.begin()).first)) {
                auto it1 = st.begin();
                auto it2 = prev(st2.end());
                if (((*it2).first > (*it1).first)) {
                    sum += (*it2).second * (*it2).first;
                    sum -= (*it1).second * (*it1).first;

                    st.insert({{(*it2).first, (*it2).second}});
                    st2.insert({(*it1).first, (*it1).second});

                    st.erase(it1);
                    st2.erase(it2);

                    
                } else { 
                    
                    if ((*it2).second > (*it1).second) {
                        sum += (*it2).second * (*it2).first;
                        sum -= (*it1).second * (*it1).first;

                        st.insert({{(*it2).first, (*it2).second}});
                        st2.insert({(*it1).first, (*it1).second});

                        st.erase(it1);
                        st2.erase(it2);

                        
                    } else {
                        break;
                    }
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
