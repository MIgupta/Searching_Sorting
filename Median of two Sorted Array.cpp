// Time Complexity O(m+n)
// Space Complexity O(m+n)
// Simple Merge Sort Approch
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int start = 0;
        int end = 0;
        vector<double> temp;
        while (start < nums1.size() && end < nums2.size())
        {
            if (nums1[start] <= nums2[end])
            {
                temp.push_back(nums1[start]);
                start++;
            }
            else
            {
                temp.push_back(nums2[end]);
                end++;
            }
        }
        while (start < nums1.size())
        {
            temp.push_back(nums1[start]);
            start++;
        }
        while (end < nums2.size())
        {
            temp.push_back(nums2[end]);
            end++;
        }
        if (temp.size() % 2 != 0)
        {
            return temp[temp.size() / 2];
        }
        else
        {
            double sum = temp[temp.size() / 2] + temp[(temp.size() / 2) - 1];
            return sum / 2;
        }
        return 0;
    }
};

// Time Complexity O(log(max(m,n)))
// Space Complexity O(1)
// Segreegate Approach
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int total = nums1.size() + nums2.size();
        int low = 0;
        int high = nums1.size();
        while (low <= high)
        {
            int aleft = (low + high) / 2;
            int half = (total + 1) / 2;
            int bleft = half - aleft;
            int al = (aleft == 0) ? INT_MIN : nums1[aleft - 1];
            int am = (aleft == nums1.size()) ? INT_MAX : nums1[aleft];
            int bm = (bleft == nums2.size()) ? INT_MAX : nums2[bleft];
            int bl = (bleft == 0) ? INT_MIN : nums2[bleft - 1];
            if (al <= bm && bl <= am)
            {
                if (total % 2 == 0)
                {
                    int m1 = max(al, bl);
                    int m2 = min(am, bm);
                    double median = (m1 + m2) / 2.0;
                    return median;
                }
                else
                {
                    double m1 = max(al, bl);
                    return m1;
                }
            }
            if (al > bm)
            {
                high = aleft - 1;
            }
            else if (bl > am)
            {
                low = aleft + 1;
            }
        }

        return nums1[low];
    }
};