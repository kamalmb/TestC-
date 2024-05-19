#include <string>
#include <vector>
#include "Word.hpp"


using namespace std;


string outputFile="texte.count.txt";



int main (int argc,char* argv[]){

    

    string inputFile = argv[1];//get the file path  from entry cmd

    Word myWord(inputFile);//create word object base on the name of the file 

    string contenu = myWord.readFile(inputFile);//read the file using the word object

    vector<string> words =myWord. splitWord(contenu); //split the file context into words 

    vector<pair<string,int>> sorted_data=myWord.calculate_value(words);//calculate value for each word and then sorted by value
    
    myWord.write(outputFile,sorted_data);// write the unique "word,value" 


    return 0;
}