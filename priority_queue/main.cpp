#include <iostream>
#include <queue>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    priority_queue<float>q1;
    q1.push(66.6);
    q1.push(22.2);
    q1.push(44.4);
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.size()<<endl;


    cout<<"***************"<<endl;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0; i < 10; i++)
        q.push(i);
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}
