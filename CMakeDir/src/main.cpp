#include "Header.h"

void SieveOfEratosthenes(size_t n,vector<int>* primeVector) //поиск простых чисел до n с помощью сита Эратосфена
{
	vector<int> isPrime(n + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i*i <= n; i++)
	{ 
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i) //возможное улучшение: i*i вместо 2*i
				isPrime[j] = false;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (isPrime[i])
			primeVector->push_back(i);
	}
}

map<int,int> NumWords(string text) //функция подсчитывает количество слов одинаково длины
{
	stringstream ss(text);
	map<int, int> wordsMap;

	for (string words; ss >> words;)
		wordsMap[words.size()]++;

	return wordsMap;
}

MaxAndMinStruct& BitShift(unsigned long num) //с использованием bitset
{
	MaxAndMinStruct retStruct;

	/*минимум*/
	for(size_t i=0;i<bitset<32>(num).count();i++)
	{
		retStruct.min=bitset<32>(retStruct.min).flip(i).to_ulong();
	}

	/*максимум*/
	for(size_t i=0;i<bitset<32>(num).count();i++)
	{
		retStruct.max=bitset<32>(retStruct.max).flip(31-i).to_ulong();
	}

	return retStruct;
}

int main()
{
	/*задача 1*/
	vector<int> v;
	SieveOfEratosthenes(30,&v);

	/*задача 2*/
	string text="ab ab ab abc abcd abcd rgfeegeerg a a a  b b b";
	map<int,int> m=NumWords(text);

	///*задача 3*/
	MaxAndMinStruct result=BitShift(0x00000006);
	
	return 0;
}