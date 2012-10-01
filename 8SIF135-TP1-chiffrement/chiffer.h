/* 
 * File:   chiffer.h
 * Author: Micael
 *
 * Created on 28 septembre 2012, 15:57
 */

#ifndef CHIFFER_H
#define	CHIFFER_H

#include <iostream>

using namespace std;

namespace chiffer {
   
    bool validateArgs(const int & argc, char** argv);
    char encrypt(char a, char b);
    char* encrypt(string input, string key);
    
}

#endif	/* CHIFFER_H */

