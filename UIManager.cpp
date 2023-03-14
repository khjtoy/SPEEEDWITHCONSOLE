#include "UIManager.h"
#include "console.h"

// 열기용
MCI_OPEN_PARMS openbgm;
UINT dwID;
MCI_OPEN_PARMS openeffect;
UINT dwID2;
void PlayingBGM()
{
	openbgm.lpstrElementName = L"BGM.mp3";
	openbgm.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&openbgm);
	dwID = openbgm.wDeviceID;
}

void Title()
{
	system("cls");

	_setmode(_fileno(stdout), _O_U8TEXT);

	wcout << L"███████╗██████╗ ███████╗███████╗███████╗███████╗██████╗     ██╗    ██╗██╗████████╗██╗  ██╗     ██████╗ ██████╗ ███╗   ██╗███████╗ ██████╗ ██╗     ███████╗██╗██╗" << endl;
	Sleep(30);
	wcout << L"██╔════╝██╔══██╗██╔════╝██╔════╝██╔════╝██╔════╝██╔══██╗    ██║    ██║██║╚══██╔══╝██║  ██║    ██╔════╝██╔═══██╗████╗  ██║██╔════╝██╔═══██╗██║     ██╔════╝██║██║" << endl;
	Sleep(30);
	wcout << L"███████╗██████╔╝█████╗  █████╗  █████╗  █████╗  ██║  ██║    ██║ █╗ ██║██║   ██║   ███████║    ██║     ██║   ██║██╔██╗ ██║███████╗██║   ██║██║     █████╗  ██║██║" << endl;
	Sleep(30);
	wcout << L"╚════██║██╔═══╝ ██╔══╝  ██╔══╝  ██╔══╝  ██╔══╝  ██║  ██║    ██║███╗██║██║   ██║   ██╔══██║    ██║     ██║   ██║██║╚██╗██║╚════██║██║   ██║██║     ██╔══╝  ╚═╝╚═╝" << endl;
	Sleep(30);
	wcout << L"███████║██║     ███████╗███████╗███████╗███████╗██████╔╝    ╚███╔███╔╝██║   ██║   ██║  ██║    ╚██████╗╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗███████╗██╗██╗" << endl;
	Sleep(30);
	wcout << L"╚══════╝╚═╝     ╚══════╝╚══════╝╚══════╝╚══════╝╚═════╝      ╚══╝╚══╝ ╚═╝   ╚═╝   ╚═╝  ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝╚══════╝╚═╝╚═╝" << endl;


	_setmode(_fileno(stdout), _O_TEXT);
}

void Explanation()
{
	cout << "===============================================" << endl;
	cout << "설명: 10개 스테이지를 35초안에 클리어하시면 됩니다!" << endl;
	cout << "게임을 시작하시려면 아무 키나 누르세요!" << endl;
	cout << "===============================================" << endl;
}

void CountDown()
{
	system("cls");
	PlayingBGM();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	_setmode(_fileno(stdout), _O_U8TEXT);



	wcout << L"██████" << endl;
	wcout << L"    ██  " << endl;
	wcout << L" █████" << endl;
	wcout << L"    ██  " << endl;
	wcout << L"██████" << endl;

	Sleep(1000);

	system("cls");
	wcout << L"██████ " << endl;
	wcout << L"     ██" << endl;
	wcout << L" █████  " << endl;
	wcout << L"██     " << endl;
	wcout << L"███████" << endl;

	Sleep(1000);

	system("cls");
	wcout << L" ██" << endl;
	wcout << L" ██" << endl;
	wcout << L" ██" << endl;
	wcout << L" ██" << endl;
	wcout << L" ██" << endl;


	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, NULL);


	Sleep(1000);


	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openbgm);
	_setmode(_fileno(stdout), _O_TEXT);

}

void BGMShutdown()
{
 	mciSendCommand(dwID, MCI_PASTE, MCI_NOTIFY, (DWORD)(LPVOID)&openbgm);
}

void PlayingEffect()
{
	openeffect.lpstrElementName = L"Clear.wav";
	openeffect.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&openeffect);
	dwID2 = openeffect.wDeviceID;
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openeffect);
	//Sleep(100); // -> 효과음 시간 정도
}
