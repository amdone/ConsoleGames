// 2048.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define random(x) (rand()%x)
using namespace std;

int M[4][4];
int num;
int score;


void createNumber() {
	int i = random(4);
	int j = random(4);
	if (M[i][j] == 0) {
		if (random(2))
			M[i][j] = 2;
		else M[i][j] = 4;
		++num;
	}
	else
		createNumber();
}


void init() {
	srand((int)time(0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			M[i][j] = 0;
		}
	}
	num = score = 0;
	createNumber();
}

void show() {
	cout << "\n\n\t\t\t\t-------------2-0-4-8-------------\n\n";
	cout << "\t\t\t\t---------------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t|";
		for (int j = 0; j < 4; j++) {
			if (M[i][j] == 0)
				cout << "\t|";
			else
				cout << M[i][j] << "\t|";
		}
		cout <<"\n\t\t\t\t---------------------------------"<< endl;
	}
	cout << "\n\t\t\t当前分数：" << score <<"\t\t\ttips:使用方向键控制移动"<< endl;
}


void up() {
	bool needNew = false;
	for (int i = 0; i < 4; i++)
	{
		int tmpArr[4] = { 0,0,0,0 };
		int count = 0;
		int j = 0;
		for (; j < 4; j++)
		{
			if (M[j][i] == 0 && j!=3 && 0 != M[j + 1][i])
				needNew = true;
			if (M[j][i] != 0)
				tmpArr[count++] = M[j][i];
		}
		j = 0;
		while (j < 4)
			M[j][i] = tmpArr[j++];

		if (M[0][i] == M[1][i] && M[0][i]) {
			if (M[2][i] == M[3][i] && M[2][i]) {
				M[0][i]*=2;
				M[1][i] = M[2][i]*=2;
				M[2][i] = M[3][i] = 0;
				num -= 2;
				score += M[0][i] + M[1][i];
			}
			else
			{
				M[0][i] *= 2;
				M[1][i] = M[2][i];
				M[2][i] = M[3][i];
				M[3][i] = 0;
				--num;
				score += M[0][i];
			}
			needNew = true;
		}
		else if (M[2][i] == M[1][i] && M[1][i]) {
			M[1][i]*=2;
			M[2][i] = M[3][i];
			M[3][i] = 0;
			--num;
			needNew = true;
			score += M[1][i];
		}
		else if (M[2][i] == M[3][i] && M[2][i]) {
			M[2][i]*=2;
			M[3][i] = 0;
			--num;
			needNew = true;
			score += M[2][i];
		}
	}
	if (needNew) createNumber();
}

void down() {
	bool needNew = false;
	for (int i = 0; i < 4; i++)
	{
		int tmpArr[4] = { 0,0,0,0 };
		int j = 3,index = 3;

		for (; j >= 0; j--) {
			if (M[j - 1][i] != 0 && j != 0 && 0 == M[j][i])
				needNew = true;
			if (M[j][i] != 0)
				tmpArr[index--] = M[j][i];
		}
		while (++j < 4) {
			M[j][i] = tmpArr[j];
		}

		if (M[3][i] == M[2][i] && M[2][i]) {
			if (M[1][i] == M[0][i] && M[0][i]) {
				M[3][i]*=2;
				M[2][i] = M[0][i]*=2;
				M[1][i] = M[0][i] = 0;
				num -= 2;
				score += M[3][i] + M[2][i];
			}
			else
			{
				M[3][i]*=2;
				M[2][i] = M[1][i];
				M[1][i] = M[0][i];
				M[0][i] = 0;
				--num;
				score += M[3][i];
			}
			needNew = true;
		}
		else if (M[2][i] == M[1][i] && M[1][i]) {
			M[2][i]*=2;
			M[1][i] = M[0][i];
			M[0][i] = 0;
			--num;
			needNew = true;
			score += M[2][i];
		}
		else if (M[1][i] == M[0][i] && M[0][i]) {
			M[1][i]*=2;
			M[0][i] = 0;
			--num;
			needNew = true;
			score += M[1][i];
		}
	}
	if (needNew) createNumber();
}


