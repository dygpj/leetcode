class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int adr[256];
        memset(adr, -1, sizeof(adr));
        int begin = -1, max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (adr[s[i]] > begin) begin = adr[s[i]];
            if (i - begin > max) max = i - begin;
            adr[s[i]] = i;
        }
        return max;
    }
};