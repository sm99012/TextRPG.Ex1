#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

namespace h_Item
{
	enum E_Category { ��ĭ = 0, �������� = 1000, �Һ������ = 2000 };
	enum E_ItemGrade { ��� = 0, ���� = 1, ���� = 2, ����ũ = 3 };
	enum E_AttackSpeed { �ſ���� = -2, ���� = -1, ���� = 0, ���� = 1, �ſ���� = 2 };

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
		Item_Equip_Weapon(string itemname, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability) : Item (itemname, ��������, itemcode, lvlimit, itemgrade)
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
			cout << "��������[����]: [" << GetItemName() << "]" << endl;
			if (GetItemGrade() == ���)
			{
				cout << "[LV: " << GetItemLVLimit() << "][���: ���]" << endl;
			}
			else if (GetItemGrade() == ����)
			{
				cout << "[LV: " << GetItemLVLimit() << "][���: ����]" << endl;
			}
			else if (GetItemGrade() == ����)
			{
				cout << "[LV: " << GetItemLVLimit() << "][���: ����]" << endl;
			}
			else if (GetItemGrade() == ����ũ)
			{
				cout << "[LV: " << GetItemLVLimit() << "][���: ����ũ]" << endl;
			}
			if (nAttackSpeed == �ſ����)
			{
				cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: �ſ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == ����)
			{
				cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == ����)
			{
				cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == ����)
			{
				cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
			}
			else if (nAttackSpeed == �ſ����)
			{
				cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: �ſ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
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
	Item_Equip_Weapon Weapon_WoodenSword("���", 1000, 1, ���, 1, 1, 0, ����, 100);
	Item_Equip_Weapon Weapon_CommonSword("����� ��", 1001, 2, ���, 2, 3, 0, ����, 100);
	Item_Equip_Weapon Weapon_Saber("��긣", 1002, 5, ���, 1, 2, 0, ����, 100);
	Item_Equip_Weapon Weapon_OldKnife("���� �ܰ�", 1003, 3, ����, 0, 10, 0, ����, 30);

	//CreateDropItem
	//DropItem Drop_Weapon_CommonSword_100(Weapon_CommonSword, 100);

	void ItemOption()
	{
		Weapon_WoodenSword.SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� ���̴�. ������ �پ�ٰ� �� ���� ����.");
		Weapon_CommonSword.SetItemDescription("���~�� ��.");
		Weapon_Saber.SetItemDescription("TextRPG ���� ���ʿ��� �θ� ���Ǵ� ���̴�. ���ݷ��� ������ �ſ� ������ ���ݼӵ��� ������.");
		Weapon_OldKnife.SetItemDescription("�ݹ��̶� �μ����Ѹ����� ������ �ܰ��̴�. ������ ���Ҵٰ� ����ϸ� ū�ڴ�ģ��.");
	}
}