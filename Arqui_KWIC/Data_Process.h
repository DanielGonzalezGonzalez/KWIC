//
//  Data_Process.h
//  Arqui_KWIC
//
//  Created by Daniel Gonzalez on 4/21/18.
//  Copyright © 2018 Daniel Gonzalez. All rights reserved.
//

#ifndef Data_Process_h
#define Data_Process_h

class DataProcess{
public:
    DataProcess();
    string getNameFile();
    vector<string> getInput(string sFileName);
private:
protected:
};

DataProcess::DataProcess(){
    
}

/*
 getNameFile() – Function
 
 Args:
 None
 
 Return:
 string sFileName: Name of the file to be open.
 */
string DataProcess::getNameFile(){
    string sFileName;
    cout << "Place name of the file to process: ";
    cin >> sFileName;
    return sFileName;
}

/*
 getInput(string) – Function
 
 Args:
 sFileName: Name of the file to be open and read.
 
 Return:
 vector<string> input: List of phrases that were read from the file.
 */
vector<string> DataProcess::getInput(string sFileName){
    vector<string> input;
    string sentence;
    ifstream file(sFileName);
    while(getline(file, sentence)){ //Agarrar cada oracion y guardarla en un vector
        input.push_back(sentence);
    }
    return input;
}
#endif /* Data_Process_h */
