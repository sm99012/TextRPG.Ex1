#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "ProfessedFunction.h"

using namespace std;
using namespace h_Function;

namespace h_Map
{
    //void Map_Print(int Array[22][22], int n)
    //{
    //    for (int y = 0; y < 22; y++)
    //    {
    //        for (int x = 0; x < 22; x++)
    //        {
    //            if (Array[x][y] == 100) //플레이어
    //            {
    //                cout << "\u25a1";
    //            }
    //            else if (Array[x][y] == 001) //필드
    //            {
    //                cout << "\u25a0";
    //            }
    //            else if (Array[x][y] == 3) //벽
    //            {
    //                cout << "  ";
    //            }
    //        }
    //        cout << endl;
    //    }
    //    LineBreak(20 - n);
    //}

    //void Map_InitializeArray(int *Array[22][22])
    //{
    //    for (int y = 0; y < 22; y++)
    //    {
    //        for (int x = 0; x < 22; x++)
    //        {
    //            *Array[x][y] = { 3 };
    //        }
    //    }
    //}

    //void Map_Move(int(*Array)[22], int posx, int posy, int n)
    //{
    //    int x = posx;
    //    int y = posy;
    //    while (true)
    //    {
    //        int InputKeyCode = _getch();
    //        switch (InputKeyCode)
    //        {
    //        case 77:
    //            if (Array[x + 1][y] == 001)
    //            {
    //                Array[x][y] = 001;
    //                Array[x + 1][y] = 100;
    //                x += 1;
    //            }
    //            break;
    //        case 75:
    //            if (Array[x - 1][y] == 001)
    //            {
    //                Array[x][y] = 001;
    //                Array[x - 1][y] = 100;
    //                x -= 1;
    //            }
    //            break;
    //        case 72:
    //            if (Array[x][y - 1] == 001)
    //            {
    //                Array[x][y] = 001;
    //                Array[x][y - 1] = 100;
    //                y -= 1;
    //            }
    //            break;
    //        case 80:
    //            if (Array[x][y + 1] == 001)
    //            {
    //                Array[x][y] = 001;
    //                Array[x][y + 1] = 100;
    //                y += 1;
    //            }
    //            break;
    //        }
    //        system("cls");
    //        Map_Print(Array, n);
    //    }
    //}

    //void MapTest()
    //{
    //    int ArrayTest[22][22] = { 0 };
    //    Map_InitializeArray(ArrayTest);
    //    for (int y = 0; y < 12; y++)
    //    {
    //        for (int x = 0; x < 22; x++)
    //        {
    //            ArrayTest[x][y] = { 001 };
    //            if (y == 0 || y == 11 || x == 0 || x == 21)
    //            {
    //                ArrayTest[x][y] = { 3 };
    //            }
    //        }
    //    }
    //    ArrayTest[1][1] = { 100 };

    //    Map_Print(ArrayTest);

    //    Map_Move(ArrayTest, 1, 1);
    //    //int a = _getch();
    //    //printf("Received Input: %d\n", a);
    //}

    //int Map_FindPlayer(int(*Array)[22], int n)
    //{
    //    bool isFind = false;
    //    int a, b;
    //    for (int y = 0; y < 12; y++)
    //    {
    //        for (int x = 0; x < 22; x++)
    //        {
    //            if (Array[x][y] == 100)
    //            {
    //                a = x; b = y;
    //                isFind = true;
    //                break;
    //            }
    //        }
    //        if (isFind == true) break;
    //    }
    //    if (n == 0)
    //    {
    //        cout << "x: " << a;
    //        return a;
    //    }
    //    else
    //    {
    //        cout << "y: " << b;
    //        return b;
    //    }
    //}

    //void Map_Explorer(int(*Array)[22], int n)
    //{
    //    system("cls");
    //    Map_Print(Array, n);

    //    int x = Map_FindPlayer(Array, 0);
    //    int y = Map_FindPlayer(Array, 1);

    //    Map_Move(Array, x, y, n);
    //}
}