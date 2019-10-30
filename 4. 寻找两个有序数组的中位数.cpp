// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int maxl1, maxl2, minr1, minr2;
        int c1, c2;
        int low = 0, high = 2 * n1;     // 虚加"#"，变成恒为偶数：2*n1+2*n2+2
        
        while (low <= high)             // =：空数组
        {
            c1 = (low + high) / 2;      // 二分法
            c2 = n1 + n2 - c1;          // n1 + n2 + 1 - c1:下标从0开始，故再-1
            
            maxl1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];  // 左边的数是先-1再除以2
            maxl2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            minr1 = (c1 == 2 * n1) ? INT_MAX : nums1[c1 / 2];   // 右边的数直接除以2，观察即可得出
            minr2 = (c2 == 2 * n2) ? INT_MAX : nums2[c2 / 2];
            
            if (maxl1 > minr2)
                high = c1 - 1;
            else if (maxl2 > minr1)
                low = c1 + 1;
            else
                break;
            
        }
        
        return (max(maxl1, maxl2) + min(minr1, minr2)) / 2.0;
    }
};