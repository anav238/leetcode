class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[256] = {-1}, maxLen = 0, start = 0;
        for (int i = 0; i < 255; i++)
            lastSeen[i] = -1;
        for (int i = 0; i < s.length(); i++) {
            start = max(start, lastSeen[s[i]] + 1);
            int len = i - start + 1;
            maxLen = max(maxLen, len);
            lastSeen[s[i]] = i;
        }
        return maxLen;
    }
};