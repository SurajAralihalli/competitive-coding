// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// Date: 17th Feb, 2023
// Tags: string

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buffer[4] = {0};
    int buf4_size = 0;
    int buf4i = 0;
    int read(char *buf, int n) {
        int charCopied = 0;
        int bufi = 0;
        while(buf4i < buf4_size && charCopied<n) {
            buf[bufi] = buffer[buf4i];
            bufi++;
            buf4i++;
            charCopied++;
        }

        while( charCopied<n ) {
            buf4_size = read4(buffer);
            buf4i = 0;
            if(buf4_size == 0) {
                break;
            }

            while(buf4i < buf4_size && charCopied<n) {
                buf[bufi] = buffer[buf4i];
                bufi++;
                buf4i++;
                charCopied++;
            }
        }
        buf[bufi] = '\0';
        return charCopied;
    }
};
