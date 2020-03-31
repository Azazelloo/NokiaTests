#include "Header.h"

void PrimeNum(size_t N,vector<int>* primeVector) //поиск N первых простых чисел перебором делителей
{
	long int primeStart=2; //начинаем проверять на простоту с двойки
	bool primeFlag;

	while(N)
	{
		primeFlag=true;

		for(long int j = 2; j <= sqrt(primeStart); j++) // оптимизированный поиск делителей с помощью sqrt
		{
			if(primeStart%j == 0)
			{
				primeFlag=false;
				++primeStart;
				break;
			}
		}

		if(primeFlag)
		{
			primeVector->push_back(primeStart);
			++primeStart;
			--N;
		}	
	}

	
}

map<int, int> NumWords(string* text) //функция подсчитывает количество слов одинаково длины
{
	vector<string> wordsVector;
	string::iterator startWord=text->begin();
	string::iterator searchWord=text->begin();

	while(searchWord != text->end())
	{
		if(*searchWord == ' ')
		{
			wordsVector.push_back(string(startWord,searchWord));
			startWord=searchWord+1; // НЕ захватываем пробел
		}

		if(searchWord+1==text->end()) 
			wordsVector.push_back(string(startWord,searchWord+1)); // если дальше конец текста, не теряем последний символ 

		++searchWord;
	}

	map<int, int> wordsMap;
	
	for (size_t i=0;i<wordsVector.size();i++)
	{
		wordsMap[wordsVector[i].size()]++; // наращаваем счетчик для каждой длины 
	}

	return wordsMap;
}

int main()
{
	string text="ab ab ab abc abcd abcd rgfeegeerg a a a  b b b";
	map<int, int> m=NumWords(&text);


		return 0;
}