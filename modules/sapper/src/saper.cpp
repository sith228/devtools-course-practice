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
