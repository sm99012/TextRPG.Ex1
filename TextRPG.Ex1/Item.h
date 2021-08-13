#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

namespace h_Item
{
	enum E_Category { 빈칸 = 0, 장비아이템 = 1000, 소비아이템 = 2000 };
	enum E_ItemGrade { 노멀 = 0, 레어 = 1, 에픽 = 2, 유니크 = 3 };
	enum E_AttackSpeed { 매우느림 = -2, 느림 = -1, 보통 = 0, 빠름 = 1, 매우빠름 = 2 };

	class Item
	{
		string nItemName = "";
		int nItemCategory = 0;
		int nItemCode = 0;
		int nLVLimit = 0;
		int nItemGrade = 0;
		string nItemDescription = "";

	public:
		Item() {}
		Item(string itemname, int category , int itemcode, int lvlimit, int itemgrade)
		{
			this->nItemName = itemname;
			this->nItemCategory = category;
			this->nItemCode = itemcode;
			this->nLVLimit = lvlimit;
			this->nItemGrade = itemgrade;
		}
		Item(string itemname, E_Category category, int itemcode, int lvlimit, E_ItemGrade itemgrade)
		{
			this->nItemName = itemname;
			this->nItemCategory = category;
			this->nItemCode = itemcode;
			this->nLVLimit = lvlimit;
			this->nItemGrade = itemgrade;
		}

		void SetItemDescription(string description)
		{
			this->nItemDescription = description;
		}

		string GetItemName()
		{
			return nItemName;
		}
		int GetItemLVLimit()
		{
			return nLVLimit;
		}
		int GetItemGrade()
		{
			return nItemGrade;
		}
		string GetItemDescription()
		{
			return nItemDescription;
		}
	};

	class Item_Equip_Weapon : public Item
	{
		int nMIN_AP;
		int nMAX_AP;
		int nDP;
		int nAttackSpeed;
		int nM_Durability;
		int nC_Durability;

	public:
		Item_Equip_Weapon(string itemname, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability) : Item (itemname, 장비아이템, itemcode, lvlimit, itemgrade)
		{
			this->nMIN_AP = min_ap;
			this->nMAX_AP = max_ap;
			this->nDP = dp;
			this->nAttackSpeed = attackspeed;
			this->nM_Durability = durability;
			this->nC_Durability = durability;
		}

		void ItemStatus()
		{
			cout << "장비아이템[무기]: [" << GetItemName() << "]" << endl;
			if (GetItemGrade() == 노멀)
			{
				cout << "[LV: " << GetItemLVLimit() << "][등급: 노멀]" << endl;
			}
			else if (GetItemGrade() == 레어)
			{
				cout << "[LV: " << GetItemLVLimit() << "][등급: 레어]" << endl;
			}
			else if (GetItemGrade() == 에픽)
			{
				cout << "[LV: " << GetItemLVLimit() << "][등급: 에픽]" << endl;
			}
			else if (GetItemGrade() == 유니크)
			{
				cout << "[LV: " << GetItemLVLimit() << "][등급: 유니크]" << endl;
			}
			if (nAttackSpeed == 매우느림)
			{
				cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 매우느림][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == 느림)
			{
				cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 느림][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == 보통)
			{
				cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 보통][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == 빠름)
			{
				cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 빠름][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == 매우빠름)
			{
				cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 매우빠름][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			cout << "[" << GetItemDescription() << "]" << endl;
		}

		void SetC_Durability(int durability)
		{
			if (nC_Durability + durability > 0)
			{
				this->nC_Durability += durability;
			}
			else this->nC_Durability = 0;
		}

		int GetMin_AP()
		{
			return nMIN_AP;
		}
		int GetMax_AP()
		{
			return nMAX_AP;
		}
	};

	//class DropItem
	//{
	//	Item* nItem;
	//	int nDropPercent;

	//public:
	//	DropItem(Item item, int droppercent)
	//	{
	//		*nItem = item;
	//		this->nDropPercent = droppercent;
	//	}
	//	void Show()
	//	{
	//		nItem->ItemStatus();
	//	}
	//};

	//CreateItem
	Item_Equip_Weapon Weapon_WoodenSword("목검", 1000, 1, 노멀, 1, 1, 0, 보통, 100);
	Item_Equip_Weapon Weapon_CommonSword("평범한 검", 1001, 2, 노멀, 2, 3, 0, 보통, 100);
	Item_Equip_Weapon Weapon_Saber("사브르", 1002, 5, 노멀, 1, 2, 0, 빠름, 100);
	Item_Equip_Weapon Weapon_OldKnife("낡은 단검", 1003, 3, 레어, 0, 10, 0, 빠름, 30);

	//CreateDropItem
	//DropItem Drop_Weapon_CommonSword_100(Weapon_CommonSword, 100);

	void ItemOption()
	{
		Weapon_WoodenSword.SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 검이다. 살상력이 뛰어나다고 할 수는 없다.");
		Weapon_CommonSword.SetItemDescription("평범~한 검.");
		Weapon_Saber.SetItemDescription("TextRPG 월드 서쪽에서 널리 사용되는 검이다. 공격력은 낮지만 매우 가벼워 공격속도가 빠르다.");
		Weapon_OldKnife.SetItemDescription("금방이라도 부서질겉만같은 오래된 단검이다. 하지만 낡았다고 방심하면 큰코다친다.");
	}
}