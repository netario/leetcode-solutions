class Solution {
public:
    int hIndex(vector<int>& citations) {
        int p = 0, q = citations.size();
        while (p < q){
            int mid = p + ((q - p) >> 1);
            if (citations[mid] >= citations.size() - mid){
                q = mid;
            } else{
                p = mid + 1;
            }
        }
        return citations.size() - p;
    }
};