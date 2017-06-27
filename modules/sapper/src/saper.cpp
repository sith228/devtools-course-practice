// Copyright 2017 Fedorov Igor

#include "./include/saper.h"
#include <string>
#include <sstream>


Saper::Saper(int wth, int hght, int countbomb) {
    field_ = new Field(wth, hght, countbomb);
}

bool Saper::IsWin() {
    return field_->IsWin();
}

void Saper::Print() {
    field_->PrintField();
}

bool Saper::TouchResult(int x, int y) {
    if (!field_->OpenCurrentCell(x, y)) {
        std::cout << "Pleas, try another one.";
        return true;
    }
    if ((*field_)[x][y].isBomb) {
        return false;
    } else if ((*field_)[x][y].num == 0) {
            field_->OpenNearCell(x, y);
    }
    return true;
}

void Saper::MarkCell(int x, int y) {
    field_->MarkCell(x, y);
}

std::string Saper::operator()(int argc, const char ** argv) {
	Arguments args;

	if (!validateNumberOfArguments(argc, argv)) {
		return "error";
	}
	try {
		args.x = parseInt(argv[1]);
		args.y = parseInt(argv[2]);
		args.choose = parseInt(argv[3]);
	}
	catch (std::string& str) {
		return str;
	}
	std::ostringstream stream;
	switch (args.choose) {
	case 0:
		std::cout <<
			"\t You make a flag!"
			<< std::endl;
		MarkCell(args.x, args.y);
		return "You make a flag";
		break;
	case 1:
		if (TouchResult(args.x, args.y)) {
			std::cout << "\t Good move!" << std::endl;
			return "Good move!";
		} else {
			//  system("cls");
			std::cout << "\t Bad move :(" << std::endl;
			Print();
			std::cout << "Ba Ba Ba Bah!" << std::endl;
			std::cout << "Ba Ba Ba Bah!" << std::endl;
			std::cout << "Ba Ba Ba Bah!" << std::endl;
			std::cout << "Ba Ba Ba Bah!" << std::endl;
			std::cout << "Sory, you lose(" << std::endl;
			/*
			do {
				std::cout << "Try again?:) (y/n)" << std::endl;
				//  answer = "n";  // std::cin >> answer;
				if (answer[0] == 'n' || answer[0] == 'N') {
					again = false;
					break;
				} else if (answer[0] == 'y' || answer[0] == 'Y') {
					again = true;
					system("cls");
					NewLVL();
					std::cout << "\t Welcome" << std::endl;
					break;
				} else {
					continue;
				}
				*/
				//  stream << "Triangle Corner #" << args.num << " = " << result;
			return "You lose";
		}
		break;
	case 2:
		std::cout <<
			"\t Have a good day!"
			<< std::endl;
		return "exit";
		break;
	}
	//	if (args.choose > 1)
	if (IsWin())
		return "You win!";
	message_ = stream.str();
	return message_;
}

void Saper::help(const char * appname, const char * message)
{
	message_ =
		std::string(message) +
		"This is a sapper application.\n\n" +
		"Please size field and number of bomb " +
		"in the following format for start:\n\n" +

		"  $ " + appname + " <Heigth> <Width> " +
		"<bomb_count>" + "\n\n" +
		
		"for make decidion:\n\n" +

		"  $ " + appname + " <row_coord> <column_coord> " +
		"<mark/open_glyfe>(f or c)" + "\n\n" +

		"All arguments should be int numbers\n" +
		"exept last for make decidion\n" +
		"You can Make flag or touch cell \n " +
		"    and finish work";
}

bool Saper::validateNumberOfArguments(int argc, const char ** argv) {
	if (argc != 4) {
		help(argv[0]);
		return false;
	} else if (parseInt(argv[3]) <= 1 ) {
		help(argv[0], "ERROR: Incorrect arguments num.\n\n");
		return false;
	}
	return true;
}

int Saper::parseInt(const char* arg) {
	int value = atoi(arg);

	if (value <= 0 || value > 50) {
		throw std::string("Wrong number format!");
	}
	return value;
}
