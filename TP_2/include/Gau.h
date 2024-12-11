#ifndef GAU_H
#define GAU_H

#include "timeseriesgenerator.h"

// Classe pour g�n�rer des s�ries temporelles selon une distribution gaussienne (normale)
class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;   // Moyenne de la distribution
    double stddev; // �cart type de la distribution
public:
    // Constructeur par d�faut : initialise la graine al�atoire et utilise une moyenne de 0 et un �cart type de 1.
    GaussianGenerator();

    // Constructeur param�tr� : permet de d�finir la graine, la moyenne et l'�cart type.
    GaussianGenerator(int seedVal, double meanVal, double stdVal);

    // G�n�re une s�rie temporelle de taille donn�e en utilisant la distribution gaussienne.
    virtual std::vector<double> generateTimeSeries(int length) override;
};

#endif
