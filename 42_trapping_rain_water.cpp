class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l(height.size(), 0), r(height.size(), 0);
        int tmp = 0;
        for (int i = 0; i < height.size(); ++ i) {
            tmp = max(tmp, height[i]);
            l[i] = tmp;
        }
        tmp = 0;
        for (int i = (int)height.size() - 1; i >= 0; -- i) {
            tmp = max(tmp, height[i]);
            r[i] = tmp;
        }
        int ret = 0;
        for (int i = 0; i < height.size(); ++ i)
            ret += min(l[i], r[i]) - height[i];
        return ret;
    }
};