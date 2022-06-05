#include "Grid.h"

bool Grid::isValidVisina(int visina)
{
	if (visina < 0 || visina > this->visina - 1) return false;
	return true;
}

bool Grid::isValidSirina(int sirina)
{
	if (sirina < 0 || sirina > this->sirina - 1) return false;
	return true;
}

int Grid::checkCell(int visina, int sirina)
{
	int counter = 0;
	for (auto& pos : movingMatrix)
		if (isValidVisina(pos[0] + visina) && isValidSirina(pos[1] + sirina) && matrix[pos[0] + visina][pos[1] + sirina])
			counter++;
	return counter;
}

void Grid::checkCells()
{
	for (int i = 0; i < visina; i++)
	{
		vector<int> v;
		for (int j = 0; j < sirina; j++)
			v.push_back(checkCell(i, j));
		neighbours.push_back(v);
	}
}

void Grid::prepare()
{
	srand(time(nullptr));
	for (int i = 0; i < visina; i++)
	{
		vector<bool> v;
		for (int j = 0; j < sirina; j++)
			v.push_back(genRndTrueOrFalse());
		matrix.push_back(v);
	}
}

bool Grid::genRndTrueOrFalse()
{
	int a = gen_rnd(1, 4);
	if (a == 4)
		return true;
	return false;
}

int Grid::gen_rnd(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

Grid::Grid(int visina, int sirina)
{
	this->visina = visina;
	this->sirina = sirina;
	this->counter = 0;
	prepare();
}

void Grid::animate()
{
	neighbours.clear();
	checkCells();
	for (int i = 0; i < visina; i++)
	{
		for (int j = 0; j < sirina; j++)
		{
			if ((neighbours[i][j] == 2 || neighbours[i][j] == 3) && matrix[i][j])
				matrix[i][j] = 1;
			if ((neighbours[i][j] < 2 || neighbours[i][j] > 3) && matrix[i][j])
				matrix[i][j] = 0;
			if ((neighbours[i][j] == 3) && !matrix[i][j])
				matrix[i][j] = 1;
		}
	}
}

string Grid::toString()
{
	counter++;
	stringstream ss;
	for (int i = 0; i < visina; i++)
	{
		for (int j = 0; j < sirina; j++)
		{
			if (matrix[i][j])
				ss << 'O' << ' ';
			else
				ss << '-' << ' ';
		}
		ss << endl;
	}
	ss << endl;
	ss << counter;
	return ss.str();
}