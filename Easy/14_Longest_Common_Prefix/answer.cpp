/*

compare first letter of each string
if they are the same, append to string
if not, return result

for letter in first string
    for string vector
        compare letter
    append letter
    
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        
        if (strs.empty()) {
            return ret;
        }

        for (int i = 0; i < strs[0].size(); i++) {
            char comp = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (comp != strs[j][i]) {
                    return ret;
                }
            }
            ret.push_back(comp);
        }
        
        return ret;
    }
};