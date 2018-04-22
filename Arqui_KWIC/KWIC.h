//
//  KWIC.h
//  Arqui_KWIC
//
//  Created by Daniel Gonzalez on 4/21/18.
//  Copyright © 2018 Daniel Gonzalez. All rights reserved.
//

#ifndef KWIC_h
#define KWIC_h

#include "Data_Process.h"
#include "Word_Process.h"
#include "Phrase_Process.h"
#include "Utility.h"

class KWIC {
public:
    Utility utility;
    WordProcess wordProcess;
    PhraseProcess phraseProcess;
    DataProcess dataProcess;
    
    KWIC();
    ~KWIC();
    
    int getOrder();
    string getName_File();
    
   
    vector<string> getInput();
    vector<string>* getPointer();
    vector<string>* getBanned_Words();
    vector<string> getAnswer();
    vector<int> getIndex_To_Delete();
    unordered_set<string> getLower_Banned_Words();
    
    void print();
    void setOrder(int order);
    void setInput(vector<string> input);
    void setAnswer(vector<string> answer);
    void setBanned_Words(vector<string> *banned_words);
    void setIndex_To_Delete(vector<int> index_to_delete);
    void setLower_Banned_Words(unordered_set<string> lower_banned_words);
    void setName_File(string NameFile);
    void Solve(vector<string> phrases);
private:
    int order;
    vector<string> input;
    vector<string> *pointer;
    vector<string> *ref;
    vector<string> answer;
    vector<string> *banned_words;
    vector<int> index_to_delete;
    unordered_set<string> lower_banned_words;
    string NameFile;
protected:
};

KWIC::KWIC(){
    this->order = 0;
    this->NameFile = "";
    this->pointer = new vector<string>();
    this->banned_words = new vector<string>();
}
KWIC::~KWIC(){
    delete this->pointer;
    delete this->banned_words;
}

int KWIC::getOrder(){
    return this->order;
}
void KWIC::setOrder(int order){
    this->order = order;
}
vector<string> KWIC::getInput(){
    return this->input;
}
void KWIC::setInput(vector<string> input){
    this->input = input;
    this->ref = this->pointer;
    this->pointer = new vector<string>(input);
    delete this-> ref;
}
vector<string>* KWIC::getPointer(){
    return this->pointer;
}
vector<string> KWIC::getAnswer(){
    return this->answer;
}
void KWIC::setAnswer(vector<string> answer){
    this->answer = answer;
}
vector<string>* KWIC::getBanned_Words(){
    return this->banned_words;
}
void KWIC::setBanned_Words(vector<string> *banned_words){
    this->ref = this->banned_words;
    this->banned_words = new vector<string>(*banned_words);
    delete this->ref;
    for (auto it = this->banned_words->begin(); it != this->banned_words->end(); it++){
        if (!this->lower_banned_words.count(*it)){
            this->lower_banned_words.insert(*it);
        }
    }
}
vector<int> KWIC::getIndex_To_Delete(){
    return this->index_to_delete;
}
void KWIC::setIndex_To_Delete(vector<int> index_to_delete){
    this->index_to_delete = index_to_delete;
}
unordered_set<string> KWIC::getLower_Banned_Words(){
    return this->lower_banned_words;
}
void KWIC::setLower_Banned_Words(unordered_set<string> lower_banned_words){
    this->lower_banned_words = lower_banned_words;
}
string KWIC::getName_File(){
    return this->NameFile;
}
void KWIC::setName_File(string NameFile){
    this->NameFile = NameFile;
}

/*
 Solve(vector<string>) – Function
 
 Args:
 phrases: phrases that were read from the input file
 
 Return:
 vector<string> clean_phrases: New list of phrases that contain
 */
void KWIC::Solve(vector<string> phrases){
    vector<string> clean_phrases;
    
    for(int phrase_iterator=0; phrase_iterator<phrases.size(); phrase_iterator++){
        vector<string> phrase; //vector que contenera cada palabra de una oracion
        istringstream iss(phrases[phrase_iterator]);
        do
        {
            string subs;
            iss >> subs;
            phrase.push_back(subs);
        } while (iss); //Loop para meter cada palabra de la oracion dentro de un vector
        
        
        /*
         Phrase processing
         Purpose: Loop using a circular shift approach to creat all the new phrases.
         */
        string new_phrase;
        for (int word_iterator=0; word_iterator < phrase.size()-1; word_iterator++){
            new_phrase = "";
            for (int circular_iterator=0; circular_iterator < phrase.size(); circular_iterator++){
                if (circular_iterator == phrase.size()-1){
                    new_phrase = new_phrase + phrase[(word_iterator + circular_iterator)%phrase.size()];
                } else if (circular_iterator == 0){
                    new_phrase = new_phrase + phrase[(word_iterator + circular_iterator)%phrase.size()] + " ";
                } else {
                    new_phrase = new_phrase + phrase[(word_iterator + circular_iterator)%phrase.size()] + " ";
                }
            }
            clean_phrases.push_back(new_phrase);
        }
        phrase.clear();
    }
    this->setInput(clean_phrases);
}

void KWIC::print(){
    for (int i=0; i < this->input.size(); i++){
        cout << this->input[i] << endl;
    }
}

#endif /* KWIC_h */
