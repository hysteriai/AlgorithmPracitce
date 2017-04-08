/*

一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；
然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2

现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：

输入第一行给出正整数N（<=
100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

输出格式：

按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。
如果所有号码都正常，则输出“All passed”。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char yzm(string s);
int main() {
  int N;
  cin >> N;
  char a[100][N];

  scanf("%s", a);

  int flag = 0;
  for (int i = 0; i < N; ++i) {
    s = yzm(v[i]);
    s1 = v[i];
    if ((string)s == s1[17])
      continue;
    else
      flag = 1;
    cout << v[i] << endl;
  }
  if (flag == 0)
    cout << "All passed" << endl;
}
char yzm(char a[][]) {
  int num = 0;
  num = (int)s[0] * 7 + (int)s[1] * 9 + (int)s[2] * 10 + (int)s[3] * 5 +
        (int)s[4] * 8 + (int)s[5] * 4 + (int)s[6] * 2 + (int)s[7] * 1 +
        (int)s[8] * 6 + (int)s[9] * 3 + (int)s[10] * 7 + (int)s[11] * 9 +
        (int)s[12] * 10 + (int)s[13] * 5 + (int)s[14] * 8 + (int)s[15] * 4 +
        (int)s[16] * 2;
  int r = num % 11;
  switch (r) {
  case 0:
    return '1';
  case 1:
    return '0';
  case 2:
    return 'X';
  case 3:
    return '9';
  case 4:
    return '8';
  case 5:
    return '7';
  case 6:
    return '6';
  case 7:
    return '5';
  case 8:
    return '4';
  case 9:
    return '3';
  case 10:
    return '2';
  }
}
