#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>
#include "tsdata.h"

// Classe pour impl�menter un classifieur K-Nearest Neighbors (KNN)
class KNN {
private:
    int k;                          // Nombre de voisins � consid�rer
    std::string similarityMeasure;  // Mesure de similarit� ("dtw", "euclidean_distance", etc.)

public:
    // Constructeur : initialise le nombre de voisins et la mesure de similarit�
    KNN(int k, const std::string &similarity);

    // �value les performances du KNN en calculant la pr�cision sur le dataset de test
    // trainData : donn�es d'entra�nement avec labels
    // testData : donn�es de test sans labels
    // ground_truth : labels r�els des donn�es de test
    double evaluate(const TimeSeriesDataset &trainData, const TimeSeriesDataset &testData, const std::vector<int> &ground_truth);

private:
    // Pr�dit le label d'une s�rie de test en fonction des donn�es d'entra�nement
    // Retourne le label le plus probable bas� sur les k voisins les plus proches
    int predict(const TimeSeriesDataset &trainData, const std::vector<double> &testSeries);
};

#endif
