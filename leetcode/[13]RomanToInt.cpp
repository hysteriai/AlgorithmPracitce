/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
Example 1:
Input: "III"
Output: 3
Example 2:
Input: "IV"
Output: 4
Example 3:
Input: "IX"
Output: 9
Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
实现思路：
从后向前遍历字符串，如果这个数比之前的都大，则把这个数加上，如果比之前的某个数小，则减去这个数
结果：
Runtime: 16 ms, faster than 99.95% of C++ online submissions for Roman to Integer.
Memory Usage: 8.3 MB, less than 99.85% of C++ online submissions for Roman to Integer.
*/

#if 0
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int iromanInt = 0;
    int numLevel = 0;
    string input;

    cin >> input;

    for (int i = input.size() - 1; i >= 0; --i)
    {
        if ('M' == input[i])
        {
            //没有比M更大的数，一定是加
            numLevel = 7;
            iromanInt += 1000;
        }
        else if ('D' == input[i])
        {
            if (numLevel > 6)
            {
                iromanInt -= 500;
            }
            else
            {
                numLevel = 6;
                iromanInt += 500;
            } 
        }
        else if ('C' == input[i])
        {
            if (numLevel > 5)
            {
                iromanInt -= 100;
            }
            else
            {
                numLevel = 5;
                iromanInt += 100;
            } 
        }
        else if ('L' == input[i])
        {
            if (numLevel > 4)
            {
                iromanInt -= 50;
            }
            else
            {
                numLevel = 4;
                iromanInt += 50;
            } 
        }
        else if ('X' == input[i])
        {
            if (numLevel > 3)
            {
                iromanInt -= 10;
            }
            else
            {
                numLevel = 3;
                iromanInt += 10;
            } 
        }
        else if ('V' == input[i])
        {
            if (numLevel > 2)
            {
                iromanInt -= 5;
            }
            else
            {
                numLevel = 2;
                iromanInt += 5;
            } 
        }
        else if ('I' == input[i])
        {
            if (numLevel > 1)
            {
                iromanInt -= 1;
            }
            else
            {
                numLevel = 1;
                iromanInt += 1;
            } 
        }       
    }

    cout << iromanInt << endl;


    return 0;
}
#endif
/*
一种简化写法，映射存储在map中
numLevel直接用值代替
用map会比用一堆ifelse慢一点
Runtime: 36 ms, faster than 91.18% of C++ online submissions for Roman to Integer.
Memory Usage: 10.5 MB, less than 98.40% of C++ online submissions for Roman to Integer.
用unordered_map比map稍快
Runtime: 28 ms, faster than 96.00% of C++ online submissions for Roman to Integer.
Memory Usage: 10.4 MB, less than 98.40% of C++ online submissions for Roman to Integer.
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int iromanInt = 0;
    int numLevel = 0;
    int num = 0;
    string s;

    cin >> s;

    map<char, int> myMap = { { 'I' , 1 },
                         { 'V' , 5 },
                         { 'X' , 10 },
                         { 'L' , 50 },
                         { 'C' , 100 },
                         { 'D' , 500 },
                         { 'M' , 1000 } };

    for (int i = s.size() - 1; i >= 0; --i)
    {
        num = myMap[s[i]];
        if (numLevel > num)
        {
            iromanInt -= num;
        }
        else
        {
            numLevel = num;
            iromanInt += num;
        }
        
    }
    cout << iromanInt << endl;

    return 0;
}


/*
其他解法：
leetcode讨论中看到的另一种解法，是从前向后遍历的，但是不能连着减两个一样的(比如IIV)
百度了一下这个表示方法没说有也没说没有。估计是不能这样连着减两个的
int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
}
*/
