#include <iostream>
#include <iomanip> // fuer setprecision()



class rational
{
    private:
        int zaehler, nenner; // Privat, kann man nur innerhalb der Klasse aufrufen

    public:
        rational(int zaehlerr, int nennerr) // Kunstruktor
        {
            setvar(zaehlerr,nennerr); // Funktionsaufruf, Variablen setzen
        }

        void setvar(int zaehlerr, int nennerr)
        {
            zaehler = zaehlerr; // zaehler setzen
            nenner = nennerr; // nenner setzen
        }

        int kgv(int nenner1, int nenner2) // Kleinste gemeinsames vielfaches bestimmen, zum erweitern
        {
            int found_kgv = 0; // Gefundener kleinste gemeinsame vielfache
            int i = 1; // Bei 1 Anfangen

            while (found_kgv==0)
            {
                if(i%nenner1==0) // i ganz teilbar durch Nenner1
                {
                    if(i%nenner2==0) // und i ganz teilbar durch Nenner2
                    {
                        found_kgv = 1; // kgv gefunden, schleife beenden
                    }
                     else
                     {
                         i++; // i inkrementieren
                     }
                }
                 else
                 {
                     i++; // i inkrementieren
                 }
            }
            return i; // i returnen i=>kgv
        }

        int ggt(int zaehler, int nenner) // groeßte gemeinsame teiler bestimmen. zum kuerzen
        {
            if (nenner < 0)
            {
                nenner = nenner * (-1);
            }
            int i = nenner;

            while(i <= nenner)
            {
                if(nenner%i==0) // Nenner3 ganz teilbar durch i
                {
                    if(zaehler%i==0) // und Zaehler3 ganz teilbar durch i 
                    {
                        break; // Schleife beenden, ggt gefunden
                    }
                     else
                     {
                         i--; // i dekrementieren
                     }
                }
                 else
                 {
                     i--; // i dekrementieren
                 }
            }
            return i; // i returnen, i=>ggt
        }

        rational operator +(rational bruch2)
        {
            if(nenner%bruch2.nenner == 0) // Nur Bruch2 erweitern
            {
                int multiplikator;

                multiplikator = nenner/bruch2.nenner; // Multiplikator zum erweitern bestimmen
                bruch2.zaehler = bruch2.zaehler * multiplikator; // Bruch2 erwitern
            }
            else if(bruch2.nenner%nenner==0) // Nur Bruch1 erweitern
            {
                int multiplikator;

                multiplikator = bruch2.nenner/nenner; // Multiplikator zum erwitern bestimmen
                zaehler = zaehler * multiplikator; // Bruch1 erwitern
            }
            else
            {
                int kgv_;
                int multiplikator;

                kgv_ = kgv(nenner, bruch2.nenner); // Kleinster emeinsames vielfaches bestimmen

                multiplikator = kgv_/nenner; // Multiplkikator1 berechnen
                zaehler = zaehler * multiplikator; // Bruch1 erwitern
                nenner = nenner * multiplikator;

                multiplikator = kgv_/bruch2.nenner; // Multiplikator2 berechnen
                bruch2.zaehler = bruch2.zaehler * multiplikator; // Brcuh2 erwitern
                bruch2.nenner = bruch2.nenner * multiplikator;
            }
            int ggt_;
            ggt_ = ggt(zaehler+bruch2.zaehler, nenner); // Groeßte gemeinsame Teiler bestimmen
            if(ggt_==0) // Wenn ggt == 0
            {
                return rational(zaehler+bruch2.zaehler,nenner); // Ohne Kuerzen berechnen
            }
             else
             {
                return rational((zaehler+bruch2.zaehler)/ggt_, nenner/ggt_); // Ansonsten mit Kuerzen
             }
        }

        rational operator -(rational bruch2) // Funktionb siehe Addition identisch
        {
            if(nenner%bruch2.nenner == 0)
            {
                int multiplikator;

                multiplikator = nenner/bruch2.nenner;
                bruch2.zaehler = bruch2.zaehler * multiplikator;
            }
            else if(bruch2.nenner%nenner==0)
            {
                int multiplikator;

                multiplikator = bruch2.nenner/nenner;
                zaehler = zaehler * multiplikator;
            }
            else
            {
                int kgv_;
                int multiplikator;

                kgv_ = kgv(nenner, bruch2.nenner);

                multiplikator = kgv_/nenner;
                zaehler = zaehler * multiplikator;
                nenner = nenner * multiplikator;

                multiplikator = kgv_/bruch2.nenner;
                bruch2.zaehler = bruch2.zaehler * multiplikator;
                bruch2.nenner = bruch2.nenner * multiplikator;
            }
            int ggt_;
            ggt_ = ggt(zaehler-bruch2.zaehler, nenner);
            if(ggt_==0)
            {
                return rational(zaehler-bruch2.zaehler,nenner);
            }
             else
             {
                return rational((zaehler-bruch2.zaehler)/ggt_, nenner/ggt_);
             }
        }

        rational operator *(rational bruch2)
        {
            zaehler = zaehler * bruch2.zaehler; // Zaehler1 * Zaehler2
            nenner = nenner * bruch2.nenner; // Nenner1 * Nenner2

            int ggt_;
            ggt_ = ggt(zaehler, nenner); // Groeßte gemeinsame Teiler bestimmen
            if(ggt_==0) // Wenn ggt == 0
            {
                return rational(zaehler,nenner); // Ohne Kuerzen berechnen
            }
             else
             {
                return rational(zaehler/ggt_, nenner/ggt_); // Ansonsten mit Kuerzen
             }
        }

        rational operator /(rational bruch2)
        {
            zaehler = zaehler * bruch2.nenner;
            nenner = nenner * bruch2.zaehler;

            int ggt_;
            ggt_ = ggt(zaehler, nenner); // Groeßte gemeinsame Teiler bestimmen
            if(ggt_==0) // Wenn ggt == 0
            {
                return rational(zaehler,nenner); // Ohne Kuerzen berechnen
            }
             else
             {
                return rational(zaehler/ggt_, nenner/ggt_); // Ansonsten mit Kuerzen
             }
        }

        void print()
        {
            double kommazahl = double(zaehler)/double(nenner);

            std::cout << zaehler << '/' << nenner << '\n';
            std::cout << std::setprecision(3) << kommazahl << '\n';
        }

};

int main()
{
    int zaehler1, nenner1, zaehler2, nenner2; 
    char slash, operation;
    rational bruch1(2, 3); 
    rational bruch2(2, 3);
    rational bruch3(2, 3);

    std::cout << "Eingabe: \n"; 
    std::cin >> zaehler1 >> slash >> nenner1 >> operation >> zaehler2 >> slash >> nenner2;
    bruch1.setvar(zaehler1,nenner1); // Variablen bruch1 setzen
    bruch2.setvar(zaehler2,nenner2); // Variablen bruch2 setzen

    switch(operation)
    {
        case '+': bruch3 = bruch1+bruch2;
                  bruch3.print();
                  break;
        case '-': bruch3 = bruch1-bruch2;
                  bruch3.print();
                  break;
        case '*': bruch3 = bruch1*bruch2;
                  bruch3.print();
                  break;
        case '/': bruch3 = bruch1/bruch2;
                  bruch3.print();
                  break;
    }



    return 0;
}