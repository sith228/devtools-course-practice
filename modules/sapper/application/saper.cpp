// Copyright 2017 Fedorov Igor

#include "./include/saper.h"


Saper::Saper(int wth, int hght, int countbomb) {
    DeactivatedBomb_ = 0;
    field_ = new Field(wth, hght, countbomb);
}

bool Saper::IsWin() {
    return field_->GetBombCount() == DeactivatedBomb_;
}

void Saper::Print() {
    field_->PrintField();
}

bool Saper::TouchResult(int x, int y) {
    if (!field_->OpenCurrentCell(x, y)) {
        std::cout << "Pleas, try another one.";
        return true;
    }
    if ((*field_)[x][y].isBomb)
        return false;
    else if ((*field_)[x][y].num == 0) {
            field_->OpenNearCell(x, y);
    }
    return true;
}

void Saper::MarkCell(int x, int y) {
    field_->MarkCell(x, y);
    if ((*field_)[x][y].isBomb)
        DeactivatedBomb_++;
}

void Saper::NewLVL() {
    field_->~Field();
    field_ = new Field();
}
