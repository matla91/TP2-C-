#ifndef SIN_H
#define SIN_H

#include "timeseriesgenerator.h"

// Classe pour g�n�rer des s�ries temporelles bas�es sur une fonction sinuso�dale
class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double A;   // Amplitude de l'onde (hauteur maximale)
    double w;   // Fr�quence angulaire de l'onde (contr�le le nombre de cycles)
    double phi; // Phase initiale (d�calage horizontal)

public:
    // Constructeur par d�faut : initialise une onde sinus avec des valeurs standard.
    SinWaveGenerator();

    // Constructeur param�tr� : permet de d�finir une graine, l'amplitude, la fr�quence et la phase.
    SinWaveGenerator(int seedVal, double amplitude, double freq, double phase);

    // G�n�re une s�rie temporelle de taille donn�e selon l'�quation d'une onde sinuso�dale :
    // f(x) = A * sin(w * x + phi)
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
