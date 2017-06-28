// Copyright 2017 Fedorov Igor

#include "./include/saper.h"
#include <string>
#include <sstream>


Saper::Saper(int wth, int hght, int countbomb) {
    field_ = new Field(wth, hght, countbomb);
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

std::string Saper::operator()(int argc, const char ** argv) {
    Arguments args;
    std::ostringstream stream;

    if (argc == 1)
        return "exit";
    if (!validateNumberOfArguments(argc, argv)) {
        message_ = stream.str();
        return message_;
    }
    args.x = parseInt(argv[1]);
    args.y = parseInt(argv[2]);
    args.choose = parseInt(argv[3]);
    switch (args.choose) {
    case 0:
        std::cout <<
            "\t You make a flag!"
            << std::endl;
        field_->MarkCell(args.x, args.y);
        field_->PrintField();
        return "You make a flag";
        break;
    case 1:
        if (TouchResult(args.x, args.y)) {
            std::cout << "\t Good move!" << std::endl;
            field_->PrintField();
            if (field_->IsWin())
                return "You win!";
            return "Good move!";
        } else {
            //  system("cls");
            std::cout << "\t Bad move :(" << std::endl;
            field_->PrintField();
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Ba Ba Ba Bah!" << std::endl;
            std::cout << "Sory, you lose(" << std::endl;
            return "You lose";
        }
        break;
    case 2:
        std::cout <<
            "\t Have a good day!"<< std::endl;
        return "exit";
        break;
    }
    message_ = stream.str();
    return message_;
}

void Saper::help(const char * appname, const char * message) {
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
        help(argv[0],"Wrong numbers of argument");
        return false;
    }
    return true;
}

int Saper::parseInt(const char* arg) {
    int value = atoi(arg);

    if (value < 0) {
        throw std::string("Wrong number format!");
    }
    return value;
}
