#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

#include "KWIC.h"

//    NameFile = getNameFile();
//    input = getinput(NameFile);
//    lowerCases(input);
//    lower_banned_words = getBannedWords();
//    input = deleteWords(lower_banned_words, input);
//    index_to_delete = getPositions();
//    deletePhrases(input, index_to_delete);
//
//    answer = Solve(input);
//
//    index_to_delete = getPositions();
//    deletePhrases(answer, index_to_delete);
//    sortPhrases(answer, order);
//
//    print(answer);

int main(){
    KWIC kwic;
    
    kwic.setName_File(kwic.dataProcess.getNameFile());
    kwic.setInput(kwic.dataProcess.getInput(kwic.getName_File()));
    kwic.setInput(kwic.utility.lowerCases(kwic.getPointer()));
    kwic.setBanned_Words(kwic.wordProcess.getBannedWords());
    kwic.setInput(kwic.wordProcess.deleteWords(kwic.getLower_Banned_Words(), kwic.getInput()));
    kwic.print();
    kwic.setIndex_To_Delete(kwic.phraseProcess.getPositions());
    kwic.setInput(kwic.phraseProcess.deletePhrases(kwic.getPointer(), kwic.getIndex_To_Delete()));
    kwic.print();
    kwic.Solve(kwic.getInput());
    kwic.setIndex_To_Delete(kwic.phraseProcess.getPositions());
    kwic.print();
    kwic.setInput(kwic.utility.sortPhrases(kwic.getPointer(), -1));
    kwic.setInput(kwic.phraseProcess.deletePhrases(kwic.getPointer(), kwic.getIndex_To_Delete()));
    kwic.print();
    

}

