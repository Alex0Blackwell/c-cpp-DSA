class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mapOrder;
        mapOrder.insert({'I', 0});
        mapOrder.insert({'V', 1});
        mapOrder.insert({'X', 2});
        mapOrder.insert({'L', 3});
        mapOrder.insert({'C', 4});
        mapOrder.insert({'D', 5});
        mapOrder.insert({'M', 6});
        
        map<char, int> mapValue;
        mapValue.insert({'I', 1});
        mapValue.insert({'V', 5});
        mapValue.insert({'X', 10});
        mapValue.insert({'L', 50});
        mapValue.insert({'C', 100});
        mapValue.insert({'D', 500});
        mapValue.insert({'M', 1000});
        
        int nextO, res;
        nextO = res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i < s.size()-1) {
                nextO = mapOrder.at(s[i+1]);
                if(nextO % 2 == 0) {
                    if(nextO - mapOrder.at(s[i]) == 1 || nextO - mapOrder.at(s[i]) == 2) {
                        res += mapValue.at(s[i+1]) - mapValue.at(s[i]);
                        i++;
                    } else {
                        res += mapValue.at(s[i]);
                    }
                } else {
                    if(nextO - mapOrder.at(s[i]) == 1) {
                        res += mapValue.at(s[i+1]) - mapValue.at(s[i]);
                        i++;
                    } else {
                        res += mapValue.at(s[i]);
                    }
                }
            } else {
                res += mapValue.at(s[i]);
            }
        }
        return res;
    }
};
