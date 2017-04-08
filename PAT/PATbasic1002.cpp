/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1
空格，但一行中最后一个拼音数字后没有空格。
输入样例：

1234567890987654321123456789

输出样例：

yi san wu


*/
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
string fun(int c) {
  string mid;
  switch (c) {
  case 0:
    mid = "ling";
    break;
  case 1:
    mid = "yi";
    break;
  case 2:
    mid = "er";
    break;
  case 3:
    mid = "san";
    break;
  case 4:
    mid = "si";
    break;
  case 5:
    mid = "wu";
    break;
  case 6:
    mid = "liu";
    break;
  case 7:
    mid = "qi";
    break;
  case 8:
    mid = "ba";
    break;
  case 9:
    mid = "jiu";
    break;
  default:
    mid = "ling";
    break;
  }
  return mid;
}
int jws(int b) {
  int count = 0;
  while (b) {
    b = b / 10;
    count++;
  }
  return count;
}
int main() {
  string s1;
  cin >> s1;
  int sum = 0;
  for (int a = 0; a < s1.length(); a++) {
    sum += (int)s1[a] - 48;
  }
  int ss = jws(sum);
  vector<string> vec;
  for (int i = ss; i > 0; i--) {
    vec.push_back(fun(sum % 10));
    sum = sum / 10;
  }
  for (int j = ss - 1; j >= 0; j--) {
    cout << vec[j];
    if (j > 0) {
      cout << " ";
    }
  }
  return 0;
}
