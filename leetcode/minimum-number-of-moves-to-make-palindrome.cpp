// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
// Date: 17th Feb, 2022
// Tags: two-pointer, greedy, 
// Explanation: https://www.youtube.com/watch?v=EpuC64ClV8k

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int lt = 0;
        int rt = s.size()-1;
        int count = 0;
        // fix left half
        cout << s << endl;
        while(lt<rt) {
            int l = lt;
            int r = rt;

            while(s[l]!=s[r]) { // find where is s[l]
                r--;
            }

            if(l==r) {
                swap(s[l], s[l+1]);
                count++;
                continue;
            }

            while(s[lt]!=s[rt]) {
                swap(s[r], s[r+1]);
                r++;
                count++;
            }

            lt++;
            rt--;
        }
        return count;
    }
};
