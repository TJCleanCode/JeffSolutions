#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Solution{
public:
    string convert(string s, int nRows){
        if(1 == nRows){
            return s;
        }
        vector<string> strSeperatedLines(nRows, "");
        int numCompleteLoop = s.size() / ((nRows - 1) * 2); 
        string::iterator it = s.begin();
        for( int i = 0;i < numCompleteLoop;++i){
            for(int j = 0;j < nRows-1;++j){
                strSeperatedLines[j] += *it;
                it++;
            }
            for(int j = nRows -1;j >0;--j){
                strSeperatedLines[j] += *it;
                it++;
            }
        }

        int remainChar = s.size() %((nRows - 1) * 2);
        if(remainChar > 0 && remainChar < nRows){
            for(int i = 0;i < remainChar ;++i){
                strSeperatedLines[i] += *it;
                it++;
            }
        } else if(remainChar >= nRows){
            for(int i = 0;i < nRows-1; ++i){
                strSeperatedLines[i] += *it;
                it++;
            }
            for(int i = nRows-1;i> nRows-1-(remainChar-(nRows-1));--i){
                strSeperatedLines[i] += *it;
                it++;
            }
        }

        string result = "";
        for(int i = 0; i<nRows;++i){
            result += strSeperatedLines[i];
        }
        return result;

                 

    } //string convert()
    
};// class Solution

int main()
{
    Solution testSolution;
    cout<<testSolution.convert("abcdefghijklmnopq",4)<<endl;
    
    return 0;
}
