class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 这个map维护最后一个该字符出现的位置
        map<char,int> mapCur;
        int ans = 0;
        int j = 0;
        for (int i=0; i<s.length(); i++) {
            map<char,int>::iterator it = mapCur.find(s[i]);
            if (it != mapCur.end()) {
                j = max(j, it->second + 1);
                it->second = i;
            } else {
                mapCur.emplace(s[i], i);
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};