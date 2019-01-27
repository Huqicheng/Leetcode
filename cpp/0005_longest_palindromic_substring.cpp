class Solution {
public:
    // a******a
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int dp[s.size()][s.size()] = {0}, left = 0, right = 0;
        int len = 0;

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            for (int j = 0; j < i; j++) {
                // check if it's palindromic
                // dp[i] == dp[j] and substring between i and j is palindromic
                dp[j][i] = (s[i] == s[j] && (i- j < 2 || dp[j+1][i-1]));

                // set the longest substring
                if (dp[j][i] && len < i -j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
        }

        return s.substr(left, right-left+1);
    }
};