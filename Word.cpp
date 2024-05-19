#include "Word.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <vector>
#include <locale>
#include <map>
#include<algorithm>


using namespace std;

Word::Word(string fileName)
{/* the constructor */
this->fileName=fileName;
}

int Word::  wordValue(string word,map<char,int> val){
    /* Calculates the score of a word based on a dictionary of character values*/
    int score=0;
    for (auto w:word)
    {   // if char existe in val dict
        if( (val.find(w) != val.end()))score+=val[w];
    }
    return score;
    }


string Word::readFile(const string& fileName) {
    /*Reads the contents of a file into a string */

    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << fileName << endl;
        exit(1);
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

vector<string> Word:: splitWord(const string& context) {
    /* Splits a string into individual words */
    vector<string> words;
    istringstream iss(context);
    string word;
    
    while (iss >> word) {
        while (!word.empty() && (ispunct(word.back()))) {
            word.pop_back();
        }
        words.push_back(word);
    }
    return words;
}

void Word::write(const string& fileName, vector<pair<string,int>> data) {
    /* Writes data to a file and remove duplicates */
    ofstream fichier(fileName);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << fileName << endl;
        exit(1);
    }
    auto last = unique(data.begin(), data.end());

    // Resize the vector to remove duplicates
    data.erase(last, data.end());
    int somme = 0;
    for (auto d : data) {
        fichier << d.first<<" , "<<d.second << endl;
        somme+=d.second;
    }
    cout<<"------------ Compte rendue ---------"<<endl;
    cout<<"Nombre de mot trouve : "<<data.size()<<",Totale de point : "<<somme<<endl;
}

bool comparePerValue(const pair<string, int> a, const pair<string, int> b) {
    return a.second < b.second;
}
vector<pair<string,int>> Word::calculate_value(const vector<string>& mots){
    
    /*Calculates the value of each word in the input vector by invoking 
    the wordValue function and stores the results in a vector of pairs, 
    which is then sorted by value.
    */
    
    vector<pair<string,int>> wordWithValue; 
    int index=0;
    for (auto mot : mots) {
            int value=wordValue(mot,val);
            wordWithValue.push_back(make_pair(mot, value));
            }
    sort(wordWithValue.begin(), wordWithValue.end(), comparePerValue);
    return wordWithValue;
}
