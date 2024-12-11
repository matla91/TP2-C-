#include "tsdata.h"
#include <algorithm> // Pour std::fill
#include <limits>    // Pour les valeurs limites comme std::numeric_limits

// Constructeur : initialise les param�tres de normalisation et de type (entra�nement ou test)
TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0) {}

// Ajoute une s�rie temporelle avec un label (pour l'entra�nement uniquement)
void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series, int label) {
    if (!isTrain) {
        throw std::runtime_error("Trying to add labeled series to a test dataset."); // Erreur : ce n'est pas un dataset d'entra�nement
    }
    if (numberOfSamples == 0) {
        maxLength = (int) series.size(); // D�finit la longueur des s�ries � partir de la premi�re s�rie ajout�e
    } else if ((int)series.size() != maxLength) {
        throw std::runtime_error("All series must have the same length."); // V�rifie que toutes les s�ries ont la m�me longueur
    }

    std::vector<double> s = series;
    if (znormalize) {
        s = zNormalizeSeries(series); // Normalise la s�rie si n�cessaire
    }

    data.insert(data.end(), s.begin(), s.end()); // Ajoute la s�rie au dataset
    labels.push_back(label);                     // Ajoute le label correspondant
    numberOfSamples++;
}

// Ajoute une s�rie temporelle sans label (pour le test uniquement)
void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series) {
    if (isTrain) {
        throw std::runtime_error("Trying to add unlabeled series to a training dataset."); // Erreur : ce n'est pas un dataset de test
    }
    if (numberOfSamples == 0) {
        maxLength = (int) series.size(); // D�finit la longueur des s�ries � partir de la premi�re s�rie ajout�e
    } else if ((int)series.size() != maxLength) {
        throw std::runtime_error("All series must have the same length."); // V�rifie que toutes les s�ries ont la m�me longueur
    }

    std::vector<double> s = series;
    if (znormalize) {
        s = zNormalizeSeries(series); // Normalise la s�rie si n�cessaire
    }

    data.insert(data.end(), s.begin(), s.end()); // Ajoute la s�rie au dataset
    numberOfSamples++;
}

// Retourne le nombre total de s�ries dans le dataset
int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

// Retourne la longueur des s�ries
int TimeSeriesDataset::getSeriesLength() const {
    return maxLength;
}

// Retourne une s�rie temporelle � partir de son index
std::vector<double> TimeSeriesDataset::getSeries(int index) const {
    if (index < 0 || index >= numberOfSamples) {
        throw std::out_of_range("Invalid index in getSeries."); // V�rifie que l'index est valide
    }
    return std::vector<double>(data.begin() + index * maxLength, data.begin() + (index + 1) * maxLength);
}

// Retourne le label d'une s�rie (uniquement pour l'entra�nement)
int TimeSeriesDataset::getLabel(int index) const {
    if (!isTrain) {
        throw std::runtime_error("No labels available for a test dataset."); // Erreur : les labels n'existent pas pour un dataset de test
    }
    if (index < 0 || index >= numberOfSamples) {
        throw std::out_of_range("Invalid index in getLabel."); // V�rifie que l'index est valide
    }
    return labels[index];
}

// Effectue une Z-normalisation sur une s�rie temporelle
std::vector<double> TimeSeriesDataset::zNormalizeSeries(const std::vector<double> &series) const {
    // Calcul de la moyenne
    double mean = 0.0;
    for (auto &val : series) mean += val;
    mean /= series.size();

    // Calcul de la variance
    double var = 0.0;
    for (auto &val : series) {
        double diff = val - mean;
        var += diff * diff;
    }
    var /= series.size();

    // Calcul de l'�cart type
    double stddev = std::sqrt(var);

    std::vector<double> normalized(series.size());
    if (stddev < 1e-12) {
        // Si la s�rie est constante, retourne une s�rie remplie de z�ros
        std::fill(normalized.begin(), normalized.end(), 0.0);
    } else {
        // Normalise chaque valeur
        for (size_t i = 0; i < series.size(); i++) {
            normalized[i] = (series[i] - mean) / stddev;
        }
    }

    return normalized;
}
