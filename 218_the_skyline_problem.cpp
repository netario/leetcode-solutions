class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ret;
        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b) { return a[0] == b[0] ? a[2] > 
            b[2] : a[0] < b[0]; });
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) { return a.second == b.second ? a.first < b.first : a
            .second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (auto& building : buildings) {
            while (!q.empty() && q.top().first < building[0]) {
                int t = q.top().first;
                q.pop();
                while (!q.empty() && q.top().first <= t)
                    q.pop();
                ret.push_back(make_pair(t, q.empty() ? 0 : q.top().second));
            }
            if (building[0] == INT_MAX) break;
            if (q.empty() || building[2] > q.top().second) ret.push_back(make_pair(building[0], building[2]));
            q.push(make_pair(building[1], building[2]));
        }
        while (!q.empty()) {
            int t = q.top().first;
            q.pop();
            while (!q.empty() && q.top().first <= t)
                q.pop();
            ret.push_back(make_pair(t, q.empty() ? 0 : q.top().second));
        }
        return ret;
    }
};