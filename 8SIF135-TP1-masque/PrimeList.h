/* 
 * File:   PrimeList.h
 * Author: Micael
 *
 * Created on 27 septembre 2012, 14:13
 */

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

#ifndef PRIMELIST_H
#define	PRIMELIST_H

class PrimeList {
public:
    PrimeList() {
        primeLength = 0;
        length = 0;
        m_isPrime = NULL;
    };
    
    PrimeList(int max) {
        Init(max);
    }
    
    virtual ~PrimeList() {
        delete m_isPrime;
        
        if (m_primeNumbers != NULL) {
            m_primeNumbers->clear();
        }
    };
    
    void Init(int max);
    std::vector<int> * GetPrimeNumbers() {
        return m_primeNumbers;
    };    
    
    int PrimeCount() const {
        return primeLength;
    }
    
    friend std::ostream & operator <<(std::ostream & o, const PrimeList & pl);
        
private:
    
    int primeLength;
    int length;
    bool * m_isPrime;
    std::vector<int> * m_primeNumbers;
    
};

#endif	/* PRIMELIST_H */

