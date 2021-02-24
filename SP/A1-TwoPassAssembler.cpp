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
#include<algorithm>

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
        string type;
    

        Mnemonics() {}

        Mnemonics(string mnemonicFormal, string opcodeFormal, string typeFormal) {
            mnemonic = mnemonicFormal;
            opcode = opcodeFormal;
            type = typeFormal;
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
        void convertToCode();
        void displaySymbolTable();
        void displayLiteralTable();
        void displayPoolTable();
        bool isMnemonic(string);
        string returnOpcode(string);
        string returnType(string);
        bool isLiteralAlreadyPresent(string);
        bool isLabelAreadyPresent(string);
        void detectErrors(string, string, string, string);
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

        mnemonicsTable.push_back(Mnemonics(mnemonics.at(0), mnemonics.at(1), mnemonics.at(2)));
    }

}


// converts the assembly program to intermeidate code
void ProgramAnalyzer :: convertToCode() {

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

        cout << "\n\n-------------------------------------\n";
        cout << label << "\t" << instruction << "\t" << operand1 << "\t" << operand2<< "\t" << LC ;

        detectErrors(label, instruction, operand1, operand2);

        // conditions for insruction
        if(instruction == "START") {
            LC = atoi(operand1.c_str());
            poolTable.push_back(PoolTable((int)literalTable.size()));
            cout << "\n(" << returnType("START") << "," << returnOpcode("START") << ") (C," << LC + 1 << ")" ;
            continue;
        }
        else if(instruction == "LTORG") {
            
            poolTable.push_back(PoolTable((int)literalTable.size()));
            
            int numberOfLiterals = poolTable.at(poolTable.size() -1 ).poolNumber - poolTable.at(poolTable.size() -2 ).poolNumber;
            
            for(int i = 0; i < numberOfLiterals; i++) {
                literalTable.at((int)literalTable.size() - numberOfLiterals + i).location = LC ;
                LC++;
            }
            shouldUpdateLC = false;
            cout << "\n(" << returnType("LTORG") << "," << returnOpcode("LTORG") << ")" ;
            continue;
        }
        else if(instruction == "ORIGIN") {
            
            if(int pos = operand1.find("+") != string::npos) {
                string symb = operand1.substr(0, pos);
                for(int i = 0; i < symbolTable.size(); i++) {
                    if(symbolTable.at(i).symbol == symb) {
                        LC = symbolTable.at(i).location + atoi(operand1.substr(pos, operand1.size() - pos).c_str());
                    }
                }
            } else {
                LC = atoi(operand1.c_str());
            }
            shouldUpdateLC = false;
            cout << "\n(" << returnType("ORIGIN") << "," << returnOpcode("ORIGIN") << ") (C," << LC << ")" ;
            continue;
        }
        else if(instruction == "DS") {
            LC = LC + atoi(operand1.c_str());
            cout << "\n(" << returnType("DS") << "," << returnOpcode("DS") << ") (C," << operand1 << ")" ;
            continue;
        }
        else if(instruction == "END") {
            shouldUpdateLC = false;
            cout << "\n(" << returnType("END") << "," << returnOpcode("END") << ")" << endl ;
            continue;
        }
        else if(instruction == "EQU") {
            
            cout << "\n(" << returnType("EQU") << "," << returnOpcode("EQU") << ")" ;
            symbolTable.push_back(SymbolTable((int)symbolTable.size(), LC, label));
            
            string symbolForEQU, operandForEQU;
            int i = 0, operandForEQUInt;

            while(operand1.at(i) != '+') {
                symbolForEQU.push_back(operand1.at(i));
                i++;
            }
            i++;
            while(i < operand1.size()) {
                operandForEQU.push_back(operand1.at(i));
                i++;
            }

            for(int j = 0; j < symbolTable.size(); j++) {
                if(symbolTable.at(j).symbol == symbolForEQU) {
                    cout << " (S," << j  << ") + " << operandForEQU;
                }
            }   
            
            continue;
        }

        cout << "\n(" << returnType(instruction) << "," << returnOpcode(instruction) << ")" ;

        
        // conditions for operand1
        if(operand1 != "-") {
            if(operand1.at(operand1.size()-1) == ',') {
                operand1.resize(operand1.size() - 1);
                cout << " (" << returnType(operand1) << "," << returnOpcode(operand1) << ")" ;
            }
            if(!isMnemonic(operand1)) {
                if(!isLabelAreadyPresent(operand1)) {
                    symbolTable.push_back(SymbolTable((int)symbolTable.size(), -1, operand1));
                    cout << " (S," << symbolTable.size()-1 << ")" ;
                }
            }
        }


        // conditions for operand2
        if (operand2 != "-") {
            if (operand2.at(0) == '=') {
                if(!isLiteralAlreadyPresent(operand2)) {
                    literalTable.push_back(LiteralTable((int)literalTable.size(), LC, operand2));
                    cout << "(L," << literalTable.size()-1 << ")" ;
                }
            } else {
                if(!isLabelAreadyPresent(operand2)) {
                    symbolTable.push_back(SymbolTable((int)symbolTable.size(), LC, operand2));
                    cout << " (S," << symbolTable.size()-1 << ")" ;
                }
            }
        }

        // conditions for label
        if (label != "-") {
            if(isLabelAreadyPresent(label)) {
                for(int i = 0; i < symbolTable.size(); i++) {
                    if(symbolTable.at(i).symbol == label) {
                        symbolTable.at(i).location = LC;
                        break;                        
                    }
                }
            }
            else {
                symbolTable.push_back(SymbolTable((int)symbolTable.size(), LC, label));
                cout << "(S," << symbolTable.size()-1 << ")" ;
            }
        } 

        shouldUpdateLC = true;

    }

    displayPoolTable();
    displayLiteralTable();
    displaySymbolTable();
    cout << "\nLC is " << LC << endl;
}


