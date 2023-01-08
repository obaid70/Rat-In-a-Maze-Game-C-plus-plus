#include<iostream>
using namespace std;
#include<fstream>
#include<stdlib.h>
void Game();
void welcome(char &);
void easy();
void LifeandScore(int, int);
void Movement();
void PrintPathEasy(int[4][4], int, int);
bool isSafeEasy(int[4][4], int, int);
bool PlayAgain(char);
int sizeOfFile(char[]);
char ** DmemoryChar(int, int);
void Read(char **, int *, int, ifstream &);
void AscendingSort(char **, int *, int);
void writeScore(char**, int*, int);
void medium();
void PrintPathMedium(int[6][6], int, int);
bool isSafeMedium(int[6][6], int, int);
void hard();
void PrintPathHard(int[8][8], int, int);
bool isSafeHard(int[8][8], int, int);
void write(char**, int*, int);
void DescendingSort(char **, int *, int);
void PrintWinEasy(int[4][4], int);
void PrintWinMedium(int[6][6], int);
void PrintWinHard(int[8][8], int);
int main()
{
	ofstream fout("score.txt");
	fout.close();
	Game();
	return 0;
}

void Game()
{
	char difficulty = '\0';
	welcome(difficulty);
	if (difficulty == '1')
	{
		easy();
	}
	else if (difficulty == '2')
	{
		medium();
	}
	else if (difficulty == '3')
	{
		hard();
	}
	return;
}

// Easy Difficulty Program.

