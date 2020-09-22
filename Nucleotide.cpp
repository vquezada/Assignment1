#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <random>

#include "Nucleotide.h"

using namespace std;
//data variables
Nucleotide::Nucleotide(){
  nucSum = 0;
  mean = 0;
  nucVariance = 0;
  stanDev = 0;
}
Nucleotide::~Nucleotide(){
}
/////////////////////////////////////////////

//This function count the number of line in the file.
void Nucleotide::nucLines(string dnaFile){

    ifstream file;
    file.open(dnaFile);
    if(!file.is_open())
    {
        cout << "Error can not open file.";
        return;
    }

    string line;
    linesInFile = 0;

    while(getline(file, line))
    {
        linesInFile++;
    }
    file.close();
}

//////////////////////////////////////////////
//This function calculates the sum of characters in the file.
void Nucleotide::calcSum(string dnaFile){
    ofstream outFile;
    outFile.open("veneziaQuezada.out", fstream::app);
    if(outFile.is_open()){

        outFile << "\n - Assignment 1 data - \n" << "Venezia Quezada \n" <<
	    "Student ID: 002341304 \n" << endl;

        ifstream file;
        file.open(dnaFile);
        if(!file.is_open())
        {
            cout << "Error can not open file." << endl;
	        return;
	    }
        string line;
        nucSum = 0;
        int i;
        while(getline(file, line))
        {
            for(i = 0; i < line.length(); ++i){
              nucSum++;
            }

	    }
	    file.close();
    }

        outFile << "The sum of the length of the DNA strings is: \n" << nucSum << endl;

        outFile.close();

    }


/////////////////////////////////////////////
//This function calculates mean
void Nucleotide::calcMean(){

    ofstream outFile;
    outFile.open("veneziaQuezada.out",fstream::app);

    if (outFile.is_open())
    {
        mean = (float)nucSum / linesInFile;
        outFile << "The mean of the length of DNA strings is:  \n" << mean << endl;
        outFile.close();
    }
}

/////////////////////////////////////////////
//This function calculates variance
void Nucleotide::calcVariance(string dnaFile)
{

    ofstream outFile;
    outFile.open("veneziaQuezada.out", fstream::app);

    if(outFile.is_open())
    {

      ifstream file;
      file.open(dnaFile);
      if(!file.is_open())
	{
	  cout << "error";
	  return;

	}
      string line;
      float var;
      float startNum = 0.0;
      float varReset;
      while(getline (file, line)){
        varReset = (float)(line.length() - mean);
	      startNum += (varReset * varReset);
	      var++;
	}

      nucVariance = startNum / var;
      file.close();
      outFile << "The variance of the length of DNA strings is: \n" << nucVariance << endl;
      outFile.close();

    }
}

////////////////////////////////////////////
//This function calculates deviation
void Nucleotide::calcDeviation()
{
  ofstream outFile;
  outFile.open("veneziaQuezada.out",  fstream::app);

  if (outFile.is_open ())
    {
      float stanDev = sqrt(nucVariance);
      outFile << "The standard deviation of the length of DNA strings is: \n" << stanDev << endl;
      outFile.close ();
    }

}

/////////////////////////////////////////
//This function calculates Probability
void Nucleotide::calcProbability (string dnaFile){
     ofstream outFile;
     outFile.open("veneziaQuezada.out", fstream::app);
     if (outFile.is_open())
    {

        ifstream file;
        file.open(dnaFile);
        if (!file.is_open())
        {
          cout << "Error can not open file." << endl;
	        return;
        }

      string line;
      float numA;
      float numC;
      float numT;
      float numG;
      numA = 0.0;
      numT = 0.0;
      numC = 0.0;
      numG = 0.0;



    while (getline (file, line))
      {
        int i;
        for (i = 0; i < line.length(); ++i)
        {
          if (line[i] == 'a' || line[i] == 'A')
          {
            ++numA;
            continue;
          }

	        else if (line[i] == 't' || line[i] == 'T')
	        {
		        ++numT;
		        continue;
	        }

	        else if (line[i] == 'c' ||line[i] ==  'C')
	        {
		        ++numC;
		        continue;
	        }

	        else if (line[i] == 'g' || line[i] == 'G')
	        {
		        ++numG;
		        continue;
	        }
	       }

}


    probA = numA / (float)nucSum;
    probT = numT / (float)nucSum;
    probC = numC / (float)nucSum;
    probG = numG / (float)nucSum;
    outFile << "Here is the relative probability of each nucleotide:" << endl;
    outFile << "A: " << probA <<endl;
    outFile << "T: " << probT <<endl;
    outFile << "C: " << probC <<endl;
    outFile << "G: " << probG <<endl;

    
    outFile.close();
    file.close();
  }


}
///////////////////////////////////////
//This function calculates bigram

