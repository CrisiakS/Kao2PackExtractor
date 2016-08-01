/**

 //DO ZROBIENIA - PROGRAM NIE OGARNIA CZASAMI PLIKOW ".AR" I ".DEF" I NIE OGARNAI TWORZENIA LOKALIZACJI Z
 //PRZECIWNYM UKOŒNIKIEM - ZROBIONE

 -PRZEPISAC METODY NA OBIEKTY BY MOZNA BYLO NIMI SWOBODNIE OPEROWAC;
 -STWORZYC PLIK ZAWIERAJACY POZOSTALE DANE PO PLIKACH I ICH STARE SCIEZKI ORAZ IDENTYFIKATORY BY MÓC W
  W PRZYSZLOSCI SPAKOWAC WSZYSTKO SPOWROTEM JAK BYLO
 -USUWANIE OKOLO 25 OSTATNICH NULLI I SLOWKA ITEM Z KAZDEGO PLIKU

  while(YoutubeVideo.isPlaying("Wgurzyłam sie [REUPLOAD]"))
	{
		myself->cancer.inject(body);
	}


**/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <direct.h>
using namespace std;
extern fstream log;

    unsigned char item[]={'i','t','e','m'};
    unsigned char item_porownanie[4];

    int ile_zer=16;
    int ile_zer_odczyt=0;

    bool debug=true;

bool odnaleziono_plik()
{
        if(item[0]==item_porownanie[0] and
           item[1]==item_porownanie[1] and
           item[2]==item_porownanie[2] and
           item[3]==item_porownanie[3])
                {
                    return true;
                }
                else
                {
                    return false;
                }
}

string sama_sciezka_pliku(string sciezka)
{
        short unsigned int rozmiar_bez_pliku=0;
        for(int i=sciezka.length();sciezka[i]!='/';i--)
        {
                rozmiar_bez_pliku=i-1;
        }
        if(rozmiar_bez_pliku!=0);
            sciezka.resize(rozmiar_bez_pliku);
        return sciezka;
}

void stworz_sciezke(string sciezka)
{
    string folder;
    cout<<"Proba stwozenia na sciezce - "<<sciezka<<endl;
    for(int i=0;i<sciezka.length();i++)
    {
        if(sciezka[i]!=47 and sciezka[i]!=92)
        {
            folder+=sciezka[i];
        }
        else
        {
            cout<<"mkdir - "<<folder<<endl;
            mkdir(folder.c_str());
            folder+=sciezka[i];
        }

    }
    cout<<"mkdir - "<<folder<<endl;
    mkdir(folder.c_str());
}

string sama_nazwa_pliku(string sciezka)
{
    short unsigned int rozmiar=0;
    for (int i=sciezka.length()-1;sciezka[i]!='/' and sciezka[i]!=92;i--)
        {
                rozmiar++;
        }
    for(int i=0;i<sciezka.length();i++)
        {
            sciezka[i]=sciezka[i+(sciezka.length()-rozmiar)];
        }

    sciezka.resize(rozmiar);
    return sciezka;
}

string sciezka_do_pliku_poprawiona(string sciezka)
{
    string poprawiona_sciezka="";
    for(int i=0;i<sciezka.size();i++)
    {
        if(sciezka[i]==92)
            {
                poprawiona_sciezka+=47;
            }
        else if(sciezka[i]==47 and sciezka[i+1]==47)
            {
                poprawiona_sciezka+=47;
                ++i;

            }
        else
            {
                poprawiona_sciezka+=sciezka[i];
            }
    }
    return poprawiona_sciezka;
}

