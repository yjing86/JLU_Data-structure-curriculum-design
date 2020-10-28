#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/********************************************************************************/
/********************************将学生的代码添加到下面******************************/

void clean(int a[30][30],const int q,const int p,const int n,const int m,const int k){
    for(int i=q;i<p;i++){
        for(int j=n;j<m;j++){
            a[i][j]=k;
        }
    }
}
void dig(int GamePanel[30][30], int i, int j, int n, int m, int mine[30][30]) {
    GamePanel[i][j] = 0;
    for (int q = i - 1; q <= i + 1; q++) {
        if (q >= 0 && q < n) {
            for (int p = j - 1; p <= j + 1; p++)
                if (0<=p && p < m && GamePanel[q][p] == -1){
                    if (mine[q][p] != 0)
                        GamePanel[q][p] = mine[q][p];
                    else
                        dig(GamePanel, q, p, n, m, mine);
                }
        }
    }
}
int panduan(int a[30][30],int b[30][30],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==-1&&b[i][j]!=-1){
                return -1;
            }
        }
    }
    return 0;
}
int calculate(int a[30][30], int i, int j, int k) {
    int count = 0;
    if (a[i - 1][j - 1] == k)
        count++;
    if (a[i - 1][j] == k)
        count++;
    if (a[i - 1][j + 1] == k)
        count++;
    if (a[i][j - 1] == k)
        count++;
    if (a[i][j + 1] == k)
        count++;
    if (a[i + 1][j - 1] == k)
        count++;
    if (a[i + 1][j] == k)
        count++;
    if (a[i + 1][j + 1] == k)
        count++;
    return count;
}
int open(int gamepanel[30][30], int mine_all[30][30], int mark[30][30], int n, int m, int i, int j) {
    int count=mine_all[i][j]+1;
    int panduan=(mark[i - 1][j - 1] == 0 && gamepanel[i - 1][j - 1] == -1 );
    if (panduan&& mine_all[i - 1][j - 1] != -1) {
        mark[i - 1][j - 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i - 1, j - 1);
    }
    panduan=(mark[i - 1][j] == 0 && gamepanel[i - 1][j] == -1) ;
    if (panduan&& mine_all[i - 1][j] != -1) {
        mark[i - 1][j] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i - 1, j);
    }
    panduan=(mark[i - 1][j + 1] == 0 && gamepanel[i - 1][j + 1] == -1 );
    if (panduan&& mine_all[i - 1][j + 1] != -1) {
        mark[i - 1][j + 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i - 1, j + 1);
    }
    panduan=(mark[i][j - 1] == 0 && gamepanel[i][j - 1] == -1 );
    if (panduan&& mine_all[i][j - 1] != -1) {
        mark[i][j - 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i, j - 1);
    }
    panduan=(mark[i][j + 1] == 0 && gamepanel[i][j + 1] == -1 );
    if (panduan&& mine_all[i][j + 1] != -1) {
        mark[i][j + 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i, j + 1);
    }
    panduan=(mark[i + 1][j - 1] == 0 && gamepanel[i + 1][j - 1] == -1);
    if (panduan&& mine_all[i + 1][j - 1] != -1) {
        mark[i + 1][j - 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i + 1, j - 1);
    }
    panduan=(mark[i + 1][j] == 0 && gamepanel[i + 1][j] == -1);
    if (panduan && mine_all[i + 1][j] != -1) {
        mark[i + 1][j] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i + 1, j);
    }
    panduan=(mark[i + 1][j + 1] == 0 && gamepanel[i + 1][j + 1] == -1 );
    if (panduan&& mine_all[i + 1][j + 1] != -1) {
        mark[i + 1][j + 1] = 1;
        count += open(gamepanel, mine_all, mark, n, m, i + 1, j + 1);
    }
    return count;
}
int next(int gamepanel[30][30],int mine_all[30][30],int mark[30][30],int n,int m,int &x,int &y,int a,int b){
    int number=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            clean(mark, 0, 30, 0, 20, 0);
            if ((mine_all[i][j] == a||mine_all[i][j]==b) && gamepanel[i][j] == -1) {
                int t = open(gamepanel, mine_all, mark, n, m, i, j);
                if (t > number) {
                    number = t;
                    x = i;
                    y = j;
                }}}}
    x--;
    y--;
    return number;
}
int RefreshGamePanel(int GamePanel[30][30], int x, int y, int mine[30][30], int n, int m, int k){
    int answer[30][30]={0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (mine[i][j] == 1){
                answer[i][j] = -1;
                for (int q = i - 1; q <= i + 1; q++) {
                    if (q >= 0 && q < n) {
                        for (int p = j - 1; p <= j + 1; p++)
                            if (p >= 0 && p < m && answer[q][p] != -1)
                                answer[q][p]++;
                    }
                }
            }
    }
    if (GamePanel[x][y] == -1) {
        if (answer[x][y] == -1) {
            return -1;
        }
        else if (answer[x][y] != 0)
            GamePanel[x][y] =answer[x][y];
        else
            dig(GamePanel, x, y, n, m, answer);
        if(panduan(GamePanel,answer,n,m)==0)
            return 1;
    }
    return 0;
}
void machine(int GamePanel[30][30], int n, int m, int& x, int& y){
    int gamepanel[30][30]={0};
    int mine_all[30][30]={0};
    clean(mine_all, 0, 30, 0, 30, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            gamepanel[i+1][j+1] = GamePanel[i][j];
            if (gamepanel[i+1][j+1] != -1)
                mine_all[i+1][j+1] = 1;
        }
    }
    int opennumber = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (gamepanel[i][j] != -1)
                opennumber++;
        }
    }
    if (opennumber == 0) {
        x = n - 1;
        y = m - 1;
        return;
        //first
    }
    int temp=0;
    do{
        temp=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (gamepanel[i][j] != -1) {
                    if (calculate(gamepanel, i, j, -1) == gamepanel[i][j]||(calculate(mine_all, i, j, 1) + gamepanel[i][j]) == 8){
                        // all mine
                        if (gamepanel[i - 1][j - 1] == -1 && mine_all[i - 1][j - 1] == 0) {
                            mine_all[i - 1][j - 1] = -1;
                            temp++;
                        }
                        if (gamepanel[i - 1][j] == -1 && mine_all[i - 1][j] == 0) {
                            mine_all[i - 1][j] = -1;
                            temp++;
                        }
                        if (gamepanel[i - 1][j + 1] == -1 && mine_all[i - 1][j + 1] == 0) {
                            mine_all[i - 1][j + 1] = -1;
                            temp++;
                        }
                        if (gamepanel[i][j - 1] == -1 && mine_all[i][j - 1] == 0) {
                            mine_all[i][j - 1] = -1;
                            temp++;
                        }
                        if (gamepanel[i][j + 1] == -1 && mine_all[i][j + 1] == 0) {
                            temp++;
                            mine_all[i][j + 1] = -1;
                        }
                        if (gamepanel[i + 1][j - 1] == -1 && mine_all[i + 1][j - 1] == 0) {
                            mine_all[i + 1][j - 1] = -1;
                            temp++;
                        }
                        if (gamepanel[i + 1][j] == -1 && mine_all[i + 1][j] == 0) {
                            mine_all[i + 1][j] = -1;
                            temp++;
                        }
                        if (gamepanel[i + 1][j + 1] == -1 && mine_all[i + 1][j + 1] == 0) {
                            mine_all[i + 1][j + 1] = -1;
                            temp++;
                        }}}}}
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (gamepanel[i][j] != -1) {
                    if (calculate(mine_all, i, j, -1) == gamepanel[i][j] ){
                        //all fine
                        if (mine_all[i - 1][j - 1] == 0) {
                            temp++;
                            mine_all[i - 1][j - 1] = 1;
                        }
                        if (mine_all[i - 1][j] == 0) {
                            mine_all[i - 1][j] = 1;
                            temp++;
                        }
                        if (mine_all[i - 1][j + 1] == 0) {
                            mine_all[i - 1][j + 1] = 1;
                            temp++;
                        }
                        if (mine_all[i][j - 1] == 0) {
                            mine_all[i][j - 1] = 1;
                            temp++;
                        }
                        if (mine_all[i][j + 1] == 0) {
                            mine_all[i][j + 1] = 1;
                            temp++;
                        }
                        if (mine_all[i + 1][j - 1] == 0) {
                            temp++;
                            mine_all[i + 1][j - 1] = 1;
                        }
                        if (mine_all[i + 1][j] == 0) {
                            mine_all[i + 1][j] = 1;
                            temp++;
                        }
                        if (mine_all[i + 1][j + 1] == 0) {
                            mine_all[i + 1][j + 1] = 1;
                            temp++;
                        }}}}}}
    while (temp != 0 );
    int mark[30][30];
    if(next(gamepanel,mine_all,mark,n,m,x,y,1,1)!=0)
        return;
    if(next(gamepanel,mine_all,mark,n,m,x,y,1,0)!=0)
        return;
    clean(mark, 0, 30, 0, 30, 0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(gamepanel[i][j]==-1&&mine_all[i][j]!=-1){
                x --;
                y --;
                return;
            }
        }
    }
}

