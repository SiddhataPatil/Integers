/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Unique Paths
 Example     : For 2x2 unique paths from top left to bottom right are 2
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int uniquePaths(int A, int B);
}obj;

int Solution::uniquePaths(int A, int B)
{
  if(A==1 || B==1)
  {
    return 1;
  }
  return (uniquePaths(A-1,B)+uniquePaths(A,B-1));
}

int main()
{
  int result=0;
  result= obj.uniquePaths(4,4) ;
  cout<< "For 4x4 matrix"<<endl;
  cout<< "Unique paths: "<< result<<endl;
  return 0;
}
