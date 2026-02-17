#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hh=0;hh<=11;hh++) {
            for(int mm=0;mm<=59;mm++) {
                if(__builtin_popcount(hh)+__builtin_popcount(mm)==turnedOn) {
                    string hour = to_string(hh);
                    string minutes = ((mm<10) ? "0":"") + to_string(mm);
                    ans.push_back(hour+":"+minutes);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int turnedOn = 1;
    vector<string> ans = s.readBinaryWatch(turnedOn);
    for(string str: ans) {
        cout<<str<<" ";
    }
}