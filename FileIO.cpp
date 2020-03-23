#include <iostream>
#include <fstream>
#include <stdio.h>
#include <clocale>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.>
//#include <iomanip>
#define mark3

int main(){
    setlocale(LC_ALL, "RUS");
    std::cout << "Файловый ввод вывод в аннотации с++:\n";
#ifdef mark1
	std::ofstream outf;
	outf.open("SomeText.txt");
	if (!outf.is_open()){
		std::cerr << "Файл, SomeText.txt Не открылся для записи!" << std::endl;
		exit(1);
	}
	else {
		outf << "Пишем первую линию #1!" << std::endl;
		outf << "Пишем вторую линию #2!" << std::endl;
		outf << "Пишем вто"<<std::flush<<"рую линию #3!\n";
		outf << "Пишем вторую линию #4!\n";
	}
	outf.close();
#endif // mark1
	/*
		ios::app — открывает файл в режиме добавления;

		ios::ate — переходит в конец файла перед чтением/записью;

		ios::binary — открывает файл в бинарном режиме (вместо текстового режима);

		 ios::in — открывает файл в режиме чтения (по умолчанию для ifstream);

		 ios::out — открывает файл в режиме записи (по умолчанию для ofstream);

		 ios::trunc — удаляет файл, если он уже существует.
	*/
#ifdef mark2
	std::ofstream outf;
	outf.open(("SomeText.dat"), std::ostream::binary | std::ios::ate);
	if (!outf.is_open()) {
		std::cerr << "Файл, SomeText.dat Не открылся для записи!" << std::endl;
		exit(1);
	}
	else {
		int num(2147483000);
		&num;

		outf << "Пишем число #";
		outf.write((char*)&num, sizeof(int));
		outf << std::endl;
		num++;

		outf << "Пишем число #";
		outf.write((char*)&num, sizeof(int));
		outf << std::endl;
		num++;

		outf << "Пишем число #";
		outf.write((char*)&num, sizeof(int));
		outf << "\n";
		num++;

		outf << "Пишем число #";
		outf.write((char*)&num, sizeof(int));
		outf << "\n";
		num++;
	}
	outf.close();
#endif // mark2
#ifdef mark3 
	std::ifstream inf("SomeText.txt");
	if (!inf.is_open()) {
		std::cerr << "Файл, SomeText.txt Не открылся для чтения!" << std::endl;
		exit(1);
	}
	else {
		while (!inf.eof())	{
			int inputLine(0);
			//std::getline(inf, inputLine);
			//inf.getline(inputLine, 30);
			inf >> inputLine;
			std::cout.precision(4);
			std::cout.setf(std::ios::fixed);
			std::cout << sqrt(inputLine) << std::endl;
		}		
	}
	inf.close();
#endif
#ifdef mark4 //неокончен будет работать странно)
	std::ifstream inf;
	inf.open(("SomeText.dat"), std::ifstream::binary);
	if (!inf.is_open()) {
		std::cerr << "Файл, SomeText.dat Не открылся для чтения!" << std::endl;
		exit(1);
	}
	else {
		while (!inf.eof()) {
			char inputLine[15]{};
			int value(0);
			inf.getline(inputLine,14);
			//inf.seekg(14 * sizeof(char),std::ios::beg);
			//auto deb = inf.tellg();
			inf.read((char*)&value, sizeof(int));
			if (inf) break;
			std::cout << inputLine << value << std::endl;
		}
	}
	inf.close();
#endif
#ifdef task1
	srand(time(NULL));
	std::ofstream outf;
	std::string fileName{ "Task1.txt" };
	outf.open(fileName);
	if (!outf.is_open()) {
		std::cerr << "Файл, " << fileName << " Не открылся для записи!" << std::endl;
		exit(1);
	}
	else {
		int n{ 2 + rand() % 13 };
		outf << n << std::endl;
		const char appen('a');
		const char substruct('s');
		for (size_t i = 0; i < n; i++){
			(rand() % 2 == 0) ? outf.put(appen) : outf.put(substruct);
			outf.put(' ');
			outf << 3 + rand() % 7 << std::endl;
		}

	}
	outf.close();
#endif // mark1
	return 0;

}