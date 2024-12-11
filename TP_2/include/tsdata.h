#ifndef TSDATA_H
#define TSDATA_H

#include <vector>
#include <cmath>
#include <stdexcept>

// Classe pour repr�senter un ensemble de s�ries temporelles (entra�nement ou test)
class TimeSeriesDataset {
private:
    bool znormalize;                  // Indique si les s�ries doivent �tre normalis�es (Z-normalization)
    bool isTrain;                     // Indique si cet ensemble est pour l'entra�nement (true) ou le test (false)
    std::vector<double> data;         // Contient les s�ries temporelles stock�es de mani�re s�quentielle
    std::vector<int> labels;          // Contient les �tiquettes des s�ries (uniquement pour l'entra�nement)
    int maxLength;                    // Longueur maximale des s�ries
    int numberOfSamples;              // Nombre total de s�ries dans l'ensemble

public:
    // Constructeur : initialise le dataset avec les param�tres de normalisation et le type (entra�nement/test)
    TimeSeriesDataset(bool znormalize, bool isTrain);

    // Ajoute une s�rie temporelle avec un label (uniquement pour les donn�es d'entra�nement)
    void addTimeSeries(const std::vector<double> &series, int label);

    // Ajoute une s�rie temporelle sans label (uniquement pour les donn�es de test)
    void addTimeSeries(const std::vector<double> &series);

    // Retourne le nombre total de s�ries dans l'ensemble
    int getNumberOfSamples() const;

    // Retourne la longueur des s�ries (toutes les s�ries ont la m�me longueur)
    int getSeriesLength() const;

    // Retourne une s�rie temporelle � partir de son index
    std::vector<double> getSeries(int index) const;

    // Retourne le label d'une s�rie (uniquement pour l'entra�nement)
    int getLabel(int index) const;

    // Indique si cet ensemble est destin� � l'entra�nement
    bool isTrainingSet() const { return isTrain; }

private:
    // Effectue une Z-normalisation sur une s�rie temporelle
    std::vector<double> zNormalizeSeries(const std::vector<double> &series) const;
};

#endif
