// Copyright 2017 Fedorov Igor

#include "./include/saper.h"
#include <string>

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
	double result;

	if (!validateNumberOfArguments(argc, argv)) {
		return message_;
	}
	try {
		args.point1_coordx = parseDouble(argv[1]);
		args.point1_coordy = parseDouble(argv[2]);
		args.point2_coordx = parseDouble(argv[3]);
		args.point2_coordy = parseDouble(argv[4]);
		args.point3_coordx = parseDouble(argv[5]);
		args.point3_coordy = parseDouble(argv[6]);
		args.operation = parseOperation(argv[7]);
		if (args.operation >= 1 && args.operation <= 2)
			args.num = parseInt(argv[8]);
	}
	catch (std::string& str) {
		return str;
	}

	Triangle triangle(args.point1_coordx, args.point1_coordy,
		args.point2_coordx, args.point2_coordy,
		args.point3_coordx, args.point3_coordy);

	std::ostringstream stream;
	switch (args.operation) {
	case 1:
		result = triangle.CalculateSide(args.num);
		stream << "Triangle Side #" << args.num << " = " << result;
		break;
	case 2:
		result = triangle.CalculateCorner(args.num);
		stream << "Triangle Corner #" << args.num << " = " << result;
		break;
	case 3:
		result = triangle.CalculatePerimeter();
		stream << "Triangle Perimeter = " << result;
		break;
	case 4:
		result = triangle.CalculateSquare();
		stream << "Triangle Square = " << result;
		break;
	case 5:
		stream << "Triangle Median Coords = " <<
			triangle.GetCoordXMedian() << ", " <<
			triangle.GetCoordYMedian();
		break;
	case 6:
		stream << "Triangle Circumscribed Circle Center = " <<
			triangle.GetCoordXCircumscribedCircle() << ", " <<
			triangle.GetCoordYCircumscribedCircle();
		break;
	case 7:
		stream << "Triangle Inscribed Circle Center = " <<
			triangle.GetCoordXInscribedCircle() << ", " <<
			triangle.GetCoordYInscribedCircle();
		break;
	}

	message_ = stream.str();
	return message_;
}

void Saper::help(const char * appname, const char * message)
{
	message_ =
		std::string(message) +
		"This is a sapper application.\n\n" +
		"Please size field and number of bomb " +
		"in the following format:\n\n" +

		"  $ " + appname + " <coord1_x> <coord1_y> " +
		"<coord2_x> <coord2_y> <coord3_x> <coord3_y> <operation> [<num>]\n\n" +

		"All arguments should be double-precision numbers\n" +
		"You can use next operations: side, corner, perimeter, square," +
		"    median, circumscribed_circle, inscribed_circle" +
		"<num> is necessary for side and corner calculation where " +
		"<num> is a number of corner/side counting from coord1 to coord3";
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