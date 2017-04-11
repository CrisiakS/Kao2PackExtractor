#ifndef plik_hpp
#define plik_hpp

    #include "../biblioteki/biblioteki.hpp"

    class plik
    {
        private:
            string nazwa;
            string sciezka_systemowa;
            string sciezka_oryginalna;
            string tokenID;
            short int ZeraNaglowka;
            string poczatek;
            string koniec;

            fstream *dane;
        public:

    };

#endif // plik_hpp