/********************************将学生的代码添加到上面******************************/
/********************************************************************************/



int main()
{
    int GamePanel[30][30];
    int temp[30][30];
    int mine[30][30];
    int iii, ii, n, m, k, i, j, minenum, x, y, win = 0;
    int bonus;
    double score;
    double  maxscore = -999, minscore = 999, sumscore=0;
    int gamenum = 1000;
    int zerocnt = 0;
    int winnum = 0;
    n = 20;
    m = 20;
    minenum = 50;
    srand(int(time(0)));
    printf("正在评测中，请稍等，我们将进行1000局游戏，取平均分*1.3作为最终成绩......\n");
    
    for (iii = 0; iii<gamenum; iii++)
    {
        
        for (i = 0; i<n; i++)
            for (j = 0; j<m; j++)
            {
                GamePanel[i][j] = -1;
                mine[i][j] = 0;
            }
        
        int cnt = 0;
        
        for (ii = 0; ii<400; ii++)
        {
            for (i = 0; i < 20; i++)
                for (j = 0; j < 20; j++)
                    temp[i][j] = GamePanel[i][j];
            machine(temp, n, m, x, y);
            if (ii == 0)
            {
                for ( k = 0; k < minenum; k++)
                {
                    i = rand() % 20;
                    j = rand() % 20;
                    while ((i == x && j == y) || mine[i][j] != 0)
                    {
                        i = rand() % 20;
                        j = rand() % 20;
                    }
                    mine[i][j] = 1;
                }
            }
            if (GamePanel[x][y] == -1)
            {
                cnt++;
                win = RefreshGamePanel(GamePanel, x, y, mine, n, m, minenum);
                if (win == 1)
                {
                    if (cnt < 80) bonus = 10;
                    else if (cnt < 90) bonus = 9;
                    else if (cnt < 100) bonus = 8;
                    else if (cnt < 120) bonus = 7;
                    else if (cnt < 150) bonus = 5;
                    else if (cnt < 200) bonus = 3;
                    else if (cnt < 250) bonus = 1;
                    else bonus = 0;
                    score = 50.0 + bonus;
                    if(iii==0 || (iii+1)%10==0) printf("第 %d 局,赢了,得 %d 分.\n", iii+1,(int)score);
                    winnum++;
                    
                    break;
                }
                else if (win == -1)
                {
                    score = 0;
                    for (i = 0; i<n; i++)
                        for (j = 0; j<m; j++)
                        {
                            if (GamePanel[i][j] != -1)
                                score=score+1;
                        }
                    score = score/10;
                    
                    if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);
                    
                    break;
                }
            }
            
        }
        if (win == 0)
        {
            score = 0;
            for (i = 0; i<n; i++)
                for (j = 0; j<m; j++)
                {
                    if (GamePanel[i][j] != -1)
                        score=score+1;
                }
            score = score / 10;
            if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);
            
        }
        if (score>maxscore) maxscore = score;
        if (score<minscore) minscore = score;
        sumscore = sumscore+score;
        
    }
    
    int orignscore,finalscore;
    
    orignscore= ceil(1.3*ceil(sumscore/gamenum));
    
    if (orignscore > 60) finalscore = 60;
    else finalscore = orignscore;
    //printf("该学生原始分数为 %d.\n\n", orignscore);
    
    
    printf("该学生最终分数为 %d.\n\n", finalscore);
    printf("该学生胜率为 %.1lf%%\n\n", winnum/10.0);
    
    system("pause");
    return 0;
}
