# Tic-Tac-Toe Game

## Overview

This repository contains a simple implementation of the classic Tic-Tac-Toe game in C++. The game includes a single-player mode against a computer opponent with an AI that uses the minimax algorithm.

## Features

- Play against the computer with an intelligent AI opponent.
- User-friendly interface with a numbered grid for easy move selection.
- Option to choose whether to start first or let the computer make the initial move.
- Dynamic display of the game board during play.
- Option to restart the game after completion.

## How to Play

1. Run the program and enter your nickname.
2. Choose whether you want to start first or let the computer make the initial move.
3. During your turn, enter the position where you want to place your 'X' on the grid.
4. The computer will make its move, and the game will continue until a winner is determined or the game ends in a draw.
5. You can choose to play again or quit after the game concludes.

## Game Logic

- The computer's AI uses the minimax algorithm to determine the best possible move.
- The game checks for a winner after each move, considering rows, columns, and diagonals.
- The game ends in a draw if all cells are filled, and no winner is declared.

## Dependencies

The game is implemented in C++ and does not require any external dependencies.

## How to Build and Run

1. Compile the source code using a C++ compiler:

   ```bash
   g++ -o tictactoe tictactoe.cpp

2. Run the executable:

   ```bash
   ./tictactoe

## Additional Notes

- This project is a console-based application and does not include a graphical user interface.
- The game logic is implemented using a 3x3 grid.
- The code includes comments for better understanding of the implementation details.
- Feel free to explore, contribute, and have fun playing Tic-Tac-Toe! :D
