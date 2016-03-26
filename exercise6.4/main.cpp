/**uva679 小球下落
有一颗二叉树，最大深度为D，且所有叶子的深度都相同。所有的结点从上到下从左
到右编号为1，2,3,...，2^D-1。在结点1处放一个小球，它会往下落。每个内结点都
有一个开关，初始全部关闭，当每次有小球落到一个开关上时，状态都会改变。当小
球到达一个结点时，如果该结点上的开关关闭，则往左走，否则往右走，直到走到叶
子结点。
输入叶子深度D和小球个数I，输出第I个小球最后所在的叶子编号。假设I不超过整棵
树的叶子个数。D<=20。输入最多包含1000组数据。
图片：http://www.lai18.com/content/2463157.html

**/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 20;
int s[1<<maxn];

int main()
{
    //cout << "Hello world!" << endl;
    int D,I;

    //第一种做法
    /*while(scanf("%d%d",&D,&I) == 2){
            //初始化开关
        memset(s, 0, sizeof(s));

        //n是最大的节点编号
        int k, n = (1<<D)-1;

        //连续让I个小球下落
        for(int i = 0; i < I; i++){
            k = 1;
            for(;;){
                s[k] = !s[k];

                //根据开关选择下落的方向
                k = s[k] ? k*2 : 2*k+1;
                if(k > n)break;//超出界限范围了
            }
        }
        printf("%d\n", k/2);*/
        while(scanf("%d%d", &D,&I) == 2){
            int k = 1;
            for(int i = 0; i < D-1; i++){
                if(I%2){ k = k*2; I = (I+1)/2;}
                else {
                    k = k*2 + 1;
                    I = I / 2;
                }
            }
            printf("%d\n",k);
            }
    return 0;
}
