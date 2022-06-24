/**@file funkcje.h*/
#ifndef FUNKCJE_H 
#define FUNKCJE_H 
#include "struktury.h"
using namespace std;
/**
* Funkcja losujaca numer rozwiazania
* @param max - maksymalna liczba do wylosowania
* @return  wylosowany numer 
*/
int random(int max);
/**
* Funkcja drukujaca najlepsze rozwiazanie w generacji
* @param x - najlepsze rozwiazanie 
* @param z - wektor przedmiotow
* @param count - licznik
* @param plik - nazwa pliku wyjsciowego
* @param organizmy - wektor rozwiazan
* @param konsola - czy zawartosc ma byc wydrukowana w konsoli
*/
void print(solution& x, vector<item>& z, int count, ofstream& plik, vector<solution>& organizmy, bool konsola = 0);
/**
* Funkcja dokonujaca selekcji w wektorze rozwiazan zaleznie od rozmiaru wektora
* @param x - wektor rozwiazan w ktorym nalezy dokonac selekcji
* @param waga - maksymalna dopuszczalna masa rozwiazania
*/
void selection(vector<solution>& x, double& waga);
/**
* Funkcja odczytujaca przelaczniki z konsoli 
* @param rozmiar - rozmiar tablicy z przelacznikami
* @param tab - tablica z przelacznikami
* @param wej - plik wejsciowy
* @param wyj - plik wyjsciowy
* @param l_gen - ilosc generacji do policzenia
* @param l_krzyz - ilosc krzyzowan na generacje
* @param waga - maksymalna dopuszczalna waga
* @param mutacje - szansa na mutacje rozwiazania
* @param szansa - szansa na dodanie genu do rozwiazania w tworzeniu populacji
* @return Jesli przelaczniki zostaly prawidlowo podane zwraca 1, w przeciwnym wypadku 0
*/
bool przelaczniki(int& rozmiar, char* tab[], string& wej, string& wyj, int& l_gen, int& l_krzyz,double& waga, int& mutacje,int& szansa);
/**
* Funkcja odczytujaca dane z pliku wejsciowego
* @param tab - wektor przedmiotow
* @param plik_wej - nazwa pliku wejsciowego
* @param max_weight - maksymalna prawidlowa waga rozwiazania
* @return Jesli dane zostaly prawidlowo odczytane z pliku funkcja zwraca 1, w przeciwnym wypadku 0
*/
bool read(vector<item>& tab, string& plik_wej, double& max_weight);
/**
* Funkcja generujaca poczatkowa populacje
* @param przedmioty - wektor przedmiotow
* @param organizmy - wektor rozwiazan
* @param najlepszy - najlepsze rozwiazanie
* @param waga - maksymalna prawidlowa waga rozwiazania
* @param szansa - szansa na dodanie genu do rozwiazania w tworzeniu populacji
*/
void make_population(vector<item>& przedmioty, vector<solution>& organizmy,solution& najlepszy, double& waga, int& szansa);
/**
* Funkcja krzyzujaca osobniki
* @param x - wektor rozwiazan
* @param nowe - wektor rozwiazan zawierajacy nowe osobniki
* @param y - wektor przedmiotow
* @param najlepszy - najlepsze rozwiazanie
* @param waga - maksymalna prawidlowa waga rozwiazania
* @param mut - szansa na mutacje osobnika 
*/
void crossing(vector<solution>& x,vector<solution>& nowe, vector<item>& y, solution& najlepszy, double& waga,int mut);
/**
* Funkcja funkcja mutujaca osobnika
* @param x - wektor rozwiazan
* @param przedmioty - wektor przedmiotow
*/
void mutate(solution& x, vector<item>& przedmioty);
/**
* Funkcja drukujaca pomoc przy wprowadzaniu przelacznikow
*/
void help();
#endif