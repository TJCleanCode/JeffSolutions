#include <iostream>
#include <string>   
#include <unordered_map>
using namespace std;
class Solution{
public:
    bool isHappy(int n){
        int convertNum = SumOfDigitsSquares(n);
        unordered_map<int, bool> convertNumSet;
        convertNumSet[n] = true;
        while(true){
            if(1 == convertNum){
                return true;
            }else if(convertNumSet.find(convertNum)!=convertNumSet.end()){
                return false;
            }
            convertNumSet[convertNum] = true; 
            convertNum = SumOfDigitsSquares(convertNum);
        }
    }
    int SumOfDigitsSquares(int intNum){
        std::string strNum = std::to_string(intNum);
        auto sumSquares = 0;
        for(std::string::iterator it = strNum.begin();it!=strNum.end();++it){
            int intDigit = *it - '0';
            sumSquares += intDigit*intDigit;
        }
        return sumSquares;
    }
            
      
};
void testSumOfDigitsSquares(){
    Solution testSolution;
    int resultOf100 = testSolution.SumOfDigitsSquares(100);
    int resultOf123 = testSolution.SumOfDigitsSquares(123);
    bool flag = true;
    if(resultOf100 != 1){
        flag = false;
        cout<<"Wrong ans --100:"<<resultOf100<<endl;
    }
    if(resultOf123 != 14){
        flag = false;
        cout<<"Wrong ans --123:"<<resultOf123<<endl;
    }
    if(flag){
        cout<<"All tests passed"<<endl;
    }
}
int main()
{
    Solution testSolution;
    cout<<testSolution.isHappy(19)<<endl;
    cout<<testSolution.isHappy(100)<<endl;
    cout<<testSolution.isHappy(22)<<endl;
    return 0;
}

