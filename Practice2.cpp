// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            m.insert({nums[i], i});
        }

        int val = 0;        
        for (int i = 0; i < nums.size(); ++i) {
            val = target - nums[i];
            if (m.find(val) != m.end()) {
                return new int[] {i, m.at(val)};
            }
        }
    }
};

// Reverse Integer
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        
        int i = 0;
        int n = str.size();
        if (str[0] == '-') {
            ++i;
            ++n;
        }

        for (; i < n / 2; ++i) {
            swap(str[i], str[n - i - 1]);
        }
        
        return stoi(str);
    }
};

// Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);

        int n = str.length();
        for (int i = 0; i < n / 2; ++i) {
            if (str[i] != str[n - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};

// Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        string temp = "";
        string longest = "";

        for (int i = 0; i < strs[0].size(); ++i) {
            temp = strs[0].substr(0, i);

            for (int j = i + 1; j < strs.size(); ++j) {
                if (strs[j].substr(0, i) != temp) {
                    return longest;
                } else {
                    longest = temp;
                }
            }
        }
        
        return strs[0];
    }
};

// Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }

        map<string, string> m = {{')', '('}, {'}', '{'}, {']', '['}};

        stack<string> stack;

        for (auto it = s.begin(); it != s.end(); ++it) {
            if (m.find(*it) != m.end()) {
                if (m.at(*it) != stack.top()) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(*it);
            }
        }
        
        return true;
    }
};

// Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        auto curr = nums.begin();
        auto next = curr + 1;

        while (curr != nums.end()) {
            while (*curr == *next) {
                next = nums.erase(next);
            }
            if (*curr != *next) {
                ++curr;
                ++next;
            }
        }
        
        return nums.size();
    }
};

// Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }

        for (auto it = nums.begin(); it != nums.end(); +it) {
            if (*it == val) {
                it = nums.erase(it);
            }
        }
        
        return nums.size();
    }
};

// Implement strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        for (auto it = haystack.begin(); it != haystack.end(); ++it) {
            if (*it == needle.begin()) {
                string str = haystack.substr(it, needle.size() - 1);
                if (str == needle) {
                    return it;
                }
            }
        }

        return -1;
    }
};

// Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto prev = nums.begin();
        auto next = nums.begin() + 1;

        for (; prev != nums.end(); ++prev, ++next) {
            if (*prev >= target) {
                return prev;
            }

            if (*prev < target && target < *next) {
                return next;
            }

            if (next == nums.end()) {
                return nums.size();
            }
        }
    }
};