void Nucleotide::calcBigram(string dnaFile){
    ofstream outFile;
    outFile.open("veneziaQuezada.out", fstream::app);
    if(outFile.is_open()){
        ifstream file;
        file.open(dnaFile);
        if(!file.is_open()){
          cout<< "error" << endl;
          return;
        }


    string line;
    numAA = 0.0;
    numAC = 0.0;
    numAT = 0.0;
    numAG = 0.0;
    numCA = 0.0;
    numCC = 0.0;
    numCT = 0.0;
    numCG = 0.0;
    numTA = 0.0;
    numTC = 0.0;
    numTT = 0.0;
    numTG = 0.0;
    numGA = 0.0;
    numGC = 0.0;
    numGT = 0.0;
    numGG = 0.0;

    while(getline(file,line)){
      int i;
      for(i=0; i<line.length(); ++i) {
        if(line[i] == 'A' ||line[i] == 'a'){

          if (line[i+1] == 'A' || line[i+1] == 'a') {
						++numAA;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++numAT;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c'){
						++numAC;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++numAG;
						continue;
					}
        }
				else if (line[i] == 'T' || line[i] == 't') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++numTA;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++numTT;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++numTC;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++numTG;
						continue;
					}
				}
				else if (line[i] == 'C' || line[i] == 'c') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++numCA;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++numCT;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++numCC;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++numCG;
						continue;
					}
				}
				else if (line[i] == 'G' || line[i] == 'g') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++numGA;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++numGT;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++numGC;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++numGG;
						continue;
				}
      }
    }
  }

    file.close();
    probAA = numAA/nucSum;
    probAT = numAT/nucSum;
	  probAC = numAC/nucSum;
	  probAG = numAG/nucSum;
  	probTT = numTT/nucSum;
	  probTA = numTA/nucSum;
	  probTC = numTC/nucSum;
	  probTG = numTG/nucSum;
	  probCA = numCA/nucSum;
	  probCT = numCT/nucSum;
	  probCC = numCC/nucSum;
	  probCG = numCG/nucSum;
	  probGA = numGA/nucSum;
	  probGT = numGT/nucSum;
	  probGC = numGC/nucSum;
	  probGG = numGG/nucSum;

    outFile << "- Here is the relative probability of each nucleotide bigram. -" << endl;
    outFile << "AA: " << probAA << endl;
	  outFile << "AT: " << probAT << endl;
	  outFile << "AC: " << probAC << endl;
	  outFile << "AG: " << probAG << endl;
	  outFile << "TA: " << probTA << endl;
	  outFile << "TT: " << probTT << endl;
	  outFile << "TC: " << probTC << endl;
	  outFile << "TG: " << probTG << endl;
	  outFile << "CA: " << probCA << endl;
	  outFile << "CT: " << probCT << endl;
	  outFile << "CC: " << probCC << endl;
	  outFile << "CG: " << probCG << endl;
	  outFile << "GA: " << probGA << endl;
	  outFile << "GT: " << probGT << endl;
	  outFile << "GC: " << probGC << endl;
	  outFile << "GG: " << probGG << endl;

    outFile.close();
}
}
/////////////////////////////////////
//This function creates 1000 random dna strings
void Nucleotide::gaussianStrands() {

	ofstream outFile;
	outFile.open("veneziaQuezada.out", fstream::app);
  if(outFile.is_open()) {


		outFile << "Gaussian Strands: " << endl;
		int = i;
		for(i=0; i<1000; ++i) {
      double a = rand() / (RAND_MAX + 1.0);
			double b = rand() / (RAND_MAX + 1.0);
			double c = (sqrt(-2 * (log(a))) * cos(2 * M_PI * b));
			int d = (stanDev * c) + mean;
			newLine = "";
			int dnaLine = 0;
			double randomDNA;

			if (d < 0) {
				dnaLine = d * -1;
			}

			else {
				dnaLine = d;
			}


			while(dnaLine > newLine.length()) {

				randomDNA = rand() / (RAND_MAX + 1.0);


				if(randomDNA > 0 && randomDNA < probA) {
					newLine += 'A';

				}
				else if(randomDNA > probA && randomDNA < (probA + probT)) {
					newLine += 'T';

				}
				else if(randomDNA > (probA + probT) && randomDNA < (probA + probT + probC)) {
					newLine += 'C';

				}
				else if(randomDNA > (probA + probT + probC) && randomDNA < (probA + probT + probC + probG)) {
					newLine += 'G';

				}
			}

			outFile << newLine << endl;
		}
		outFile << " " << endl;
		outFile.close();
	}

}
