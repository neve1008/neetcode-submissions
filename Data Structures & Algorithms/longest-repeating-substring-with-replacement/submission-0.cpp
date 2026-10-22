class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        int count[26] = {};
        int answer = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right]-'A']++;
            maxCount = max(maxCount, count[s[right]-'A']);
            while (right - left + 1 - maxCount > k) {
                count[s[left]-'A']--;
                left++;
                maxCount = 0;
                for (int i = 0; i < 26; i++) {
                    maxCount = max(maxCount, count[i]);
                }
            }
            answer = max(answer, right - left + 1);
        }
        return answer; 
    }
};
