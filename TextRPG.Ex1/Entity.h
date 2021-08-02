#pragma once
#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

namespace h_Entity
{
	class Entity
	{
		string nEntityName;
		static int EntityCode;
		int nEntityCode;

		int nLV;
		int nHP;
		int nMP;

		int nStrikingPower;
		int nDefensivePower;
		int nSpeed;

	public:
		Entity(string name, int lv, int hp, int mp, int sp, int dp, int speed)
		{
			EntityCode += 1;
			this->nEntityName = name;
			this->nLV = lv;
			this->nEntityCode = EntityCode;
			this->nHP = hp;
			this->nMP = mp;
			this->nStrikingPower = sp;
			this->nDefensivePower = dp;
			this->nSpeed = speed;
		}

		virtual void EntityStatus()
		{
			cout << "[이름: " << nEntityName << ", LV: " << nLV << ", HP: " << nHP << ", MP: " << nMP << "]" << endl;
		}

		void ChangeEntityStatus(int hp = 0, int mp = 0)
		{
			if (nHP + hp >= 0) this->nHP += hp;
			else this->nHP = 0;
			if (nMP + mp >= 0) this->nMP += mp;
			else this->nMP = 0;
			EntityStatus();
		}

		string GetName()
		{
			return nEntityName;
		}

		int GetEntityCode()
		{
			return nEntityCode;
		}

		int GetHP()
		{
			return nHP;
		}

		int GetMP()
		{
			return nMP;
		}

		int GetLV()
		{
			return nLV;
		}

		void LVUp(int lv)
		{
			this->nLV += lv;
			nHP += 10;
			nMP += 2;
		}
	}
	;int Entity::EntityCode = 0;

	class Item
	{
		string nItemName;
		int nItemCategory;
		int nItemCode;
		enum E_Category { 장비아이템 = 1, 소비아이템 = 2 };

	public:
		Item(string itemname, int category, int itemcode)
		{
			this->nItemName = itemname;
			this->nItemCategory = category;
			this->nItemCode = itemcode;
		}

		string GetIteName()
		{
			return nItemName;
		}
	};
	//CreateItem
	Item Equip_Weapon_Sword("Sword", 1000, 1000);
	Item Equip_Weapon_Saber("Saber", 1000, 1001);
	Item Equip_Weapon_Knife("Knife", 1000, 1002);
	class EquipmentSlot
	{


	public:
		EquipmentSlot()
		{

		}
	};

	class ItemSlot
	{


	public:
		ItemSlot()
		{

		}
	};

	class Player : public Entity
	{
		int nMAXEXP = 12;
		int nCurrentEXP = 0;
		static EquipmentSlot* nEquipmentSlot;
		static ItemSlot* nItemSlot;

	public:
		Player(string name, int lv, int hp, int mp, int sp, int dp, int speed) : Entity(name, lv, hp, mp, sp, dp, speed)
		{

		}

		void EntityStatus()
		{
			cout << "[이름: " << GetName() << ", LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "], HP: " << GetHP() << ", MP: " << GetMP() << "]" << endl;
			cout << endl;
		}

		void PlayerEXPSystem(int exp)
		{
			nCurrentEXP += exp;
			while (nCurrentEXP >= nMAXEXP)
			{
				nCurrentEXP -= nMAXEXP;
				nMAXEXP *= 1.5;
				LVUp(1);
			}
			EntityStatus();
		}
	};

	//CreateEquipmentSlot
	EquipmentSlot* Player::nEquipmentSlot;
	//CreateItemSlot
	ItemSlot* Player::nItemSlot;

	class Monster : public Entity
	{
		int nEXP;
		vector <Item> DropItem;

	public:
		Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp) : Entity(name, lv, hp, mp, sp, dp, speed)
		{
			this->nEXP = exp;
		}

		void EntityStatus()
		{
			cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", HP: " << GetHP() << ", MP: " << GetMP() << ", EXP: " << nEXP << "]" << endl;
			DropItemList();
			cout << endl;
		}

		void AddDropItem(Item item)
		{
			DropItem.push_back(item);
		}

		void DropItemList()
		{
			cout << "[드랍아이템]" << endl;
			vector <Item>::iterator it;
			int ItemNumber = 1;
			for (it = DropItem.begin(); it != DropItem.end(); it++)
			{
				Item Item = *it;
				cout << ItemNumber << ". " << Item.GetIteName() << endl;
				ItemNumber++;
			}
		}
	};
}