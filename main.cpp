#include <bits/stdc++.h>
using namespace std;

const int computer = 1;
const int human = 2;
const int side = 3;
const char compMove = 'O';
const char humanMove = 'X';
string name;


void showBoard(char board[][side]){
    cout << "\t\t\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void showInstructions(){
    cout << "Choose a cell numbered from 1 to 9 as below and play\n\n";
    cout << "\t\t\t 1 | 2 | 3 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 4 | 5 | 6 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 7 | 8 | 9 \n\n";
}


void initialize(char board[][side])
{
    for (int i=0; i<side; i++)
        for (int j=0; j<side; j++)
            board[i][j] = '*';
}

void declareWinner(int whoseTurn){
    if(whoseTurn == computer)
        cout << "Computer won!\n";
    else
        cout << name << " won!\n";
}

bool rowCrossed(char board[][side])
{
    for(int i=0; i<side; i++)
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2] && board[i][0] != '*')
            return true;
    return false;
}

bool columnCrossed(char board[][side])
{
    for(int i=0; i<side; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '*')
            return true;
    }
    return false;
}

bool diagonalCrossed(char board[][side])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*')
        return true;
    return false;
}

bool gameOver(char board[][side])
{
    return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}

int minimax(char board[][side], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true){
        if (isAI == true)
            return -10;
        if (isAI == false)
            return +10;
    }
    else{
        if(depth < 9){
            if(isAI){
                bestScore = -999;
                for(int i=0; i<side; i++)
                {
                    for(int j=0; j<side; j++)
                    {
                        if (board[i][j] == '*')
                        {
                            board[i][j] = compMove;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = '*';

                            if(score > bestScore)
                                bestScore = score;
                        }
                    }
                }
                return bestScore;
            }
            else{
                bestScore = 999;
                for (int i = 0; i < side; i++)
                {
                    for (int j = 0; j < side; j++)
                    {
                        if (board[i][j] == '*'){

                            board[i][j] = humanMove;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = '*';

                            if (score < bestScore)
                                bestScore = score;
                        }
                    }
                }
                return bestScore;
            }
        }
        else
            return 0;
    }
    return 0;
}

int bestMove(char board[][side], int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = compMove;
                score = minimax(board, moveIndex+1, false);
                board[i][j] = '*';

                if(score > bestScore){
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x*3+y;
}

// A function to play Tic-Tac-Toe
void playTicTacToe(int whoseTurn)
{
    char board[side][side];
    int moveIndex = 0, x=0, y=0;

    initialize(board);
    showInstructions();

    while(!gameOver(board) && moveIndex != side*side){
        int n;
    
        if(whoseTurn == computer){
            n = bestMove(board, moveIndex);
            x = n/side;
            y = n%side;
            board[x][y] = compMove;

            cout << "Computer has put a " << compMove << " in cell " << n+1 << "\n\n";
            showBoard(board);
            moveIndex++;
            whoseTurn = human;
        }
        else if(whoseTurn == human){
            cout << "You can insert in the following positions: ";
            for(int i=0; i<side; i++)
                for(int j=0; j<side; j++)
                    if(board[i][j] == '*')
                        cout << (i*3+j)+1 << ' ';

            cout << "\n\nEnter the position = ";
            cin >> n;

            n--;
            x = n/side;
            y = n%side;

            if(board[x][y] == '*' && n<9 && n>=0){
                board[x][y] = humanMove;
                cout << name << " has put a " << humanMove << " in cell " << n+1 << "\n\n";
                showBoard(board);
                moveIndex++;
                whoseTurn = computer;
            }
            else if(board[x][y] != '*' && n<9 && n>=0)
                cout << "\nPosition is occupied, select any one place from the available places\n\n";

            else if(n<0 || n>8)
                cout << "Invalid position\n";
        }
    }

    if(!gameOver(board) && moveIndex == side*side)
        cout << "Game is a draw!\n";
    else{
        if(whoseTurn == computer)
            whoseTurn = human;
        else if(whoseTurn == human)
            whoseTurn = computer;
        
        declareWinner(whoseTurn);
    }
}

int main(){
    cout << "\n-------------------------------------------------------------------\n\n";
    cout << "\t\t\t Tic-Tac-Toe\n";
    cout << "\n-------------------------------------------------------------------\n\n";
    char cont = 'y';

    cout << "Enter your nickname: ";
    cin >> name;

    do{
        char choice;
        cout << "Do you want to start first? (y/n): ";
        cin >> choice;

        if(choice=='n')
            playTicTacToe(computer);
        else if(choice=='y')
            playTicTacToe(human);
        else
            cout << "Invalid choice\n";
        
        cout << "Do you want to quit (y/n): ";
        cin >> cont;
    } while(cont == 'n');
    return 0;
}