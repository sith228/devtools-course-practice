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

void Saper::NewLVL() {
    field_->~Field();
    field_ = new Field();
}

void Saper::Gaming() {
    bool again = true;
    int x = 0, y = 0;
    std::string answer = "c";
    std::cout << "\t Welcome!" << std::endl;
    while (true) {
        Print();
        std::cout << "Enter coords." << std::endl;
        std::cout << "Enter number of row: " << std::endl;
        // std::cin >> x;
        std::cout << "Enter number of column: " << std::endl;
        // std::cin >> y;
        do {
            std::cout << "Make flag or touch cell: (f/c)" << std::endl;
            answer = "c";  // std::cin >> answer;
            if (answer[0] == 'c' || answer[0] == 'C') {
                system("cls");
                if (TouchResult(x, y)) {
                    std::cout << "\t Good move!" << std::endl;
                } else {
                    system("cls");
                    std::cout << "\t Bad move :(" << std::endl;
                    Print();
                    std::cout << "Ba Ba Ba Bah!" << std::endl;
                    std::cout << "Ba Ba Ba Bah!" << std::endl;
                    std::cout << "Ba Ba Ba Bah!" << std::endl;
                    std::cout << "Ba Ba Ba Bah!" << std::endl;
                    std::cout << "Sory, you lose(" << std::endl;
                    do {
                        std::cout << "Try again?:) (y/n)" << std::endl;
                        answer = "n";  // std::cin >> answer;
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
                    } while (true);
                }
                break;
            } else if (answer[0] == 'f' || answer[0] == 'F') {
                system("cls");
                std::cout <<
                    "\t You make a flag! My congratulations!"
                    << std::endl;
                MarkCell(x, y);
                break;
            } else {
                continue;
            }
            break;
        } while (true);
        if (!again)
            break;
    }
    std::cout << "Come again!)" << std::endl;
    system("pause");
}

std::string Saper::operator()(int argc, const char ** argv) {
	Arguments args;

	if (!validateNumberOfArguments(argc, argv)) {
		return message_;
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
			"\t You make a flag! My congratulations!"
			<< std::endl;
		MarkCell(args.x, args.y);
		break;
	case 1:
		if (TouchResult(args.x, args.y)) {
			std::cout << "\t Good move!" << std::endl;
		}
		else {
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
			break;
		}
		if (args.choose > 1)


			message_ = stream.str();
		return message_;
	}
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

bool Saper::validateNumberOfArguments(int argc, const char ** argv)
{
	return false;
}

int parseInt(const char* arg) {
	int value = atoi(arg);

	if (value <= 0 || value > 50) {
		throw std::string("Wrong number format!");
	}
	return value;
}
