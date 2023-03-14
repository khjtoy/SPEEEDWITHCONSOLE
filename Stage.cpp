#include "Stage.h"
#include "Player.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

bool Stage::AnswerStage(int stage)
{
	char c = ' ';
	int num = 0;
	switch (stage)
	{
	case 1:
		c = _getch();
		if (c == 'q' || c == 'Q')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2:
		cin >> num;
		if (num == 32)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (RouletteX == 20)
		{
			RouletteX = 18;
			isIncrease = false;
		}
		else if (RouletteX == -1)
		{
			RouletteX = 1;
			isIncrease = true;
		}
		gotoxy(RouletteX, RouletteY);
		cout << "△";
		gotoxy(0, 0);
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (RouletteX == 11 || RouletteX == 12 || RouletteX == 10) return true;
			else
			{
				RouletteX = 0;
				isIncrease = true;
			}
		}

		if (isIncrease)
			RouletteX++;
		else
			RouletteX--;

		break;
	case 4:
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int Width, Height;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		if (Width <= 50 && Height <= 30)
		{
			return true;
		}
		return false;
		break;
	case 5:
		if (count == 5)
			return true;

		setColor(4, 0);

		for (int i = 0; i < count; i++)
		{
			cout << keyCount[i];
			if (i != 4)
			{
				cout << " - ";
			}
		}

		setColor(7, 0);

		for (int i = count; i < 5; i++)
		{
			cout << keyCount[i];
			if (i != 4)
			{
				cout << " - ";
			}
		}

		c = _getch();

		if (c == keyCount[count])
		{
			count++;
		}
		else {
			count = 0;
		}
		break;
	case 6:
		if (player->currentX == 5 && player->currentY == 8)
		{
			return true;
		}
		//cout << player->currentX << " " << player->currentY;
		player->Init();
		c = _getch();
		switch (c)
		{
		case 'w':
		case 'W':
			player->ChangeY(1);
			break;
		case 's':
		case 'S':
			player->ChangeY(-1);
			break;
		case 'a':
		case 'A':
			player->ChangeX(1);
			break;
		case 'd':
		case 'D':
			player->ChangeX(-1);
			break;
		}
		if (maze[player->currentY][player->currentX] == '1' || player->currentX < 0)
		{
			player->SetX(0);
			player->SetY(1);
		}
		break;
	case 7:
		cin >> playerAnswer[0];
		cin >> playerAnswer[1];

		if (playerAnswer[0] == answer[0] && playerAnswer[1] == answer[1])
			return true;
		break;
	case 8:
		cin >> playerAnswer[0];

		if (playerAnswer[0] == answer[2])
			return true;
		break;
	case 9:

		if (count == 0)
			return true;

		player->Init();
		gotoxy(player->currentX, player->currentY);
		cout << "＠";
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			int x = 0, y = 0;
			if (dir == 0)
			{
				x = player->currentX - 1;
				y = player->currentY;
				gotoxy(x, y);
				cout << "◀";
				CheckEnemy(x - 1, y);
	    		Sleep(200);
				LoadStage();
			}
			else if (dir == 1)
			{
				x = player->currentX + 1;
				y = player->currentY;
				gotoxy(x, y);
				cout << "▶";
				CheckEnemy(x + 1, y);
				Sleep(200);
				LoadStage();
			}
			else if (dir == 2)
			{
				x = player->currentX;
				y = player->currentY - 1;
				gotoxy(x, y);
				cout << "▲";
				CheckEnemy(x, y);
				Sleep(200);
				LoadStage();
			}
			else if (dir == 3)
			{
				x = player->currentX;
				y = player->currentY + 1;
				gotoxy(x, y);
				cout << "▼";
				CheckEnemy(x, y);
				Sleep(200);
				LoadStage();
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			dir = 0;
			if (!CheckCollision(player->currentX - 2, player->currentY))
			{
				player->ChangeX(1);
				Sleep(100);
				LoadStage();
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			dir = 1;
			if (!CheckCollision(player->currentX + 2, player->currentY))
			{
				player->ChangeX(-1);
				Sleep(100);
				LoadStage();
			}
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			dir = 2;
			if (!(CheckCollision(player->currentX, player->currentY - 1)))
			{
				player->ChangeY(1);
				Sleep(100);
				LoadStage();
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			dir = 3;
			if (!(CheckCollision(player->currentX, player->currentY + 1)))
			{
				player->ChangeY(-1);
				Sleep(100);
				LoadStage();
			}
		}

		break;
	case 10:
		gotoxy(player->currentX, player->currentY);
		cout << "＠";

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			player->ChangeX(-1);
			Sleep(100);
			LoadStage();
		}

		if (player->currentX >= 40)
			return true;
		break;
	}
	return false;
}


