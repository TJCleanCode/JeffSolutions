#include <iostream>
#include <string>
#include <cassert>
using std::string;



class Solution{
public:
    unsigned int RomanSymbolToInt(const char symbol){
        if('I' == symbol){
            return 1;
        }else if('V' == symbol){
            return 5;
        }else if('X' == symbol){
            return 10;
        }else if('L' == symbol){
            return 50;
        }else if('C' == symbol){
            return 100;
        }else if('D' == symbol){
            return 500;
        }else if('M' == symbol){
            return 1000;
        }else{
            std::cout<<"Invalid Roman Symbol"<<std::endl;
            return 0; // There is no zero in Roman numerals
        }
    }

    int romanToInt(string s){
        int intRomanNum = 0;
        int lastNum = 0;
        for(auto it = s.rbegin();it!=s.rend();++it){
            int intRomanSymbol = RomanSymbolToInt(*it);
            if(intRomanSymbol >= lastNum){
                intRomanNum = intRomanSymbol + intRomanNum;
                lastNum = intRomanSymbol;
            }else{
                intRomanNum -= intRomanSymbol;
            }
        }
        std::cout<<intRomanNum<<std::endl;
        return intRomanNum;
    } // int romanToInt
}; // class Solution


void testRomanToInt(){
    Solution testSolution;
    assert(testSolution.romanToInt("MCM") == 1900);
    assert(testSolution.romanToInt("XCVIII") == 98);

    std::cout<<"All tests passed"<<std::endl;
}


int main(){
    testRomanToInt();
    return 0;
}





