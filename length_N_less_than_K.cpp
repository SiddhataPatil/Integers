/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Numbers of length N and value less than K
 Example     : A={3,0,1,5} length 1 and less than 2 = 2 numbers 1 and 0
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int solve(vector<int> &A, int B, int C);
}obj;

int Solution::solve(vector<int> &A, int B, int C) {
   if(A.size() == 0)
   {
     return 0;
   }

   int k = 0 ;
   int less_than = C;
   int length_of_numbers = B;

   vector<int> resulting_array;

   while(less_than > 0)//  2digits > 0
   {   //    cout<<"less-------"<<less_than<<endl;
       ++k; //1
       resulting_array.push_back(less_than%10); // 2
       less_than /= 10; // 2 /=10 = 0
    //   cout<<"less_than"<<less_than<<endl;
   }

//   cout << "length_of_numbers= "<<length_of_numbers <<  " " << "k="<<k << endl;
///////////////////////////////////////
//If B is greater than length of C
   if(length_of_numbers < k) //  2digits < 0
   {
       int sum = A.size(); //4
       if(A[0] == 0 && length_of_numbers != 1) --sum; //
       for(int i = 0; i < length_of_numbers-1 /* 1*/; ++i)
       {
           sum *= A.size();
       }
      // cout<<"sum"<<sum<<endl;
       return sum;

   }

   else if(length_of_numbers > k) // 2>2
   {
       return 0;
   }
//////////////////////////////////////////////////////////
   else
   {
       reverse(resulting_array.begin(),resulting_array.end());

       vector<int> smaller_than_i(10);
      // cout<<"k="<<k<<endl;
       vector<int> first(k);

       for(int i = 0; i < k /*2*/; ++i)
       {
           for(int j = 0 ; j < A.size()/*4*/; ++j)
           {
               if(resulting_array[i] == A[j] && i != 0 && first[i-1] == i)
               {
          //         cout << A[j] << " " << resulting_array[i] << endl;
                   first[i] = i+1;
               } else if (i == 0 && resulting_array[i] == A[j]) first[i] = 1;
           }
       }

       cout << endl;

       for(int i =  0; i < 10; ++i)
       {
           for(int j = 0; j < A.size(); ++j)
           {
               if(A[j] < i)
               {
                   ++smaller_than_i[i];
               }
           }
       }

       vector<int> D(length_of_numbers);

       D[0] += smaller_than_i[resulting_array[0]];
       //cout << D[0] << endl;

       if(A[0] == 0 && length_of_numbers!=1)
       {
          D[0]--;
       }

       for(int i = 1; i  < length_of_numbers; ++i)
       {
           D[i] += D[i-1]*A.size();
           if(first[i-1] == i)
                D[i] += smaller_than_i[resulting_array[i]];
           cout << i << " " << D[i-1]*A.size() << " " << \
           first[i] << " " << smaller_than_i[resulting_array[i]] << endl;
       }
       return D[length_of_numbers-1];
   }

}

int main()
{
  int A1[4] = {3,0,1,5};
//  cout<<"Given array {3,0,1,5} how many numbers are 1 digit less than 2"<<endl;
	vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  int result=0;
  result = obj.solve(A,2,20) ;
//  cout<<result<<endl;
  return 0;
}
