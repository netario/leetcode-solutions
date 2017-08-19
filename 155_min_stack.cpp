class MinStack {
public:
    vector<int> s, v; 
    void push(int x) {
        s.push_back(x);
        if (v.empty() || v[v.size() - 1] >= x)v.push_back(x);
    }
    void pop() {
        if (v[v.size() - 1] == s[s.size() - 1]) v.pop_back();
        s.pop_back();
    }
    int top() {
        return s[s.size() - 1];
    }
    int getMin() {
        return v[v.size() - 1];
    }
};