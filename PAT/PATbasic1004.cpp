/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩

其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int n;
  cin >> n;
  int a[n];
  string name[n];
  string grade[n];
  for (int i = 0; i < n; i++) {
    cin >> name[i];
    cin >> grade[i];
    cin >> a[i];
  }
  string max1, max2;
  string min1, min2;
  int temp1 = 0, temp2 = 100;
  for (int j = 0; j < n; j++) {
    if (a[j] > temp1) {
      max1 = name[j];
      max2 = grade[j];
      temp1 = a[j];
    }
    if (a[j] < temp2) {
      min1 = name[j];
      min2 = grade[j];
      temp2 = a[j];
    }
  }
  cout << max1 << " " << max2 << endl;
  cout << min1 << " " << min2 << endl;
  return 0;
}
