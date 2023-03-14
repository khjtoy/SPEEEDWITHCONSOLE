#include "Game.h"
#include "UIManager.h"
#include "Stage.h"
//#include "console.h"

#pragma comment(lib, "winmm.lib")

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	m_stage = new Stage;

	//CursorHide();
	fullScreen();
	Title();
	Explanation();
	isStart = true;
}

bool Game::Update()
{
	if (m_stage->GetStage() == 0 && _kbhit())
	{
		_getch();
		CountDown();
		m_stage->AddStage();
		m_stage->LoadStage();
		startTimer = clock();
	}
	else if(m_stage->GetStage() > 0)
	{
		int end = (long)clock();
		if (double(end - startTimer) / CLOCKS_PER_SEC > 35)
		{
			isStart = false;
			BGMShutdown();
			bool isBreak = GameOver();
			return isBreak;
		}
		m_stage->UseStage(m_stage->GetStage());
		bool isClear = m_stage->AnswerStage(m_stage->GetStage());

		if (isClear)
		{
			if (m_stage->GetStage() == 10)
			{
				isStart = false;
				BGMShutdown();
				bool isBreak = GameClear();
				return isBreak;
			}
			else
			{
				m_stage->AddStage();
				PlayingEffect();
			}
		}
		else
		{
			if (m_stage->GetStage() == 4 || m_stage->GetStage() == 9 || m_stage->GetStage() == 10) return false;
		}
		m_stage->LoadStage();
	}
	return false;
}


bool Game::GameClear()
{
	system("cls");
	cin.clear();
	Sleep(500);
	cout << "��� ���������� Ŭ�����ϼ̽��ϴ�!" << endl;
	Sleep(500);
	cout << "����ϽǶ�� R�� �����ּ���." << endl;
	Sleep(500);
	cout << "������ �����Ϸ��� ESC�� �����ּ���!" << endl;
	Sleep(1500);
	bool isCheck = false;
	int c;
	
	c = _getch();
	while (!isCheck)
	{
		if (c == 27) return true;
		else if (c == 'r' || c == 'R')
		{
			m_stage->ResetStage();
			Init();
			isCheck = true;
		}
		else c = _getch();
	}
	return false;
}

bool Game::GameOver()
{
	system("cls");
	cin.clear();
	Sleep(500);
	cout << "�ƽ����ϴ�. ���� Ŭ��� �����ϼ̽��ϴ�." << endl;
	Sleep(500);
	cout << "����� ����� " << m_stage->GetStage() - 1 << "�������� Ŭ�����Դϴ�." << endl;
	Sleep(500);
	cout << "����ϽǶ�� R�� �����ּ���." << endl;
	Sleep(500);
	cout << "������ �����Ϸ��� ESC�� �����ּ���!" << endl;
	Sleep(1500);
	bool isCheck = false;
	int c;

	c = _getch();
	while (!isCheck)
	{
		if (c == 27) return true;
		else if (c == 'r' || c == 'R')
		{
			m_stage->ResetStage();
			Init();
			isCheck = true;
		}
		else c = _getch();
	}
	return false;
}