// display the symbol table
void ProgramAnalyzer :: displaySymbolTable() {
    
    // cout << "\n==============================";
    cout << "\n\nSymbol table is :\n"; 
    cout << "INDEX\tSYMBOL\tADDRESS" << endl;  
    for(int i = 0; i < symbolTable.size(); i++) {
        cout << i << "\t" << symbolTable.at(i).symbol << "\t" << symbolTable.at(i).location << endl;
    }
    
}


// display literal table
void ProgramAnalyzer :: displayLiteralTable() {
    
    // cout << "\n==============================";
    cout << "\n\nLiteral table is :\n"; 
    cout << "INDEX\tLITERAL\tADDRESS" << endl;  
    for(int i = 0; i < literalTable.size(); i++) {
        cout << i << "\t" << literalTable.at(i).literal << "\t" << literalTable.at(i).location << endl;
    }
    
}


// display pool table 
void ProgramAnalyzer :: displayPoolTable() {
    
    // cout << "\n==============================";
    cout << "\n\nPool table is :\n";
    cout << "INDEX\tPOOL NUMBER" << endl;  
    for(int i = 0; i < poolTable.size(); i++) {
        cout << i << "\t" << poolTable.at(i).poolNumber << endl;
    }
    
}


// returns true or false based on whether input is present in mnemonic table
bool ProgramAnalyzer :: isMnemonic(string search) {

    for(int i = 0; i < mnemonicsTable.size(); i++) {
        if(mnemonicsTable.at(i).mnemonic == search) return true;
    } 
    return false;
}


// returns the opcode of the instruction
string ProgramAnalyzer :: returnOpcode(string instruction) {

    for(int i = 0; i < mnemonicsTable.size(); i++) {
        if(mnemonicsTable.at(i).mnemonic == instruction) {
            return mnemonicsTable.at(i).opcode;
        }
    }
    return "NA";
}


// returns the type of instruction
string ProgramAnalyzer :: returnType(string instruction) {

    for(int i = 0; i < mnemonicsTable.size(); i++) {
        if(mnemonicsTable.at(i).mnemonic == instruction) {
            return mnemonicsTable.at(i).type;
        }
    }
    return "NA";
}


// is literal already there in literal pool
bool ProgramAnalyzer :: isLiteralAlreadyPresent (string literal) {
    
    for(int i = poolTable.at((int)poolTable.size() - 1).poolNumber; i < literalTable.size(); i++) {
        if(literalTable.at(i).literal == literal) {
            return true;
        }
    }
    return false;
}

// is label already there in literal pool
bool ProgramAnalyzer :: isLabelAreadyPresent (string label) {
    
    for(int i = 0; i < symbolTable.size(); i++) {
        if(symbolTable.at(i).symbol == label) {
            return true;
        }
    }
    return false;
}

// detect errors in program
void ProgramAnalyzer :: detectErrors(string label, string instruction, string operand1, string operand2) {

    vector <string> errorMessages;
    
    if(instruction == "MOVEM" || instruction == "MOVER" || instruction == "ADD" || instruction == "SUB" || instruction == "MULT")
        if(operand1 != "AREG," && operand1 != "BREG," && operand1 != "CREG," && operand1 != "DREG,")
            errorMessages.push_back("Invalid operand declared");

    if(instruction == "LTORG" || instruction == "END" || instruction == "STOP")
        if(operand1 != "-" || operand2 != "-")
            errorMessages.push_back("Operand detected for declarative statements");

    for(int i = 0; i < errorMessages.size(); i++) {
        cout << "\nERROR : " << errorMessages.at(i);
    }

}


int main () {

    ProgramAnalyzer analyzer;
    analyzer.convertToCode();

    return 0;
}
