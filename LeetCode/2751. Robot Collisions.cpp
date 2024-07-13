class Solution {
public:
    struct robot{
        int pos,health,oPos;
        char direction;
        robot(int pos1,int health1,int oPos1,char direction1){
            pos = pos1;
            health = health1;
            oPos = oPos1;
            direction = direction1;
        }
        void print(){
            cout << pos <<' ' << health << ' '<< direction <<endl;
        }
        bool operator<(const robot & other) const{
            return pos < other.pos;
        }
    };
    static bool mycmp(robot & p1, robot & p2){
        return p1.oPos < p2.oPos;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot> ans;
        vector<robot> arr;
        for(int i = 0;i<(int)positions.size();++i){
            robot cur(positions[i],healths[i],i,directions[i]);
            arr.push_back(cur);
        }
        sort(arr.begin(), arr.end());
        
        stack<robot> st;
        for(auto & it : arr){
            if(st.empty()){ 
                st.push(it);
            }else{
                if(it.direction == 'L'){
                    while(st.size() && st.top().direction == 'R'){
                        robot cur = st.top(); st.pop();
                        if(cur.health > it.health){
                            it.health = 0;
                            --cur.health;
                            st.push(cur);
                            break;
                        }else if(cur.health < it.health){
                            it.health--;
                            cur.health = 0;
                        }else{
                            it.health = 0;
                            break;
                        }
                    }
                    if(it.health > 0){
                        st.push(it);
                    }
                }else{
                    st.push(it);
                }
            }
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(),ans.end(),mycmp);
        vector<int> ans2;
        for(auto & it : ans){
            ans2.push_back(it.health);
        }
        return ans2;
    }
};
