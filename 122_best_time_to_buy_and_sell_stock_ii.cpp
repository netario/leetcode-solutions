class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> f(prices.size() + 5, vector<int>(3, INT_MIN));
        f[0][0] = 0;
        for (int i = 0; i < prices.size(); ++ i)
            for (int j = 0; j < 2; ++ j)
                if (f[i][j] != INT_MIN){
                    f[i + 1][j] = max(f[i + 1][j], f[i][j]);
                    if (j == 0){
                        f[i + 1][1] = max(f[i + 1][1], f[i][j] - prices[i]);
                    } else{
                        f[i + 1][0] = max(f[i + 1][0], f[i][j] + prices[i]);
                    }
                }
        return f[prices.size()][0];
    }
};