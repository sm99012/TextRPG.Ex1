#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Entity.h"
#include "Item.h"
#include "ProfessedFunction.h"

using namespace std;
using namespace h_Entity;
using namespace h_Item;
using namespace h_Function;

void MainGUI(Player* player);

bool M_Battle(Map* map, Player* player, Monster monster1)
{
	Monster m1 = monster1;
	bool isBattle = true;
	while (player->GetC_HP() > 0 && m1.GetC_HP() > 0 && isBattle == true)
	{
		cout << "[" << map->MapName << "][전투]" << endl;
		player->PlayerBattleStatus();
		m1.EntityStatus();
		cout << "[1.공격][2.방어][3.도망]" << endl;
		cout << "선택지 입력: ";
		int Number = _getch();
		//cin >> Number;
		int DEF; //[2.방어] 선택시 플레이어의 방어력은 두배로 적용되고 몬스터를 직접 공격할 수 없다.
		switch (Number)
		{
		case 49:
		{
			system("cls");
			int P_Damage = Attack(player, &m1, 0);
			cout << "[" << map->MapName << "][전투]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "플레이어 공격" << endl;
			Attack_Output_PlayerDamage(player, &m1, P_Damage, 0);
			player->Set_Equip_Weapon_Durability(-1);
			Sleep(2000);
			system("cls");
			cout << "[" << map->MapName << "][전투]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			if (m1.GetC_HP() > 0)
			{
				int M_Damage = Attack(player, &m1, 1);
				cout << "몬스터 공격" << endl;
				Attack_Output_PlayerDamage(player, &m1, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			break;
		}
		case 50:
		{
			system("cls");
			DEF = player->GetDefensivePower();
			player->AddStatus(0, DEF, 0);
			cout << "[" << map->MapName << "][전투]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "플레이어 방어" << endl;
			player->Set_Equip_Weapon_Durability(-2);
			Defense_Output_Player(player);
			Sleep(2000);
			system("cls");
			int M_Damage = Attack(player, &m1, 1);
			cout << "[" << map->MapName << "][전투]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			if (m1.GetC_HP() > 0)
			{
				cout << "몬스터 공격" << endl;
				Attack_Output_PlayerDamage(player, &m1, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			player->AddStatus(0, -DEF, 0);
			cout << "[" << map->MapName << "][전투]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "플레이어 방어해제" << endl;
			Defense_Output_Player(player);
			Sleep(2000);
			system("cls");
			break;
		}
		case 51:
		{
			cout << "[3.도망]" << endl;
			cout << endl;
			cout << "플레이어는 도망쳤다!" << endl;
			isBattle = false;
			Sleep(2000);
			break;
		}
		}
	}
	if (isBattle == true)
	{
		system("cls");
		BattleEnd_Output(player, &m1);
		cout << "[1.확인]" << endl;
		int Number2 = _getch();
		return true;
	}
	else return false;
}
void M_Battle(Map* map, Player* player, Monster monster1, Monster monster2)
{

}
void M_Battle(Map* map, Player* player, Monster monster1, Monster monster2, Monster monster3)
{

}

Map* MoveLeftMap(Player* player)
{
	Map* nMap = player->GetPlayerMap();
	if (nMap->BeforeMap != NULL)
	{
		cout << "왼쪽맵으로 이동합니다!" << endl;
		Sleep(2000);
		nMap = nMap->BeforeMap;
		player->SetPlayerMap(nMap);
	}
	else
	{
		cout << "이동할 수 없습니다!" << endl;
		Sleep(2000);
	}
	return nMap;
}
Map* MoveRightMap(Player* player)
{
	Map* nMap = player->GetPlayerMap();
	if (nMap->AfterMap != NULL)
	{
		cout << "오른쪽맵으로 이동합니다." << endl;
		Sleep(2000);
		nMap = nMap->AfterMap;
		player->SetPlayerMap(nMap);
	}
	else
	{
		cout << "이동할 수 없습니다!" << endl;
		Sleep(2000);
	}
	return nMap;
}

void Map_Print(Map* map, int n)
{
	system("cls");
	cout << "[" << map->MapName << "][탐험]" << endl;
	int(*Array)[22] = map->Field;
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			if (Array[x][y] == 100) //플레이어
			{
				cout << "\u25cb";
			}
			else if (Array[x][y] == 001) //필드
			{
				cout << "\u25a0";
			}
			else if (Array[x][y] == 3) //벽
			{
				cout << "  ";
			}
			else if (Array[x][y] == 200) //몬스터
			{
				cout << "\u25a1";
			}
		}
		cout << endl;
	}
	//LineBreak(22-n);

	cout << "[1.스테이터스][2.탐험종료]" << endl;
	cout << "선택지 입력: ";
	int ChoiceNumber1 = _getch();
	switch (ChoiceNumber1)
	{
	case 49:
	{
		system("cls");
		P_Player.EntityStatus();
		cout << "[1.스탯올리기][2.창닫기]";
		int ChoiceNumber2 = _getch();
		switch (ChoiceNumber2)
		{
		case 49:
		{
			P_Player.PlayerStatusSystem();
			break;
		}
		case 50:
		{
			break;
		}
		}
	}
	case 50:
	{
		break;
	}
	}

}

void Map_Move(Map* map, int posx, int posy, int n)
{
	bool isMove = true;
	int(*Array)[22] = map->Field;
	int x = posx;
	int y = posy;
	while (isMove == true)
	{
		int InputKeyCode = _getch();
		switch (InputKeyCode)
		{
		case 77:
			if (Array[x + 1][y] == 001 || Array[x + 1][y] == 200)
			{
				if (Array[x + 1][y] == 200)
				{
					system("cls");
					if (M_Battle(map, &P_Player, M_WeakSlime) == true)
					{
						Array[x][y] = 001;
						Array[x + 1][y] = 100;
						x += 1;
					}
				}
				else
				{
					Array[x][y] = 001;
					Array[x + 1][y] = 100;
					x += 1;
				}
			}
			break;
		case 75:
			if (Array[x - 1][y] == 001 || Array[x - 1][y] == 200)
			{
				if (Array[x - 1][y] == 200)
				{
					system("cls");
					if (M_Battle(map, &P_Player, M_WeakSlime) == true)
					{
						Array[x][y] = 001;
						Array[x - 1][y] = 100;
						x -= 1;
					}
				}
				else
				{
					Array[x][y] = 001;
					Array[x - 1][y] = 100;
					x -= 1;
				}
			}
			break;
		case 72:
			if (Array[x][y - 1] == 001 || Array[x][y - 1] == 200)
			{
				if (Array[x][y - 1] == 200)
				{
					system("cls");
					if (M_Battle(map, &P_Player, M_WeakSlime) == true)
					{
						Array[x][y] = 001;
						Array[x][y - 1] = 100;
						y -= 1;
					}
				}
				else
				{
					Array[x][y] = 001;
					Array[x][y - 1] = 100;
					y -= 1;
				}
			}
			break;
		case 80:
			if (Array[x][y + 1] == 001 || Array[x][y + 1] == 200)
			{
				if (Array[x][y + 1] == 200)
				{
					system("cls");
					if (M_Battle(map, &P_Player, M_WeakSlime) == true)
					{
						Array[x][y] = 001;
						Array[x][y + 1] = 100;
						y += 1;
					}
				}
				else
				{
					Array[x][y] = 001;
					Array[x][y + 1] = 100;
					y += 1;
				}
			}
			break;
		case 50:
		{
			isMove = false;
			break;
		}
		}
		if (isMove == true)
		{
			system("cls");
			Map_Print(map, n);
		}
		else break;
	}
}

int Map_FindPlayer(int(*Array)[22], int n)
{
	bool isFind = false;
	int a, b;
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			if (Array[x][y] == 100)
			{
				a = x; b = y;
				isFind = true;
				break;
			}
		}
		if (isFind == true) break;
	}
	if (n == 0)
	{
		//cout << "x: " << a;
		return a;
	}
	else
	{
		//cout << "y: " << b;
		return b;
	}
}

