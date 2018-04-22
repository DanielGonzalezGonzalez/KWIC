//
//  Phrase_Process.h
//  Arqui_KWIC
//
//  Created by Daniel Gonzalez on 4/21/18.
//  Copyright © 2018 Daniel Gonzalez. All rights reserved.
//

#ifndef Phrase_Process_h
#define Phrase_Process_h


class PhraseProcess{
public:
    PhraseProcess();
    vector<string> deletePhrases(vector<string> *phrases, vector<int> positions);
    vector<int> getPositions();
private:
protected:
};

PhraseProcess::PhraseProcess(){
    
}

/*
 deletePhrases(vector<string>, vector<int>) – Function
 
 Args:
 &phrases: Reference of the list of phrases
 positions: List of positions of phrases to delete
 
 Return:
 None
 */
vector<string> PhraseProcess::deletePhrases(vector<string> *phrases, vector<int> positions){
    sort(positions.rbegin(), positions.rend());
    for(int iA = 0; iA < positions.size(); iA++){
        phrases->erase(phrases->begin()+(positions[iA]-1));
    }
    return *phrases;
}

/*
 getPositions() – Function
 
 Args:
 None
 
 Return:
 vector<int> positinos: List of the number of phrases that are going to be deleted.
 */
vector<int> PhraseProcess::getPositions(){
    vector<int> positions;
    int index;
    cout << "Enter the number of phrase that you'd like to delete. To end enter '0'" << endl;
    while(cin >> index && index != 0){
        positions.push_back(index);
    }
    return positions;
}
#endif /* Phrase_Process_h */
