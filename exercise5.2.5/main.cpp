/**
丑数uva136
丑数是指不能被2,3,5以外的其他素数整数的数，
把丑数从小到大排列起来，结果如下：
1,2,3,4,5,6,8,9,10,12,15....
求第1500个丑数

**/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;
const int coeff[3] = {2,3,5};
int main()
{
    //cout << "Hello world!" << endl;
    priority_queue<LL,vector<LL>,greater<LL>>pq;
    set<LL>s;
    pq.push(1);
    s.insert(1);
    for(int i = 1; ; i++)
    {
        LL x = pq.top();
        pq.pop();
        if(i == 1500){
            cout<<"The 1500 ugly number is "<<x<<".\n";
            break;
        }
        for(int j = 0; j < 3; j++){
            LL x2 = x*coeff[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }

    return 0;
}
