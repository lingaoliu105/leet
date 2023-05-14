#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool queryString(string s, int n)
    {
        vector<int> initVec = vector<int>();
        for (int i = 0;i<s.length();i++){
            initVec.push_back(i);
        }
        return containString(s,"1",initVec,n);
    }

    bool containString(string super, string sub, vector<int> indices,int n){
        int len = sub.length();
        if (strToInt(sub)>n && !indices.empty()) return true;
        int size = indices.size();
        vector<int> childVec = vector<int>();
        for (int i = 0;i<size;i++){
            int index = indices.at(i);
            if (super.substr(index,len)==sub){
                childVec.push_back(index);
            }
        }
        if (indices.empty()) return false;
        return containString(super, sub + "0", childVec, n) && containString(super, sub + "1", childVec, n);
    }

    int strToInt(string bin){
        int len = bin.length();
        int total = 0;
        for (int i = 0;i<len;i++){
            total+= (bin.at(i)-48)<<(len-i-1);
        }
        return total;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    cout << s.strToInt("1010") << endl;
    bool b = s.queryString("10010111100001110010",10);
    return 0;
}
