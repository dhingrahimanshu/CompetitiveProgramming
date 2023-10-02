class Solution {
public:
    bool winnerOfGame(string colors) {
        int count=0 , count2 =0;
        int n = (int)colors.size();
        
        for(int i =0 ;i<n;){
            int j = i;
            while(j<n && colors[i]==colors[j]){
                j++;
            }
            if(colors[i]=='A'){
                count+= max(0 , j-i -2);
            }else{
                count2+=max(0 , j -i -2);
            }
            i = j;
        }
        if(count2>=count){
            return false;
        }
        return true;


    }
};
