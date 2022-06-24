#include "funkcje.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
default_random_engine generator(time(NULL));
int random(int max)
{
    
    uniform_int_distribution<int> liczby(0, max);
    int number = liczby(generator);
    return number;
}
void print(solution& x, vector<item>& z, int count, ofstream& plik, vector<solution>& organizmy, bool konsola)
{
    if (konsola)
    {
        cout << endl << "Generacja " << count + 1 << ", waga " << x.weight << ", wartosc " << x.value << endl;
        for (int i = 0; i < x.body.size(); i++)
        {
            if (x.body[i] == 1)
            {
                cout << z[i].name << " waga " << z[i].weight << ", wartosc " << z[i].value << endl;
            }
        }
        cout << "**wielkosc tablicy " << organizmy.size() << "**" << endl;
        return;
    }
    else
    {
        plik << endl << "Generacja " << count + 1 << ", waga " << x.weight << ", wartosc " << x.value << endl;
        for (int i = 0; i < x.body.size(); i++)
        {
            if (x.body[i] == 1)
            {
                plik << z[i].name << " waga " << z[i].weight << ", wartosc " << z[i].value << endl;
            }
        }
        return;
    }
}
void selection(vector<solution>& x,double& waga)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i].weight > 1.5* waga || x[i].weight == 0)
        {
            x.erase(x.begin() + i);
            i--;
            continue;
        }
    }  
}
void help()
{
    cout << "Program do dzialania wymaga siedmiu przelacznikow, oto mozliwe opcje:" << endl;
    cout << " -g           po tym wpisujemy ilosc generacji do wyliczeniaw" << endl;
    cout << " -h           ten przelacznik wyswietla pomoc" << endl;
    cout << " -i           po tym wpisujemy nazwe pliku wejsciowego" << endl;
    cout << " -k           po tym wpisujemy ile krzyzowan ma wystapic na generacje" << endl;
    cout << " -m           po tym wpisujemy procent mutacji do dwoch miejsc po przecinku np. 5.25" << endl;
    cout << " -o           po tym wpisujemy nazwe pliku wyjsciowego" << endl;
    cout << " -w           po tym wpisujemy maksymalna mozliwa wage plecaka" << endl;
    cout << " -z           szansa na dodanie przedmiotu do rozwiazania" << endl;
    return;
}
bool przelaczniki(int& rozmiar, char* tab[], string& wej, string& wyj, int& l_gen, int& l_krzyz,double& waga, int& mutacja,int& szansa)
{
    if (rozmiar == 15)
    {
        for (int i = 1; i < rozmiar; i++)
        {
            int ilosc = 0;
            string przelacznik = tab[i];
            if (przelacznik.size() == 2)
            {
                switch (przelacznik[1])
                {
                case'h':
                    help();
                    return 0;
                case 'i':
                    i++;
                    wej = tab[i];
                    break;
                case 'o':
                    i++;
                    wyj = tab[i];
                    break;
                case 'm':
                    i++;
                    przelacznik = tab[i];
                    for (int y = 0; y < przelacznik.size(); y++)
                    {
                        if (isdigit(przelacznik[y])|| przelacznik[y]=='.')
                        {
                            if (przelacznik[y] == '.')
                                ilosc++;
                            if (ilosc == 2)
                            {
                                cout << "Blad mutacji" << endl;
                                help();
                                return 0;
                            }
                            continue;
                        }
                        else
                        {
                            cout << "Blad mutacji" << endl;
                            help();
                            return 0;
                        }
                    }
                    
                    mutacja = atof(tab[i]);
                    mutacja *= 10;
                    break;
                case 'g':
                    i++;
                    przelacznik = tab[i];
                    for (int y = 0; y < przelacznik.size(); y++)
                    {
                        if (isdigit(przelacznik[y]))
                        {
                            continue;
                        }
                        else
                        {
                            cout << "Blad generacji" << endl;
                            help();
                            return 0;
                        }
                    }
                    l_gen = atoi(tab[i]);
                    break;
                case 'k':
                    i++;
                    przelacznik = tab[i];
                    for (int y = 0; y < przelacznik.size(); y++)
                    {
                        if (isdigit(przelacznik[y]))
                        {
                            continue;
                        }
                        else
                        {
                            cout << "Blad krzyzowan" << endl;
                            help();
                            return 0;
                        }
                    }
                    l_krzyz = atoi(tab[i]);
                    break;
                case 'w':
                    i++;
                    przelacznik = tab[i];
                    for (int y = 0; y < przelacznik.size(); y++)
                    {
                        if (isdigit(przelacznik[y]) || przelacznik[y] == '.')
                        {
                            if (przelacznik[y] == '.')
                                ilosc++;
                            if (ilosc == 2)
                            {
                                cout << "Blad wagi" << endl;
                                help();
                                return 0;
                            }
                            continue;
                        }
                        else
                        {
                            cout << "Blad wagi"<<endl;
                            help();
                            return 0;
                        }
                    }
                    waga = atof(tab[i]);
                    break;
                case 'z':
                    i++;
                    przelacznik = tab[i];
                    for (int y = 0; y < przelacznik.size(); y++)
                    {
                        if (isdigit(przelacznik[y]) || przelacznik[y] == '.')
                        {
                            if (przelacznik[y] == '.')
                                ilosc++;
                            if (ilosc == 2)
                            {
                                cout << "Blad szansy" << endl;
                                cout << endl;
                                help();
                                return 0;
                            }
                            continue;
                        }
                        else
                        {
                            cout << "Blad szansy" << endl;
                            help();
                            return 0;
                        }
                    }
                    szansa = atof(tab[i]);
                    szansa *= 10;
                    break;
                default:
                    cout << "Nie istnieje przelacznik "<<tab[i] << endl;
                    help();
                    return 0;
                }
            }
            else
            {
                cout << "Bledny przelacznik" << i<< endl;
                help();
                return 0;
            }
        }
        return 1;
    }
    else
    {
    cout << "Za malo parametrow" << endl;
        help();
        return 0;
    }
}
bool read(vector<item>& tab, string& plik_wej,double& max_weight)
{
    ifstream plik(plik_wej);
    if (plik.is_open())
    {
        item cos;
        int ilosc = 0;
        while (plik >> cos.name)
        {
            ilosc += 1;
            if (plik >> cos.weight)
            {
                ilosc += 1;
            }
            if (plik >> cos.value)
            {
                ilosc += 1;
            }
            if (cin.fail())
            {
                cout << "Plik wejsciowy zawiera bledy" << endl;
                return 0;
            }
            if (cos.weight <= max_weight)
                tab.push_back(cos);
        }
        if (ilosc%3 != 0)
        {
            cout << "Brakuje danych w pliku" << endl;
            plik.close();
            return 0;
        }
        plik.close();
    }
    else
    {
        cout << "Plik " <<plik_wej << " nie istnieje" << "\n";
        plik.close();
        return 0;
    }
    return 1;
}
void make_population(vector<item>& przedmioty, vector<solution>& organizmy, solution& najlepszy, double& waga, int& szansa)
{
    for (int i = 0; i < przedmioty.size(); i++)
    {
        solution zwierze;

        for (int y = 0; y < przedmioty.size(); y++)
        {
            int losuj = random(999) + 1;
            if (losuj < szansa)
            {
                zwierze.body.push_back(1);
                zwierze.weight += przedmioty[y].weight;
                zwierze.value += przedmioty[y].value;
            }
            else
                zwierze.body.push_back(0);
        }
        if (zwierze.weight <= waga && zwierze.value > najlepszy.value)
        {
            najlepszy = zwierze;
            PlaySound(TEXT("track1.wav"), NULL, SND_FILENAME);
        }
        organizmy.push_back(zwierze);
    }
}
void mutate(solution& x, vector<item>& przedmioty) 
{
    int miejsce = rand() % przedmioty.size();
    if (x.body[miejsce] == 0)
    {
        x.body[miejsce] = 1;
        x.weight += przedmioty[miejsce].weight;
        x.value += przedmioty[miejsce].value;
    }
    else
    {
        x.body[miejsce] = 0;
        x.weight -= przedmioty[miejsce].weight;
        x.value -= przedmioty[miejsce].value;
    }
}
void crossing(vector<solution>& x, vector<solution>& nowe, vector<item>& tab, solution& najlepszy, double& waga, int mut)
{
        solution new1, new2;
        int index1 = random(x.size()-1);
        int index2 = random(x.size()-1);
        int cut1 = rand() % (tab.size() - 2)+1;
        for (int i = 0; i < cut1; i++)
        {
            new1.body.push_back(x[index1].body[i]);
            if (x[index1].body[i] == 1)
            {
                new1.weight += tab[i].weight;
                new1.value += tab[i].value;
            }
            new2.body.push_back(x[index2].body[i]);
            if (x[index2].body[i] == 1)
            {
                new2.weight += tab[i].weight;
                new2.value += tab[i].value;
            }
        }
        for (int i = cut1; i < tab.size(); i++)
        {
            new1.body.push_back(x[index2].body[i]);
            if (x[index2].body[i] == 1)
            {
                new1.weight += tab[i].weight;
                new1.value += tab[i].value;
            }
            new2.body.push_back(x[index1].body[i]);
            if (x[index1].body[i] == 1)
            {
                new2.weight += tab[i].weight;
                new2.value += tab[i].value;
            }
        }
        int mutation = random(999) + 1;
        if (mutation <= mut)
        {
            mutate(new1, tab);
        }
        nowe.push_back(new1);
        if (new1.weight<=waga && new1.value>najlepszy.value)
        {
            PlaySound(TEXT("track1.wav"), NULL, SND_FILENAME);
            najlepszy = new1;
        }
        mutation = random(999) + 1;
        if (mutation <= mut)
        {
            mutate(new2, tab);
        }
        nowe.push_back(new2);
        if (new2.weight<=waga && new2.value>najlepszy.value)
        {
            PlaySound(TEXT("track1.wav"), NULL, SND_FILENAME);
            najlepszy = new2;
        }
}
