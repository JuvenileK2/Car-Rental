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
                puts("Usunac ktory wiersz tablicy Auto?: ");
                scanf("%d",&n);
                RemoveAuto(n,&tAuta);
                break;
        case 33:
                puts("Usunac ktory wiersz tablicy Wypozyczenia?: ");
                scanf("%d",&n);
                RemoveWypozyczenie(n,&tWypozyczenia);
                break;
        case 41:							
                puts("Wybierz rekord z tabeli, ktory chcesz zmodyfikowac");
                puts("1 - Osoby\n 2 - Auta\n 3 - Wypozyczenia\n");
                scanf("%d", &n);
                if(n == 1){
                    puts("Podaj numer wiersza do edycji: ");
                    scanf("%d", &n);
                    if(n >= 0 && n < linesO){
                        struct Osoba osoba = tOsoby[n];
                        puts("Podaj nowe dane w nastepujacej kolejnosci(imie, nazwisko, adres");
                        scanf("%s %s %s", osoba.imie, osoba.nazwisko, osoba.adres);
                        Osoby[n] = osoba;
                        puts("Dane zostaly nadpisane");
                    }
                   
                }
                
               else if(n == 2){
                    puts("Podaj numer wiersza do edycji: ");
                    scanf("%d", &n);
                    if(n >= 0 && n < linesA){
                        struct Auto auto = tAuta[n];
                        puts("Podaj nowe dane w nastepujacej kolejnosci(marka, model, kolor");
                        scanf("%s %s %s", auto.marka, auto.model, auto.kolor);
                        Auta[n] = auto;
                        puts("Dane zostaly nadpisane");
                    }
                    
                    
                   
                }
             else if(n == 3){
                    puts("Podaj numer wiersza do edycji");
                    scanf("%d", &n);
                    if(n >= 0 && n < linesW){
                        struct Wypozyczenia wypozyczenia = tWypozyczenia[n];
                        puts("Podaj nowe dane w nastepujacej kolejnosci(Numer klienta, numer samochodu, data wypozyczenia, data zwrotu");
                        scanf("%u %u %u %u", &wypozyczenia.nr_klienta, &wypozyczenia.nr_samochodu, &wypozyczenia.data_wyp, &wypozyczenia.data_zwrotu);
                        Wypozyczenia[n] = wypozyczenia;
                        puts("Dane zostaly nadpisane");
                        
                        
                    }
                    else{
                        puts("Podaj poprawna wartosc!")
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
		if(strcmp(tOsoby[i].imie,"DELETE"))
			continue;
		SaveOsoba(tOsoby[i]);
	}
	for(int i=0;i<linesA;i++){
		Backup("Auta.txt");
		if(strcmp(tAuta[i].model,"DELETE"))
			continue;
		SaveAuto(tAuta[i]);
	}
	for(int i=0;i<linesW;i++){
		Backup("Wypozyczenia.txt");
		if(tWypozyczenia[i].cena=0.0)
			continue;
		SaveWypozyczenie(tWypozyczenia[i]);
	}
}
