#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Map.h"

using namespace std;
using namespace h_Item;
using namespace h_Map;

namespace h_Entity
{
	class Entity
	{
		string nEntityName;
		static int EntityCode;
		int nEntityCode;

		int nLV;
		int nM_HP;
		int nC_HP;
		int nM_MP;
		int nC_MP;

		int nMaxStrikingPower;
		int nMinStrikingPower;
		int nDefensivePower;
		int nSpeed;

	public:
		Entity(string name, int lv, int hp, int mp, int sp, int dp, int speed)
		{
			EntityCode += 1;
			this->nEntityName = name;
			this->nLV = lv;
			this->nEntityCode = EntityCode;
			this->nM_HP = hp;
			this->nC_HP = hp;
			this->nM_MP = mp;
			this->nC_MP = mp;
			this->nMaxStrikingPower = sp;
			this->nMinStrikingPower = sp;
			this->nDefensivePower = dp;
			this->nSpeed = speed;
		}

		virtual void EntityStatus()
		{
			cout << "[�̸�: " << nEntityName << ", LV: " << nLV << ", C_HP/M_HP: " << nC_HP << "/" << nM_HP << ", C_MP/M_MP: " << nC_MP << "/" << nM_MP << "]" << endl;
		}

		void ChangeEntityStatus(int hp = 0, int mp = 0)
		{
			if (nC_HP + hp >= 0) this->nC_HP += hp;
			else this->nC_HP = 0;
			if (nC_MP + mp >= 0) this->nC_MP += mp;
			else this->nC_MP = 0;
		}

		string GetName()
		{
			return nEntityName;
		}

		int GetEntityCode()
		{
			return nEntityCode;
		}

		int GetC_HP()
		{
			return nC_HP;
		}
		int GetM_HP()
		{
			return nM_HP;
		}

		int GetC_MP()
		{
			return nC_MP;
		}
		int GetM_MP()
		{
			return nM_MP;
		}

		int GetLV()
		{
			return nLV;
		}

		int GetMaxStrikingPower()
		{
			return nMaxStrikingPower;
		}
		int GetMinStrikingPower()
		{
			return nMinStrikingPower;
		}

		int GetDefensivePower()
		{
			return nDefensivePower;
		}

		void AddStatus(int addmaxsp = 0, int addminsp = 0, int adddf = 0, int addspeed = 0)
		{
			nMaxStrikingPower += addmaxsp;
			nMinStrikingPower += addminsp;
			nDefensivePower += adddf;
			nSpeed += addspeed;
		}

		void LVUp(int lv)
		{
			this->nLV += lv;
			nM_HP += 5;
			nC_HP = nM_HP;
			nM_MP += 2;
			nC_MP = nM_MP;
			if ((nLV - 1) % 3 == 0)
			{
				nMaxStrikingPower += 1;
				nMinStrikingPower += 1;
				nDefensivePower += 1;
			}
		}
	}; int Entity::EntityCode = 0;

	class Monster : public Entity
	{
		int nEXP;
		int nDropGold;
		//vector <DropItem> nDropItem;

	public:
		Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold = 0) : Entity(name, lv, hp, mp, sp, dp, speed)
		{
			this->nEXP = exp;
			this->nDropGold = gold;
		}

		void EntityStatus()
		{
			cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
			cout << endl;
		}
		
		void EntityInformation()
		{
			cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", EXP: " << nEXP << "]" << endl;
			DropItem();
			cout << endl;
		}

		//void AddDropItem(DropItem dropitem)
		//{
		//	nDropItem.push_back(dropitem);
		//}

		void DropItemList()
		{
			cout << "[���������]" << endl;
		}

		void DropItem()
		{
			
		}

		int GetEXP()
		{
			return nEXP;
		}

