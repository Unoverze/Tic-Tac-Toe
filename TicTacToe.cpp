#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

//add multiplayer

void tttBoard(char* emptySpaces);
bool findWinnerPlayer1(char* emptySpaces, char player1);
bool findWinnerPlayer2(char* emptySpaces, char player2);
void player1Turn(char* emptySpaces, char player1);
void player2Turn(char* emptySpaces, char player2);
void botTurn(char* emptySpaces, char bot);
bool tieChecker(char* emptySpaces, char player1, char player2, int round);
char Winner(char winner);

int main()
{

	srand(time(0));
	int userInput;

	bool game_run = true;

	while (game_run)
	{
		std::cout << "(Developed by Unoverze)";
		std::cout << "-----Welcome To TicTacToe-----\n";
		std::cout << "Singleplayer (1)" << '\n';
		std::cout << "Multiplayer (2)" << '\n';
		std::cout << "> ";
		std::cin >> userInput;
		std::cout << "\n\n\n";
		system("cls");

		if (userInput == 1)
		{
			//singleplayer
			char sp_userInput;
			char player1 = ' ';
			char botEnemy = ' ';
			std::string retryInput;

			bool choosing_run = true;
			while (choosing_run)
			{
				std::cout << "Choose your Character, X or O\n";
				std::cout << "> ";
				std::cin >> sp_userInput;
				system("cls");
				if (sp_userInput == 'X')
				{
					player1 = 'X';
					botEnemy = 'O';
					choosing_run = false;
				}
				else if (sp_userInput == 'O')
				{
					player1 = 'O';
					botEnemy = 'X';
					choosing_run = false;
				}
			}

			char Spaces[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
			std::cout << "\nGame has started, Have Fun!\n";

			bool run = true;
			int match = 0;

			while (run)
			{
				match++;
				tttBoard(Spaces);
				player1Turn(Spaces, player1);
				system("cls");

				if (findWinnerPlayer1(Spaces, player1))
				{
					run = false;
					Winner(player1);
					std::cout << "\nBoard: \n\n";
					tttBoard(Spaces);
				}
				else if (tieChecker(Spaces, player1, botEnemy, match))
				{
					run = false;
					std::cout << "\nIt is a tie!\n";
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}

				tttBoard(Spaces);
				botTurn(Spaces, botEnemy);
				system("cls");

				if (findWinnerPlayer2(Spaces, botEnemy))
				{
					run = false;
					Winner(botEnemy);
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}
				else if (tieChecker(Spaces, player1, botEnemy, match))
				{
					run = false;
					std::cout << "\nIt is a tie!\n";
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}

				std::cout << "\n\nGame has ended!\n\n";
				std::cout << "Try again? (Yes/No)\n";
				std::cout << "> ";
				std::cin >> retryInput;
				if (retryInput == "Yes")
				{
					for (int r = 0; r < 9; r++)
					{
						Spaces[r] = ' ';
					}
					std::cout << "\n\nCleaning up the board";
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					system("cls");
					std::cout << "\nFinished, Have Fun!\n\n";
					run = true;
				}
				else if (retryInput == "No")
				{
					break;
				}
			}
		}
		else if (userInput == 2)
		{
			char player1;
			char player2;
			char user1Input;
			std::string retryInput;
			//multiplayer
			bool choosing_run = true;
			while (choosing_run)
			{
				std::cout << "Choose your character, Player 1, X or O\n";
				std::cout << "> ";
				std::cin >> user1Input;
				system("cls");
				if (user1Input == 'X')
				{
					std::cout << "\nPlayer 2 is set to O\n";
					player1 = 'X';
					player2 = 'O';
					choosing_run = false;
				}
				else if (user1Input == 'O')
				{
					std::cout << "\nPlayer 2 is set to X\n";
					player1 = 'O';
					player2 = 'X';
					choosing_run = false;
				}
			}

			char Spaces[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
			std::cout << "\nGame has started, Have Fun!\n";

			bool run = true;
			int match = 0;

			while (run)
			{
				match++;
				tttBoard(Spaces);
				player1Turn(Spaces, player1);
				system("cls");

				if (findWinnerPlayer1(Spaces, player1))
				{
					run = false;
					Winner(player1);
					std::cout << "\nBoard: \n\n";
					tttBoard(Spaces);
				}
				else if (tieChecker(Spaces, player1, player2, match))
				{
					run = false;
					std::cout << "\nIt is a tie!\n";
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}

				tttBoard(Spaces);
				player2Turn(Spaces, player2);
				system("cls");

				if (findWinnerPlayer2(Spaces, player2))
				{
					run = false;
					Winner(player2);
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}
				else if (tieChecker(Spaces, player1, player2, match))
				{
					run = false;
					std::cout << "\nIt is a tie!\n";
					std::cout << "\nBoard: ";
					tttBoard(Spaces);
				}

				std::cout << "\n\nGame has ended!\n\n";
				std::cout << "Try again? (Yes/No)\n";
				std::cout << "> ";
				std::cin >> retryInput;
				if (retryInput == "Yes")
				{
					for (int r = 0; r < 9; r++)
					{
						Spaces[r] = ' ';
					}
					std::cout << "\n\nCleaning up the board";
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					std::cout << ".";
					Sleep(1000);
					system("cls");
					std::cout << "\nFinished, Have Fun!\n\n";
					run = true;
				}
				else if (retryInput == "No")
				{
					break;
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "Invalid Input, Please try again.\n\n\n";
			Sleep(2000);
			system("cls");
		}
		return 0;
	}
}

void tttBoard(char* emptySpaces)
{
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << emptySpaces[0] << "  |  " << emptySpaces[1] << "  |  " << emptySpaces[2] << "  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << emptySpaces[3] << "  |  " << emptySpaces[4] << "  |  " << emptySpaces[5] << "  " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << emptySpaces[6] << "  |  " << emptySpaces[7] << "  |  " << emptySpaces[8] << "  " << '\n';
	std::cout << "     |     |     " << '\n';
}

//checks if player1 won
bool findWinnerPlayer1(char* emptySpaces, char player1)
{
	//forplayer1
	//rows
	if (emptySpaces[0] == player1 && emptySpaces[1] == player1 && emptySpaces[2] == player1)
	{
		return true;
	}
	else if (emptySpaces[3] == player1 && emptySpaces[4] == player1 && emptySpaces[5] == player1)
	{
		return true;
	}
	else if (emptySpaces[6] == player1 && emptySpaces[7] == player1 && emptySpaces[8] == player1)
	{
		return true;
	}
	//columns
	else if (emptySpaces[0] == player1 && emptySpaces[3] == player1 && emptySpaces[6] == player1)
	{
		return true;
	}
	else if (emptySpaces[1] == player1 && emptySpaces[4] == player1 && emptySpaces[7] == player1)
	{
		return true;
	}
	else if (emptySpaces[2] == player1 && emptySpaces[5] == player1 && emptySpaces[8] == player1)
	{
		return true;
	}
	//diagonal
	else if (emptySpaces[0] == player1 && emptySpaces[4] == player1 && emptySpaces[8] == player1)
	{
		return true;
	}
	else if (emptySpaces[2] == player1 && emptySpaces[4] == player1 && emptySpaces[6] == player1)
	{
		return true;
	}
	return false;
}

//checks if player2 won
bool findWinnerPlayer2(char* emptySpaces, char player2)
{
	//rows
	if (emptySpaces[0] == player2 && emptySpaces[1] == player2 && emptySpaces[2] == player2)
	{
		return true;
	}
	else if (emptySpaces[3] == player2 && emptySpaces[4] == player2 && emptySpaces[5] == player2)
	{
		return true;
	}
	else if (emptySpaces[6] == player2 && emptySpaces[7] == player2 && emptySpaces[8] == player2)
	{

		return true;
	}

	//columns
	else if (emptySpaces[0] == player2 && emptySpaces[3] == player2 && emptySpaces[6] == player2)
	{
		return true;
	}
	else if (emptySpaces[1] == player2 && emptySpaces[4] == player2 && emptySpaces[7] == player2)
	{
		return true;
	}
	else if (emptySpaces[2] == player2 && emptySpaces[5] == player2 && emptySpaces[8] == player2)
	{
		return true;
	}

	//diagonal
	else if (emptySpaces[0] == player2 && emptySpaces[4] == player2 && emptySpaces[8] == player2)
	{
		return true;
	}
	else if (emptySpaces[2] == player2 && emptySpaces[4] == player2 && emptySpaces[6] == player2)
	{
		return true;
	}
	return false;
}

//checks if the match is a tie
bool tieChecker(char* emptySpaces, char player1, char player2, int round)
{
	for (int i = 0; i < 9; i++)
	{
		if (emptySpaces[i] == ' ' || findWinnerPlayer2(emptySpaces, player2) || findWinnerPlayer1(emptySpaces, player1))
		{
			return false;
		}
	}
	if (round >= 9 && findWinnerPlayer2(emptySpaces, player2) == false && findWinnerPlayer1(emptySpaces, player1) == false)
	{
		return true;
	}
	return false;
}

//for player1
void player1Turn(char* emptySpaces, char player1)
{
	int spacePlayer1Choice;
	while (true)
	{
		std::cout << "Player 1: ";
		std::cin >> spacePlayer1Choice;

		if (spacePlayer1Choice == 1 && emptySpaces[0] == ' ')
		{
			emptySpaces[0] = player1;
			break;
		}
		else if (spacePlayer1Choice == 2 && emptySpaces[1] == ' ')
		{
			emptySpaces[1] = player1;
			break;
		}
		else if (spacePlayer1Choice == 3 && emptySpaces[2] == ' ')
		{
			emptySpaces[2] = player1;
			break;
		}
		else if (spacePlayer1Choice == 4 && emptySpaces[3] == ' ')
		{
			emptySpaces[3] = player1;
			break;
		}
		else if (spacePlayer1Choice == 5 && emptySpaces[4] == ' ')
		{
			emptySpaces[4] = player1;
			break;
		}
		else if (spacePlayer1Choice == 6 && emptySpaces[5] == ' ')
		{
			emptySpaces[5] = player1;
			break;
		}
		else if (spacePlayer1Choice == 7 && emptySpaces[6] == ' ')
		{
			emptySpaces[6] = player1;
			break;
		}
		else if (spacePlayer1Choice == 8 && emptySpaces[7] == ' ')
		{
			emptySpaces[7] = player1;
			break;
		}
		else if (spacePlayer1Choice == 9 && emptySpaces[8] == ' ')
		{
			emptySpaces[8] = player1;
			break;
		}
		else
		{
			std::cout << "\n\nInvalid Option, Please choose an empty spot!\n\n";
		}
	}
}

//for multiplayer
void player2Turn(char* emptySpaces, char player2)
{
	int spacePlayer2Choice;

	while (true)
	{
		std::cout << "Player 2: ";
		std::cin >> spacePlayer2Choice;

		if (spacePlayer2Choice == 1 && emptySpaces[0] == ' ')
		{
			emptySpaces[0] = player2;
			break;
		}
		else if (spacePlayer2Choice == 2 && emptySpaces[1] == ' ')
		{
			emptySpaces[1] = player2;
			break;
		}
		else if (spacePlayer2Choice == 3 && emptySpaces[2] == ' ')
		{
			emptySpaces[2] = player2;
			break;
		}
		else if (spacePlayer2Choice == 4 && emptySpaces[3] == ' ')
		{
			emptySpaces[3] = player2;
			break;
		}
		else if (spacePlayer2Choice == 5 && emptySpaces[4] == ' ')
		{
			emptySpaces[4] = player2;
			break;
		}
		else if (spacePlayer2Choice == 6 && emptySpaces[5] == ' ')
		{
			emptySpaces[5] = player2;
			break;
		}
		else if (spacePlayer2Choice == 7 && emptySpaces[6] == ' ')
		{
			emptySpaces[6] = player2;
			break;
		}
		else if (spacePlayer2Choice == 8 && emptySpaces[7] == ' ')
		{
			emptySpaces[7] = player2;
			break;
		}
		else if (spacePlayer2Choice == 9 && emptySpaces[8] == ' ')
		{
			emptySpaces[8] = player2;
			break;
		}
		else
		{
			std::cout << "\n\nInvalid Option, Please choose an empty spot!\n\n";
		}
	}
}

//for bot enemy
void botTurn(char* emptySpaces, char bot)
{
	int spacePlayer2Choice;

	while (true)
	{
		spacePlayer2Choice = rand() % 9;

		if (spacePlayer2Choice == 1 && emptySpaces[0] == ' ')
		{
			emptySpaces[0] = bot;
			break;
		}
		else if (spacePlayer2Choice == 2 && emptySpaces[1] == ' ')
		{
			emptySpaces[1] = bot;
			break;
		}
		else if (spacePlayer2Choice == 3 && emptySpaces[2] == ' ')
		{
			emptySpaces[2] = bot;
			break;
		}
		else if (spacePlayer2Choice == 4 && emptySpaces[3] == ' ')
		{
			emptySpaces[3] = bot;
			break;
		}
		else if (spacePlayer2Choice == 5 && emptySpaces[4] == ' ')
		{
			emptySpaces[4] = bot;
			break;
		}
		else if (spacePlayer2Choice == 6 && emptySpaces[5] == ' ')
		{
			emptySpaces[5] = bot;
			break;
		}
		else if (spacePlayer2Choice == 7 && emptySpaces[6] == ' ')
		{
			emptySpaces[6] = bot;
			break;
		}
		else if (spacePlayer2Choice == 8 && emptySpaces[7] == ' ')
		{
			emptySpaces[7] = bot;
			break;
		}
		else if (spacePlayer2Choice == 9 && emptySpaces[8] == ' ')
		{
			emptySpaces[8] = bot;
			break;
		}
	}
}

char Winner(char winner)
{
	std::cout << "Player " << winner << " has won the game!";
	return 0;
}