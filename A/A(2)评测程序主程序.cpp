#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


/********************************************************************************/
/********************************将学生的代码添加到下面******************************/










/********************************将学生的代码添加到上面******************************/
/********************************************************************************/



int main()
{
	int GamePanel[30][30];
	int temp[30][30];
	int mine[30][30];
	int iii, ii, n, m, k, i, j, minenum, x, y, win = 0;
	int score, bonus, finalscore = -999;
	n = 20;
	m = 20;
	minenum = 50;
	srand(int(time(0)));
	printf("正在评测中，请稍等\n");

	for (iii = 0; iii<10; iii++)
	{
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
			{
				GamePanel[i][j] = -1;
				mine[i][j] = 0;
			}
		for (k = 0; k<minenum; k++)
		{
			i = rand() % 20;
			j = rand() % 20;
			while (mine[i][j] != 0)
			{
				i = rand() % 20;
				j = rand() % 20;
			}
			mine[i][j] = 1;
		}

		int cnt = 0;

		for (ii = 0; ii<400; ii++)
		{
			int t1, t2;
			for (t1 = 0; t1 < 20; t1++)
				for (t2 = 0; t2 < 20; t2++)
					temp[t1][t2] = GamePanel[t1][t2];
	
			machine(temp, n, m, x, y); //该函数由学生实现
	
			if (GamePanel[x][y] == -1)
			{
				cnt++;
				win = RefreshGamePanel(GamePanel, x, y, mine, n, m, minenum);//该函数老师已经实现
				if (win == 1)		//扫雷成功，游戏结束
				{
					if (cnt < 80) bonus = 100;
					else if (cnt < 90) bonus = 90;
					else if (cnt < 100) bonus = 80;
					else if (cnt < 120) bonus = 70;
					else if (cnt < 150) bonus = 50;
					else if (cnt < 200) bonus = 30;
					else if (cnt < 250) bonus = 10;
					else bonus = 0;
					score = 500 + bonus;
					break;
				}
				else if (win == -1)		//扫雷失败，游戏结束
				{
					score = 0;
					for (i = 0; i<n; i++)
						for (j = 0; j<m; j++)
						{
							if (GamePanel[i][j] != -1)
								score++;
						}
					break;
				}
			}

		} //end for ii

		if (win == 0)	//点击超400次游戏仍未结束，分数等于目前打开的格子数
		{
			score = 0;
			for (i = 0; i<n; i++)
				for (j = 0; j<m; j++)
				{
					if (GamePanel[i][j] != -1)
						score++;
				}
		}
		if (score>finalscore) finalscore = score;
	}	// end for iii

	printf("\n该学生分数为 %d.\n\n", finalscore/10);
	system("pause");
	return 0;
}
