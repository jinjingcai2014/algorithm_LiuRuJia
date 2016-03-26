/**给出一系列的矩阵，给他们取名A ，B……   以及它们的行数和列数。给完后，
给出一系列的表达式，然后要求求出按这些表达式进行计算，会有多少次
乘法步骤。
SecondPart = Line { Line } <EOF>
Line       = Expression <CR>
Expression = Matrix | "(" Expression Expression ")"
Sample Input
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))Matrix     = "A" | "B" | "C" | ... | "X" | "Y" | "Z"
**/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

struct Matrix{
    int a, b;
    Matrix(int a = 0, int b = 0):a(a),b(b){}
}m[26];

using namespace std;
stack<Matrix>s;

int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >>name;
        int k = name[0] - 'A';
        cin >>m[k].a>>m[k].b;
    }

    string expr;
    while(cin >> expr){
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for(int i = 0; i < len ; i++){
            if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
            else if(expr[i] == ')'){
                Matrix m2 = s.top(); s.pop();
                Matrix m1 = s.top(); s.pop();
                if(m1.b != m2.a){error = true; break;}
                ans += m1.a*m1.b*m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if(error)cout<<"error\n"<<endl;
        else cout<<ans;
    }
    return 0;
}
