#pragma once
#include "console.h"
#include <WinUser.h>
//#include <gL/GL.h>
//#include <GLFW/glfw3.h>
//#include <windowsx.h>

class Roulette;
class Player;

class Stage
{
public:
	Stage();
	~Stage();
	string CurrentTitle(int stage)
	{
		return subtitles[stage - 1];
	}
	bool AnswerStage(int stage);
	void UseStage(int stage);
	void AddMap(int stage);
	void InitStage();
	int GetStage()
	{
		return stage;
	}
	void AddStage()
	{
		stage++;
		InitStage();
	}
	void ResetStage()
	{
		stage = 0;
	}
	void LoadStage();
	void SetMaze();
	void CheckEnemy(int x, int y);
	bool CheckCollision(int x, int y);
private:
	int stage;
	int count = 0;
	int RouletteX;
	int RouletteY;
	bool isIncrease;
	char keyCount[5] = { 'F', 'O', 'C', 'q', 'R' };
	string answer[3] = { "*@", "%-", "YTREEWQ" };
	string playerAnswer[2];
	POINT enemyPos[4] = { {10,8}, {5,5}, {7,16},{20,20} };
	//��: 0 ��: 1 ����ġ��: 2
	int miroY = 10;
	int miroX = 7;
	int dir;
	char maze[10][7];
	string subtitles[10] = { "Q�� ��������!", "(6 X 5) + 2�� ������ �Է��ϼ���!", "�귿�� ��������� ���߼���!(�����̽� ���)", "�ܼ� ũ�⸦ �ּ�ȭ�ϼ���!(Ŭ���� ���� ��, �ٽ� Ȯ���ϼž� �մϴ�.)",
	"F-O-C-q-R�� ������� �Է��ϼ���!(��ҹ��� ����)", "�̷θ� Ż���ϼ���!(�̵�Ű:WASD)", "�Ȱ��� ���� ���弼��! \n*@\n%-", "QWEERTY�� ���ٷ� �Է��ϼ���!",
	"��� ���� �� ���̼���!(�̵�:ȭ��ǥ, ����:�����̽�(���������� ���� ȭ��ǥ ��������..))", "������� ����ϼ���!(�����̽� ���)"};
	Roulette* m_Roulette;
	Player* player;
	//GLFWwindow* glfw_window = nullptr;
};

