/* Systems Programming Lab
 * Yatish Kelkar TE IT 8001
 * Sequential File
*/

#include<iostream>
#include<fstream>
using namespace std;

int main () {

    ifstream fileObject;

    fileObject.open("sampleFile.txt", ios::in);

    if(!fileObject) {
        cout << "Could not open file";
    } else {
        cout << "File opened successfully";
    }

    while(!fileObject.eof()) {
        char ch;
        fileObject.get(ch);
        cout << ch;
    }

    fileObject.close();

    return 0;
}