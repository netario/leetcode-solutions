class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        stack<pair<int, int>> s;
        for (int i = 0; i < height.size(); ++ i){
            int p = i;
            while (!s.empty() && s.top().first > height[i]){
                ret = max(ret, s.top().first * (i - s.top().second));
                p = s.top().second;
                s.pop();
            }
            s.push(make_pair(height[i], p));
        }
        while (!s.empty()){
            ret = max(ret, s.top().first * ((int)height.size() - s.top().second));
            s.pop();
        }
        return ret;
    }
};