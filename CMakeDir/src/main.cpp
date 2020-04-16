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

	while(searchWord != text->end()) //парсим принятый string в вектор string'ов, посимвольно
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

	map<int, int> wordsMap; //результирующий map, где индекс - количество букв в слове, значение - количество слов
	
	for (size_t i=0;i<wordsVector.size();i++)
	{
		wordsMap[wordsVector[i].size()]++; // наращиваем счетчик для каждой длины 
	}

	return wordsMap;
}

void BitShift(MaxAndMinStruct& retStruct, unsigned long num) //с использованием bitset
{
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

}

int main()
{
	/*задача 1*/
	vector<int> v;
	PrimeNum(10,&v);

	/*задача 2*/
	string text="ab ab ab abc abcd abcd rgfeegeerg a a a  b b b";
	map<int, int> m=NumWords(&text);

	/*задача 3*/
	MaxAndMinStruct result;
	BitShift(result,0x00000006);
	
	return 0;
}