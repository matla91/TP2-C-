#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <numeric> // Pour std::accumulate
#include <cmath>   // Pour std::sqrt
#include <stdexcept> // Pour std::invalid_argument

class TimeSeriesDataset
{
    public:
        TimeSeriesDataset(bool znormalize, bool isTrain, vector<double> data, vector<int> labels, int maxLength, int numberOfSamples)
            :znormalize(znormalize), isTrain(isTrain), data(data), labels(labels), maxLength(maxLength), numberOfSamples(numberOfSamples){
                if(znormalize){
                    applyZNormalization();
                }
            }
        virtual ~TimeSeriesDataset();

    protected:
        bool znormalize;        // Indique si les donn�es doivent �tre normalis�es
        bool isTrain;           // Indique s'il s'agit d'un ensemble d'entra�nement
        std::vector<double> data;  // Donn�es des s�ries temporelles
        std::vector<int> labels;   // �tiquettes des s�ries
        int maxLength;          // Longueur maximale d'une s�rie
        int numberOfSamples;    // Nombre d'�chantillons dans le dataset

    private:
        void applyZNormalization(int sizeSerie, double x){

            for(int i, i < sizeSerie, i++){
                x = series[i];
                x = (x - mean(data))/stddev(data);
                series.push_back(x)
            }
        }

};

#endif // TIMESERIESDATASET_H
