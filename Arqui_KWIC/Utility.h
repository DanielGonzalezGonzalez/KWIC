//
//  Utility.h
//  Arqui_KWIC
//
//  Created by Daniel Gonzalez on 4/21/18.
//  Copyright © 2018 Daniel Gonzalez. All rights reserved.
//

#ifndef Utility_h
#define Utility_h

/*
 Structs purpose:
 Used for sorting any type of data, ascending or descending.
 */
struct ascending
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
struct descending
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a < b; }
};

class Utility{
public:
    Utility();
    vector<string> sortPhrases(vector<string> *phrases, int order);
    vector<string> lowerCases(vector<string> *phrases);
private:
protected:
};

Utility::Utility(){
    
}

/*
 sortPhrases(vector<string>, int) – Function
 
 Args:
 &phrases: Reference of the list of phrases to be ordered.
 order: 0 - ascending order | 1 - descending order
 
 Return:
 None
 */
vector<string> Utility::sortPhrases(vector<string> *phrases, int order){
    cout << "Enter sort order\n0 for ascending\n1 for descending" << endl;
    cin >> order;
    if(order == 0){
        sort(phrases->begin(), phrases->end(), ascending());
    } else {
        sort(phrases->begin(), phrases->end(), descending());
    }
    return *phrases;
}

/*
 lowerCases(vector<string>) – Function
 
 Args:
 &phrases: Reference to the list of phrases read from file.
 
 Return:
 None
 */
vector<string> Utility::lowerCases(vector<string> *phrases){
    for (auto it = phrases->begin(); it != phrases->end(); it++){
        transform(it->begin(), it->end(), it->begin(), ::tolower);
    }
    return *phrases;
}

#endif /* Utility_h */
