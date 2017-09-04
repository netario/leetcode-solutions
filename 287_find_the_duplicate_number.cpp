class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret = -1, p = 1, q = (int)nums.size() - 1;
        while (p <= q) {
            int mid = p + (q - p) / 2, cnt = 0;
            for (auto& num : nums)
                cnt += num <= mid;
            if (cnt >= mid + 1) {
                ret = mid;
                q = mid - 1;
            } else {
                p = mid + 1;
            }
        }
        return ret;
    }
};