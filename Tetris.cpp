#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TABLE_X 20
#define TABLE_Y 38

#define LEFT 75 // ←
#define RIGHT 77  // →
#define UP 72 // ↑
#define DOWN 80 // ↓

//공백 = 0;
//▦ = 1;
//■ = 2;

void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

const int block1[4][4][4] = {
    {
        {0,0,0,0},
        {0,0,0,0},
        {2,2,2,2},
        {0,0,0,0}
    },
    {
        {0,0,2,0},
        {0,0,2,0},
        {0,0,2,0},
        {0,0,2,0}
    },
    {
        {0,0,0,0},
        {0,0,0,0},
        {2,2,2,2},
        {0,0,0,0}
    },
    {
        {0,0,2,0},
        {0,0,2,0},
        {0,0,2,0},
        {0,0,2,0}
    }
};

const int block2[4][4][4] = {
    {
        {0,0,0,0},
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,2,2,0},
        {0,2,2,0},
        {0,0,0,0}
    }
};

const int block3[4][4][4]= {
    {
        {0,2,0,0},
        {0,2,0,0},
        {0,2,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,2,2,2},
        {0,2,0,0},
        {0,0,0,0}
    },
    {
        {0,2,2,0},
        {0,0,2,0},
        {0,0,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,0,2,0},
        {2,2,2,0},
        {0,0,0,0}
    }
};

const int block4[4][4][4] = {
    {
        {0,0,0,0},
        {0,2,0,0},
        {0,2,2,0},
        {0,0,2,0}
    },
    {
        {0,0,0,0},
        {0,2,2,0},
        {2,2,0,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,2,0,0},
        {0,2,2,0},
        {0,0,2,0}
    },
    {
        {0,0,0,0},
        {0,2,2,0},
        {2,2,0,0},
        {0,0,0,0}
    }
};

const int block5[4][4][4] = {
    {
        {0,0,0,0},
        {0,2,2,2},
        {0,0,2,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {0,0,2,0},
        {0,2,2,0},
        {0,0,2,0}
    },
    {
        {0,0,2,0},
        {0,2,2,2},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,0,2,0},
        {0,0,2,2},
        {0,0,2,0},
        {0,0,0,0}
    }
};

class Block {
protected:
    int shape[4][4][4];
    int x;
    int y;
    int rotationCount;
public:
    int getShape(int rotationCount, int y, int x) {
        return shape[rotationCount][y][x];
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getRotationCount() {
        return rotationCount;
    }
    void down() {
        y++;
    }
    void left() {
        x--;
    }
    void right() {
        x++;
    }
    void rotate() {
        rotationCount = (rotationCount + 1) % 4;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;;
    }
    void setRotationCount(int r) {
        this->rotationCount = r;
    }
    void setShape(int r, int y,int x,int value) {
        this->shape[r][y][x] = value;
    }
};

class Block1 :public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 3;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k];
                }
            }
        }
    }
};

class Block2 :public Block {
public:
    Block2() {
        x = TABLE_X / 2 - 3;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k];
                }
            }
        }
    }
};

class Block3 :public Block {
public:
    Block3() {
        x = TABLE_X / 2 - 3;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k];
                }
            }
        }
    }
};

class Block4 :public Block {
public:
    Block4() {
        x = TABLE_X / 2 - 3;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k];
                }
            }
        }
    }
};

class Block5 :public Block {
public:
    Block5() {
        x = TABLE_X / 2 - 3;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k];
                }
            }
        }
    }
};


class MainMenu {
public:
    MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@@@@  @@@@@@@   @  @@@@@@@@@\n";
        cout << "\t\t"; cout << "      @        @                 @        @     @   @  @        \n";
        cout << "\t\t"; cout << "      @        @                 @        @     @   @  @        \n";
        cout << "\t\t"; cout << "      @        @@@@@@@@@@        @        @    @    @  @@@@@@@@@\n";
        cout << "\t\t"; cout << "      @        @                 @        @ @ @     @          @\n";
        cout << "\t\t"; cout << "      @        @                 @        @    @    @          @\n";
        cout << "\t\t"; cout << "      @        @@@@@@@@@@        @        @     @   @  @@@@@@@@@\n";
        cout << "\n\n\n";
        cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n";
        getchar(); //아무키 입력 기다림
        system("cls");
    }
};

