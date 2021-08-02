#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <windows.h>
#include "Map.h"
#include "Entity.h"

using namespace std;
using namespace h_Map;
using namespace h_Entity;

void main()
{
	//플레이어생성
	Player Player("Player", 1, 50, 10, 3, 3, 1);

	//몬스터생성
	Monster M_WeakSlime("WeakSlime", 1, 20, 0, 1, 1, 1, 4);
	M_WeakSlime.AddDropItem(Equip_Weapon_Sword);

	Monster M_WeakSkeleton("WeakSkeleton", 3, 30, 5, 3, 0, 1, 7);
	M_WeakSkeleton.AddDropItem(Equip_Weapon_Sword);
	M_WeakSkeleton.AddDropItem(Equip_Weapon_Saber);
	M_WeakSkeleton.AddDropItem(Equip_Weapon_Knife);

	Player.EntityStatus();
	M_WeakSlime.EntityStatus();
	M_WeakSkeleton.EntityStatus();
	
	Map Map1();
}