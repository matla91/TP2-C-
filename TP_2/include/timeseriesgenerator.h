#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>
#include <random>

class TimeSeriesGenerator {
protected:
    int seed;
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seedVal);
    virtual ~TimeSeriesGenerator() {}

    // G�n�re une s�rie temporelle de taille length
    virtual std::vector<double> generateTimeSeries(int length) = 0;

    // Affiche une s�rie temporelle
    static void printTimeSeries(const std::vector<double> &ts);
};

#endif
