#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <Windows.h>
#include "Grid.h"

using namespace std;

int main()
{
	const int visina = 25;
	const int sirina = 50;

	Grid grid(visina, sirina);
	while (true)
	{
		system("cls");
		cout << grid.toString() << endl;
		grid.animate();
		Sleep(500);
	}
}