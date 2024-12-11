#include "timeseriesgenerator.h"

// Constructeur par d�faut : initialise la graine de mani�re al�atoire.
TimeSeriesGenerator::TimeSeriesGenerator() : seed(std::random_device{}()) {}

// Constructeur param�tr� : utilise une graine donn�e par l'utilisateur pour g�n�rer des r�sultats reproductibles.
TimeSeriesGenerator::TimeSeriesGenerator(int seedVal) : seed(seedVal) {}

// Fonction statique : affiche les valeurs d'une s�rie temporelle.
void TimeSeriesGenerator::printTimeSeries(const std::vector<double> &ts) {
    for (auto &val : ts) {
        std::cout << val << " "; // Affiche chaque valeur s�par�e par un espace.
    }
    std::cout << std::endl;
}
