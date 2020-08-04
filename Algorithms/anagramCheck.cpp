class Solution {
public:
    bool isAnagram(string s, string t) {
        int sArr[26] = {0};
        int tArr[26] = {0};

        for(char el : s)
            sArr[el-'a']++;

        for(char el : t)
            tArr[el-'a']++;

        bool res = false;
        for(int i = 0; i < 26; ++i)
            res = ((sArr[i] != tArr[i]) || res);

        return !res;
    }
};
