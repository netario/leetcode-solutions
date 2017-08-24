class Solution {
private:
    int f[250];
    int getFather(int c){
        if (f[c] != c) f[c] = getFather(f[c]);
        return f[c];
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        for (int i = 0; i < M.size(); ++ i)
            f[i] = i;
        for (int i = 0; i < M.size(); ++ i)
            for (int j = 0; j < M[0].size(); ++ j)
                if (M[i][j] == 1){
                    f[getFather(i)] = getFather(j);
                }
        unordered_map<int, int> hash;
        for (int i= 0; i < M.size(); ++ i)
            if (hash.count(getFather(i)) == 0){
                ret ++;
                hash[getFather(i)] ++;
            }
        return ret;
    }
};