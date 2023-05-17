#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using std::cout;

int GAMEOVER = 1;
int SCORE = 1;

class Object
{
public:
    int positionX;
    int positionY;
};

class Board
{
public:
    char border = '$';
    char bg = ' ';
    static const int height = 10;
    static const int width = 20;
    char board[height][width];

    void ResetBoard()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                {
                    board[i][j] = border;
                }
                else
                {
                    board[i][j] = bg;
                }
            }
        }
    }

    void DisplayBoard()
    {
        system("cls");
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
};

class Snake : public Object
{
private:
    Board *boardIni;
    char snakeChar = '0';

public:
    int snakeLength = 0;
    Object snakeBody[100];

    Snake(int sPosX, int sPosY, Board *board_) : boardIni(board_)
    {
        AddBody(sPosX, sPosY);
    }

    void AddBody(int bPosX, int bPosY)
    {
        snakeBody[snakeLength].positionX = bPosX;
        snakeBody[snakeLength].positionY = bPosY;
        if (snakeBody[snakeLength].positionX != 0 && snakeBody[snakeLength].positionY != 0)
        {
            boardIni->board[snakeBody[snakeLength].positionX][snakeBody[snakeLength].positionY] = snakeChar;
        }
        snakeLength++;
    }

    void UpdateBody(int nPosX, int nPosY)
    {
        for (int i = 0; i < snakeLength; i++)
        {
            boardIni->board[snakeBody[i].positionX][snakeBody[i].positionY] = boardIni->bg;
        }

        for (int i = snakeLength - 1; i > 0; i--)
        {
            snakeBody[i].positionX = snakeBody[i - 1].positionX;
            snakeBody[i].positionY = snakeBody[i - 1].positionY;
            boardIni->board[snakeBody[i].positionX][snakeBody[i].positionY] = snakeChar;
        }
        snakeBody[0].positionX += nPosX;
        snakeBody[0].positionY += nPosY;
        boardIni->board[snakeBody[0].positionX][snakeBody[0].positionY] = snakeChar;
    }
};

class Food : public Object
{
private:
    char foodChar = '*';

public:
    void placeFood(Board &board)
    {
        srand(time(0));
        positionX = rand() % ((board.height - 1) - 1) + 1;
        positionY = rand() % ((board.width - 1) - 1) + 1;

        board.board[positionX][positionY] = foodChar;
    }

    void deleteFood(Board &board)
    {
        if (positionX == 0 || positionX == board.height - 1 || positionY == 0 || positionY == board.width - 1)
        {
            board.board[positionX][positionY] = board.border;
        }
        else
        {
            board.board[positionX][positionY] = board.bg;
        }
    }
};

void handleInput(Snake &snake_)
{
    switch (getch())
    {
    case 'w':
        snake_.UpdateBody(-1, 0);
        break;
    case 'a':
        snake_.UpdateBody(0, -1);
        break;
    case 's':
        snake_.UpdateBody(1, 0);
        break;
    case 'd':
        snake_.UpdateBody(0, 1);
        break;
    case 'q':
        GAMEOVER = 0;
        break;
    default:
        break;
    }
}

void handleLogic(Board &board, Snake &snake, Food &food)
{
    if (snake.snakeBody[0].positionX == food.positionX && snake.snakeBody[0].positionY == food.positionY)
    {
        food.deleteFood(board);
        snake.AddBody(snake.snakeBody[snake.snakeLength - 1].positionX, snake.snakeBody[snake.snakeLength - 1].positionY + 1);
        SCORE++;
        food.placeFood(board);
    }

    if (snake.snakeBody[0].positionX == 0 || snake.snakeBody[0].positionX == board.height - 1 || snake.snakeBody[0].positionY == 0 || snake.snakeBody[0].positionY == board.width - 1)
    {
        GAMEOVER = 0;
        cout << "GAMEOVER";
    }
}

int main()
{
    Board board;
    board.ResetBoard();

    Snake snake(board.height / 2, board.width / 2, &board);

    Food food;
    food.placeFood(board);

    while (GAMEOVER)
    {
        cout << "Press q to quit"
             << "\n";
        cout << "SCORE = " << SCORE << "\n";
        board.DisplayBoard();
        if (kbhit())
        {
            handleInput(snake);
        }
        handleLogic(board, snake, food);
    }
    return 0;
}