/* Systems Programming Lab
 * Yatish Kelkar TE IT 8001
 * Assignment 1 : Pass 1 of Two Pass Assembler
 * 17/02/21
*/

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<sstream>

#define SIZE_SMALL 50
#define SIZE_LARGE 100

using namespace std;

class SymbolTable {

    public : 
        int index;
        int location;
        string symbol;

    // public :

        SymbolTable() {}

        SymbolTable(int indexFormal, int locationFormal, string symbolFormal) {
            index = indexFormal;
            location = locationFormal;
            symbol = symbolFormal;
        }
};

class LiteralTable {
    
    public : 
        int index;
        int location;
        string literal;

    // public :

        LiteralTable() {}

        LiteralTable(int indexFormal, int locationFormal, string literalFormal) {
            index = indexFormal;
            location = locationFormal;
            literal = literalFormal;
        }
};

class PoolTable {

    public : 
        int poolNumber;

        PoolTable(int poolNumberFormal) {
            poolNumber = poolNumberFormal;
        }
};

class Mnemonics {
    
    public : 
        string mnemonic;
        string opcode;  

    

        Mnemonics() {}

        Mnemonics(string mnemonicFormal, string opcodeFormal) {
            mnemonic = mnemonicFormal;
            opcode = opcodeFormal;
        }
};

class ProgramAnalyzer {
    
    private : 
        vector <SymbolTable> symbolTable;
        vector <LiteralTable> literalTable;
        vector <PoolTable> poolTable;
        vector <Mnemonics> mnemonicsTable;
        fstream sourceFile, intermediateCodeFile, symbolFile, literalFile, poolFile, mnemonicFile;
        int LC;
    
    public : 
        ProgramAnalyzer();
        bool convertToCode();
        void displaySymbolTable();
        void displayLiteralTable();
        void displayPoolTable();
        bool isMnemonic(string);
};

ProgramAnalyzer :: ProgramAnalyzer () {

    string currentLine;
    cout << "\nOpening source file..." << endl;
            
    sourceFile.open("assembly-program.txt", ios::in);

    if(!sourceFile) {
        cout << "\nError opening source assembly file, please try again" << endl;
        exit(0);
    } else {
        cout << "\nSource assembly file opened successfully" << endl;
    }

    mnemonicFile.open("mnemonics.txt", ios::in);

    if(!mnemonicFile) {
        cout << "\nError opening mnemonic file, please try again" << endl;
        exit(0);
    } 

    while(!mnemonicFile.eof() && getline(mnemonicFile, currentLine, '\n')) {

        vector <string> mnemonics;
        string word;
        
        istringstream s(currentLine);
        while(getline(s, word, ' ')) {
            mnemonics.push_back(word);
        }

        mnemonicsTable.push_back(Mnemonics(mnemonics.at(0), mnemonics.at(1)));
    }

}

bool ProgramAnalyzer :: convertToCode() {

    string currentLine, word;
    bool shouldUpdateLC = false;
    
    cout << "\nStarting reading source file..." << endl;

    while(!sourceFile.eof() && getline(sourceFile, currentLine, '\n')) {
        
        if(shouldUpdateLC) LC++;
        
        vector <string> inputWords;
        string label, instruction, operand1, operand2;
       
        istringstream s(currentLine);
        while(getline(s, word, ' ')) {
            inputWords.push_back(word);
        }

        label = inputWords.at(0);
        instruction = inputWords.at(1);
        operand1 = inputWords.at(2);
        operand2 = inputWords.at(3);

        
        cout << label << "\t" << instruction << "\t" << operand1 << "\t" << operand2<< "\t" << LC << endl;

        // conditions for label
        if (label != "-") {
            symbolTable.push_back(SymbolTable((int)symbolTable.size(), LC, label));
        } 


        // conditions for insruction
        if(instruction == "START") {
            LC = atoi(operand1.c_str()) - 1;
            poolTable.push_back(PoolTable((int)literalTable.size()));
        }
        else if(instruction == "LTORG") {
            
            poolTable.push_back(PoolTable((int)literalTable.size()));
            
            int numberOfLiterals = poolTable.at(poolTable.size() -1 ).poolNumber - poolTable.at(poolTable.size() -2 ).poolNumber;
            
            for(int i = 0; i < numberOfLiterals; i++) {
                literalTable.at((int)literalTable.size() - numberOfLiterals + i).location = LC ;
                LC++;
            }
            shouldUpdateLC = false;
            continue;
        }
        else if(instruction == "END") {
            shouldUpdateLC = false;
            continue;
        }

        
        // conditions for operand1
        if(operand1 != "-") {
            if(operand1.at(operand1.size()-1) == ',') {
                operand1.resize(operand1.size() - 1);
            }
            if(!isMnemonic(operand1)) {
                
            }
        }


        // conditions for operand2
        if (operand2 != "-") {
            if (operand2.at(0) == '=') {
                literalTable.push_back(LiteralTable((int)literalTable.size(), LC, operand2));
            } else {
                symbolTable.push_back(SymbolTable((int)symbolTable.size(), LC, operand2));
            }
        }

        shouldUpdateLC = true;

    }
    
    displayPoolTable();
    displayLiteralTable();
    displaySymbolTable();
    cout << "\nLC is " << LC;
    return true;
}

void ProgramAnalyzer :: displaySymbolTable() {
    
    cout << "\nSymbol table is :\n" << endl; 
    cout << "INDEX\tSYMBOL\tADDRESS" << endl;  
    for(int i = 0; i < symbolTable.size(); i++) {
        cout << i << "\t" << symbolTable.at(i).symbol << "\t" << "address" << endl;
    }

}

void ProgramAnalyzer :: displayLiteralTable() {
    
    cout << "\nLiteral table is :\n" << endl; 
    cout << "INDEX\tLITERAL\tADDRESS" << endl;  
    for(int i = 0; i < literalTable.size(); i++) {
        cout << i << "\t" << literalTable.at(i).literal << "\t" << literalTable.at(i).location << endl;
    }

}

void ProgramAnalyzer :: displayPoolTable() {
    
    cout << "\nPool table is :\n" << endl;
    cout << "INDEX\tPOOL NUMBER" << endl;  
    for(int i = 0; i < poolTable.size(); i++) {
        cout << i << "\t" << poolTable.at(i).poolNumber << endl;
    }

}

bool ProgramAnalyzer :: isMnemonic(string search) {

    for(int i = 0; i < mnemonicsTable.size(); i++) {
        if(mnemonicsTable.at(i).mnemonic == search) return true;
    } 
    return false;
}


int main () {

    ProgramAnalyzer analyzer;
    analyzer.convertToCode();

    return 0;
}
