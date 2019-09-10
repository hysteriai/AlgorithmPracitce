/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
*/

/*
摩斯码的映射存在二维数组中。然后通过map做摩斯码的去重
运行时间和内存使用都击败100%的其他程序
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int uniNum = 0;
        map <string, int> Morse;
        char asz[26][12] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int size = words.size();
        for (int i = 0; i < size; ++i)
        {
            string MorseCode = "";
            for (char &c : words[i])
            {
                MorseCode += asz[c - 'a'];
            }

            Morse[MorseCode] = 0;
        }
        return (int) Morse.size();
    }
};

/*
用set或者unordered_set看起来更直观一些，但是使用的内存更多。
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int uniNum = 0;
        set<string> Morse;
        char asz[26][12] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int size = words.size();
        for (int i = 0; i < size; ++i)
        {
            string MorseCode = "";
            for (char &c : words[i])
            {
                MorseCode += asz[c - 'a'];
            }

            Morse.insert(MorseCode);
        }
        return (int) Morse.size();
    }
};