void Stage::UseStage(int stage)
{
	switch (stage)
	{
	case 3:
		//system("cls");
		break;
	}
}

void Stage::LoadStage()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "================================" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 188);
	cout << "Stage " << stage << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	cout << CurrentTitle(stage) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "================================" << endl;
	AddMap(stage);
}

void Stage::SetMaze()
{
	strcpy_s(maze[0], "111111");
	strcpy_s(maze[1], "000001");
	strcpy_s(maze[2], "101111");
	strcpy_s(maze[3], "100011");
	strcpy_s(maze[4], "101001");
	strcpy_s(maze[5], "100101");
	strcpy_s(maze[6], "111001");
	strcpy_s(maze[7], "101011");
	strcpy_s(maze[8], "100002");
	strcpy_s(maze[9], "111111");
}

void Stage::CheckEnemy(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (enemyPos[i].x == x && enemyPos[i].y == y)
		{
			enemyPos[i].x = INT_MAX;
			enemyPos[i].y = INT_MAX;
			count--;
			break;
		}
	}
}

bool Stage::CheckCollision(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (enemyPos[i].x == x && enemyPos[i].y == y)
		{
			return true;
		}
	}
	return false;
}

void Stage::AddMap(int stage)
{
	switch (stage)
	{
	case 3:
		cout << "■■■■■□■■■■■" << endl;
		break;
	case 6:
		if(player == nullptr)
		   player = new Player(0, 1);
		cout << endl;
		cout << "========================" << endl;
		for (int i = 0; i < miroY; i++)
		{
			for (int j = 0; j < miroX - 1; j++)
			{
				if (j == player->currentX && i == player->currentY)
				{
					cout << "＠";
					continue;
				}
				switch (maze[i][j])
				{
				case '0':
					cout << "  ";
					break;
				case '1':
					cout << "■";
					break;
				case '2':
					cout << "★";
					break;
				default:
					cout << "error";
				}
			}
			cout << endl;
		}
		cout << "========================" << endl;
		break;
	case 9:
		cout << "남은 적 개수: " << count;
		setColor(4, 0);
		for (int i = 0; i < 4; i++)
		{
			if (enemyPos[i].x == INT_MAX && enemyPos[i].y == INT_MAX)
				continue;
			gotoxy(enemyPos[i].x, enemyPos[i].y);
			cout << "●";
		}
		setColor(15, 0);
		break;
	case 10:
		setColor(4, 0);
		gotoxy(40, 5);
		cout << "■";
		gotoxy(40, 6);
		cout << "■";
		gotoxy(40, 7);
		cout << "■";
		gotoxy(40, 8);
		cout << "■";
		gotoxy(40, 9);
		cout << "■";
		gotoxy(40, 10);
		cout << "■";
		gotoxy(40, 11);
		cout << "■";
		gotoxy(40, 12);
		cout << "■";
		gotoxy(40, 13);
		cout << "■";
		gotoxy(40, 14);
		cout << "■";
		gotoxy(40, 15);
		cout << "■";
		setColor(15, 0);
		break;
	}
}

void Stage::InitStage()
{
	switch (GetStage())
	{
	case 3:
		RouletteY = 5;
		RouletteX = 0;
		isIncrease = true;
		break;
	case 4:
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
		break;
	case 6:
		fullScreen();
		SetMaze();
		break;
	case 9:
		count = 4;
	case 10:
		player->SetX(10);
		player->SetY(10);
	}
}
