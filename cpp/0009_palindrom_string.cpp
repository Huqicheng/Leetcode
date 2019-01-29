class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int tmp = x;
        int revertedNumber = 0;
        while (x > 0) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        return tmp == revertedNumber;
    }
    
};