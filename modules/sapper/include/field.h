// Copyright 2017 Fedorov Igor

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_

struct Cell
{
    bool isBomb = false;
    char viewCell = '*';
    int num = 0;
};

class Field {
 private:
     Cell **field_;
     short int Height_ ;
     short int Width_ ;
     short int NumBomb_ ;
 public:
     Field(int Width = 10, int Height = 10, int bombcount = 10);
     ~Field();
     void PrintField();
     // feedback from touch
     void OpenNearCell(int x, int y);
     bool OpenCurrentCell(int x_, int y_);
     // mark cell as cell with bomb
     void MarkCell(int x, int y);
     // access to cell
     Cell* operator[] (int index);
     // create array[,]
     void GenerateField();
     // getter
     short int GetBombCount() {
         return NumBomb_;
     }
 private:
     // add in field bombcount bombs
     void GenerateBomb(int bombcount);
     // generate num of bomb for each cell
     void GenerateCellNum();
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
