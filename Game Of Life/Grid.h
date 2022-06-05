#pragma once
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Grid
{
private:
	int visina, sirina;
	int counter;
	vector<vector<bool>> matrix;
	vector<vector<int>> neighbours;
	vector<vector<int>> movingMatrix
	{
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	bool isValidVisina(int visina);
	bool isValidSirina(int sirina);
	int checkCell(int visina, int sirina);
	void checkCells();
	void prepare();
	bool genRndTrueOrFalse();
	int gen_rnd(int min, int max);
	
public:
	Grid(int visina, int sirina);
	void animate();
	string toString();
};