/*
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0*/

#include <iostream>
using namespace std;
int get(int n1,int n2){
int result=0;
while(n1){
  if((n1%10)==n2)
    result=n2+result*10;
  n1/=10;
}
  return result;
}
int main(){
  int a,da,b,db;
  cin>>a>>da>>b>>db;
  int pa,pb;
  pa=get(a,da);
  pb=get(b,db);
 cout<<pa+pb;
  return 0;
}
