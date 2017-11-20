/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space
 Example     : Input : [1, 0]
               Return : [0, 1]
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void arrange(vector<int> &A);
}obj;

void Solution::arrange(vector<int> &A)
{
    int temp=A.size();

    for(int i=0;i<A.size();i++)
    {
        A[i]+=(A[A[i]]%temp)*temp;
    }

    for(int i=0;i<temp;i++)
    {
      A[i]/=temp;
    }
}

int main()
{
  int array1[2]={1,0};
  vector<int> A (array1, array1+sizeof(array1)/sizeof(array1[0]));
  int result=0;
  obj.arrange(A) ;
  for (int i=0; i<A.size();i++)
  {
    cout<<A[i]<<endl;
  }
  return 0;
}
