class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && fmod((log10(n) / log10(4)), 1) == 0;
    }
};