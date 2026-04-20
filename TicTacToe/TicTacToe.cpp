#include <iostream>

using namespace std;

void printBlock(int TicTac[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (TicTac[i][j] == -1)
            {
                cout << " ";
            }
            else
            if (TicTac[i][j] == 0)
            {
                cout << "O";
            }
            else
            if (TicTac[i][j] == 1)
            {
                cout << "X";
            }

            if (j != 3 - 1)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i != 3 - 1)
        {
            cout << "----------" << endl;
        }
        
    }
}

void SetBlock(int (&_TicTac)[3][3], int _square, int _XorO)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (_square == 1)
            {
                if (_TicTac[i][j] == -1)
                {
                    _TicTac[i][j] = _XorO;
                }
                else
                {
                    cout << "Square already filled. Miss a turn!";
                }
                
            }
            _square--;
        }
        
    }
}

int checkDone(int _TicToe[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (_TicToe[i][j] == -1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int checkWinner(int _TicTac[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (_TicTac[i][0] != -1 && _TicTac[i][0] == _TicTac[i][1] && _TicTac[i][1] == _TicTac[i][2])
            return _TicTac[i][0];
    }

    for (int j = 0; j < 3; j++)
    {
        if (_TicTac[0][j] != -1 && _TicTac[0][j] == _TicTac[1][j] && _TicTac[1][j] == _TicTac[2][j])
            return _TicTac[0][j];
    }

    if (_TicTac[0][0] != -1 && _TicTac[0][0] == _TicTac[1][1] && _TicTac[1][1] == _TicTac[2][2])
        return _TicTac[0][0];

    if (_TicTac[0][2] != -1 && _TicTac[0][2] == _TicTac[1][1] && _TicTac[1][1] == _TicTac[2][0])
        return _TicTac[0][2];

    return -1;

}

int main()
{
    int square = -1;
    int XorO = -1;
    int cont = 0;
    int TicToe[3][3] = { {-1,-1,-1},{-1,-1,-1},{-1,-1,-1} };
    cout << endl;
    cout << "TIC TAC TOE" << endl;
    printBlock(TicToe);
    cout << endl;

    do
    {

        do
        {
            cout << "What square do you want to write? 1-9 (-1 to exit)" << endl;
            cin >> square;
            if (square == -1)
            {
                return 0;
            }
        } while (square < 1 || square > 9);
    
        do
        {
            cout << "X or O? (type 0 for O or 1 for X)" << endl;
            cin >> XorO;
        } while (XorO != 0 && XorO != 1);
    

    SetBlock(TicToe, square, XorO);
    cout << endl;
    printBlock(TicToe);

    int Winner = checkWinner(TicToe);
    if (Winner != -1)
    {
        if (Winner == 1)
        {
            cout << "X won!" << endl;
            break;
        }
            
        else
            if (Winner == 0)
            {
                cout << "O won!" << endl;
                break;
            }
    }

    } while (checkDone(TicToe));

    if (checkWinner(TicToe) == -1)
    {
        cout << "No winner!" << endl;
    }
}
