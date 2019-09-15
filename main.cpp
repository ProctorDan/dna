#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <random>


using namespace std;

class DNA
{
    
    public:

        string dna_seq;
        double chrs = 0.0; 
        double lines = 0.0;
        double mean = 0.0;
        double variance = 0.0;

        int getSum(void);
        int getLines(void);
        double getMean(void);
        double getStand(void);
        double getVariance(void);
        string getRandSeq(int);
        string calcSingle(string one_line);
        string calcBi(string one_line);
        void calcVariance(double mean, string line);
        void addChars(int);
        void addLines(void);
        void setString(string dna);
        void reset(void);

};

string DNA::calcSingle(string one_line)
{

    int A = 0;
    int C = 0;
    int T = 0;
    int G = 0;

    for (int i = 0; i < one_line.length(); ++i)
    {
        if(one_line[i] == 'A') {
            ++A;
        }
        if(one_line[i] == 'C') {
            ++C;
        }
        if(one_line[i] == 'T') {
            ++T;
        }
        if(one_line[i] == 'G') {
            ++G;
        }   
    }

    float probA = A / chrs;
    float probC = C / chrs;
    float probT = T / chrs;
    float probG = G / chrs;

    return "Probability of A: " + std::to_string(probA) + "\nProbability of C: " + std::to_string(probC) + "\nProbability of T: " + std::to_string(probT) + "\nProbability of G: " + std::to_string(probG) + "\n\n";
}

string DNA::calcBi(string one_line)
{
    int total_bigrams = 0;
    int AA = 0;
    int AC = 0;
    int AT = 0;
    int AG = 0;
    int CA = 0;
    int CC = 0;
    int CT = 0;
    int CG = 0;
    int TA = 0;
    int TC = 0;
    int TT = 0;
    int TG = 0;
    int GA = 0;
    int GC = 0;
    int GT = 0;
    int GG = 0;
    
    for (int i = 0; i < one_line.length() - 1; ++i)
    {

        char p1 = one_line[i];
 //       cout << typeid(p1).name() << endl;
        char p2 = one_line[i + 1];
 //       string bi = p1 + p2; for some reason when I concat they are integers, but outputting separate they are chars
        ++total_bigrams;
        if (p1 == 'A' && p2 == 'A') {
            ++AA;
        }
        else if (p1 == 'A' && p2 == 'C') {
            ++AC;
        }
        else if (p1 == 'A' && p2 == 'T') {
            ++AT;
        }
        else if (p1 == 'A' && p2 == 'G') {
            ++AG;
        }
        else if (p1 == 'C' && p2 == 'A') {
            ++CA;
        }
        else if (p1 == 'C' && p2 == 'T') {
            ++CT;
        }
        else if (p1 == 'C' && p2 == 'C') {
            ++CC;
        }
        else if (p1 == 'C' && p2 == 'G') {
            ++CG;
        }
        else if (p1 == 'T' && p2 == 'A') {
            ++TA;
        }
        else if (p1 == 'T' && p2 == 'C') {
            ++TC;
        }
        else if (p1 == 'T' && p2 == 'T') {
            ++TT;
        }
        else if (p1 == 'T' && p2 == 'G') {
            ++TG;
        }
        else if (p1 == 'G' && p2 == 'A') {
            ++GA;
        }
        else if (p1 == 'G' && p2 == 'C') {
            ++GC;
        }
        else if (p1 == 'G' && p2 == 'T') {
            ++GT;
        }
        else if (p1 == 'G' && p2 == 'G') {
            ++GG;
        } 
    }

    return "Probability of AA: " + std::to_string(float(AA) / float(total_bigrams)) + "\nProbability of AC: " + std::to_string(float(AC) / float(total_bigrams)) + "\nProbability of AT: " + std::to_string(float(AT) / float(total_bigrams)) + "\nProbability of AG: " + std::to_string(float(AG) / float(total_bigrams)) + "\nProbability of CA: " + std::to_string(float(CA) / float(total_bigrams)) + "\nProbability of CC: " + std::to_string(float(CC) / float(total_bigrams)) + "\nProbability of CT: " + std::to_string(float(CT) / float(total_bigrams)) + "\nProbability of CG: " + std::to_string(float(CG) / float(total_bigrams)) + "\nProbability of TA: " + std::to_string(float(TA) / float(total_bigrams)) + "\nProbability of TC: " + std::to_string(float(TC) / float(total_bigrams)) + "\nProbability of TT: " + std::to_string(float(TT) / float(total_bigrams)) + "\nProbability of TG: " + std::to_string(float(TG) / float(total_bigrams)) + "\nProbability of GA: " + std::to_string(float(GA) / float(total_bigrams)) + "\nProbability of GC: " + std::to_string(float(GC) / float(total_bigrams)) + "\nProbability of GT: " + std::to_string(float(GT) / float(total_bigrams)) + "\nProbability of GG: " + std::to_string(float(GG) / float(total_bigrams)) + "\n\n";

}

