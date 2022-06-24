/**@file*/
#ifndef STRUKTURY_H
#define STRUKTURY_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>
#include <random>
#pragma comment(lib,"winmm.lib")
using namespace std;
/**
* Struktura definiujaca jeden przedmiot
* @struct item
* @param name - nazwa przedmiotu
* @param weight - waga przedmiotu
* @param value - wartosc przedmiotu
*/
struct item
{
    string name;
    double weight=0;
    double value=0;
};
/**
* Struktura definiujaca jedno rozwiazanie problemu
* @struct solution
* @param body - wektor 0 i 1 okreslajacych czy przedmiot wg kolejnosci dodania znajduje sie w rozwiazaniu
* @param weight - waga rozwiazania
* @param value - wartosc rozwiazania
* @param operator - definiuje jak maja byc sortowane elementy
*/
struct solution
{
    vector<bool> body;
    double weight=0;
    double value=0;
};
#endif
