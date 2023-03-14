#pragma once
class Player
{
public:
	Player(int x, int y);
	~Player();
	void ChangeX(int num) { currentX -= num; }
	void ChangeY(int num) { currentY -= num; }
	void SetX(int num) { currentX = num; }
	void SetY(int num) { currentY = num; }
	void Init();
public:
	int currentX;
	int currentY;
};

