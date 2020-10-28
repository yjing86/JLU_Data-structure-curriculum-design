#include "snake.h"
using namespace std;
typedef struct A25 {
	int x = 0;
	int y = 0;
}AA25;
point return25(AA25 a) {
	point b;
	b.x = a.x;
	b.y = a.y;
	return b;
}
AA25 find25(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp, int type) {
	AA25 xy;
	int i = 1, j=2, l = 1, h, k, aa, bb, xx = 0, yy = 0;
	int temp = 0;
	while (i <= gp.n) {
		j = 2;
		while(j<=gp.m){
			temp = gp.panel[i][j] == type;
			if (temp) {
				aa = i - snake[t][1].x;
				int panduan = (aa < 0);
				if (panduan)
					aa = aa * (-1);
				bb = j - snake[t][1].y;
				panduan = (bb < 0);
				if (panduan)
					bb = -bb;
				panduan = (l == 1);
				if (panduan) {
					k = aa + bb;
					h = aa + bb;
					xx = i;
					yy = j;
				}
				k = aa + bb;
				panduan = (k < h);
				if (panduan) {
					xx = i;
					yy = j;
					h = aa + bb;
				}
				l++;
			}
			j = j + 2;
		}
		i++;
	}
	xy.x = xx;
	xy.y = yy;
	return xy;
}
bool exmaine25(point snake[5][100], int len[5], int t, GamePanel gp, int orientation)
{
	int i;
	int temp = 0;
	temp = snake[t][1].y == gp.m && (orientation == 1 || orientation == 4 || orientation == 5);
	if (temp)
		return false;
	temp = snake[t][1].x == gp.n && (orientation == 0 || orientation == 4 || orientation == 7);
	if (temp)
		return false;
	temp = snake[t][1].y == 2 && (orientation == 2 || orientation == 6 || orientation == 7);
	if (temp) return
		false;
	temp = snake[t][1].x == 1 && (orientation == 3 || orientation == 5 || orientation == 6);
	if (temp)
		return false;
	for (i = 2; i <= len[t]; i++) {
		temp = snake[t][1].x + 1 == snake[t][i].x && snake[t][1].y == snake[t][i].y && orientation == 0;
		if (temp)
			return false;
	}
	for (i = 2; i <= len[t]; i++) {
		temp = snake[t][1].x - 1 == snake[t][i].x && snake[t][1].y == snake[t][i].y && orientation == 3;
		if (temp)
			return false;
	}
	for (i = 2; i <= len[t]; i++) {
		temp = snake[t][1].y + 2 == snake[t][i].y && snake[t][1].x == snake[t][i].x && orientation == 1;
		if (temp)
			return false;
	}
	for (i = 2; i <= len[t]; i++) {
		temp = snake[t][1].y - 2 == snake[t][i].y && snake[t][1].x == snake[t][i].x && orientation == 2;
		if (snake[t][1].y - 2 == snake[t][i].y && snake[t][1].x == snake[t][i].x && orientation == 2)
			return false;
	}
	temp = gp.panel[snake[t][1].x + 1][snake[t][1].y] == 2 && orientation == 0;
	if (temp)
		return false;
	temp = gp.panel[snake[t][1].x - 1][snake[t][1].y] == 2 && orientation == 3;
	if (temp)
		return false;
	temp = gp.panel[snake[t][1].x][snake[t][1].y + 2] == 2 && orientation == 1;
	if (temp)
		return false;
	temp = gp.panel[snake[t][1].x][snake[t][1].y - 2] == 2 && orientation == 2;
	if (temp)
		return false;
	return true;
}
bool check25(point snake[5][100], int len[5], int t, GamePanel gp, int direction)
{
	return true;
}
int next25(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp, AA25 a1, AA25 a2) {
	int temp = (a2.x != 0 && a2.y != 0 && (a2.x + a2.y) < (a1.x + a1.y));
	point p;
	if (temp)
		p = return25(a2);
	else
		p = return25(a1);
	int orientation = direct[t];
	int i, j;
	int temp1 = p.x < snake[t][1].x&& direct[t] != 0;
	int temp2 = p.x > snake[t][1].x && direct[t] != 3;
	int temp3 = p.y < snake[t][1].y&& direct[t] != 1;
	int temp4 = p.y > snake[t][1].y && direct[t] != 2;
	if (temp1)
		orientation = 3;
	else if (temp2)
		orientation = 0;
	else if (temp3)
		orientation = 2;
	else if (temp4)
		orientation = 1;
	temp1 = exmaine25(snake, len, t, gp, orientation);
	temp2 = exmaine25(snake, len, t, gp, orientation);
	temp3 = exmaine25(snake, len, t, gp, orientation);
	temp4 = exmaine25(snake, len, t, gp, orientation);
	if (!temp1) {
		orientation = 0;
		if (!temp2) {
			orientation = 1;
			if (!temp3) {
				orientation = 2;
				if (!temp4) {
					orientation = 3;
				}
			}
		}
	}
	return orientation;
}
int machine_move25(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)
{
	int type = 1;
	AA25 a = find25(snake, len, direct, t, gp, type);
	type = 3;
	AA25 b = find25(snake, len, direct, t, gp, type);
	return next25(snake, len, direct, t, gp, a, b);
}
