
// int binarySearch_left(vector<int> &A, int s,int e,int target){

//     int mid = s +(e-s)/2;

//     while(s<=e){

//         if(target==A[mid]){

//             return mid;

//         }

//         else if(target>A[mid]){

//             s=mid+1;

//         }

//         else{

//             e=mid-1;

//         }

//         mid=s+(e-s)/2;

//     }

//     return -1;

// }



// int binarySearch_right(vector<int> &A, int s,int e,int target){

//     int mid=s+(e-s)/2;

//     while(s<=e){

//         if(target==A[mid]){

//             return mid;

//         }

//         else if(target>A[mid]){

//             e=mid-1;

//         }

//         else{

//             s=mid+1;

//         }

//         mid=s+(e-s)/2;

//     }

//     return -1;

// }



// int findPeakElement(vector<int> &A)
//     {
//         // this problem is on "binary search the answer"
//         // very easy and can be easily implemented ~aditya verma
//         // tc = o(logn) and need to return any of the peak element if multiple peak element exists
//         int n = A.size();
//         int s = 0;
//         int e = n - 1;
//         // base condition
//         if(A == 1){
//             return 0;
//         }
//         while (s <= e)
//         {
//             // write the criteria for the mid element
//             int mid = s + (e - s) / 2;
//             // first check for the mid which lies in between the first and the last element
//             if (mid > 0 && mid < n - 1)
//             {
//                 if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
//                 {
//                     return mid;
//                 }
//                 // if the mid is not the answer then search either left or right
//                 // write the criteria for both
//                 else if (A[mid - 1] > A[mid + 1])
//                 { 
//                     // then search in left half
//                     e = mid - 1;
//                 }
//                 else
//                 {
//                     // search in the right half
//                     s = mid + 1;
//                 }
//             }
//             // handling the base/edge case
//             else if (mid == 0)
//             {
//                 if (A[0] > A[1])
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
//                 if (A[n - 1] > A[n - 2])
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


// int Solution::solve(vector<int> &A, int B) {

//     int e = A.size()-1;

//     int p = peak(A);

//     //search in the increasing region

//     if(B == A[p]){

//         return p;

//     }

//     int ans1 = binarySearch_left(A,0,p-1,B);

//     int ans2 = binarySearch_right(A,p+1,e,B);

//     if(ans1!=-1){

//         return ans1;

//     }

//     else{

//         return ans2;

//     }

// }

