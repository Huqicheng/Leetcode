class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int max_area = INT_MIN;
        while (left < right) {
            max_area = max( (right - left) * min(height[left], height[right]), max_area );
            if (height[left] < height[right]) {
                left ++;
            }
            else {
                right --;
            }
        }
        return max_area;
    }
};