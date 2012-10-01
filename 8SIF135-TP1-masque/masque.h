/* 
 * File:   main.h
 * Author: Micael
 *
 * Created on 28 septembre 2012, 14:07
 */

#ifndef MAIN_H
#define	MAIN_H

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

namespace masque {
    
    char * buildSequence(std::string key, int length);
    bool validateArgs(const int & argc, char** argv);

}


#endif	/* MAIN_H */

