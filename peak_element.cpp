// class Solution
// {
// public:
//     int findPeakElement(vector<int> &nums)
//     {
//         // this problem is on "binary search the answer"
//         // very easy and can be easily implemented ~aditya verma
//         // tc = o(logn) and need to return any of the peak element if multiple peak element exists
//         int n = nums.size();
//         int start = 0;
//         int end = n - 1;

//         while (start <= end)
//         {
//             // write the criteria for the mid element
//             int mid = start + (end - start) / 2;
//             // first check for the mid which lies in between the first and the last element
//             if (mid > 0 && mid < n - 1)
//             {
//                 if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
//                 {
//                     return mid;
//                 }
//                 // if the mid is not the answer then search either left or right
//                 // write the criteria for both
//                 else if (nums[mid - 1] > nums[mid])
//                 {
//                     // then search in left half
//                     end = mid - 1;
//                 }
//                 else
//                 {
//                     // search in the right half
//                     start = mid + 1;
//                 }
//             }
//             // handling the base/edge case
//             else if (mid == 0)
//             {
//                 if (nums[0] > nums[1])
//                 {
//                     return 0;
//                 }
//                 else
//                 {
//                     return 1;
//                 }
//             }
//             else if (mid == n - 1)
//             {
//                 if (nums[n - 1] > nums[n - 2])
//                 {
//                     return n - 1;
//                 }
//                 else
//                 {
//                     return n - 2;
//                 }
//             }
//         }
//         return -1;
//     }
// };