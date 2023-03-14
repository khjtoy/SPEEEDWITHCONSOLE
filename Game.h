#pragma once

class Stage;

class Game
{
private:
	Stage* m_stage;
	bool isStart = false;
	int startTimer;
	long timer;
public:
	Game();
	~Game();
	void Init();
	bool Update();
	bool GetStart() { return isStart; }
	bool GameClear();
	bool GameOver();
	//void LoadStage();
};

