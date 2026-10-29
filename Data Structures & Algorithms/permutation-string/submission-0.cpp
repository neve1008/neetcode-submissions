class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int target[26] = {};
        for (char c : s1) {
            target[c - 'a']++;
        }

        int window[26] = {};
        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            bool same = true;

            window[s2[right] - 'a']++;

            if (right - left + 1 > s1.size()) {
                window[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == s1.size()) {
                for (int i = 0; i < 26; i++) {
                    if (target[i] != window[i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    return true;
                }
            }
        }
        return false;
    }
};
