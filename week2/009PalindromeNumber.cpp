#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
//Determine whether an integer is a palindrome.
// Trick: do this problem without extra space
class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0 ||(x % 10 == 0 && x!= 0)){
            return false;
        }else{
            int result = 0; // is this an extra space??
            int xCopy = x;
            while(result < xCopy){
                result *= 10;
                result += xCopy % 10;
                xCopy /= 10;
            }
cout<<result<<endl;
cout<<xCopy<<endl;
            return (xCopy == result || result/10 == xCopy);
        }
    }// bool isPalindrome(int)
}; // class Solution

void testSolution(){
    Solution testSolution;
    assert(testSolution.isPalindrome(0));
    assert(testSolution.isPalindrome(123321));
    assert(testSolution.isPalindrome(12321));
    assert(!testSolution.isPalindrome(-11));

    cout<<"All tests passed"<<endl;
}

int main(){
    testSolution();

    return 0;
}


