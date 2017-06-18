// Copyright 2017 Fedorov Igor

#include <stdlib.h>
#include <iostream>
#include <string>

#include "./include/saper.h"

int main() {
	bool again = true;
	int x, y;
	std::string answer;
	Saper app(12,4,7);
	std::cout << "\t Welcome!" << std::endl;
	while (true)
	{
		app.Print();
		std::cout << "Enter coords." << std::endl;
		std::cout << "Enter number of row: " << std::endl;
		std::cin >> x;
		std::cout << "Enter number of column: " << std::endl;
		std::cin >> y;
		do {
			std::cout << "Make flag or touch cell: (f/c)" << std::endl;
			std::cin >> answer;
			if (answer[0] == 'c' || answer[0] == 'C') {
				system("cls");
				if (app.TouchResult(x, y)) {
					std::cout << "\t Good move!" << std::endl;
				}
				else {
					system("cls");
					std::cout << "\t Bad move :(" << std::endl;
					app.Print();
					std::cout << "Ba Ba Ba Bah!" << std::endl;
					std::cout << "Ba Ba Ba Bah!" << std::endl;
					std::cout << "Ba Ba Ba Bah!" << std::endl;
					std::cout << "Ba Ba Ba Bah!" << std::endl;
					std::cout << "Sory, you lose(" << std::endl;
					do {
						std::cout << "Try again?:) (y/n)" << std::endl;
						std::cin >> answer;
						if (answer[0] == 'n' || answer[0] == 'N') {
							again = false;
							break;
						}
						else if (answer[0] == 'y' || answer[0] == 'Y') {
							again = true;
							system("cls");
							app.NewLVL();
							std::cout << "\t Welcome" << std::endl;
							break;
						}
						else continue;
					} while (true);
				}

				break;
			}
			else if (answer[0] == 'f' || answer[0] == 'F') {
				system("cls");
				std::cout << "\t You make a flag! My congratulations!" << std::endl;
				app.MarkCell(x, y);
				break;
			}
			else continue;
		} while (true);
		if (!again)
			break;
	}
	std::cout << "Come again!)"<<std::endl;
	system("pause");
}
