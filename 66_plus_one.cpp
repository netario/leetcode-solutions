class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;
        bool h = false;
        for (int i = digits.size() - 1; i >= 0; i --)
            if (digits[i] > 9){
                digits[i] %= 10;
                if (i != 0) digits[i - 1] ++;
                    else    h = true;
            }
        if (h == true){
            digits.push_back(0);
            for (int i = digits.size() - 1; i > 0; i --) digits[i] = digits[i - 1];
            digits[0] = 1;
        }
        return digits;
    }
};