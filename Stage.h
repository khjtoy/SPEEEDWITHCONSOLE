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
	//빈: 0 벽: 1 도작치점: 2
	int miroY = 10;
	int miroX = 7;
	int dir;
	char maze[10][7];
	string subtitles[10] = { "Q를 누르세요!", "(6 X 5) + 2의 정답을 입력하세요!", "룰렛의 정가운데에서 멈추세요!(스페이스 사용)", "콘솔 크기를 최소화하세요!(클릭을 해제 후, 다시 확대하셔야 합니다.)",
	"F-O-C-q-R를 순서대로 입력하세요!(대소문자 구분)", "미로를 탈출하세요!(이동키:WASD)", "똑같이 따라 만드세요! \n*@\n%-", "QWEERTY를 꺼꾸로 입력하세요!",
	"모든 적을 다 죽이세요!(이동:화살표, 공격:스페이스(마지막으로 누른 화살표 방향으로..))", "결승전에 통과하세요!(스페이스 사용)"};
	Roulette* m_Roulette;
	Player* player;
	//GLFWwindow* glfw_window = nullptr;
};

