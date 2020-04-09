#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>

#define	  stop __asm nop
using namespace std;

struct MaxAndMinStruct
{
	unsigned long min=0;
	unsigned long max=0;
};

void PrimeNum(size_t N,vector<int>* primeVector);
map<int,int> NumWords(string* text);
MaxAndMinStruct& BitShift(unsigned long num);