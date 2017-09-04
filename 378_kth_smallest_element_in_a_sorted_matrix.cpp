class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ret = -1;
        auto cmp = [](pair<vector<int>::iterator, vector<int>::iterator>& a, 
                      pair<vector<int>::iterator, vector<int>::iterator>& b) { return *a.first > *b.first; };
        priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, 
                       vector<pair<vector<int>::iterator, vector<int>::iterator>>, 
                       decltype(cmp)> q(cmp);
        for (int i = 0; i < matrix.size(); ++ i) 
            q.push(make_pair(matrix[i].begin(), matrix[i].end()));
        for (int i = 0; i < k; ++ i) {
            auto p = q.top();
            q.pop();
            ret = *p.first;
            if (p.first + 1 == p.second) continue;
            q.push(make_pair(p.first + 1, p.second));
        }
        return ret;
    }
};