/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of
using extra space.

You could also try reversing an integer. However, if you have solved the problem
"Reverse Integer", you know that the reversed integer might overflow. How would
you handle such case?

There is a more generic way of solving this problem.


*/
public class Solution {
  public boolean isPalindrome(int x) {
    int i = 0;
    int rev = 0;
    int n = x;
    if (x < 0)
      return false;
    else {
      while (true) {
        i = x % 10;
        rev = rev * 10 + i;
        x /= 10;
        if (x == 0)
          break;
      }
      if (rev == n)
        return true;
      else
        return false;
    }
  }
}
