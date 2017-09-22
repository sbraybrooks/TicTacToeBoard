/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard threeTb;
	Piece ret = threeTb.toggleTurn();
	ASSERT_TRUE(ret == O) << "toggleTurn returns correct piece on first turn of game";
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.getPiece(1,2) == Blank) << "getPiece returns incorrect value when coordinates are blank";
	
	EXPECT_TRUE(threeTb.placePiece(1,2) == X);
	EXPECT_TRUE(threeTb.getPiece(1,2) == X) << "getPiece returns incorrect value when coordinates are X";
	
	EXPECT_TRUE(threeTb.placePiece(2,2) == O);
	EXPECT_TRUE(threeTb.getPiece(2,2) == O) << "getPiece returns incorrect value when coordinates are O";
	
	EXPECT_TRUE(threeTb.getPiece(4,1) == Invalid) << "getPiece returns incorrect value when coordinates are 4,1";
	EXPECT_TRUE(threeTb.getPiece(1,4) == Invalid) << "getPiece returns incorrect value when coordinates are 1,4";
	EXPECT_TRUE(threeTb.getPiece(5,5) == Invalid) << "getPiece returns incorrect value when coordinates are 5,5";
	EXPECT_TRUE(threeTb.getPiece(0,1) == Invalid) << "getPiece returns incorrect value when coordinates are 0,1";
	EXPECT_TRUE(threeTb.getPiece(1,0) == Invalid) << "getPiece returns incorrect value when coordinates are 1,0";
	EXPECT_TRUE(threeTb.getPiece(0,0) == Invalid) << "getPiece returns incorrect value when coordinates are 0,0";
}

TEST(TicTacToeBoardTest, placePiece_getWinner)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.placePiece(1,1) == X) << "placePiece returns incorrect value when placing X on blank cell";
	EXPECT_TRUE(threeTb.placePiece(1,2) == O) << "placePiece returns incorrect value when placing O on blank cell";
	EXPECT_TRUE(threeTb.placePiece(1,2) == O) << "placePiece returns incorrect value when placing X on O cell";
	EXPECT_TRUE(threeTb.placePiece(0,0) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(1,0) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(0,1) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(0,0) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(4,1) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(1,4) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(4,4) == Invalid) << "placePiece returns incorrect value when placing X on incorrect cell";
	EXPECT_TRUE(threeTb.placePiece(2,3) == X);
	EXPECT_TRUE(threeTb.placePiece(2,1) == O);
	EXPECT_TRUE(threeTb.placePiece(2,2) == X);
	EXPECT_TRUE(threeTb.placePiece(3,3) == O);
	EXPECT_TRUE(threeTb.placePiece(3,2) == X);
	EXPECT_TRUE(threeTb.placePiece(3,1) == O);
	EXPECT_TRUE(threeTb.placePiece(1,3) == X);
	EXPECT_TRUE(threeTb.placePiece(1,3) == X) << "placePiece returns incorrect value when placing O on X cell";
	EXPECT_TRUE(threeTb.getPiece(1,3) == X) << "game is over so board should not change and turn shouln't have changed";
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.placePiece(1,3) == O);
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.placePiece(1,3) == O) << "trying to place an X on an O place should return O";
	
}

TEST(TicTacToeBoardTest, diagonalWinX)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.placePiece(1,1) == X);
	EXPECT_TRUE(threeTb.placePiece(1,3) == O);
	EXPECT_TRUE(threeTb.placePiece(2,2) == X);
	EXPECT_TRUE(threeTb.placePiece(3,2) == O);
	EXPECT_TRUE(threeTb.placePiece(3,3) == X);
	EXPECT_TRUE(threeTb.getWinner() == X);
}

TEST(TicTacToeBoardTest, verticalWinX)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.placePiece(1,1) == X);
	EXPECT_TRUE(threeTb.placePiece(2,2) == O);
	EXPECT_TRUE(threeTb.placePiece(2,1) == X);
	EXPECT_TRUE(threeTb.placePiece(3,2) == O);
	EXPECT_TRUE(threeTb.placePiece(3,1) == X);
	EXPECT_TRUE(threeTb.getWinner() == X);
}

TEST(TicTacToeBoardTest, horizontalWinO)
{
	TicTacToeBoard threeTb;
	EXPECT_TRUE(threeTb.placePiece(1,1) == X);
	EXPECT_TRUE(threeTb.placePiece(2,2) == O);
	EXPECT_TRUE(threeTb.placePiece(2,1) == X);
	EXPECT_TRUE(threeTb.placePiece(3,2) == O);
	EXPECT_TRUE(threeTb.placePiece(3,3) == X);
	EXPECT_TRUE(threeTb.placePiece(1,2) == O);
	EXPECT_TRUE(threeTb.getWinner() == O);
}