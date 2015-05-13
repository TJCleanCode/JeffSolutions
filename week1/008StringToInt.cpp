#include <iostream>
#include <cassert> //assert
#include <limits> // std::numeric_limits<int>::min() / max()
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::size_t;
class Solution{
public:
    int myAtoi(string str) {
        size_t lengthStr = str.length();
        size_t index = str.find_first_not_of(" ");
        int sign = 1;
        long int result = 0;
        if(index != std::string::npos){
            if(str[index]=='+'){
                index++;
            }else if(str[index]=='-'){
                sign *= -1;
                index++;
            }
            for(;index < lengthStr;index++){
                if(str[index] < '0'|| str[index] > '9'){
                    break;
                }else {
                    int num = int(str[index] -'0');
                    result = result*10 + num;
                    
                    if(result*sign > std::numeric_limits<int>::max()){
                        return std::numeric_limits<int>::max();
                    }else if(result*sign < std::numeric_limits<int>::min()){
                        return std::numeric_limits<int>::min();
                    }
                }
            }
            

            return result * sign;
        }

        return 0;
    }
}; // class Solution

void testSolution(){
    Solution testSolution;
    //assert(0 == testSolution.myAtoi("+"));
    assert(123 == testSolution.myAtoi("      +123abc"));
    assert( -12345 == testSolution.myAtoi("-12345"));
    assert(std::numeric_limits<int>::max() == testSolution.myAtoi("1111111111111111111111111111111111111"));
    assert(-2147483648 == testSolution.myAtoi("-2147483648"));
    assert(2147483647 == testSolution.myAtoi("2147483647")); 
    cout<<"All test passed"<<endl;
}

                

int main(int argc, char const *argv[])
{
    testSolution();
	return 0;
}
