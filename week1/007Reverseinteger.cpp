#include <iostream>
#include <limits>
#include <cstdlib>

using std::cout;
using std::endl;
using std::numeric_limits;
//using std::abs() is it ok

class Solution{
public:
    int reverse(int x){
        long int longX = std::abs(x);
        long int result = 0;
        while(longX){
            result *=10;
            result += longX%10;
            longX /= 10;
        }
        //The result overflows
        // the value of numeric_limits<int>::max() is 2147483647
        // the value of numeric_limits<int>::min() is -2147483648
        if(result > numeric_limits<int>::max() || result < numeric_limits<int>::min() ){
            return 0;
        }else {
            return x > 0 ? result : (-result);
        }
    }// int reverse()

};// class Solution

void testReverse(){
    Solution testSolution;
    int test1 = 12321, result1 = testSolution.reverse(test1);
    int test2 = 1000000009, result2 = testSolution.reverse(test2);
    int test3 = 123000, result3 = testSolution.reverse(test3);
    int test4 = -1230, result4 = testSolution.reverse(test4);
    int test5 = -test2, result5 = testSolution.reverse(test5);
    bool flag = true;
    if(12321 != result1){
        cout<<"Wrong Ans, input value->"<<test1<<", get the value"<<result1<<endl;
        flag = false;
    }
    if(0 != result2){
        cout<<"Wrong Ans, input value->"<<test2<<", get the value"<<result2<<endl;
        flag = false;
    }
    if(321 != result3){
        cout<<"Wrong Ans, input value->"<<test3<<", get the value"<<result3<<endl;
        flag = false;
    }
    if(-321 != result4){
        cout<<"Wrong Ans, input value->"<<test4<<", get the value"<<result4<<endl;
        flag = false;
    }
    if(0 != result5){
        cout<<"Wrong Ans, input value->"<<test5<<", get the value"<< result5<<endl;
        flag = false;
    }

    if(flag){
        cout<<"All tests passed"<<endl;
    }
}

int main(){
    testReverse();

    return 0;
}


