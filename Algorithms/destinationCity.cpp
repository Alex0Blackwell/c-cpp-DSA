class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m;

        for(int i = 0; i < paths.size(); ++i) {
            for(int j = 0; j < 2; ++j) {
                if(j == 0)
                    m[paths[i][0]] += 2;
                else
                    m[paths[i][1]]++;
            }
        }

        for(auto i : m) {
            if(i.second == 1)
                return i.first;
        }
        return paths[0][1];
    }
};
