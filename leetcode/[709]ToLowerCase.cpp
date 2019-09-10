/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
*/
class Solution {
public:
    string toLowerCase(string str) {
        for (char &c : str)
        {
            if ('A' <= c && 'Z' >= c)
                c += 'a' - 'A';
        }
        return str;
    }
};

/* 使用下标，性能和上面差不多 */
class Solution {
public:
    string toLowerCase(string str) {
        int len = str.length();
        for (int i = 0; i < len; ++i)
        {
            if ('A' <= str[i] && 'Z' >= str[i])
            str[i] += 'a' - 'A';
        }
        return str;
    }
};
