class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1){
            return findMedian(nums1, 0, nums2, 0, n / 2 + 1);
        }else{
            return (findMedian(nums1, 0, nums2, 0, n / 2) + findMedian(nums1, 0, nums2, 0, n / 2 + 1)) / 2;
        }
    }
private:
    double findMedian(vector<int>& nums1, int x1, vector<int>& nums2, int x2, int k){
        if (x1 >= nums1.size()) return nums2[x2 + k - 1];
        if (x2 >= nums2.size()) return nums1[x1 + k - 1];
        if (k == 1) return min(nums1[x1], nums2[x2]);
        int n1 = x1 + k / 2, n2 = x2 + k / 2;
        if (n1 > nums1.size()) n1 = nums1.size();
        if (n2 > nums2.size()) n2 = nums2.size();
        if (nums1[n1 - 1] <= nums2[n2 - 1]){
            return findMedian(nums1, n1, nums2, x2, k - (n1 - x1));
        }else{
            return findMedian(nums1, x1, nums2, n2, k - (n2 - x2));
        }
    }
};