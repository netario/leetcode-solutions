class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0) return -1;
        int p = 0;
        while (true){
            int v = 0, q = p;
            while (v >= 0){
                v += gas[q] - cost[q];
                q = (q + 1) % gas.size();
                if (v >= 0 && q == p) return p;
            }
            if (q <= p) return -1;
            p = q;
        }
    }
};