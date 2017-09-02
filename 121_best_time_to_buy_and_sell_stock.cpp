class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, pmin = INT_MAX;
        for (int i = 0; i < prices.size(); ++ i){
            ret = max(ret, prices[i] - pmin);
            pmin = min(pmin, prices[i]);
        }
        return ret;
    }
};