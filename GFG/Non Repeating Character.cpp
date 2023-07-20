char nonrepeatingCharacter(string S)
{

   map <int,int> a;
   for(auto it :S){
       a[it]++;
   }
   for(auto it : S){
       if(a[it]==1)return it;
   }
   return '$';
   
}
