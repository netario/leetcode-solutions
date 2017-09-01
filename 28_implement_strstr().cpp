class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++ i)
            if (haystack.substr(i, needle.size()) == needle) return i;
        return -1;
    }
};