#include "stp.h"
#include <random>

// Constructeur par d�faut : initialise la graine avec une valeur al�atoire.
StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

// Constructeur param�tr� : initialise la graine avec une valeur donn�e (pour des r�sultats reproductibles).
StepGenerator::StepGenerator(int seedVal) : TimeSeriesGenerator(seedVal) {}

// G�n�re une s�rie temporelle avec un comportement de saut
std::vector<double> StepGenerator::generateTimeSeries(int length) {
    // G�n�rateur de nombres al�atoires bas� sur la graine.
    std::mt19937 gen(seed);

    // Distribution pour les valeurs enti�res dans l'intervalle [0, 100].
    std::uniform_int_distribution<int> dist_val(0, 100);

    // Distribution pour g�n�rer une probabilit� entre 0.0 et 1.0.
    std::uniform_real_distribution<double> dist_prob(0.0, 1.0);

    // Vecteur pour stocker la s�rie temporelle, initialis�e avec des z�ros.
    std::vector<double> series(length, 0.0);
    series[0] = 0.0; // La premi�re valeur est toujours 0.

    // Remplit le vecteur avec des valeurs g�n�r�es.
    for (int i = 1; i < length; i++) {
        double p = dist_prob(gen); // G�n�re une probabilit� al�atoire.
        if (p < 0.5) {
            // Avec 50% de chance, choisit une nouvelle valeur entre 0 et 100.
            series[i] = dist_val(gen);
        } else {
            // Sinon, conserve la valeur pr�c�dente.
            series[i] = series[i - 1];
        }
    }

    // Retourne la s�rie g�n�r�e.
    return series;
}