int main()
{
  //  char dupa[]="dupa8";
  //  plik nowy(dupa);
     const char *nazwa_pliku;
     string nazwa;

     cout<<"Podaj Sciezke pliku :";
     cin>>nazwa;

     nazwa_pliku=nazwa.c_str();
     fstream log("log.txt", ios::out);

     ifstream pliczek(nazwa_pliku, ios::out | ios::binary);
     fstream *wsk_dane;
     const char *wsk_sciezka;
     string sciezka_do_pliku;

     vector<unsigned char> sciezka_pliku;
     char x = 0;
     int item_temp;
     int poczatek_sciezki;
     int ile_plikow=0;

     bool czytanie_sciezki=false;
     short int faza_odczytu=1;


     for(int i=1;!pliczek.eof();i++)
     {
        pliczek.read(( char * ) & x, sizeof x );

        item_porownanie[0]=item_porownanie[1];
        item_porownanie[1]=item_porownanie[2];
        item_porownanie[2]=item_porownanie[3];
        item_porownanie[3]=x;


        if(x==0)
            {
                ile_zer++;
            }
            else if(odnaleziono_plik() and ile_zer>15)
            {
                ile_zer=0;

                poczatek_sciezki=i+13;
                czytanie_sciezki=true;
                ile_plikow++;
                item_temp=0;
                faza_odczytu=2;

                    cout<<"Odnaleziono plik nr:"<<ile_plikow<<endl;
                    log<<"Odnaleziono plik nr:"<<ile_plikow<<endl;
            }


        if(faza_odczytu==2)
        {
            if(poczatek_sciezki<=i)
            {
                if(czytanie_sciezki==true)
                {
                     if(x!=0 and x>32 and x<123)
                     {
                        sciezka_do_pliku+=x;
                     }
                    else
                        {
                            const char * wsk_sciezka_do_pliku = sciezka_do_pliku.c_str();
                            poczatek_sciezki=0;
                            czytanie_sciezki=false;
                            faza_odczytu=3;

                           // getch();
                        }
                }
            }
        }

        if(faza_odczytu==3)
        {
            cout<<"Surowa sciezka '"<<sciezka_do_pliku<<"'"<<endl;
            log<<"Surowa sciezka '"<<sciezka_do_pliku<<"'"<<endl;
            cout<<"Poprawiona sciezka '"<<sciezka_do_pliku_poprawiona(sciezka_do_pliku)<<"'"<<endl;
            log<<"Poprawiona sciezka '"<<sciezka_do_pliku_poprawiona(sciezka_do_pliku)<<"'"<<endl;
            cout<<"Poprawiona sama sciezka '"<<sciezka_do_pliku_poprawiona(sama_sciezka_pliku(sciezka_do_pliku_poprawiona(sciezka_do_pliku)))<<"'"<<endl;
            log<<"Poprawiona sama sciezka '"<<sciezka_do_pliku_poprawiona(sama_sciezka_pliku(sciezka_do_pliku_poprawiona(sciezka_do_pliku)))<<"'"<<endl;
            cout<<"Nazwa pliku '"<<sama_nazwa_pliku(sciezka_do_pliku)<<"'"<<endl;
            log<<"Nazwa pliku '"<<sama_nazwa_pliku(sciezka_do_pliku)<<"'"<<endl;
            stworz_sciezke(sciezka_do_pliku_poprawiona(sama_sciezka_pliku(sciezka_do_pliku_poprawiona(sciezka_do_pliku))));

            wsk_dane=new fstream;
            cout<<"Tworze plik na poprawionej lokalizacji '"<<sciezka_do_pliku_poprawiona(sciezka_do_pliku)<<"'"<<endl;
            log<<"Tworze plik na poprawionej lokalizacji '"<<sciezka_do_pliku_poprawiona(sciezka_do_pliku)<<"'"<<endl;

            wsk_dane->open(sciezka_do_pliku_poprawiona(sciezka_do_pliku).c_str(),ios::out | ios::binary);
            sciezka_do_pliku="";

            char bufor_tga[2];

            bool wypierdolone_zera=false;
            while(!odnaleziono_plik() and ile_zer<25)
            {
                pliczek.read(( char * ) & x, sizeof x );
                i++;

                item_porownanie[0]=item_porownanie[1];
                item_porownanie[1]=item_porownanie[2];
                item_porownanie[2]=item_porownanie[3];
                item_porownanie[3]=x;

                bufor_tga[0]=bufor_tga[1];
                bufor_tga[1]=x;

                if(x!=0 and wypierdolone_zera==false)
                {
                    if(x==2)
                    {
                        wsk_dane->write(&bufor_tga[0],sizeof x);
                        wsk_dane->write(&bufor_tga[0],sizeof x);
                    }
                    cout<<"Zera Wypierdolone - rozpoczynam zapis do pliku"<<endl;
                    log<<"Zera Wypierdolone - rozpoczynam zapis do pliku"<<endl;
                    wypierdolone_zera=true;
                }



                if(wypierdolone_zera==true)
                {


                 //   w tym miejscu zbieraja sie dane programu


                    wsk_dane->write(&x,sizeof x);
               //     cout<<x;
                }
            }
            wsk_dane->close();
            delete wsk_dane;
            cout<<endl<<endl<<"--------------------------"<<endl;
            log<<endl<<endl<<"--------------------------"<<endl;
            faza_odczytu=1;
        }

     }
    cout<<endl<<"Ilosc plikow: "<<ile_plikow<<endl;
    log<<endl<<"Ilosc plikow: "<<ile_plikow<<endl;
    log.close();
    cin>>x;

}



