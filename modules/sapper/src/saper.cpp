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
    stream_ = new std::ostringstream();
    if (argc == 1) {
        PrintHelp(argv[0], stream_);
        return "exit";
    }
    if (!validateNumberOfArguments(argc, argv)) {
        PrintHelp(argv[0], stream_);
        return "wrong arguments!";
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
    }
    std::cout <<
        "\t Have a good day!" << std::endl;
    return "exit";
}

void Saper::PrintHelp(const char *appname, std::ostream *ofs) {
    *ofs <<
        "This is a simple saper application. Usage:\n"
        "\n    " << appname << " <x> <y> <option>"
        "\n   <option> = 0 - touch cell. 1 - mark cell. 2 - exit "
        "and print the result"
        "\n    " << appname << " <somth>"
        "\n        -- exit"
        "\n           a formal parameter is int "
        "\n";
}

bool Saper::validateNumberOfArguments(int argc, const char ** argv) {
    if (argc != 4) {
        PrintHelp(argv[0], stream_);
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
