class Solution {
private:
    vector<string> findMax(vector<int>& nums) {
        vector<string> ret(nums.size() + 1, "");
        for (auto& num : nums)
            ret[nums.size()] += '0' + num;
        string tmp = ret[nums.size()];
        int i = 0;
        while (tmp.size() > 0) {
            while (i + 1 != tmp.size() && tmp[i] >= tmp[i + 1])
                i ++;
            tmp.erase(tmp.begin() + i);
            i = max(i - 1, 0);
            ret[tmp.size()] = tmp;
        }
        return ret;
    }
        string combine(string& a, string& b) {
        string ret = "";
        int ia = 0, ib = 0;
        while (ia < a.size() || ib < b.size()) {
            //cout << ret << ' ' << ia << ' ' << ib << endl;
            if (ia == a.size() || a[ia] < b[ib]) {
                ret += b[ib];
                ib ++;
                continue;
            }
            if (ib == b.size() || b[ib] < a[ia]) {
                ret += a[ia];
                ia ++;
                continue;
            }
            string sa = "", sb = "";
            int i = 0;
            while (true) {
                if (ia + i < a.size()) sa += a[ia + i];
                if (ib + i < b.size()) sb += b[ib + i];
                if (ia + i == a.size() || ib + i == b.size() || a[ia + i] != b[ib + i]) break;
                i ++;
            }
            if (sa > sb) {
                while (a[ia] == b[ib]) {
                    ret += a[ia];
                    ia += 1;
                }
            } else {
                while (b[ib] == a[ia]) {
                    ret += b[ib];
                    ib += 1;
                }
            }
        }
        return ret;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        string ret = "";
        vector<string> arr1 = findMax(nums1), arr2 = findMax(nums2);
        for (int i = 0; i <= k; ++ i) 
            if (i <= nums1.size() && k - i <= nums2.size())
                ret = max(ret, combine(arr1[i], arr2[k - i]));
        vector<int> ans;
        for (auto& num : ret)
            ans.push_back(num - '0');
        return ans;
    }
};