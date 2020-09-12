/*

easiest, calculate largest area for each value and return the largest
two for loops
Time O(n^2)

two pointer solution
Time O(n)

*/


// //brute force
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int ret = 0;

//         for (int i = 0; i < height.size(); i++) {
//             int curr;
//             for (int j = i; j < height.size(); j++) {
//                 curr = min(height[i], height[j]) * (j-i);
//                 ret = max(ret, curr);
//             }
//         }

//         return ret;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int start = 0;
        int end = height.size()-1;

        while (start < end) {
            int curr = min(height[start], height[end]) * (end-start);
            ret = max(ret, curr);
            if (height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }

        return ret;
    }
};
