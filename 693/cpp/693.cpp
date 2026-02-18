#include <iostream>
using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool one = n&1;
        n>>=1;
        while(n>0) {
            if((n&1) == one) return false;
            n>>=1;
            one = !one;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.hasAlternatingBits(5) << endl; // true
    cout << s.hasAlternatingBits(7) << endl; // false
    cout << s.hasAlternatingBits(11) << endl; // false
    cout << s.hasAlternatingBits(10) << endl; // true
    return 0;
}