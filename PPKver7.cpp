#include "funkcje.h"
using namespace std;
int main(int argc, char* argv[])
{
    string naz_pl_wej = "przedmioty.txt";
    string naz_pl_wyj = "wyniki.txt";
    int l_gen = 1000;
    int l_krzy = 10;
    int wspol_mut = 2;
    double max_weight = 12;
    int szansa = 200;
    //if (przelaczniki(argc, argv, naz_pl_wej, naz_pl_wyj, l_gen, l_krzy, max_weight, wspol_mut, szansa))
    {
        //zmienne globalne
        vector<item> przedmioty;
        //odczytanie danych z pliku
        if (read(przedmioty, naz_pl_wej, max_weight) == 0)
            return 0;
        //tworzenie populacji
        vector<solution> organizmy;
        solution best;
        best.value = 0;
        make_population(przedmioty, organizmy, best, max_weight, szansa);
        //liczenie generacji
        ofstream plik_wyj(naz_pl_wyj);
        int ilosc = 0;
        while (ilosc < l_gen)
        {
            vector<solution> nowe_organizmy;
            //krzyzowanie
            for (int i = 0; i < l_krzy; i++)
            {
                crossing(organizmy, nowe_organizmy, przedmioty, best, max_weight, wspol_mut);
            }
            //selekcja
            selection(nowe_organizmy, max_weight);
            for (int i = 0; i < nowe_organizmy.size(); i++)
            {
                organizmy.push_back(nowe_organizmy[i]);
            }
            //drukowanie
            print(best, przedmioty, ilosc, plik_wyj, organizmy,1);
            ilosc++;
        }
        plik_wyj.close();
        PlaySound(TEXT("track2.wav"), NULL, SND_FILENAME);
    }
    //else
    //{
    //    return 0;
    //}
}