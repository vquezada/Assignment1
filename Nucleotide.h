#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;
//Nucleotide class
class Nucleotide{
public:

//constructors
    Nucleotide();
    ~Nucleotide();
//Class variables
    string floatile;
    float linesInFile;
    string newLine;
    float nucSum;
    float mean;
    float nucVariance;
    float stanDev;
    string d;

    float numA;
    float numC;
    float numT;
    float numG;

    float probA;
    float probC;
    float probT;
    float probG;

    float numAA;
    float numAC;
    float numAT;
    float numAG;
    float numCA;
    float numCC;
    float numCT;
    float numCG;
    float numTA;
    float numTC;
    float numTT;
    float numTG;
    float numGA;
    float numGC;
    float numGT;
    float numGG;
    float probAA;
    float probAC;
    float probAT;
    float probAG;
    float probCA;
    float probCC;
    float probCT;
    float probCG;
    float probTA;
    float probTC;
    float probTT;
    float probTG;
    float probGA;
    float probGC;
    float probGT;
    float probGG;

//class functions
    void nucLines(string dnaFile);

    void calcSum(string dnaFile);

    void calcMean();

    void calcVariance(string dnaFile);

    void calcDeviation();

    void calcProbability(string dnaFile);

    void calcBigram(string dnaFile);

    void gaussianStrands();
};
