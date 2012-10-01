/* 
 * File:   main.cpp
 * Author: Micael
 *
 * Created on 27 septembre 2012, 13:58
 */

#include <cstdlib>
#include <string>
#include "masque.h"
#include "chiffer.h"
#include <fstream>
#include <limits.h>

using namespace std;

namespace chiffer {
    
    bool validateArgs(const int & argc, char** argv) {
        if (argc < 3) {
            cout << argv[0] << " - " << "correct use is: " << argv[0] << " <cle> <fichier-entree>" << endl;
            return false;
        }

        return true;
    }

    char encrypt(char a, char b) {
      return a ^ b;
    }

    char* encrypt(string input, string key) {
      int maskLen = input.length();
      char * mask = masque::buildSequence(key, maskLen);
      char * cyphedString = new char[maskLen + 1]();
      cyphedString[maskLen] = '\0';

      for (int i = 0; i < maskLen; i++) {
        cyphedString[i] = encrypt(input.at(i), mask[i]);
      }

      return cyphedString;
    }
}

int main(int argc, char** argv) {
    if (!chiffer::validateArgs(argc, argv)) {
        return -2;
    }
    string key = string(argv[1]);
    
    ifstream * inputfile = new ifstream();
    inputfile->open(argv[2], ios::in | ios::ate);
    // find the length
    int contentlength = inputfile->tellg();
    inputfile->seekg(0, ios::beg);
    inputfile->clear();

    if (contentlength > 0) {
        char * content = new char[contentlength]();
        inputfile->read(content, contentlength);

        string s_content = string(content);

        char * encrypted = chiffer::encrypt(s_content, key);       
        cout << encrypted;
                
        delete content;
        delete encrypted;
    }
    
    delete inputfile;
    return 0;
}


    