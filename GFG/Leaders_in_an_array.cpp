
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> arr;
        int ele =-1;
        for(int i =n-1;i>=0;i--){
            if(a[i]>=ele){
                arr.push_back(a[i]);
            }
            ele = max(ele , a[i]);
        }
        reverse(arr.begin(), arr.end());
        
        return arr;
        
    }
};

