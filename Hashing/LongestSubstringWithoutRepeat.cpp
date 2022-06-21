// Given a string, 

// find the length of the longest substring without repeating characters.

// Example:

// The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

// For "bbbbb" the longest substring is "b", with the length of 1.


int Solution::lengthOfLongestSubstring(string s) {
    unordered_map<char, int> counter;
    int ans = 0;
    int i = 0, j = 0;
    while(j < s.size()){
        counter[s[j]] ++;
        while(counter[s[j]] > 1){
            counter[s[i++]]--;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
