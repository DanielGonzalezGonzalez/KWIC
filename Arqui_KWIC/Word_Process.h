//
//  Word_Process.h
//  Arqui_KWIC
//
//  Created by Daniel Gonzalez on 4/21/18.
//  Copyright © 2018 Daniel Gonzalez. All rights reserved.
//

#ifndef Word_Process_h
#define Word_Process_h

class WordProcess{
public:
    WordProcess();
    ~WordProcess();
    vector<string> deleteWords(unordered_set<string> banned_words, vector<string> phrases);
    vector<string>* getBannedWords();

private:
    vector<string>* point;
protected:
};

WordProcess::WordProcess(){
    this->point = new vector<string>();
}

WordProcess::~WordProcess(){
    delete this->point;
}

/*
 deletedWords(unordered_set<string>, vector<strign>) – Function
 
 Args:
 banned_words: set of words that needs to be deleted
 phrases: phrases that were read from the input file
 
 Return:
 vector<string> clean_phrases: New phrases without the banned_words.
 */
vector<string> WordProcess::deleteWords(unordered_set<string> banned_words, vector<string> phrases){
    vector<string> clean_phrases;
    vector<string> process_phrase;
    for(int phrases_iterator = 0; phrases_iterator < phrases.size(); phrases_iterator++){
        
        /*
         iss: String stream
         Purpose: Read word by word from the phrase. Push it, only if the word is not banned
         */
        istringstream iss(phrases[phrases_iterator]);
        do
        {
            string subs;
            iss >> subs;
            if (!banned_words.count(subs)){
                process_phrase.push_back(subs);
            }
        } while (iss);
        
        /*
         Phrase processing.
         Purpose: Loop through the phrase to creat the new phrase and add it to the final vector
         */
        string new_phrase = "";
        for (int word_iterator=0; word_iterator < process_phrase.size(); word_iterator++){
            new_phrase += process_phrase[word_iterator] + " ";
        }
        clean_phrases.push_back(new_phrase);
        process_phrase.clear();
    }
    return clean_phrases;
}

/*
 getBannedWords() – Function
 
 Args:
 None
 
 Return:
 pair<vector<string>, unordered_set<string>> set_list_banned_words:
 First: List of banned words
 Second: Set of banned words
 */
vector<string>* WordProcess::getBannedWords(){
    vector<string> banned_words;
    //unordered_set<string> set_banned_words;
    string word;
    cout << "Enter all the words to delete from the file. To finish enter '*End*'" << endl;
    while(cin >> word && word != "*End*"){
        banned_words.push_back(word);
    }
    //lowerCases(banned_words);
//    for(int banned_iterator = 0; banned_iterator < banned_words.size(); banned_iterator++){
//        set_banned_words.insert(banned_words[banned_iterator]);
//    }
//    return set_banned_words;
    this->point = new vector<string>(banned_words);
    return point;
}
#endif /* Word_Process_h */
