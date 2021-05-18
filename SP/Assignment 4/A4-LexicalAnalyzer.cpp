/* Systems Programming Lab
 * Yatish Kelkar TE IT 8001
 * Assignment 4 : Lexical Analyzer for subset of C
 * 15/05/21
*/


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<vector>
using namespace std;
#define MAXLENGTH 10

class Table {

    public:
    
    string token;
    string type;

    void returnSymbolString();

    Table(string tokenF, string typeF) {
        token = tokenF;
        type = typeF;
    }
};

bool isKeyword(char buffer[]) {

	char keywords[32][MAXLENGTH] = {"auto","break","case","char","const","continue","default",
	"do","double","else","enum","extern","float","for","goto",
	"if","int","long","register","return","short","signed",
	"sizeof","static","struct","switch","typedef","union",
	"unsigned","void","volatile","while"};

	int i, flag = false;
	
    // loop through all keywords, if matches then return true
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = true;
			break;
		}
	}
	return flag;
}
 
int main() {
	
    char buffer[15], operators[] = "+-*/%=";
	vector<Table> symbolTable;
    char character;

    string operatorSymb = "operator", identifierSymb = "identifier", keywordSymb = "keyword";

    // file obj to read the file
    ifstream fileObject("sample_prog_lex.txt");

	int bufferCounter=0;
	
	if(!fileObject.is_open()){
		cout<<"ERROR : cannot open the file\n";
		exit(0);
	}
	
    // loop through every char of file
	while(!fileObject.eof()) {
   		
        character = fileObject.get();
   		
        // if character is operator
		for(int i = 0; i < 6; ++i){
   			if(character == operators[i])
                symbolTable.push_back(Table(string(1, character), operatorSymb));
   		}
   		
   		if(isalnum(character)){
   			buffer[bufferCounter++] = character;
   		}
   		else if((character == ' ' || character == '\n') && (bufferCounter != 0)){
   				buffer[bufferCounter] = '\0';
   				bufferCounter = 0;
   				   				
   				if(isKeyword(buffer))
   					symbolTable.push_back(Table(string(buffer), keywordSymb));
   				else
   					symbolTable.push_back(Table(string(buffer), identifierSymb));
   		}
   		
	}

    cout << "Table is: " << endl;
    cout << "Token\tType" << endl;
    for(int i = 0; i < symbolTable.size(); i++) 
        cout << symbolTable.at(i).token << "\t" << symbolTable.at(i).type << endl;
	
	fileObject.close();
	
	return 0;
}

/*

OUTPUT 

PS F:\College Assignements\SP> g++ LexicalAnalyzer.cpp   
PS F:\College Assignements\SP> ./a                       
Table is: 
Token   Type
void    keyword
main    identifier
int     keyword
a       identifier
b       identifier
c       identifier
isEven  identifier
c       identifier
=       operator
a       identifier
+       operator
b       identifier
isEven  identifier
=       operator
b       identifier
%       operator
2       identifier
*/