void DNA::reset(void)
{
    chrs = 0;
    lines = 0.0;
    mean = 0.0;
    variance = 0.0;
}

int DNA::getLines(void)
{
    return lines;
}

int DNA::getSum(void)
{
    return chrs;
}

double DNA::getMean(void)
{
    return chrs / lines;
}

double DNA::getVariance(void)
{
    return variance / lines;
}

double DNA::getStand(void)
{
    return sqrt((variance / lines));
}

string DNA::getRandSeq(int length)
{
    int r;
    string A = "A";
    string C = "C";
    string T = "T";
    string G = "G";
    string rand_dna = "";

    for (int i = 0; i < length; ++i)
    {
        r = rand() % 4;
        if (r == 0)
        {
            rand_dna.append(A);
        }

        else if (r == 1)
        {
            rand_dna.append(C);
        }

        else if (r == 2)
        {
            rand_dna.append(T);
        }

        else if (r == 3)
        {
            rand_dna.append(G);
        }
    }

    return rand_dna;
}

void DNA::calcVariance(double mean, string line)
{
    double num = (line.length() - mean);
    variance += pow(num, 2);
}

void DNA::addChars(int current_chrs)
{
    chrs += current_chrs;
}

void DNA::addLines(void)
{
    lines += 1;
}

void DNA::setString(string dna)
{ 
    dna_seq = dna;
    addLines();
    addChars(dna_seq.length());
}


int main(int argc, char** argv) 
{
    DNA dna;
    const int new_dnas = 1000;
    
    string inp;
    string file;

    ofstream outfile("dproctor.out");
    outfile << "Dan Proctor\n";
    outfile << "2288481\n";
    outfile << "CPSC 350\n\n";

    cout << "Would you like to process a DNA file? (yes/no): ";
    cin >> inp;
    
    while (inp == "yes")
    {

        string line;
        string dna_string;
        string all_chrs;

        cout << "Enter the name of the DNA file: ";
        cin >> file;

        ifstream dna_file(file);
        
        while(getline(dna_file, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            all_chrs += line;
            dna.setString(line);
        }
        
        string single_prob = dna.calcSingle(all_chrs);
        string bi_prob = dna.calcBi(all_chrs);
        double mean = dna.getMean();
        int sum = dna.getSum();

        dna_file.clear();
        dna_file.seekg(0, ios::beg);
        line = "";

        while(getline(dna_file, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            dna.calcVariance(mean, line);
        }

        double variance = dna.getVariance();
        double st_dev = dna.getStand();

        outfile << "The sum is: " << sum << "\n";
        outfile << "The mean is: " << mean << "\n";
        outfile << "The variance is: " << variance << "\n";
        outfile << "The standard deviation is: " << st_dev << "\n";
        outfile << single_prob << "\n\n";
        outfile << bi_prob << "\n\n";

        dna_file.close();

    /*
        random_device rd;
        default_random_engine generator(rd());
        normal_distribution<double> distribution(mean, st_dev); easy to do with an array....

    */


        int count = 0;
        outfile << "Generating 1000 DNA strings...\n";
        while (count != 1000)
        {
            double a = ((double) rand() / (RAND_MAX)); // generates random double between 0 - 1
            double b = ((double) rand() / (RAND_MAX));
            double c = (sqrt((-2 * log(a))) * (cos((2 * M_PI * b)))); 
            double d = (st_dev * c) + mean; 
            d = round(d);

            if (count <= 45 || count >= 955)
            {
                if (d >= 1 && d <= ceil(.045 * mean))
                {
                    ++count;
                    outfile << dna.getRandSeq(round(d)) << "\n";
                }
            }
            
            else if ((count <= 318 && count > 45) || (count >= 682 && count < 955))       
            {
                if (d > .045 * mean && d <= .318 * mean)
                {
                    ++count;
                    outfile << dna.getRandSeq(round(d)) << "\n";
                }
            } 

            else if ((count <= 499 && count > 318) || (count >= 501 && count < 682))
            {
                if (d > .318 * mean && d <= round(mean) - 1)
                {
                    ++count;
                    outfile << dna.getRandSeq(round(d)) << "\n";
                }
            }

            else if (count == 500)
            {
                ++count;
                outfile << dna.getRandSeq(round(mean)) << "\n";
            } 
            
        }

        dna.reset();
        cout << "Would you like to process another file? (yes/no): ";
        cin >> inp;
        outfile << "\n\n\n\n";

    }
    outfile.close();
    return 0;
}