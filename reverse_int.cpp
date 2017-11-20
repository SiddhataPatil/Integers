/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Reverse an integer
 Example     : Given [123] return [321]
 ==============================================================================================================================
 */

#include <iostream>
using namespace std;

class Solution
{
public:
  int ReverseInteger (int no);
}obj;

int overflow (int reminder, int rev_num)
{
    if (rev_num > (INT_MAX / 10) || (rev_num == (INT_MAX / 10) \
    && reminder > (INT_MAX % 10)))
    {
      return 0;
    }
    return 1;
}

int Solution::ReverseInteger (int no)
{
  int reminder = 0;
  int rev_num=0;
  bool negative = false;
  bool check = false;
  while (no!=0)
  {
    if (no<0)
    {
      no=abs(no);
      negative=true;
    }
    reminder = no%10;
    check=overflow(reminder,rev_num);
    if(check)
    {
      rev_num=rev_num*10;
      rev_num=rev_num+reminder;
      no=no/10;
    }
    else
    {
      cout<<"Given Number is out of range"<<endl;
      return -1;
    }
  }
  if(negative) // if number is negative, reverse number should also be negative
  {
    return rev_num*-1;
  }
  return rev_num;
}

int main()
{
  int number=123;
  //int number=-2147483648;
  cout<<"Original number = 123"<<endl;
  cout<<"Reverse number = ";
  int result=0;
  result= obj.ReverseInteger(number) ;
  cout<<result<<endl;
  return 0;
}
