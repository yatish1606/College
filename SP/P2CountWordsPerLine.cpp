/* Systems Programming Lab
 * Yatish Kelkar TE IT 8001
 * Words per line from file
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define SIZE 100

class Count {
         
    int words[SIZE];
    int lines;

    public : 
        void readFile();
        void displayResults();
};

void Count::readFile() {
    
    fstream fileObject;
    fileObject.open("sampleFile.txt", ios::in);
    lines = 0;

    if(!fileObject) {
        cout << "Error opening file";
    }

    for(int i = 0; i < SIZE; i++) {
        words[i] = 0;
    }

    words[0] = 0;
    fileObject.seekp(0);

    while(!fileObject.eof()) {
        char ch;
        fileObject.get(ch);

        if(ch == ' ') {
            words[lines]++;
        } else if(ch == '\n') {
            words[lines]++;
            lines++;
        }
    }
    words[lines]++;
}

void Count::displayResults() {

    cout << "Line" << "\t" << "Words" << endl;

    for(int i = 0; i < lines+1; i++) {
        cout << i+1 << "\t" << words[i] << endl;
    }
}

int main () {
    
    Count C;
    C.readFile();
    C.displayResults();

    return 0;
}

/*
OUTPUT 

Line    Words
1       10
2       9
3       2
4       7
5       2
6       2
7       3
8       2
9       3
10      3

*/

/*
SAMPLE TEXT FILE

this is just a sample file for testing of program.
here we will find out the number of words
per line
so we will check for whitespace and
newline character 
and increment
System Programming lab
Yatish Kelkar
TE IT 8001
Practice Assignment 2 
*/