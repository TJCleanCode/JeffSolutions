#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        return isReplaced(s,t) && isReplaced(t,s);
    }
    bool isReplaced(string s, string t){
    size_t lengthStr = s.size();
    unordered_map<char,char> mapChar;
    for(size_t i=0;i<lengthStr;++i){
        mapChar[s[i]] = t[i];
    }
    
    for(size_t i=0;i<lengthStr;++i){
        if(t[i] != mapChar[s[i]]){
            return false;
        }
    }
    return true;
    }
};


int main(){
    Solution testSolution;
    string test1S = "abb";
    string test1T = "acc";
    cout<<testSolution.isIsomorphic(test1S,test1T)<<endl;
}
