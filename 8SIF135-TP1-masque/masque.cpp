
/*
 * File:   main.cpp
 * Author: Micael
 *
 * Created on 27 septembre 2012, 14:02
 */

#include "masque.h"
#include "PrimeList.h"

using namespace std;

/*
 * Used to compute a finite length mask using prime numbers deltas as generation
 * seed.
 */
namespace masque {

char* buildSequence(string key, int length) {
	// normalize the string to
	if (key.length() < 4) {
		int missZero = 4 - key.length();
		key = string(missZero, '0').append(key);
	}

	// as I don't like to handle zeros in multiplications or power, I pad everything by 2.
	int * ikey = new int[4]();
	for (int i = 0; i < 4; i++) {
		ikey[i] = (int)(key.at(i) - '0') + 2;
		if (i > 0) {
			ikey[i] += ikey[i - 1];
		}
	}
	
	// let's be cool, ASCII 32 to 122
	int mod = 'z' - ' '; // char 122 - char 3;
  char * seq = new char[length + 1]();
	seq[length] = '\0';

	char base = ikey[0];
	int step = abs(ikey[1] - ikey[2]);
  
  PrimeList* pl = new PrimeList();
	
	do {
		base = ((base + step) % mod) + ' ';
		seq[--length] = base;
    
    // get the number of primes below 'base'
    pl->Init(base);
    
		step += pl->PrimeCount();
	} while (length > 0);

	delete ikey;
  delete pl;

	return seq;
}

bool validateArgs(const int & argc, char** argv) {
    if (argc < 3) {
        cout << "masque - Correct use is : masque <key> <length>.";
        return false;
    }
        
    return true;    

    
}

}
#ifndef LIB
#define TEST_COUNT 10
int main(int argc, char** argv) {    
    if (!masque::validateArgs(argc, argv)) {
        return -2;
    }
            
    int length = atoi(argv[2]);
    string key = string(argv[1]);

    for (int i = 0; i < TEST_COUNT; i++) {
      char * seq = masque::buildSequence(key, length);
      cout << seq << endl;
    }
    
    char * seq = masque::buildSequence(key, length);
    cout << seq;
    
    delete seq;
    return 0;
}

#endif