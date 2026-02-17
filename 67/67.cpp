/*Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();

        int i = n-1, j=m-1;
        int carry=0;
        string ans = "";
        while(carry!=0 || i>=0 || j>=0) {
            int sum = carry;
            if(i>=0) sum+=a[i]-'0';
            if(j>=0) sum+=b[j]-'0';
            if(sum==0) {
                ans+='0';
                carry=0;
            }
            else if(sum==1) {
                ans+='1';
                carry=0;
            }
            else if(sum==2) {
                ans+='0';
                carry=1;
            } else {
                ans+='1';
                carry=1;
            }
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};