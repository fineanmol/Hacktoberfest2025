// Find Resultant Array After Removing Anagrams

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isAnagram(string s1 , string s2){

        int arr[26]={0};

        for(char ch : s1){
            arr[ch-'a']++;
        }

        for(char ch : s2){
            arr[ch-'a']--;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(arr[i]!=0){
                return false;
            }
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>resultant;
        
        resultant.push_back(words[0]);

        for(int i=1; i<n ; i++){
            if(!isAnagram(resultant.back(),words[i])){
                resultant.push_back(words[i]);
            }
        }

        return resultant;
    }
};



int main() {
    Solution obj;

    // Example input
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};

    // Call the function
    vector<string> ans = obj.removeAnagrams(words);

    // Print the output
    cout << "Resultant words after removing consecutive anagrams:\n";
    for (string s : ans)
        cout << s << " ";

    cout << endl;
    return 0;
}