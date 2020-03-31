#include "Header.h"

void PrimeNum(size_t N,vector<int>* primeVector) //����� N ������ ������� ����� ��������� ���������
{
	long int primeStart=2; //�������� ��������� �� �������� � ������
	bool primeFlag;

	while(N)
	{
		primeFlag=true;

		for(long int j = 2; j <= sqrt(primeStart); j++) // ���������������� ����� ��������� � ������� sqrt
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

map<int, int> NumWords(string* text) //������� ������������ ���������� ���� ��������� �����
{
	vector<string> wordsVector;
	string::iterator startWord=text->begin();
	string::iterator searchWord=text->begin();

	while(searchWord != text->end())
	{
		if(*searchWord == ' ')
		{
			wordsVector.push_back(string(startWord,searchWord));
			startWord=searchWord+1; // �� ����������� ������
		}

		if(searchWord+1==text->end()) 
			wordsVector.push_back(string(startWord,searchWord+1)); // ���� ������ ����� ������, �� ������ ��������� ������ 

		++searchWord;
	}

	map<int, int> wordsMap;
	
	for (size_t i=0;i<wordsVector.size();i++)
	{
		wordsMap[wordsVector[i].size()]++; // ���������� ������� ��� ������ ����� 
	}

	return wordsMap;
}

int main()
{
	string text="ab ab ab abc abcd abcd rgfeegeerg a a a  b b b";
	map<int, int> m=NumWords(&text);


		return 0;
}