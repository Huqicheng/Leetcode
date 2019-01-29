class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        x = x > 0 ? x : -x;
        long res = 0;
        while (x > 0) {
            int pop = x % 10;
            res = res * 10 + pop;
            x /= 10;
        }
        res = res * sign;
        if (res > INT_MAX || res < INT_MIN)
        {
            return 0;
        }
        return (int) res;
    }
};