void left() {
	bool needNew = false;
	for (int i = 0; i < 4; i++)
	{
		int tmpArr[4] = {0,0,0,0};
		int count = 0;
		int j = 0;
		for (; j < 4; j++)
		{
			if (M[i][j] == 0 && j != 3 && 0 != M[i][j+1])
				needNew = true;
			if (M[i][j] != 0)
				tmpArr[count++] = M[i][j];
		}
		j = 0;
		while (j<4)
			M[i][j] = tmpArr[j++];

		if (M[i][0] == M[i][1] && M[i][0]) {
			if (M[i][2] == M[i][3] && M[i][2]) {
				M[i][0]*=2;
				M[i][1] = M[i][2]*=2;
				M[i][2] = M[i][3] = 0;
				num -= 2;
				score += M[i][0] + M[i][1];
			}
			else
			{
				M[i][0]*=2;
				M[i][1] = M[i][2];
				M[i][2] = M[i][3];
				M[i][3] = 0;
				--num;
				score += M[i][0];
			}
			needNew = true;
		}
		else if (M[i][2] == M[i][1] && M[i][1]) {
			M[i][1]*=2;
			M[i][2] = M[i][3];
			M[i][3] = 0;
			--num;
			needNew = true;
			score += M[i][1];
		}
		else if (M[i][2] == M[i][3] && M[i][2]) {
			M[i][2]*=2;
			M[i][3] = 0;
			--num;
			needNew = true;
			score += M[i][2];
		}
	}
	if (needNew) createNumber();
}

void right() {
	bool needNew = false;
	for (int i = 0; i < 4; i++)
	{
		int tmpArr[4] = {};
		int j = 3,index = 3;

		for (; j >= 0; j--) {
			if (M[i][j-1] != 0 && j != 0 && 0 == M[i][j])
				needNew = true;
			if (M[i][j] != 0)
				tmpArr[index--] = M[i][j];
		}
		while (++j < 4) {
			M[i][j] = tmpArr[j];
		}
		if (M[i][3] == M[i][2] && M[i][2]) {
			if (M[i][1] == M[i][0] && M[i][0]) {
				M[i][3]*=2;
				M[i][2] = M[i][0]*=2;
				M[i][1] = M[i][0] = 0;
				num -= 2;
				score += M[i][3] + M[i][2];
			}
			else
			{
				M[i][3]*=2;
				M[i][2] = M[i][1];
				M[i][1] = M[i][0];
				M[i][0] = 0;
				--num;
				score += M[i][3];
			}
			needNew = true;
		}
		else if (M[i][2] == M[i][1] && M[i][1]) {
			M[i][2]*=2;
			M[i][1] = M[i][0];
			M[i][0] = 0;
			--num;
			needNew = true;
			score += M[i][2];
		}
		else if (M[i][1] == M[i][0] && M[i][0]) {
			M[i][1]*=2;
			M[i][0] = 0;
			--num;
			needNew = true;
			score += M[i][1];
		}
	}
	if (needNew) createNumber();
}


bool isFull() {
	return(num == 16);
}

bool isOver() {
	for (int i = 0; i < 4; i++)
	{
		if (M[i][0] == M[i][1] || M[i][1] == M[i][2] || M[i][2] == M[i][3])
			return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (M[0][i] == M[1][i] || M[1][i] == M[2][i] || M[2][i] == M[3][i])
			return false;
	}
	return true;
}

int main() {
	init();
	show();
	int ch;
	while ((ch = _getch()) != 0x1B) /* Press ESC to quit... */
	{
		if (isFull() && isOver())
			break;
		switch (ch) {
			case 0xE0:
				switch (ch = _getch()) {
					case 72:	up();
						break;
					case 80:	down();
						break;
					case 75:	left();
						break;
					case 77:	right();
						break;
					default:
						break;
				}
				system("cls");
				show();
				break;
			default:
				break;
		}
	}
	cout << "游戏结束!\n最终得分为:" << score << endl;
}

