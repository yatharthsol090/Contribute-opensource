class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int x1 = nums[0], x2 = max(nums[0], nums[1]);
        int ans = x2;
        
        for(int i = 2; i<nums.size()-1; i++) {
            ans = max(x2, x1+nums[i]);
            x1 = x2;
            x2 = ans;
        }
        
        x1 = 0, x2 = nums[1];
        int ans2 = x2;
        
        for(int i = 2; i<nums.size(); i++) {
            ans2 = max(x2, x1+nums[i]);
            x1 = x2;
            x2 = ans2;
        } 
        return max(ans, ans2);
    }
};
