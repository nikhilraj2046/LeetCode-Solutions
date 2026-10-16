class Solution {
public:
    string maskPII(string s) {
        int n = s.size(); 
        if (s.find('@') != string::npos) { 
            int idx = s.find('@');
            string res = "";
            res += tolower(s[0]);
            res += "*****";
            res += tolower(s[idx - 1]);
            for (int i = idx; i < n; i++) {
                res += tolower(s[i]);
            }
            return res;
            
        } else { 
            string digits = "";
            for (char c : s) {
                if (isdigit(c)) {
                    digits += c;
                }
            }
            string t = "***-***-" + digits.substr(digits.size() - 4);
            int size = digits.size() - 10;
            if (size == 0) {
                return t;
            } else if (size == 1) {
                return "+*-" + t;
            } else if (size == 2) {
                return "+**-" + t;
            } else if (size == 3) {
                return "+***-" + t;
            }
        }
        return s;
    }
};
