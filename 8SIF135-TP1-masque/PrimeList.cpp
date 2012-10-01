/* 
 * File:   PrimeList.cpp
 * Author: Micael
 * 
 * Created on 27 septembre 2012, 14:13
 */

#include "PrimeList.h"

void PrimeList::Init(int max) {    
    primeLength = max - 2; 
    length = max;

    // m_isPrime[0] and m_isPrime[1] are always true
    m_isPrime = new bool[max]();
    
    for (int i = 0; i < max; i++) {
        m_isPrime[i] = true;
    }
	double rootOfMax = sqrt((double)max);
    for (int i = 2; i <= rootOfMax; i++) {
        if (m_isPrime[i]) {
            int j = (int) pow((double)i, 2);
            for (; j < max; j += i) {
                if (m_isPrime[j]) {
                    primeLength--;
                }
                m_isPrime[j] = false;
            }
        }
    }
    // construct the final array;
    m_primeNumbers = new std::vector<int>(primeLength);
    int primeIdx = 0;
    for (int i = 2; i < max; i++) {
        if (m_isPrime[i]) {
            m_primeNumbers->at(primeIdx++) = i;
        }
    }
}

std::ostream& operator<<(std::ostream & o, const PrimeList & pl) {
    o << "Prime count: " << pl.primeLength << std::endl;
    o << "{";
    typedef std::vector<int>::const_iterator primeIt;
    primeIt it = pl.m_primeNumbers->begin();
    for (; it != pl.m_primeNumbers->end() - 1; it++) {
        o << (*it) << ", ";
    }
    o << (*it) << "}";    
    
    return o;
}