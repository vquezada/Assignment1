#include <iostream>
#include <string>
#include <fstream>
#include "Nucleotide.h"
using namespace std;


int main(){
// create object
    Nucleotide* dnaData = new Nucleotide();
    cout << "enter file name: " << endl;
    string dnaFile;
    cin>> dnaFile;
// opens file and catches error
    ifstream file;
    file.open(dnaFile);
    if(!file.is_open()){
    cout << "error" << endl;
    cout << "enter file name: " << endl;
    getline(cin, dnaFile);
  }
  else{
    file.close();
  }
//moves data to out file
    dnaData->nucLines(dnaFile);
    dnaData->calcSum(dnaFile);
    dnaData->calcMean();
    dnaData->calcVariance(dnaFile);
    dnaData->calcDeviation();
    dnaData->calcProbability(dnaFile);
    dnaData->calcBigram(dnaFile);
    dnaData->gaussianStrands();

  return 0;



}
