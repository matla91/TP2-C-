#ifndef STP_H
#define STP_H

#include "timeseriesgenerator.h"

// Classe pour g�n�rer des s�ries temporelles avec une fonction de saut
class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par d�faut : initialise une graine al�atoire.
    StepGenerator();

    // Constructeur param�tr� : permet de d�finir une graine sp�cifique pour des r�sultats reproductibles.
    StepGenerator(int seedVal);

    // G�n�re une s�rie temporelle de taille donn�e selon une logique de saut :
    // - � chaque instant, une nouvelle valeur al�atoire entre 0 et 100 est choisie (50% de chance).
    // - Sinon, la valeur pr�c�dente est conserv�e.
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