class backup {
public:
    static void updateBlock(Block* source, Block& backupBlock) {
        backupBlock.setX(source->getX());
        backupBlock.setY(source->getY());
        backupBlock.setRotationCount(source->getRotationCount());

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    backupBlock.setShape(i, j, k, source->getShape(i, j, k));
                }
            }
        }
    }

    static void updateTable(vector<vector<int>>& source, vector<vector<int>>& backupTable) {
        backupTable.resize(source.size(), vector<int>(source.size()));
        copy(source.begin(), source.end(), backupTable.begin());
    }
};

class GameTable {
private:
    int x; //가로
    int y; //세로
    Block* blockObject;
    vector<vector<int>> table;
public:
    GameTable(int x, int y):x(x),y(y){ //테트리스 판 뼈대 생성
        blockObject = nullptr;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        //가장 자리 뼈대 색칠
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }

        for (int i = 0; i < y; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }
    //게임판 그리는 함수
    void DrawGameTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1)cout << "▦";
                else if (table[i][j] == 2)cout << "■";
                else cout << "  ";
            }
            cout << "\n";
        }
    }

    //블럭 생성
    void createBlock() {
        srand((unsigned int)time(NULL));
        int select = rand() % 5 + 1;;
        if (select == 1) blockObject = new Block1();
        else if (select == 2) blockObject = new Block2();
        else if (select == 3)blockObject = new Block3();
        else if (select == 4) blockObject = new Block4();
        else if (select == 5)blockObject = new Block5();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
            }
        } 
    }
    
    //블럭 이동
    void MoveBlock(int key) {
        //백업
        Block backupBlock;
        vector<vector<int>> backupTable;
        backup::updateBlock(blockObject, backupBlock);
        backup::updateTable(table, backupTable);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2)table[Y][X] = 0;
            }
        }

        if (key == DOWN) blockObject->down();
        else if (key == LEFT)blockObject->left();
        else if (key == RIGHT)blockObject->right();

        //이동한 블럭 상태를 테이블에 갱신 or 취소
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);
                
                if (blockValue != 2)continue;

                if (table[Y][X] == 0) {
                    table[Y][X] = blockValue;
                }
                else if (table[Y][X] == 1) {
                    copy(backupTable.begin(), backupTable.end(), table.begin());
                    blockObject->setX(backupBlock.getX());
                    blockObject->setY(backupBlock.getY());
                    return;
                }
            }
        }
    }

    //블럭 회전
    void RotateBlock() {
        //백업
        Block backupBlock;
        vector<vector<int>> backupTable;
        backup::updateBlock(blockObject, backupBlock);
        backup::updateTable(table, backupTable);

        //테이블에서 블럭 객체 지우기
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2)table[Y][X]=0;
            }
        }

        blockObject->rotate(); // 회전

        //회전한 블럭 상태를 테이블에 갱신 or 취소
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);
                
                if (blockValue != 2)continue;

                if (table[Y][X] == 0) {
                    table[Y][X] = blockValue;
                }
                else if (table[Y][X] == 1) {
                    copy(backupTable.begin(), backupTable.end(), table.begin());
                    blockObject->setRotationCount(backupBlock.getRotationCount());
                    return;
                }
            }
        }
    }
};

class Gameplay {
private:
    GameTable* gt;
public:
    Gameplay() {
        gt = new GameTable(TABLE_X, TABLE_Y);
        gt->createBlock();
        gt->DrawGameTable();
        while (true) {
            int nSelect;
            if (_kbhit()) {
                nSelect = _getch();
                if (nSelect == 224) {
                    nSelect = _getch();
                    switch (nSelect) {
                    case UP:
                        gt->RotateBlock();
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case DOWN:
                        gt->MoveBlock(DOWN);
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case LEFT:
                        gt->MoveBlock(LEFT);
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case RIGHT:
                        gt->MoveBlock(RIGHT);
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    ~Gameplay() {
        delete gt;
    }
};

int main(void){
    CursorView(false);
    system("mode con cols=100 lines=40 | title 테트리스 게임");
    GameTable gt(TABLE_X, TABLE_Y);
    MainMenu();
    Gameplay();
    getchar();
    return 0;
}
