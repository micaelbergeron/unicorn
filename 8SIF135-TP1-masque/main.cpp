/* 
 * File:   main.cpp
 * Author: Micael
 *
 * Created on 27 septembre 2012, 14:02
 */

#include <cstdlib>
#include <string>
#include <sstream>
#include "PrimeList.h"
#include <iostream>

using namespace std;

char encrypt(char a, char b);
char * encrypt(string input, string key);
char * buildSequence(string key, int length);
bool validateArgs(const int & argc, char** argv);

/*
 * Used to compute a finite length mask using prime numbers deltas as generation
 * seed.
 */
int main(int argc, char** argv) {    
    if (!validateArgs(argc, argv)) {
        return -2;
    }
            
    int length = atoi(argv[2]);
    string key = string(argv[1]);
    
	string s = "Je t'aime mon amour :D !!!";
	cout << s << endl;	
	s = encrypt(s, "1100");
	cout << s << endl;
	s = encrypt(s, "1100");
	cout << s << endl;

    string dummy;
    cin >> dummy;    
    return 0;
}

char* buildSequence(string key, int length) {
	// normalize the string to
	if (key.length() < 4) {
		int missZero = 4 - key.length();
		key = string(missZero, '0').append(key);
	}

	// as I don't like to handle zeros in multiplications or power, I pad everything by 2.
	int * ikey = new int[4]();
	for (int i = 0; i < 4; i++) {
		ikey[i] = (int)(key.at(i) - '0') + (2 + i);
		if (i > 0) {
			ikey[i] += (ikey[i - 1] / 2);
		}
	}
	
	// let's be cool, ASCII 32 to 122
	int mod = 'z' - ' '; // char 122 - char 3;
    char * seq = new char[length + 1]();
	seq[length] = '\0';

	char base = ikey[0];
	int step = abs((int) (pow((double)ikey[1],2) - pow((double)ikey[2],2))); // step = |x2^2 - x2^2|
	
	do {
		base = ((base + step) % mod) + ' ';
		seq[--length] = base;

		step += length;
	} while (length > 0);

	delete ikey;

	return seq;
}

char encrypt(char a, char b) {
	return a ^ b;
}

char* encrypt(string input, string key) {
	int maskLen = input.length();
	char * mask = buildSequence(key, maskLen);
	char * cyphedString = new char[maskLen + 1]();
	cyphedString[maskLen] = '\0';

	for (int i = 0; i < maskLen; i++) {
		cyphedString[i] = encrypt(input.at(i), mask[i]);
	}

	return cyphedString;
}

bool validateArgs(const int & argc, char** argv) {
    if (argc < 3) {
        cout << "masque - Correct use is : masque <key> <length>.";
        return false;
    }
        
    return true;    
}