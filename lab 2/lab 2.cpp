#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include "database.cpp"
using namespace std;

#define Train tr;

struct train
{
	int number_train;
	char destination[40];//пункт назначения
	int days;
	int arrival_hours, arrival_min;//время прибытия
	int stop_min;

	

	

	
};

int exam(FILE* f, int tf = 0)
	{
		if (f)
		{
			tf = 1;
			cout << "Все ОК! Файл открыт!\n";
		}
		
		throw "Файл не открыт!";

		return tf;
	
	}

void input(FILE* file, train TR)
	{
		cout << "Введите номер поезда: " << TR.number_train << endl;

		cout << "Введите пункт назначения: " << TR.destination << endl;

		cout << "Введите количество дней поездки: " << TR.days << endl;

		cout << "Введите время прибытия через пробел : " << TR.arrival_hours << " " << TR.arrival_min << endl;

		cout << "Введите время стоянки (в минутах) : " << TR.stop_min << endl;


		fwrite(&TR, sizeof(train), 1, file);
	}

void output(train TR)
	{
		cout << "Номер поезда: " << TR.number_train << endl;

		cout << "Пункт назначения: " << TR.destination << endl;

		cout << "Количество дней поездки: " << TR.days << endl;

		cout << "Время прибытия через пробел : " << TR.arrival_hours << " " << TR.arrival_min << endl;

		cout << "Время стоянки (в минутах) : " << TR.stop_min << endl;
	}

int main()
{
	setlocale(LC_ALL, "");
 
	FILE* fp;
	fp = fopen("data.txt", "r");

	vector<train> Train;

	int n;
	cout << "Сколько объектов вы хотите ввести?\n"; cin >> n;

	for (int i = 0; i < n; i++)
	{
		input(fp, tr[i]);
	}


	for (int i = 0; i < n; i++)
	{
		output(tr[i]);
	}


	
	

	
	fclose(fp);
}

