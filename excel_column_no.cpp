/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given a column title as appears in an Excel sheet, return its corresponding column number.
 Example     : A=1, B=2...AA=27 etc.
 ==============================================================================================================================
 */

#include <iostream>
using namespace std;

class Solution
{
public:
  int titleToNumber(string);
}obj;

int Solution::titleToNumber(string A)
{
       int result = 0;
       for (int i = 0; i < A.size(); i++) {
               result = result * 26 + (A[i] - 'A' + 1);
       }
       return result;
}

int main()
{
  string s = "AA";
  int result=0;
  result= obj.titleToNumber(s) ;
  cout<< "AA = ";
  cout<<result<<endl;
  return 0;
}
