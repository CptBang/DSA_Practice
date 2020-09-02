/*

create string of s length and copy each letter in based on its vertices

*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret = s;
        
        for (int i = 0; i < indices.size(); i++) {
            ret[indices[i]] = s[i];
        }
        
        return ret;
    }
};

// no additional space allocated, but it looks so nasty
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < indices.size(); i++) {
            while (indices[i] != i) {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        
        return s;
    }
};