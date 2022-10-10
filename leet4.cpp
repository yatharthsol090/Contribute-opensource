class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        
        while(i<version1.size() or j < version2.size()) {
            long sum1 = 0, sum2 = 0;
            
            while(i < version1.size() and version1[i] != '.') {
                sum1 += 10*sum1 + (version1[i] - '0');
                i++;
            }
            i++;
            
            while(j < version2.size() and version2[j] != '.') {
                sum2 += 10*sum2 + (version2[j] - '0');
                j++;
            }
            j++;
            
            if(sum1 < sum2) return -1;
            if(sum1 > sum2) return 1;
            
        }
        
        return 0;
    }
};
