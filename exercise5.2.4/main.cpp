/**uva 156 题意：不能通过字母重拍得到输入文中其他单词的单词
*测试用例***
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
****************结果*************
Disk
NotE
derail
drIed
eye
ladder
soon
**/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int>cnt;
vector<string>words;

//将单词进行标准化
string repr(const string&s){
    string ands = s;
    for(int i = 0; i < ands.length(); i++)
    {
        ands[i] = tolower(ands[i]);
    }
    sort(ands.begin(), ands.end());
    return ands;
}

int main()
{
    //cout << "Hello world!" << endl;
    int n = 0;
    string s;
    while(cin >> s){
        if(s[0] == '#')break;
        words.push_back(s);

        //将单词进行标准化
        string r = repr(s);
        if(!cnt.count(r))cnt[r] = 0;
        cnt[r]++;
    }
    vector<string>ans;
    for(int i = 0; i < words.size(); i++)
    {
        if(cnt[repr(words[i])] == 1)ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<"\n";
    return 0;
}