		int GetGold()
		{
			return nDropGold;
		}
	};

	struct Map
	{
		string MapName;
		string MapDescription;
		int MapCode;
		int Field[22][22] = { 0 };
		int FieldHigh;
		Map* BeforeMap = NULL;
		Map* AfterMap = NULL;

		vector <Monster> Map_Monster;
	};

	Map* CreateMap(string mapname, int mapcode)
	{
		Map* pTempMap = new Map;
		pTempMap->MapName = mapname;
		pTempMap->MapCode = mapcode;
		return pTempMap;
	}

	void LinkMapAtoB(Map* A, Map* B)
	{
		A->AfterMap = B;
		B->BeforeMap = A;

		//cout << "[" << A->MapName << "] �� [" << B->MapName << "] ���� ����Ǿ����ϴ�." << endl;
	}

	void MapInformation(Map* map)
	{
		cout << "[" << map->MapName << "][" << map->MapCode << "][" << map->MapDescription << "]" << endl;
		if (map->BeforeMap != NULL)
			cout << "BeforeMap: " << map->BeforeMap->MapName << ", ";
		else
			cout << "BeforeMap: " << "X" << ", ";
		if (map->AfterMap != NULL)
			cout << "AfterMap: " << map->AfterMap->MapName << endl;
		else
			cout << "AfterMap: " << "X" << endl;
	}

	class Player : public Entity
	{
		int nMAXEXP = 12;
		int nCurrentEXP = 0;

		int nCanUseStatusPoint = 0;
		int nUsedStatusPoint = 0;
		int nAdditionalStatus_STR = 0;
		int nAdditionalStatus_CRITICAL = 0;
		int nAdditionalStatus_DEF = 0;

		Map* nCurrentMap = NULL;

	public:
		Item_Equip_Weapon* EquipmentSlot_Weapon = NULL;
		int nGold = 0;

		Player(string name, int lv, int hp, int mp, int sp, int dp, int speed) : Entity(name, lv, hp, mp, sp, dp, speed)
		{
			
		}

		void EntityStatus()
		{
			cout << "[�÷��̾� �������ͽ� â]--------------------------------------------------" << endl;
			cout << "[�̸�: " << GetName() << "]" << endl;
			cout << "[LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "]]" << endl;
			cout << "[C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", ���ݷ�: " << GetMinStrikingPower() << " ~ " << GetMaxStrikingPower() << ", ũ��Ƽ��: " << nAdditionalStatus_CRITICAL << " %, ����: " << GetDefensivePower() << "]" << endl;
			cout << endl;
			cout << "[����� ��������Ʈ: [���ݷ�: " << nAdditionalStatus_STR << ", ũ��Ƽ��: " << nAdditionalStatus_CRITICAL << ", ����: " << nAdditionalStatus_DEF << "]]" << endl;
			cout << "[����� ��������Ʈ: " << nUsedStatusPoint << " / ������� ���� ��������Ʈ: " << nCanUseStatusPoint << "]" << endl;
			if (EquipmentSlot_Weapon != NULL)
			{
				EquipmentSlot_Weapon->ItemStatus();
			}
			cout << "--------------------------------------------------------------------------" << endl;
		}

		void PlayerBattleStatus()
		{
			cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
			cout << endl;
		}

		void PlayerEXPSystem(int exp)
		{
			nCurrentEXP += exp;
			while (nCurrentEXP >= nMAXEXP)
			{
				nCurrentEXP -= nMAXEXP;
				nMAXEXP *= 1.2;
				LVUp(1);
				nCanUseStatusPoint += 3;
			}
			EntityStatus();
		}

		void PlayerDropSystem(Item* item = NULL, int Gold = 0)
		{

			this->nGold += Gold;
		}

		void PlayerStatusSystem()
		{
			cout << "[1.���ݷ� ����][2.ũ��Ƽ�� ����][3.���� ����][4.â�ݱ�]" << endl;
			cout << "������ �Է�: ";
			int Number;
			cin >> Number;
			switch (Number)
			{
			case 1:
			{
				if (nCanUseStatusPoint > 0)
				{
					nAdditionalStatus_STR++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
					AddStatus(1, 0, 0);
				}
				else
				{
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
					Sleep(2000);
				}
				break;
			}
			case 2:
			{
				if (nCanUseStatusPoint > 0)
				{
					nAdditionalStatus_CRITICAL++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
				}
				else
				{
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
					Sleep(1000);
				}
				break;
			}
			case 3:
			{
				if (nCanUseStatusPoint > 0)
				{
					nAdditionalStatus_DEF++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
					AddStatus(0, 1, 0);
				}
				else
				{
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
					Sleep(1000);
				}
				break;
			}
			default: return;
			}
			PlayerStatusSystem();
		}

		void Set_Equip_Weapon_Durability(int durability)
		{
			if (EquipmentSlot_Weapon != NULL)
			{
				EquipmentSlot_Weapon->SetC_Durability(durability);
			}
		}

		void SetEquipment_Weapon(Item_Equip_Weapon *weapon)
		{
			EquipmentSlot_Weapon = weapon;
			AddStatus(weapon->GetMax_AP(), weapon->GetMin_AP());
		}

		void SetPlayerMap(Map* map)
		{
			this->nCurrentMap = map;
		}

		Map* GetPlayerMap()
		{
			return nCurrentMap;
		}
	};
	//�÷��̾� ����.
	Player P_Player("�÷��̾�", 1, 50, 10, 0, 0, 1);

	//���� ����.
	Monster M_WeakSlime("��ȭ�� ������", 1, 5, 0, 2, 3, 1, 5, 1);
	Monster M_Slime("������", 3, 15, 0, 3, 3, 1, 12, 3);
	Monster M_WeakSkeleton("WeakSkeleton", 3, 30, 5, 4, 0, 1, 7, 2);

	//�� ����
	Map* StartingMap;
	Map* TrainingForest;
	Map* Beginner_HuntingField1;
	Map* Beginner_HuntingField2;

	//�� �ʱ�ȭ
	void Map_InitializeArray(int (*Array)[22])
	{
		for (int y = 0; y < 22; y++)
		{
			for (int x = 0; x < 22; x++)
			{
				Array[x][y] = { 3 };
			}
		}
	}

	//�� ����
	void Map_StartingMap_Option()
	{
		Map_InitializeArray(StartingMap->Field);
		for (int y = 0; y < 7; y++)
		{
			for (int x = 0; x < 7; x++)
			{
				StartingMap->Field[x][y] = { 001 };
				if (y == 0 || y == 6 || x == 0 || x == 6)
				{
					StartingMap->Field[x][y] = { 3 };
				}
			}
		}
		StartingMap->Field[1][3] = { 100 };
		StartingMap->Field[5][3] = { 200 };
		StartingMap->FieldHigh = 7;
	}
	void Map_TrainingForest_Option()
	{
		Map_InitializeArray(TrainingForest->Field);
		for (int y = 0; y < 7; y++)
		{
			for (int x = 0; x < 16; x++)
			{
				TrainingForest->Field[x][y] = { 001 };
				if (y == 0 || y == 6 || x == 0 || x == 15)
				{
					TrainingForest->Field[x][y] = { 3 };
				}
			}
		}
		for (int y = 6; y < 9; y++)
		{
			TrainingForest->Field[12][y] = { 001 };
			TrainingForest->Field[13][y] = { 001 };
			TrainingForest->Field[14][y] = { 001 };
		}
		TrainingForest->Field[1][3] = { 100 };
		TrainingForest->FieldHigh = 7;
	}

	void MapOption()
	{
		StartingMap = CreateMap("������ ����", 1);
		StartingMap->MapDescription = "�ʺ� �÷��̾���� ����.";
		TrainingForest = CreateMap("������ ��", 2);
		TrainingForest->MapDescription = "�ʺ� �÷��̾���� ���� �⺻���� ������ �̷������ ���.";
		Beginner_HuntingField1 = CreateMap("�ʺ��� �����1", 3);
		Beginner_HuntingField1->MapDescription = "�ʺ� �÷��̾���� ���������� ���1.";
		Beginner_HuntingField2 = CreateMap("�ʺ��� �����2", 4);
		Beginner_HuntingField2->MapDescription = "�ʺ� �÷��̾���� ���������� ���2.";

		//�� �ʵ弳��
		Map_StartingMap_Option();
		Map_TrainingForest_Option();

		cout << endl;
		LinkMapAtoB(StartingMap, TrainingForest);
		LinkMapAtoB(TrainingForest, Beginner_HuntingField1);
		LinkMapAtoB(Beginner_HuntingField1, Beginner_HuntingField2);

		cout << endl;
		MapInformation(StartingMap);
		MapInformation(TrainingForest);
		MapInformation(Beginner_HuntingField1);
		MapInformation(Beginner_HuntingField2);
	}

	void MonsterDropOption()
	{
		//M_WeakSkeleton.AddDropItem(Drop_Weapon_CommonSword_100);
	}

	void PlayerOption()
	{
		P_Player.SetEquipment_Weapon(&Weapon_WoodenSword); //�ʱ� �÷��̾� ����
		P_Player.SetPlayerMap(StartingMap);
	}

	int Attack(Player* player, Monster* monster, int n)
	{
		srand(time(0));
		if (n == 0)
		{
			int P_Damage = rand() % (player->GetMaxStrikingPower() - player->GetMinStrikingPower() + 1) + player->GetMinStrikingPower();
			int Damage = P_Damage - monster->GetDefensivePower();
			if (Damage <= 0) Damage = 1;
			monster->ChangeEntityStatus(-Damage, 0);
			return Damage;
		}
		else if (n == 1)
		{
			int M_Damage = monster->GetMaxStrikingPower() - player->GetDefensivePower();
			if (M_Damage <= 0) M_Damage = 1;
			player->ChangeEntityStatus(-M_Damage, 0);
			return M_Damage;
		}
	}
	void Attack_Output_PlayerDamage(Player* player, Monster* monster, int Damage, int n)
	{
		if (n == 0)
		{
			if (Damage <= 0) Damage = 1;

			cout << "[" << monster->GetName() << "] ���� [" << Damage << "] ��ŭ�� �������� �־���!" << endl;
			cout << "[" << monster->GetName() << ": [" << monster->GetC_HP() << "/" << monster->GetM_HP() << "]]" << endl;
		}
		else if (n == 1)
		{
			if (Damage <= 0) Damage = 1;

			cout << "[" << monster->GetName() << "] ���� [" << Damage << "] ��ŭ�� �������� �޾Ҵ�!" << endl;
			cout << "[" << player->GetName() << ": [" << player->GetC_HP() << "/" << player->GetM_HP() << "]]" << endl;
		}
	}
	void Defense_Output_Player(Player* player)
	{
		int OutputCount = player->GetDefensivePower();
		cout << "[" << player->GetName() << "] �� [����] �� [" << OutputCount << "] �� �Ǿ���!" << endl;
	}
	void BattleEnd_Output(Player* player, Monster* monster)
	{
		int GetEXP = monster->GetEXP();
		int GetGold = monster->GetGold();
		player->PlayerEXPSystem(GetEXP);
		player->PlayerDropSystem(NULL, GetGold);
		cout << "[" << monster->GetName() << "] �� �׾���!" << endl;
		cout << "[" << player->GetName() << "] [����ġ: + " << GetEXP << "]" << endl;
		cout << "[" << player->GetName() << "] [Gold: + " << GetGold << "]" << endl;
	}
}