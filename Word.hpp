
#ifndef WORD_HPP
#define WORD_HPP

#include <string>
#include <vector>
#include <map>


using namespace std;
class Word
{
private:
 string fileName ;
 map<char,int> val=
{{'A', 32}, {'B', 36}, {'C', 33}, {'D', 40}, {'E', 41}, {'F', 47}, {'G', 31}, {'H', 27},
    {'I', 49}, {'J', 28}, {'K', 30}, {'L', 42}, {'M', 29}, {'N', 38}, {'O', 51}, {'P', 43},
    {'Q', 45}, {'R', 39}, {'S', 35}, {'T', 52}, {'U', 37}, {'V', 46}, {'W', 34}, {'X', 48},
    {'Y', 44}, {'Z', 50}, {'é', 60}, {'è', 61}, {'ê', 62}, {'à', 63}, {'â', 64}, {'ë', 65},
    {'û', 66}, {'ù', 67}, {'î', 68}, {'ç', 69}, {'ô', 70}, {'ö', 71}, {'ü', 72}, {'a', 1},
    {'b', 4}, {'c', 5}, {'d', 8}, {'e', 10}, {'f', 11}, {'g', 13}, {'h', 16}, {'i', 18},
    {'j', 19}, {'k', 21}, {'l', 21}, {'m', 23}, {'n', 2}, {'o', 3}, {'p', 6}, {'q', 7},
    {'r', 9}, {'s', 12}, {'t', 14}, {'u', 15}, {'v', 17}, {'w', 20}, {'x', 24}, {'y', 25},
    {'z', 26}};

 /* data */
public:
    Word(string fileName);
    int wordValue(string word,map<char,int> val);
    string readFile(const string& fileName) ;
    vector<string> splitWord(const string& context);
    vector<pair<string,int>> calculate_value(const vector<string>& mots);
    void write(const string& fileName, vector<pair<string,int>> data);
    
};

#endif

