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
		cout << "[" << map->MapName << "][����]" << endl;
		player->PlayerBattleStatus();
		m1.EntityStatus();
		cout << "[1.����][2.���][3.����]" << endl;
		cout << "������ �Է�: ";
		int Number = _getch();
		//cin >> Number;
		int DEF; //[2.���] ���ý� �÷��̾��� ������ �ι�� ����ǰ� ���͸� ���� ������ �� ����.
		switch (Number)
		{
		case 49:
		{
			system("cls");
			int P_Damage = Attack(player, &m1, 0);
			cout << "[" << map->MapName << "][����]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "�÷��̾� ����" << endl;
			Attack_Output_PlayerDamage(player, &m1, P_Damage, 0);
			player->Set_Equip_Weapon_Durability(-1);
			Sleep(2000);
			system("cls");
			cout << "[" << map->MapName << "][����]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			if (m1.GetC_HP() > 0)
			{
				int M_Damage = Attack(player, &m1, 1);
				cout << "���� ����" << endl;
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
			cout << "[" << map->MapName << "][����]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "�÷��̾� ���" << endl;
			player->Set_Equip_Weapon_Durability(-2);
			Defense_Output_Player(player);
			Sleep(2000);
			system("cls");
			int M_Damage = Attack(player, &m1, 1);
			cout << "[" << map->MapName << "][����]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			if (m1.GetC_HP() > 0)
			{
				cout << "���� ����" << endl;
				Attack_Output_PlayerDamage(player, &m1, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			player->AddStatus(0, -DEF, 0);
			cout << "[" << map->MapName << "][����]" << endl;
			player->PlayerBattleStatus();
			m1.EntityStatus();
			cout << "�÷��̾� �������" << endl;
			Defense_Output_Player(player);
			Sleep(2000);
			system("cls");
			break;
		}
		case 51:
		{
			cout << "[3.����]" << endl;
			cout << endl;
			cout << "�÷��̾�� �����ƴ�!" << endl;
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
		cout << "[1.Ȯ��]" << endl;
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
		cout << "���ʸ����� �̵��մϴ�!" << endl;
		Sleep(2000);
		nMap = nMap->BeforeMap;
		player->SetPlayerMap(nMap);
	}
	else
	{
		cout << "�̵��� �� �����ϴ�!" << endl;
		Sleep(2000);
	}
	return nMap;
}
Map* MoveRightMap(Player* player)
{
	Map* nMap = player->GetPlayerMap();
	if (nMap->AfterMap != NULL)
	{
		cout << "�����ʸ����� �̵��մϴ�." << endl;
		Sleep(2000);
		nMap = nMap->AfterMap;
		player->SetPlayerMap(nMap);
	}
	else
	{
		cout << "�̵��� �� �����ϴ�!" << endl;
		Sleep(2000);
	}
	return nMap;
}

void Map_Print(Map* map, int n)
{
	system("cls");
	cout << "[" << map->MapName << "][Ž��]" << endl;
	int(*Array)[22] = map->Field;
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			if (Array[x][y] == 100) //�÷��̾�
			{
				cout << "\u25cb";
			}
			else if (Array[x][y] == 001) //�ʵ�
			{
				cout << "\u25a0";
			}
			else if (Array[x][y] == 3) //��
			{
				cout << "  ";
			}
			else if (Array[x][y] == 200) //����
			{
				cout << "\u25a1";
			}
		}
		cout << endl;
	}
	//LineBreak(22-n);

	cout << "[1.�������ͽ�][2.Ž������]" << endl;
	cout << "������ �Է�: ";
	int ChoiceNumber1 = _getch();
	switch (ChoiceNumber1)
	{
	case 49:
	{
		system("cls");
		P_Player.EntityStatus();
		cout << "[1.���ȿø���][2.â�ݱ�]";
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
} //���� ����

void MainGUI(Player* player)
{
	Map* CurrentMap = player->GetPlayerMap();
	while (true)
	{
		system("cls");
		cout << "[" << CurrentMap->MapName << "]" << endl;
		LineBreak(22);
		cout << "[1.�� �̵�][2.�� Ž��][3.�������ͽ�]" << endl;
		int ChoiceNumber1 = _getch();
		switch (ChoiceNumber1)
		{
		case 49:
		{
			cout << "[1.�����̵�][2.�������̵�]" << endl;
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
			cout << "[1.â�ݱ�]";
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
	//�ʱ� �� ����
	MapOption();
	//�ʱ� �÷��̾� ����
	PlayerOption();
	//�ʱ� ���� ����
	
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

	//cout << "��";
	//ItemOption();
	//Weapon_WoodenSword.ItemStatus();
	//Drop_Weapon_CommonSword_100.Show();

	//string s = "��Ʈ�� ���ڿ��� ���ڸ� ����� ������ �� ������ �˾ƺ��� �׽�Ʈ �̴�. �̴� �������� ���������� �ݵ�� �ʿ��� �׽�Ʈ�̴�.";
	//cout << s;
	
	//Map_Print(StartingMap->Field);
	MainGUI(&P_Player); //���ӽ���
}