/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        
        for (int i = 0; i < address.length(); ++i)
        {
            if ('.' != address[i])
                result.push_back(address[i]);
            else
                result += "[.]";
        }
        
        return result;
    }
};
