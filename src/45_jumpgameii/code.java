class Solution {
    private int[] dp;
    private int[] nums;
    
    public int jump(int[] nums) {
        int[] dp = initialize(nums.length);
        return search(nums, dp, 0, 0);
    }
    
    private int[] initialize(int len) {
        int[] dp = new int[len];
        Arrays.fill(dp, Integer.MAX_VALUE);
        return dp;
    }
    
    private int search(int[] nums, int[] dp, int cur, int hops) {
        if (cur == nums.length - 1) {
            return hops;
        }
        if (dp[cur] < Integer.MAX_VALUE) {
            return hops + dp[cur];
        }
        int min = Integer.MAX_VALUE;
        int minPossible = nums[cur] < nums.length - cur - 1 ? 2 : 1;
        for (int i = Math.min(nums[cur], nums.length - cur - 1); i >= 1; --i) {
            int h = search(nums, dp, cur + i, hops + 1);
            if (h < min) {
                min = h;
                if (min == minPossible) {
                    break;
                }
            }
        }
        if (min < Integer.MAX_VALUE) {
            dp[cur] = min - hops;
        }
        return min;
    }
}

