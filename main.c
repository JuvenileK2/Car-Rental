#include <stdio.h>
#include "DBfunc.h"



int main(){
	int cmd;
	int loop = 1;
	int n;

	int linesO=0;
	int linesA=0;
	int linesW=0;
	struct Osoba *tOsoby;
	struct Auto *tAuta;
	struct Wypozyczenia *tWypozyczenia;

	puts("Ladowanie tablic");
	linesO = InitTableOsoby(&tOsoby);
	linesA = InitTableAuta(&tAuta);
	linesW = InitTableWypozyczenia(&tWypozyczenia);
	puts("\nTablice wczytane");


	while(loop){
		puts("\nPodaj komende:\n");
		scanf("%d",&cmd);
		switch(cmd){
		default:
			puts("Wpisz 0 aby wyswietlic pomoc, 9 aby wyjsc");
			break;
		case 0:
			puts("1 - Osoba\n 2 - Auto\n 3 - Wypozyczenia\n");
			puts("\n1(1,2,3) - wyswietl\n");
			puts("2(1,2,3) - dodaj\n");
			puts("3(1,2,3) - usun\n");
			break;

		case 11:
			WyswietlOsoba(&tOsoby,linesO);
			break;
		case 12:
			WyswietlAuto(&tAuta,linesA);
			break;
		case 13:
			WyswietlWypoczyenie(&tWypozyczenia,linesW);
			break;
		case 21:
			linesO = AddOsoba(MakeOsoba(),&tOsoby,linesO);
			break;
		case 22:
			linesA = AddAuto(MakeAuto(),&tAuta,linesA);
			break;
		case 23:
			linesW = AddWypozyczenie(MakeWypozyczenia(),&tWypozyczenia,linesW);
			break;
		case 31:
			puts("Usunac ktory wiersz tablicy?: ");
			scanf("%d",&n);
			RemoveOsoba(n,&tOsoby);
			break;
		case 32:
                {
                int n;
                puts("Podaj numer wiersza do edycji: ");
                scanf("%d", &n);
                if (n >= 0 && n < linesW) {
                struct Wypozyczenia wypozyczenie = tWypozyczenia[n];
                puts("Podaj nowe dane w nastepujacej kolejnosci (Numer klienta, numer samochodu, data wypozyczenia, data zwrotu, cena, kaucja)");
                scanf("%d %d %s %s %f %f", &wypozyczenie.nr_klienta, &wypozyczenie.nr_samochodu, wypozyczenie.data_wyp, wypozyczenie.data_zwrotu, &wypozyczenie.cena, &wypozyczenie.kaucja);
                tWypozyczenia[n] = wypozyczenie;
                puts("Dane zostaly nadpisane");

                FILE* file = fopen("Wypozyczenia.txt", "r+");

                if (file != NULL) {
                fseek(file, n * sizeof(struct Wypozyczenia), SEEK_SET);
                fwrite(&wypozyczenie, sizeof(struct Wypozyczenia), 1, file);
                fclose(file);
                }
                else
                    {
                    puts("Blad otwarcia pliku");
                    }
                }
                else
                {
                    puts("Podaj poprawny numer wiersza!");
                }
        }
break;

		case 9:
			loop = 0;
			break;
		}
	}
	puts("Zapisywanie plikow");
	for(int i=0;i<linesO;i++){
		Backup("Osoby.txt");
		SaveOsoba(tOsoby[i]);
	}
	for(int i=0;i<linesA;i++){
		Backup("Auta.txt");
		SaveAuto(tAuta[i]);
	}
	for(int i=0;i<linesW;i++){
		Backup("Wypozyczenia.txt");
		SaveWypozyczenie(tWypozyczenia[i]);
	}
}
