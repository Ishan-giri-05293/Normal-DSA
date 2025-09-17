class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;            // make room for next bit
            result |= (n & 1);       // take LSB from n and add it
            n >>= 1;                  // shift input right
        }
        return result;
    }
};
