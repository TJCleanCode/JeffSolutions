#include <iostream>
#include <stack>
#include <cassert>
#include <string>

using std::string;
using std::stack;
using std::cout;

class Solution{
public:
    bool isValid(string s){
        stack<char> parenthese;
        for(auto it = s.begin();it != s.end();it++){
            if(isStartBrackets(*it)){
                parenthese.push(*it);
            }else if(isEndBrackets(*it)){
                if(parenthese.empty()){
                    return false;
                }else{
                    if(isMatch(parenthese.top(), *it)){
                        parenthese.pop();
                    }else{
                        return false;
                    }
                }
            }
        }

        return parenthese.empty();

    }

    bool isStartBrackets(const char character){
        return (character == '(') || (character == '{') || (character == '[');
    }
    bool isEndBrackets(const char character){
        return (character == ')') || (character == '}') || (character == ']');
    }
    
    bool isMatch(const char startBrack,const char endBrack){
        return (startBrack == '(' && endBrack == ')') || \
               (startBrack == '{' && endBrack == '}') || \
               (startBrack == '[' && endBrack == ']');
    }
};



int main(){
    Solution testSolution;
    cout<<testSolution.isValid("((((()))))");
    cout<<testSolution.isValid("[][][](([[]]))(");
    cout<<testSolution.isValid("fjdkslajfasl");

    return 0;
}   
