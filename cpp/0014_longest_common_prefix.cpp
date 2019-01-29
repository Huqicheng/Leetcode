class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) 
        {
            return "";
        }
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestCommonPrefix(vector<string>& strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }
        
        int mid = (right - left) / 2 + left;
        string leftLCP = longestCommonPrefix(strs, left, mid);
        string rightLCP = longestCommonPrefix(strs, mid+1, right);
        
        return commonPrefix(leftLCP, rightLCP);
    }
    
    string commonPrefix(string str1, string str2) {
        int len_1 = str1.length(), len_2 = str2.length();
        int min_len = min(len_1, len_2);
        for (int i = 0; i < min_len; i++) {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
            }
        }
        return str1.substr(0, min_len);
    }
};