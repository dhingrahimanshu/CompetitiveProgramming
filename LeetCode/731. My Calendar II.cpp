class MyCalendarTwo {
public:
    multiset <pair<int,int>> arr;
    MyCalendarTwo() {
        
    }
    bool check () {
        int interval = 0;

        for (auto & it : arr) {
            if (it.second == -1) {
                interval--;
            } else {
                interval++;
            }
            if (interval == 3) return false;
        }

        return true;
    }
    
    bool book(int start, int end) {
        arr.insert({start, 1});
        arr.insert({end, -1});
        bool ans = check();
        if (!ans) {
            arr.erase(arr.find({start, 1}));
            arr.erase(arr.find({end, -1}));
        }
        return ans;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
