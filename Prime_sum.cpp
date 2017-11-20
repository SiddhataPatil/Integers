/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : iven an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
 Example     : Input : 4
               Output: 2 + 2 = 4
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  vector<int> primesum(int A) ;
}obj;

vector<int> Solution::primesum(int A)
{
    vector<int> A1;
    int sq_root = sqrt(A);
    bool *array1=new bool[A+1];

    for(int i=0;i<=A;i++)
    {
      array1[i]=0;
    }

    for(int i=2;i<=sq_root;i++)
    {
        if(array1[i]==0)
        {
            for(int j=i;j<=A/i;j++)
            {
              array1[i*j]=1;
            }
          }
    }
    for(int i=2;i<A;i++)
    {
      if(!array1[i] && !array1[A-i])
      {
          A1.push_back(i);
          A1.push_back(A-i);
          return A1;
      }
    }
return A1;
}

int main()
{
  vector<int> B;
  int result=0;
  B= obj.primesum(252) ;
  cout<<"Prime sum = 252"<<endl;
  cout<<"For the above Primesum, Prime numbers are as follows: "<<endl;
  for (int i=0; i<B.size();i++)
  {
    cout<<B[i]<<endl;
  }
  return 0;
}
