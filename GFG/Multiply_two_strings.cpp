class Solution{
  public:
    string ito(string s1 , int x , int q){
        int car=0;
        string ans;
        for(int i =s1.size()-1 ;i>=0;i--){
            int re = car + (s1[i]-'0')*x;
            ans+= (char)(re%10 +'0');
            // cout <L< 
            car= re/10;
        }
        ans+=(char)(car + '0');
        reverse(ans.begin(), ans.end());
        
        // cout << ans <<"=" << ans.size() <<endl;
        string ff(q , '0');
        ans+=ff;
        // if(x==9){
        //     cout << q <<" " <<  ans <<endl;
        // }
        
        return ans;
    }
    string multiplyStrings(string s1, string s2) {
        int a=1;
        if(s1[0]=='-'){
           a=-1;
           s1 = s1.substr(1);
       }
       if(s2[0]=='-'){
           a*=-1;
           s2 = s2.substr(1);
       }
       if(s1.size()<s2.size()){
           swap(s1 , s2);
       }
       
    //   cout << s1 <<" " << s2 <<endl;
       
       if(s1.size()!=s2.size()){
           string uf( s1.size()-s2.size() , '0');
           s2 = uf+s2;
       }
       
    //   cout << ito("1112" , 9 , 0) <<endl;
       
       vector<string> ans;
       int ma = 0;
       for(int i =s2.size()-1;i>=0;i--){
           string temp = ito(s1 , s2[i]-'0' , s2.size() -i-1 );
           ma  =max(ma,(int) temp.size());
           ans.push_back(temp);
       }
    //   cout << ans[0] <<endl;
       for(int i=0;i<ans.size();i++){
           int x = ma - ans[i].size();
           if(x){
               string a(x , '0');
               ans[i] = a+ ans[i];
           }
           
       }
    //   for(auto it : ans){
    //       cout << it <<" ";
    //   }
    //   cout <<endl;
       int n = ans[0].size() ;
    //   cout <<"n = " << n <<endl;
       string fans;
       int car=0;
       
       for(int i =ans[0].size() -1 ;i>=0;i--){
           int x = car;
        //   cout << i <<endl;
           for(int j =0 ;j<(int)ans.size() ;j++){
            //   cout << ans[j][i] <<" ";
               x+= (ans[j][i]-'0');
           }
        //   cout << endl;
        //   cout << x <<endl;
           fans+=(char)(x%10 + '0');
           car = x/10;
       }
    //   cout << fans <<' ';
    //   cout << car <<endl;
       if(car){
           string last = to_string(car);
            reverse(last.begin(), last.end());
            fans =last +fans;
       }
       
       
       
       int i =0;
    //   cout << fans <<endl;
      reverse(fans.begin(), fans.end());
       while(i<fans.size() && fans[i]=='0'){
           i++;
       }
       
       fans = fans.substr(i);
       
       
      
       if(a==-1){
           fans = "-"+ fans;
       }
       return fans;
       
       
       
    }

};
