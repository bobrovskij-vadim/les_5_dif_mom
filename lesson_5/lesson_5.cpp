#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

//1.  Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
//    и выводящую в консоль список уникальных слов(если слово повторяется больше 1 раза, 
//    то вывести его надо один раз).Продемонстрировать работу функции, передав итераторы различных типов.
// 
// 2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные пользователем 
//    из стандартного потока ввода и разбивать их на предложения.Далее программа должна вывести 
//    пользователю все предложения, отсортировав их по длине.

void pr();

template<typename T>

void unique_str(T begin, T end) 
{
	sort(begin, end);
	unique_copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
}

int main()

{
	{
		//---------------Ex_1---------------
		std::cout << "---------------Ex_1---------------\n";
		std::cout << "Unique string:\n";
		std::vector<std::string> str_vec{ "one", "three", "two", "four", "five", "six", "seven", "one", "two" };

		copy(str_vec.begin(), str_vec.end(), std::ostream_iterator<std::string>(std::cout, " "));
		std::cout << std::endl;

		//unique_str(str_vec.begin(), str_vec.end());

		std::cout << "\n\nUnique int:\n";
		std::vector<int> int_vec{ 1, 3, 4, 5, 6, 6, 3 };

		copy(int_vec.begin(), int_vec.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		unique_str(int_vec.begin(), int_vec.end());

		std::cout << std::endl;
	}

	//---------------Ex_2---------------
	std::cout << "\n---------------Ex_3---------------\n";
	std::vector<std::string> text;
	std::vector<std::vector<std::string>> splited_text;
	std::string input;
	
	while (input != "*")
	{
		
		std::cin >> input;
		text.push_back(input);
	};

	std::vector < std::string> sentence;
	

	for (auto i : text)
	{
		sentence.push_back(i);
		for (auto j : i)
		{
			if (j == '.')
			{
				
				splited_text.push_back(sentence);
				sentence.clear();

			}
			//std::cout << j << " ";
		}
		
	}

	for (auto i : splited_text)
	{
		for (auto j : i) {
			
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}		

	std::cout << std::endl;

	std::set<std::vector<std::string>> my_text;

	for (auto i : splited_text)
	{
		my_text.insert(i);
	}
	

	for (auto i : my_text)
	{
		for (auto j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}

	

	



}
