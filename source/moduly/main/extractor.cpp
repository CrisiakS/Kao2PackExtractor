/**

 //DO ZROBIENIA - PROGRAM NIE OGARNIA CZASAMI PLIKOW ".AR" I ".DEF" I NIE OGARNAI TWORZENIA LOKALIZACJI Z
 //PRZECIWNYM UKOŒNIKIEM - ZROBIONE

 -PRZEPISAC METODY NA OBIEKTY BY MOZNA BYLO NIMI SWOBODNIE OPEROWAC;
 -STWORZYC PLIK ZAWIERAJACY POZOSTALE DANE PO PLIKACH I ICH STARE SCIEZKI ORAZ IDENTYFIKATORY BY MÓC W
  W PRZYSZLOSCI SPAKOWAC WSZYSTKO SPOWROTEM JAK BYLO
 -USUWANIE OKOLO 25 OSTATNICH NULLI I SLOWKA ITEM Z KAZDEGO PLIKU



**/

#include "../biblioteki/biblioteki.hpp"
#include "../sciezki/sciezki.hpp"

extern fstream log;

    unsigned char item[]={'i','t','e','m'};
    unsigned char item_porownanie[4];

    int ile_zer=0;

    bool debug=true;

bool odnaleziono_plik()
{
        if(item[0]==item_porownanie[0] and
           item[1]==item_porownanie[1] and
           item[2]==item_porownanie[2] and
           item[3]==item_porownanie[3])
                {
                    cout<<endl<<"Znaleziono faze 'item'!"<<endl;
                    cout<<"ile zer - "<<ile_zer<<endl;
                 //   getch();
                    return true;
                }
                else
                {
                    return false;
                }
}



bool prawdopodobny_item()
    {
        bool prawdopodobienstwo;
        if(item_porownanie[3]==item[0] and item_porownanie[2]==0 and item_porownanie[1]==0 and item_porownanie[0]==0)
            prawdopodobienstwo=true;
        else if(item_porownanie[2]==item[0] and item_porownanie[3]==item[1] and item_porownanie[1]==0 and item_porownanie[0]==0)
            prawdopodobienstwo=true;
        else if(item_porownanie[1]==item[0] and item_porownanie[2]==item[1] and item_porownanie[3]==item[2] and item_porownanie[0]==0)
            prawdopodobienstwo=true;
        else if(item_porownanie[0]==item[0] and item_porownanie[1]==item[1] and item_porownanie[2]==item[2] and item_porownanie[3]==item[3])
            prawdopodobienstwo=true;
        else
            prawdopodobienstwo=false;

        return prawdopodobienstwo;
    }


int main()
{
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

     bool pomin_raz=false;


     bool czytanie_sciezki=false;
     short int faza_odczytu=1;

     for(int i=1;!pliczek.eof();i++)
     {
         if(pomin_raz==true)
             {
                 pomin_raz=false;
             }
         else
             {
                 pliczek.read(( char * ) & x, sizeof x );

                    item_porownanie[0]=item_porownanie[1];
                    item_porownanie[1]=item_porownanie[2];
                    item_porownanie[2]=item_porownanie[3];
                    item_porownanie[3]=x;
             }


        if(faza_odczytu==1)
        {
            if(x==0)
                {
                    ile_zer++;
                }
            if(x!=0 and !prawdopodobny_item())
                {
                    ile_zer=0;
                }
            if(x!=0 and prawdopodobny_item())
                {
                    ile_zer++;
                }

            if(odnaleziono_plik() and ile_zer>=25)
                {
                    ile_zer=0;

                    poczatek_sciezki=i+13;
                    czytanie_sciezki=true;
                    ile_plikow++;
                    item_temp=0;
                    faza_odczytu=2;
                    cout<<"Koniec 1 fazy odczytu"<<endl;
                    cout<<"2 faza odczytu"<<endl;

                        cout<<"Odnaleziono plik nr:"<<ile_plikow<<endl;
                        log<<"Odnaleziono plik nr:"<<ile_plikow<<endl;
                }
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
                            cout<<"Koniec 2 fazy odczytu"<<endl;
                            cout<<"3 faza odczytu"<<endl;
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
            bool usuniete_zera=false;

            char dane_pliku;

            while(!odnaleziono_plik() and !pliczek.eof())
            {
                pliczek.read(( char * ) & x, sizeof x );
                i++;
              //  getch();

                item_porownanie[0]=item_porownanie[1];
                item_porownanie[1]=item_porownanie[2];
                item_porownanie[2]=item_porownanie[3];
                item_porownanie[3]=x;

                if(x==0 )
                    {
                        ile_zer++;
                    }

                if(x!=0 and !prawdopodobny_item())
                    {
                        ile_zer=0;
                    }

                if(x!=0 and prawdopodobny_item())
                    {
                        ile_zer++;
                    }
               //     cout<<ile_zer<<endl;

                bufor_tga[0]=bufor_tga[1];
                bufor_tga[1]=x;

             //   cout<<endl<<(int)x<<endl;
             //   cout<<usuniete_zera<<endl;
             //   getch();

                if(x!=0 and usuniete_zera==false)
                {
                    if(x==2)
                    {
                        wsk_dane->write(&bufor_tga[0],sizeof x);
                        wsk_dane->write(&bufor_tga[0],sizeof x);
                    }
                    cout<<"Zera usuniete - rozpoczynam zapis do pliku"<<endl;
                    log<<"Zera usuniete - rozpoczynam zapis do pliku"<<endl;
                    usuniete_zera=true;
                }

                if(usuniete_zera==true)
                {
                    // zapisywanie danych
                    wsk_dane->write(&x,sizeof x);
                }
            }
            //czyszczenie z koncowych zer
            wsk_dane->close();
            delete wsk_dane;
            cout<<endl<<endl<<"--------------------------"<<endl;
            log<<endl<<endl<<"--------------------------"<<endl;

            cout<<"ilosc zer przy powrocie - "<<ile_zer<<endl;
      //      getch();
            faza_odczytu=1;
            pomin_raz=true;

      //      getch();

            cout<<"Koniec 3 fazy odczytu"<<endl;
            cout<<"1 faza odczytu"<<endl;
        }

     }
    cout<<endl<<"Ilosc plikow: "<<ile_plikow<<endl;
    log<<endl<<"Ilosc plikow: "<<ile_plikow<<endl;
    log.close();
    cin>>x;

}



