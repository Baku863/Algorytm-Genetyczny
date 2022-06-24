# Algorytm-Genetyczny
Problem plecakowy rozwiązywany algorytmem genetycznym.

Program uruchamiany jest z linii poleceń. Do programu należy
przekazać siedem przełączników. Przykładowe wprowadzenie
przełączników powinno wyglądać tak:

program -i przedmioty.txt -o wyniki -g 2000 -k 100 -m 5 -w 7.5 -z 50

Kolejno są to: 
- plik wejściowy
- plik wyjściowy 
- liczba generacji 
- liczba krzyżowań 
- procent mutacji 
- maksymalna waga 
- szansa na dodanie genu do rozwiązania.

Uruchomienie programu z przełącznikiem -h lub bez parametrów,
powoduje wyświetlenie pomocy. Każdy nieprawidłowość dotycząca
wprowadzenia przełączników, ma odpowiedni komunikat w zależności
od tego, gdzie popełniono błąd. Podanie nieprawidłowej nazwy pliku
wejściowego informuje użytkownika o błędzie. Przykładowe błędy:
''Za mało parametrow''
''Bledny przelacznik''
''Nie istnieje przelacznik <<to co zostało wpisane>>''
''Blad szansy''
Plik wejściowy i wyjściowy są plikami tekstowymi. Przy wprowadzaniu
pliku wejściowego wymagane jest użycie rozszerzenia „ .txt”.


W programie wykorzystano dwie autorskie struktury. Pierwsza z
nich opisuje przedmiot odczytany z pliku wejściowego, za pomocą
parametrów takich jak nazwa, waga i wartość. Druga z zastosowanych
struktur w programie, opisuje pojedyncze rozwiązanie. Składa się ona z
trzech elementów. Pierwszym z nich jest wektor wypełniony
wartościami typu bool, o długości odpowiadającej ilości przedmiotów
dostępnych do rozwiązania zadania. Następnymi parametrami struktury
są waga i wartość całego rozwiązania.

Program korzysta z algorytmu genetycznego, który składa się z
czterech etapów:
- wstępnego tworzenia populacji początkowej
- krzyżowania
- mutacji
- selekcji powstałej generacji

Ogólne działanie programu:

Funkcją główna zaczyna się od wczytania przełączników
podanych w konsoli przez użytkownika, za pomocą funkcji
przelaczniki(). Funkcja jest typu bool więc, jeśli wystąpiłby jakiś błąd,
program zostanie przerwany, a użytkownik poinformowany o przyczynie
zakończenia programu. Następnie utworzony zostaje wektor elementów
opisanych za pomocą struktury item. Do tego kontenera sczytywane
będą przedmioty zawarte w pliku wejściowym, za pomocą funkcji
read(). W momencie wystąpienia błędu funkcja read() działa
analogicznie do funkcji przełączniki(). Po prawidłowym zakończeniu
funkcji, zostaje utworzony wektor elementów typu solution, który
będzie zawierał możliwe rozwiązania problemu plecakowego oraz
zainicjalizowana zmienna typu solution, do przechowywania
najlepszego rozwiązania. Następnym krokiem jest utworzenie populacji
poprzez wykonanie funkcji make_population(), która domyślnie tworzy
tylu osobników, ile przedmiotów znajduje się w wektorze. Po utworzeniu
populacji, rozpoczyna się pętla w której następuje:
- utworzenie wektora zawierającego możliwe nowe rozwiązania
- krzyżowanie osobników za pomocą funkcji crossing(), w ilości
podanej przez użytkownika
- mutacja osobnika w funkcji mutate()
- nowe osobniki są poddawane selekcji w funkcji selection()
- ostatnim krokiem w pętli jest zapisanie najlepszego osobnika do pliku
wyjściowego przy użyciu funkcji print()
Na koniec użytkownik jest poinformowany o zakończeniu działania
programu, głosowym komunikatem.
