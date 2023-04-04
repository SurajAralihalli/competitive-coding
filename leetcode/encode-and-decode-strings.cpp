// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/encode-and-decode-strings/description/
// Date: 4th April, 2023
// Tags: strings, design

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string strings = "";
        string counts = (to_string(strs.size()) + ";");
        for(auto s: strs) {
            counts += (to_string(s.size()) + ";");
            strings += s;
        }  
        string sol =  counts + strings;
        return sol;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = s.find(';');
        int n = stoi(s.substr(0, i));
        vector<int> sizes;
        vector<string> sol;
        for(int j=0;j<n;j++) {
            int i_ = s.find(';', i+1);
            int l = stoi(s.substr(i+1, i_ - i - 1));
            i = i_;
            sizes.push_back(l);
        }
        i++;
        for(auto k : sizes) {
            string ans = s.substr(i, k);
            sol.push_back(ans);
            i = i + k;
        }

        return sol;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));encode-and-decode-strings
