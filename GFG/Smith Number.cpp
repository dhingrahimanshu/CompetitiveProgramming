class Solution {
  public:
    int smithNum(int n) {
        map <int,int> stor;
        int temp = n;
        while(n && n%2==0){
            n/=2;
            stor[2]++;
        }
        int i = 3;
        for(int i = 3;i*i<=n;i+=2){
            while(n && n%i==0){
                stor[i]++;
                n/=i;
            }
        }
        if(n>1){
            stor[n]++;
        }
        
        int sum=0;
        while(temp){
            sum += temp%10;
            temp/=10;
        }
        int sum2=0;
        int count =0 ;
        for(auto it: stor){
            count+=it.second;
            int x= 0 ,temp3 = it.first;
            while(temp3){
                x += temp3%10;
                temp3/=10;
            }
            sum2+= x*it.second;
        }
        if(count==1)return 0;
        return sum==sum2;
    }
};
