class Solution {
  public: 
  
    long long orientation (int p1[], int p2[], int p3[]) {
        
        long long val = ((p2[1] - p1[1]) *1ll* (p3[0] - p2[0])) - ((p2[0] - p1[0]) *1ll* (p3[1] - p2[1]));
        
        if (val == 0) {
            return 0;
        }
        
        if (val > 0) return 1;
        return 2;
    }
  
  
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        
        int sign1 = orientation (p1, q1, p2);
        int sign2 = orientation (p1, q1, q2);
        
        int sign3 = orientation (p2, q2, q1);
        int sign4 = orientation (p2, q2, p1);
        
        
        if (sign1 + sign2 + sign3 + sign4 == 0) {
            if (p1[0]>=p2[0] && p1[0]<=q2[0] || p2[0]>=p1[0] && p2[0]<=q1[0]) {
                return "true";
            }
            
            if (p1[1]>=p2[1] && p1[1]<=q2[1] || p2[1]>=p1[1] && p2[1]<=q1[1]) {
                return "true";
            }
        }
        if ((sign1 != sign2) && (sign3 != sign4)) {
            return "true";
        }
        
        return "false";
        
    }
};
