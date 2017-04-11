#include "sciezki.hpp"

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
                    rozmiar++;

            for(int i=0;i<sciezka.length();i++)
                    sciezka[i]=sciezka[i+(sciezka.length()-rozmiar)];

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
