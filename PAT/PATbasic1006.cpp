/*


让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。
输入样例1：

234

输出样例1：

BBSSS1234

输入样例2：

23

输出样例2：

SS123

*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int jws(int a) {
  int count = 0;
  while (a) {
    count++;
    a = a / 10;
  }
  return count;
}
void bai(int b) {
  if (b > 0) {
    for (int i = 0; i < b; i++) {
      cout << "B";
    }
  }
}
void shi(int b) {
  if (b > 0) {
    for (int i = 0; i < b; i++) {
      cout << "S";
    }
  }
}
void ge(int b) {
  if (b > 0) {
    for (int i = 1; i <= b; i++) {
      cout << i;
    }
  }
}
int main() {
  int n;
  cin >> n;
  if (jws(n) == 3) {
    bai(n / 100);
    n = n - 100 * (n / 100);
    shi(n / 10);
    ge(n % 10);
    cout << endl;
  } else if (jws(n) == 2) {
    shi(n / 10);
    ge(n % 10);
    cout << endl;
  } else {
    ge(n);
    cout << endl;
  }
  return 0;
}