void easy()
{
	char Name[50] = { '\0' }, filename[10] = { "score.txt" };
	char move = '\0', play = '\0';
	int maze[4][4] = { { 1, 0, 0, 0 }, { 1, 1, -2, 0 }, { 0, 1, 1, 1 }, { 0, 0, 0, 1 } };
	int row = 4, score = 0, lives = 3, x = 0, y = 0, temp = 0, Filesize = 0;
	int sol[4][4];
	char ** names = NULL;
	int * Score = NULL;
	ofstream fout(filename, ios::app);
	ifstream fin;
	cout << "\n\n\t\t\t\t Please enter your Name : ";
	cin.ignore();
	cin.getline(Name, 50);
	while (lives != 0)
	{
		system("CLS");
		cout << "\t\t\t\t Player Name : " << Name << endl;
		LifeandScore(lives, score);
		cout << "\n Path : " << endl << endl;
		PrintPathEasy(sol, x, y);
		Movement();
		cout << "\t\t\t\t\t press P to pause game." << endl;
		cout << "\n\nPlease choose your movement." << endl;
		cin >> move;
		if (move == 'p' || move == 'P')
		{
			while (move == 'p' || move == 'P')
			{
				cout << "\t\t\t\t\tGame Paused! Press S to Start/Resume Game." << endl;
				cin >> move;
				if (move == 's' || move == 'S')
				{
					break;
				}
				else if (move != 'S' || move != 's')
				{
					move = 'p';
				}
			}
		}
		while (move != 'u'&&move != 'U'&&move != 'd'&&move != 'D'&&move != 'l'&&move != 'L'&&move != 'r'&&move != 'R')
		{
			cout << " Please choose your movement.\n" << endl;
			cin >> move;
		}
		if (move == 'u' || move == 'U')
		{
			x--;
			if (isSafeEasy(maze, x, y) == true)
			{
				sol[x + 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeEasy(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x++;
			}
		}
		if (move == 'd' || move == 'D')
		{
			x++;
			if (isSafeEasy(maze, x, y) == true)
			{
				sol[x - 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeEasy(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x--;
			}
		}
		if (move == 'r' || move == 'R')
		{
			y++;
			if (isSafeEasy(maze, x, y) == true)
			{
				sol[x][y - 1] = 1;
				score = score + 5;
			}
			else if (isSafeEasy(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y--;
			}
		}
		if (move == 'l' || move == 'L')
		{
			y--;
			if (isSafeEasy(maze, x, y) == true)
			{
				sol[x][y + 1] = 1;
				score = score + 5;
			}
			else if (isSafeEasy(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y++;
			}
		}
		if (x == row - 1 && y == row - 1)
		{
			sol[x][y] = 1;
			system("CLS");
			cout << endl << endl << "Path : " << endl << endl;
			PrintPathEasy(sol, x, y);
			cout << "\n\nCongratulations! The Rat has reached the Destination. You won the Game." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			cout << "\nThe Original Maze was this : " << endl << endl;
			PrintWinEasy(maze, row);
			fout << Name << " : " << score << endl;
			break;
		}
		if (lives == 0)
		{
			system("CLS");
			cout << "\n\nThe Rat is out of Lives! You Lost the Game. Better Luck next time." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			fout << Name << " : " << score << endl;
		}
	}
	cout << "\n\nWould you like to play Again? [Y/N]" << endl;
	cin >> play;
	if (PlayAgain(play) == true)
	{
		system("CLS");
		Game();
	}
	else
	{
		fout.close();
		fin.open(filename);
		Filesize = sizeOfFile(filename);
		names = DmemoryChar(Filesize, 50);
		Score = new int[Filesize];
		Read(names, Score, Filesize, fin);
		cout << "\nHigh Score Table :\n" << endl;
		DescendingSort(names, Score, Filesize);
		write(names, Score, Filesize);
		writeScore(names, Score, Filesize);
		fin.close();
		cout << "\n\nThank You! for playing RAT IN A MAZE!" << endl << endl;
		return;
	}
	return;
}

void PrintWinEasy(int array[4][4], int Rows)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl << endl;
	}
}

void welcome(char & difficulty)
{
	cout << "\n\t\t\t\t\t Welcome to RAT IN A MAZE!" << endl;
	cout << "\n\n\t\t\t\t You have 3 lives to reach from Source to Destination.\n";
	cout << "\n\n\t\t\t\t 1 is a valid path and you can pass it.\n\n\t\t\t\t 0 is a block and you cannot pass it.\n\n\t\t\t\t -2 is a Monster which will decrease the Rats life by 1." << endl;
	cout << "\n\n\t\t\t\t if you reach 1 your score will increase by 5.\n\n\t\t\t\t if you reach 0 your score will decrease by 1.\n\n\t\t\t\t if you reach -2 (M) your score will decrease by 5. " << endl;
	while (difficulty != '1' && difficulty != '2' && difficulty != '3')
	{
		cout << "\n\n\t\t\t\t Please choose the difficulty : \n\n\t\t\t\t enter 1 For Easy (4x4 Maze).\n\n\t\t\t\t enter 2 For Medium (6x6 Maze).\n\n\t\t\t\t enter 3 For Difficult (8x8 Maze).\n\t\t\t\t ";
		cin >> difficulty;
		system("CLS");
	}
	system("CLS");
	return;
}

void LifeandScore(int life, int score)
{
	cout << "\n\t\t\t\t\t Lifes = " << life << endl;
	cout << "\n\t\t\t\t\t Score = " << score << endl;
	return;
}

void Movement()
{
	cout << "\n\t\t\t\t\t Movement Controls :" << endl;
	cout << "\n\t\t\t\t\t Up = U" << endl;
	cout << "\n\t\t\t\t\t Down = D" << endl;
	cout << "\n\t\t\t\t\t Left = L" << endl;
	cout << "\n\t\t\t\t\t Right = R" << endl;
	cout << endl;
	return;
}

void PrintPathEasy(int array[4][4], int x, int y)
{
	int flag = 0;
	for (int k = 0; k < 4; k++)
	{
		if (flag == 0)
		{

			cout << char(218) << char(196) << char(196) << char(194);
			for (int i = 0; i <2; i++)
			{
				cout << char(196) << char(196) << char(194);
			}
			cout << char(196) << char(196) << char(191) << endl;
			flag = 1;
		}
		for (int i = 0; i < 4; i++)
		{
			cout << char(179);
			if (x == k && y == i)
			{
				cout << "R";
			}
			else if (array[k][i] == 1)
			{
				cout << "1";
			}
			else if (array[k][i] == 0)
			{
				cout << "0";
			}
			else if (array[k][i] == -2)
			{
				cout << "M";
			}
			else
			{
				cout << " ";
			}
			cout << char(255);
		}
		cout << char(179) << endl;
		cout << char(192) << char(196) << char(196) << char(193);
		for (int i = 0; i < 2; i++)
		{
			cout << char(196) << char(196) << char(193);
		}
		cout << char(196) << char(196) << char(217) << endl;
	}
	return;
}

bool isSafeEasy(int maze[4][4], int x, int y)
{
	if (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1)
	{
		return true;
	}
	return false;
}

bool PlayAgain(char option)
{
	if (option == 'y' || option == 'Y')
	{
		return true;
	}
	return false;
}

int sizeOfFile(char filename[])
{
	int size = 0;
	char array[50] = { '\0' };
	ifstream fin(filename);
	while (fin.getline(array, 50))
	{
		size++;
	}
	fin.close();
	return size;
}

char ** DmemoryChar(int Row, int Col)
{
	char ** array = new char*[Row];
	for (int i = 0; i < Row; i++)
	{
		array[i] = new char[Col];
	}
	return array;
}

void Read(char ** names, int * score, int rows, ifstream & fin)
{
	for (int i = 0; i < rows; i++)
	{
		fin.getline(names[i], 50, ':');
		fin >> score[i];
		fin.ignore();
	}
	return;
}

void AscendingSort(char ** array, int * score, int row)
{
	int temp = 0;
	char * temp2 = NULL;
	for (int i = 0; i < row; i++)
	{
		for (int j = i + 1; j < row; j++)
		{
			if (score[i] > score[j])
			{
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
				temp2 = array[i];
				array[i] = array[j];
				array[j] = temp2;
			}
		}
	}
	return;
}

void DescendingSort(char ** array, int * score, int row)
{
	int temp = 0;
	char * temp2 = NULL;
	for (int i = 0; i < row; i++)
	{
		for (int j = i + 1; j < row; j++)
		{
			if (score[i] < score[j])
			{
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
				temp2 = array[i];
				array[i] = array[j];
				array[j] = temp2;
			}
		}
	}
	return;
}

void write(char**array1, int*array2, int Row)
{
	for (int i = 0; i < Row; i++)
	{
		cout << array1[i] << " : " << array2[i] << endl;
	}
	return;
}

void writeScore(char**array1, int*array2, int Row)
{
	ofstream fout("score.txt");
	for (int i = 0; i < Row; i++)
	{
		fout << array1[i] << " : " << array2[i] << endl;
	}
	fout.close();
	return;
}

// Medium Difficulty Program.

void medium()
{
	char Name[50] = { '\0' }, filename[10] = { "score.txt" };
	char move = '\0', play = '\0';
	int maze[6][6] = { { 1, 0, 0, 0, 0, 0 }, { 1, 1, 0, -2, 0, 0 }, { -2, 1, 1, 0, 0, 0 }, { 0, 0, 1, 1, -2, 0 }, { 0, 0, 0, 1, 1, 0 }, { 0, 0, 0, -2, 1, 1 } };
	int row = 6, score = 0, lives = 3, x = 0, y = 0, temp = 0, Filesize = 0;
	int sol[6][6];
	char ** names = NULL;
	int * Score = NULL;
	ofstream fout(filename, ios::app);
	ifstream fin;
	cout << "\n\n\t\t\t\t Please enter your Name : ";
	cin.ignore();
	cin.getline(Name, 50);
	while (lives != 0)
	{
		system("CLS");
		cout << "\t\t\t\t Player Name : " << Name << endl;
		LifeandScore(lives, score);
		cout << "\n Path : " << endl << endl;
		PrintPathMedium(sol, x, y);
		Movement();
		cout << "\t\t\t\t\t press P to pause game." << endl;
		cout << "\n\nPlease choose your movement." << endl;
		cin >> move;
		if (move == 'p' || move == 'P')
		{
			while (move == 'p' || move == 'P')
			{
				cout << "\t\t\t\t\tGame Paused! Press S to Start/Resume Game." << endl;
				cin >> move;
				if (move == 's' || move == 'S')
				{
					break;
				}
				else if (move != 'S' || move != 's')
				{
					move = 'p';
				}
			}
		}
		while (move != 'u'&&move != 'U'&&move != 'd'&&move != 'D'&&move != 'l'&&move != 'L'&&move != 'r'&&move != 'R')
		{
			cout << " Please choose your movement.\n" << endl;
			cin >> move;
		}
		if (move == 'u' || move == 'U')
		{
			x--;
			if (isSafeMedium(maze, x, y) == true)
			{
				sol[x + 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeMedium(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x++;
			}
		}
		if (move == 'd' || move == 'D')
		{
			x++;
			if (isSafeMedium(maze, x, y) == true)
			{
				sol[x - 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeMedium(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x--;
			}
		}
		if (move == 'r' || move == 'R')
		{
			y++;
			if (isSafeMedium(maze, x, y) == true)
			{
				sol[x][y - 1] = 1;
				score = score + 5;
			}
			else if (isSafeMedium(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y--;
			}
		}
		if (move == 'l' || move == 'L')
		{
			y--;
			if (isSafeMedium(maze, x, y) == true)
			{
				sol[x][y + 1] = 1;
				score = score + 5;
			}
			else if (isSafeMedium(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y++;
			}
		}
		if (x == row - 1 && y == row - 1)
		{
			sol[x][y] = 1;
			system("CLS");
			cout << endl << endl << "Path : " << endl << endl;
			PrintPathMedium(sol, x, y);
			cout << "\n\nCongratulations! The Rat has reached the Destination. You won the Game." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			cout << "\nThe Original Maze was this : " << endl << endl;
			PrintWinMedium(maze, row);
			fout << Name << " : " << score << endl;
			break;
		}
		if (lives == 0)
		{
			system("CLS");
			cout << "\n\nThe Rat is out of Lives! You Lost the Game. Better Luck next time." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			fout << Name << " : " << score << endl;
		}
	}
	cout << "\n\nWould you like to play Again? [Y/N]" << endl;
	cin >> play;
	if (PlayAgain(play) == true)
	{
		system("CLS");
		Game();
	}
	else
	{
		fout.close();
		fin.open(filename);
		Filesize = sizeOfFile(filename);
		names = DmemoryChar(Filesize, 50);
		Score = new int[Filesize];
		Read(names, Score, Filesize, fin);
		cout << "\nHigh Score Table :\n" << endl;
		DescendingSort(names, Score, Filesize);
		write(names, Score, Filesize);
		writeScore(names, Score, Filesize);
		fin.close();
		cout << "\n\nThank You! for playing RAT IN A MAZE!" << endl << endl;
		return;
	}
	return;
}

void PrintPathMedium(int array[6][6], int x, int y)
{
	int flag = 0;
	for (int k = 0; k < 6; k++)
	{
		if (flag == 0)
		{

			cout << char(218) << char(196) << char(196) << char(194);
			for (int i = 0; i <4; i++)
			{
				cout << char(196) << char(196) << char(194);
			}
			cout << char(196) << char(196) << char(191) << endl;
			flag = 1;
		}
		for (int i = 0; i < 6; i++)
		{
			cout << char(179);
			if (x == k && y == i)
			{
				cout << "R";
			}
			else if (array[k][i] == 1)
			{
				cout << "1";
			}
			else if (array[k][i] == 0)
			{
				cout << "0";
			}
			else if (array[k][i] == -2)
			{
				cout << "M";
			}
			else
			{
				cout << " ";
			}
			cout << char(255);
		}
		cout << char(179) << endl;
		cout << char(192) << char(196) << char(196) << char(193);
		for (int i = 0; i < 4; i++)
		{
			cout << char(196) << char(196) << char(193);
		}
		cout << char(196) << char(196) << char(217) << endl;
	}
	return;
}

bool isSafeMedium(int maze[6][6], int x, int y)
{
	if (x >= 0 && x < 6 && y >= 0 && y < 6 && maze[x][y] == 1)
	{
		return true;
	}
	return false;
}

void PrintWinMedium(int array[6][6], int Rows)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl << endl;
	}
}

// Hard Difficulty Program.

void hard()
{
	char Name[50] = { '\0' }, filename[10] = { "score.txt" };
	char move = '\0', play = '\0';
	int maze[8][8] = { { 1, 0, -2, 0, -2, 0, 0, 0 }, { 1, -2, 0, -2, 0, 0, 0, -2 }, { 1, 0, 0, 0, 0, -2, 0, 0 }, { 1, -2, 0, 0, -2, 0, 0, 0 }, { 1, 0, 0, 1, 1, 1, -2, 0 }, { 1, -2, -2, 1, 0, 1, 0, 0 }, { 1, 0, 0, 1, 0, 1, 1, -2 }, { 1, 1, 1, 1, -2, 0, 1, 1 } };
	int row = 8, score = 0, lives = 3, x = 0, y = 0, temp = 0, Filesize = 0;
	int sol[8][8];
	char ** names = NULL;
	int * Score = NULL;
	ofstream fout(filename, ios::app);
	ifstream fin;
	cout << "\n\n\t\t\t\t Please enter your Name : ";
	cin.ignore();
	cin.getline(Name, 50);
	while (lives != 0)
	{
		system("CLS");
		cout << "\t\t\t\t Player Name : " << Name << endl;
		LifeandScore(lives, score);
		cout << "\n Path : " << endl << endl;
		PrintPathHard(sol, x, y);
		Movement();
		cout << "\t\t\t\t\t press P to pause game." << endl;
		cout << "\n\nPlease choose your movement." << endl;
		cin >> move;
		if (move == 'p' || move == 'P')
		{
			while (move == 'p' || move == 'P')
			{
				cout << "\t\t\t\t\tGame Paused! Press S to Start/Resume Game." << endl;
				cin >> move;
				if (move == 's' || move == 'S')
				{
					break;
				}
				else if (move != 'S' || move != 's')
				{
					move = 'p';
				}
			}
		}
		while (move != 'u'&&move != 'U'&&move != 'd'&&move != 'D'&&move != 'l'&&move != 'L'&&move != 'r'&&move != 'R')
		{
			cout << " Please choose your movement.\n" << endl;
			cin >> move;
		}
		if (move == 'u' || move == 'U')
		{
			x--;
			if (isSafeHard(maze, x, y) == true)
			{
				sol[x + 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeHard(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x++;
			}
		}
		if (move == 'd' || move == 'D')
		{
			x++;
			if (isSafeHard(maze, x, y) == true)
			{
				sol[x - 1][y] = 1;
				score = score + 5;
			}
			else if (isSafeHard(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				x--;
			}
		}
		if (move == 'r' || move == 'R')
		{
			y++;
			if (isSafeHard(maze, x, y) == true)
			{
				sol[x][y - 1] = 1;
				score = score + 5;
			}
			else if (isSafeHard(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y--;
			}
		}
		if (move == 'l' || move == 'L')
		{
			y--;
			if (isSafeHard(maze, x, y) == true)
			{
				sol[x][y + 1] = 1;
				score = score + 5;
			}
			else if (isSafeHard(maze, x, y) == false)
			{
				if (maze[x][y] == 0)
				{
					sol[x][y] = 0;
					score--;
					if (score < 0)
					{
						score = 0;
					}
				}
				if (maze[x][y] == -2)
				{
					sol[x][y] = -2;
					score = score - 5;
					if (score < 0)
					{
						score = 0;
					}
					lives--;
				}
				y++;
			}
		}
		if (x == row - 1 && y == row - 1)
		{
			sol[x][y] = 1;
			system("CLS");
			cout << endl << endl << "Path : " << endl << endl;
			PrintPathHard(sol, x, y);
			cout << "\n\nCongratulations! The Rat has reached the Destination. You won the Game." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			cout << "\nThe Original Maze was this : " << endl << endl;
			PrintWinHard(maze, row);
			fout << Name << " : " << score << endl;
			break;
		}
		if (lives == 0)
		{
			system("CLS");
			cout << "\n\nThe Rat is out of Lives! You Lost the Game. Better Luck next time." << endl << endl;
			cout << "\nYour Final Score : " << score << endl << endl;
			fout << Name << " : " << score << endl;
		}
	}
	cout << "\n\nWould you like to play Again? [Y/N]" << endl;
	cin >> play;
	if (PlayAgain(play) == true)
	{
		system("CLS");
		Game();
	}
	else
	{
		fout.close();
		fin.open(filename);
		Filesize = sizeOfFile(filename);
		names = DmemoryChar(Filesize, 50);
		Score = new int[Filesize];
		Read(names, Score, Filesize, fin);
		cout << "\nHigh Score Table :\n" << endl;
		DescendingSort(names, Score, Filesize);
		write(names, Score, Filesize);
		writeScore(names, Score, Filesize);
		fin.close();
		cout << "\n\nThank You! for playing RAT IN A MAZE!" << endl << endl;
		return;
	}
	return;
}

void PrintPathHard(int array[8][8], int x, int y)
{
	int flag = 0;
	for (int k = 0; k < 8; k++)
	{
		if (flag == 0)
		{

			cout << char(218) << char(196) << char(196) << char(194);
			for (int i = 0; i <6; i++)
			{
				cout << char(196) << char(196) << char(194);
			}
			cout << char(196) << char(196) << char(191) << endl;
			flag = 1;
		}
		for (int i = 0; i < 8; i++)
		{
			cout << char(179);
			if (x == k && y == i)
			{
				cout << "R";
			}
			else if (array[k][i] == 1)
			{
				cout << "1";
			}
			else if (array[k][i] == 0)
			{
				cout << "0";
			}
			else if (array[k][i] == -2)
			{
				cout << "M";
			}
			else
			{
				cout << " ";
			}
			cout << char(255);
		}
		cout << char(179) << endl;
		cout << char(192) << char(196) << char(196) << char(193);
		for (int i = 0; i < 6; i++)
		{
			cout << char(196) << char(196) << char(193);
		}
		cout << char(196) << char(196) << char(217) << endl;
	}
	return;
}

bool isSafeHard(int maze[8][8], int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8 && maze[x][y] == 1)
	{
		return true;
	}
	return false;
}

void PrintWinHard(int array[8][8], int Rows)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl << endl;
	}
}