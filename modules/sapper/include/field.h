// Copyright 2017 Fedorov Igor


#ifndef MODULES_SAPPER_INCLUDE_FIELD_H_
#define MODULES_SAPPER_INCLUDE_FIELD_H_

struct Cell {
    bool isBomb = false;
    char viewCell = '*';
    int num = 0;
};

class Field {
 public:
     explicit Field(int Width = 10, int Height = 10, int bombcount = 10);
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
     int16_t GetBombCount() {
         return NumBomb_;
     }

 private:
     // add in field bombcount bombs
     void GenerateBomb(int bombcount);
     // generate num of bomb for each cell
     void GenerateCellNum();
     Cell **field_;
     int16_t Height_;
     int16_t Width_;
     int16_t NumBomb_;
};

#endif  // MODULES_SAPPER_INCLUDE_FIELD_H_
