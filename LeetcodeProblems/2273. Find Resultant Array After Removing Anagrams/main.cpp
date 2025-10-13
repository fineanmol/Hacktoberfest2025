class Solution {
    
public:
     vector<string> removeAnagrams(const vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i) {
            if (!isAnagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
    
    bool isAnagram(const string &a, const string &b) {
        if (a.size() != b.size()) return false;

        int freq[26] = {0};

        for (int i = 0; i < a.size(); i++) {
            freq[a[i] - 'a']++;
            freq[b[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return false;
       
        return true;
    }
};