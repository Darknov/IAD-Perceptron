#pragma once
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void wczytajWzorceZadaniowe(vector<vector<double>> wzorceWejsciowe, vector<vector<double>> wzorceWyjsciowe)
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


int main(int argc)
{
	vector<vector<double>> wzorceWejsciowe;
	vector<vector<double>> wzorceWyjsciowe;

	wczytajWzorceZadaniowe(wzorceWejsciowe, wzorceWyjsciowe);


	
	
	cin.ignore();
	cin.get();
}

