/*
令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
bool isprime(int m) {

  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      return false;
    }
  }
  return true;
}
int main(){
int m,n;
cin>>m>>n;
int flag=1;
for(int i=0;flag<=n+3;i++)
{
  if(isprime(i))
  {
    vec.push_back(i);
    flag++;
  }
}
int flag1=1;
for(int j=m+1;j<=n+1;j++)
{
  if(flag1%10==0)
    cout<<vec[j]<<endl;
  else if(flag1<=(n-m))
    cout<<vec[j]<<" ";
  else
     cout<<vec[j];
  flag1++;
}



}
