#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


/********************************************************************************/
/********************************��ѧ���Ĵ�����ӵ�����******************************/










/********************************��ѧ���Ĵ�����ӵ�����******************************/
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
	printf("���������У����Ե�\n");

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
	
			machine(temp, n, m, x, y); //�ú�����ѧ��ʵ��
	
			if (GamePanel[x][y] == -1)
			{
				cnt++;
				win = RefreshGamePanel(GamePanel, x, y, mine, n, m, minenum);//�ú�����ʦ�Ѿ�ʵ��
				if (win == 1)		//ɨ�׳ɹ�����Ϸ����
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
				else if (win == -1)		//ɨ��ʧ�ܣ���Ϸ����
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

		if (win == 0)	//�����400����Ϸ��δ��������������Ŀǰ�򿪵ĸ�����
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

	printf("\n��ѧ������Ϊ %d.\n\n", finalscore/10);
	system("pause");
	return 0;
}