void Map_Explorer(Map* map)
{
	int(*Array)[22] = map->Field;
	int n = map->FieldHigh;
	Map_Print(map, n);

	int x = Map_FindPlayer(Array, 0);
	int y = Map_FindPlayer(Array, 1);

	Map_Move(map, x, y, n);
}

void Map_Initialize(Map* map)
{
	if (map == StartingMap)
	{
		Map_StartingMap_Option();
	}
	else if (map == TrainingForest)
	{
		Map_TrainingForest_Option();
	}
} //몬스터 리젠

void MainGUI(Player* player)
{
	Map* CurrentMap = player->GetPlayerMap();
	while (true)
	{
		system("cls");
		cout << "[" << CurrentMap->MapName << "]" << endl;
		LineBreak(22);
		cout << "[1.맵 이동][2.맵 탐험][3.스테이터스]" << endl;
		int ChoiceNumber1 = _getch();
		switch (ChoiceNumber1)
		{
		case 49:
		{
			cout << "[1.왼쪽이동][2.오른쪽이동]" << endl;
			int ChoiceNumber2 = _getch();
			switch (ChoiceNumber2)
			{
			case 49:
			{
				CurrentMap = MoveLeftMap(player);
				break;
			}
			case 50:
			{
				CurrentMap = MoveRightMap(player);
				break;
			}
			}
			break;
		}
		case 50:
		{
			Map* CurrentMap = P_Player.GetPlayerMap();
			Map_Initialize(CurrentMap);
			Map_Explorer(CurrentMap);
			break;
		}
		case 51:
		{
			system("cls");
			P_Player.EntityStatus();
			cout << "[1.창닫기]";
			int ChoiceNumber2 = _getch();
			switch (ChoiceNumber2)
			{
			case 49:
				break;
			}
		}
		}
	}
}


void main()
{
	//초기 맵 설정
	MapOption();
	//초기 플레이어 설정
	PlayerOption();
	//초기 몬스터 설정
	
	system("cls");

	//P_Player.EntityStatus();
	//M_WeakSlime.EntityStatus();
	//M_WeakSkeleton.EntityStatus();

	//PT();

	//cout << endl;
	//M_Battle(TrainingForest, &P_Player, M_WeakSlime);
	//M_WeakSlime.EntityStatus();
	//P_Player.PlayerEXPSystem(10);
	//P_Player.PlayerEXPSystem(10);
	//P_Player.PlayerEXPSystem(10);
	//P_Player.PlayerEXPSystem(10);

	//cout << "잉";
	//ItemOption();
	//Weapon_WoodenSword.ItemStatus();
	//Drop_Weapon_CommonSword_100.Show();

	//string s = "스트링 문자열은 문자를 몇개까지 저장할 수 있을지 알아보는 테스트 이다. 이는 아이템의 설명을위해 반드시 필요한 테스트이다.";
	//cout << s;
	
	//Map_Print(StartingMap->Field);
	MainGUI(&P_Player); //게임시작
}