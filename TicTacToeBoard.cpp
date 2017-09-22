#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
	if(turn == X)
	{
	  turn = O;
	  return X;
	}
	else if (turn == O)
	{
	  turn = X;
	  return turn;
	}
	else
	  return Invalid;
}

/**
 * Places the piece of the current turn on the board,
 * returns what piece is placed,
 * and toggles which Piece's turn it is.
 * placePiece does NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value.
 * When the game is over, no more pieces can be placed so attempting to place a piece should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece place = board[row-1][column-1];
  if (getWinner() == Blank)
    return place;
  else if (row > 3 || column > 3 || row < 1 || column < 1)
    return Invalid;
  if (place == X || place == O)
    return place;
  else if (place == Blank)
  {
    board[row-1][column-1] = turn;
    Piece playedTurn = turn;
    toggleTurn();
    return playedTurn;
  }
  else
    return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > 3 || column > 3 || row < 1 || column < 1)
    return Invalid;
  Piece pieceAtCoord = board[row-1][column-1];
  return pieceAtCoord;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece prev = board[0][0];
  int inRow = 0;
  Piece cur;
  for(int i = 0; i < BOARDSIZE; i++)
  {
    for(int j = 0; j < BOARDSIZE; j++)
    {
      cur = board[i][j];
      if(i == 0 && j == 0)
      {
        if(cur == X || cur == O)
        {
          prev = cur;
          inRow = 1;
        }
      }
      else if(j == 0)
      {
        if(cur == X || cur == O)
        {
          prev = cur;
          inRow = 1;
        }
      }
      else
      {
        if(cur == X || cur == O)
        {
          if(cur==prev)
          {
            inRow++;
            if(inRow == 3)
              return cur;
          }
        }
      }
    }
  }
  
  prev = board[0][0];
  inRow = 0;
  
  for(int j = 0; j < BOARDSIZE; j++)
  {
    for(int i = 0; i < BOARDSIZE; i++)
    {
      cur = board[i][j];
      if(i == 0 && j == 0)
      {
        if(cur == X || cur == O)
        {
          prev = cur;
          inRow = 1;
        }
      }
      else if(i == 0)
      {
        if(cur == X || cur == O)
        {
          prev = cur;
          inRow = 1;
        }
      }
      else
      {
        if(cur == X || cur == O)
        {
          if(cur==prev)
          {
            inRow++;
            if(inRow == 3)
              return cur;
          }
        }
      }
    }
  }
  
  if(board[0][0] == X && board[1][1] == X && board[2][2] == X)
    return X;
  if(board[0][0] == O && board[1][1] == O && board[2][2] == O)
    return X;
  if(board[2][0] == X && board[1][1] == X && board[0][2] == X)
    return X;
  if(board[2][0] == O && board[1][1] == O && board[0][2] == O)
    return X;

  for(int i = 0; i < BOARDSIZE; i++)
  {
    for(int j = 0; j < BOARDSIZE; j++)
    {
        if(board[i][j] == Blank)
          return Invalid;
    }
  }
  return Blank;
}
