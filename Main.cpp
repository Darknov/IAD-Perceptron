#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;

void wczytajWzorceZadaniowe(vector<vector<double>> &wzorceWejsciowe, vector<vector<double>> &wzorceWyjsciowe)
{
	// wczytywanie wzorcow podanych w zadaniu
	wzorceWejsciowe.push_back({ 1,0,0,0 });
	wzorceWejsciowe.push_back({ 0,1,0,0 });
	wzorceWejsciowe.push_back({ 0,0,1,0 });
	wzorceWejsciowe.push_back({ 0,0,0,1 });

	wzorceWyjsciowe.push_back({ 1,0,0,0 });
	wzorceWyjsciowe.push_back({ 0,1,0,0 });
	wzorceWyjsciowe.push_back({ 0,0,1,0 });
	wzorceWyjsciowe.push_back({ 0,0,0,1 });
}

void wczytajWzorceZPliku(	string pathToWzorceWejsciowe, string pathToWzorceWyjsciowe,
							vector<vector<double>> &wzorceWejsciowe, vector<vector<double>> &wzorceWyjsciowe)
{
	ifstream inputFileStream;
	inputFileStream.open(pathToWzorceWejsciowe);
	int size;
	inputFileStream >> size;

	int i = 0;

	while (true)
	{
		if (inputFileStream.good())
		{
			wzorceWejsciowe.push_back({});
			for (int j = 0; j < size; j++)
			{
				int bufor;
				inputFileStream >> bufor;
				wzorceWejsciowe[i].push_back(bufor);
			}
			i++;
		}
		else
			break;
	}

	inputFileStream.close();

	i = 0;
	size = 0;
	inputFileStream.open(pathToWzorceWyjsciowe);
	
	inputFileStream >> size;

	while (true)
	{
		if (inputFileStream.good())
		{
			wzorceWyjsciowe.push_back({});
			for (int j = 0; j < size; j++)
			{
				int bufor;
				inputFileStream >> bufor;
				wzorceWyjsciowe[i].push_back(bufor);
			}
			i++;
		}
		else
			break;
	}

	inputFileStream.close();

}

int main(int argc)
{
	vector<vector<double>> wzorceWejsciowe;
	vector<vector<double>> wzorceWyjsciowe;
	bool czyLosowaKolejnoscWzorcow = false;
	bool running = false;
	//wczytajWzorceZadaniowe(wzorceWejsciowe, wzorceWyjsciowe);

	wczytajWzorceZPliku("wzorceWejsciowe.txt", "wzorceWyjsciowe.txt", wzorceWejsciowe, wzorceWyjsciowe);

	cout << "Wzorce wejsciowe: " << endl;

	for (int i = 0; i < wzorceWejsciowe.size(); i++)
	{
		for(int j = 0; j < wzorceWejsciowe[i].size(); j++)
		{
			cout << wzorceWejsciowe[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Wzorce wyjsciowe: " << endl;
	

	for (int i = 0; i < wzorceWyjsciowe.size(); i++)
	{
		for (int j = 0; j < wzorceWyjsciowe[i].size(); j++)
		{
			cout << wzorceWyjsciowe[i][j] << " ";
		}
		cout << endl;
	}
	// glowna petla nauki

	

	while (running)
	{
		// w tym miejscu uczymy uposledzone neurony

		// feed net with wzorzces

		// propagate forward

		// progragate backward

		// save every 10, 20, 50 iterations
	}
	
	cin.ignore();
	cin.get();
}

