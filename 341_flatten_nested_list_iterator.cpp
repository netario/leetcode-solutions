/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
    int nxt = INT_MIN;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push(make_pair(nestedList.begin(), nestedList.end()));
    }
    int next() {
        if (nxt != INT_MIN) {
            int ret = nxt;
            nxt = INT_MIN;
            return ret;
        }
        while (!stk.empty() && stk.top().first == stk.top().second)
            stk.pop();
        if (stk.empty()) return INT_MIN;
        auto it = stk.top().first;
        stk.top().first ++;
        if (!(*it).isInteger()) {
            stk.push(make_pair((*it).getList().begin(), (*it).getList().end()));
            return next();
        } else {
            return (*it).getInteger();
        }
        return INT_MIN;
    }
    bool hasNext() {
        nxt = next();
        return nxt != INT_MIN && !stk.empty();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */