#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string> 
#include <time.h>
#include <windows.h>
using namespace std;

const int width = 20, height = 20;
int i, j, score = 0;
string arr[20][20];
enum edirection { stop = 0, LEFT, RIGHT, UP, DOWN };
edirection dir;
bool gameover;
string o = "o";
int fruitx, fruity, dirx = 10, diry = 10;


void Setup() {
	gameover = false;
	dir = stop;
	fruitx = rand() % width;
	fruity = rand() % height;
}

void draw() {
	system("cls");
	for (j = 0; j < 20; j++) {
		*(*(arr + 0) + j) = "* ";
		cout << *(*(arr + 0) + j);
	}
	cout << endl;

	for (i = 1; i < 19; i++) {
		for (j = 0; j < 20; j++) {
			if (j == 0 || j == 19) {
				*(*(arr + i) + j) = "* ";
				cout << *(*(arr + i) + j);
			}

			else if (i == diry && j == dirx) {
				*(*(arr + i) + j) = "O ";
				cout << *(*(arr + i) + j);
			}

			else if (i == fruity && j == fruitx)
				cout << "& ";

			else cout << "  ";
		}
		cout << endl;
	}

	for (j = 0; j < 20; j++) {
		*(*(arr + 19) + j) = "* ";
		cout << *(*(arr + 19) + j);
	}
	cout << endl;
	cout << "score= " << score << endl;
}


void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'x':
			gameover = true;
			break;

		}
	}
}

void check() {
	if (diry == 0 || diry == 19 || dirx == 0 || dirx == 19) { cout << "Game Over :(" << endl << "Please try again"; gameover = true; }
	else if (diry == fruity && dirx == fruitx) {
		fruitx = (rand() % (width - 1));
		fruity = (rand() % (height - 1));
		if (fruitx == 0)
			fruitx++;
		if (fruity == 0)
			fruity++;
		*(*(arr + dirx) + diry) += o;
		score += 10;

	}
}

void logic() {

	switch (dir) {

	case LEFT:
		dirx--;
		check();
		break;
	case RIGHT:
		dirx++;
		check();
		break;
	case UP:
		diry--;
		check(); 
		break;
	case DOWN:
		diry++;
		check();
		break;
	default:
		break;
	}
}
void menu() {
	while (!gameover) {
		cout << "Enter the number for level: " << endl;
		cout << "1_level 1:500(lowest)" << endl;
		cout << "2_level 2:300" << endl;
		cout << "3_level 3:200" << endl;
		cout << "4_level 4:100" << endl;
		cout << "5_level 5:50" << endl;
		cout << "6_level 6:10(fastest)" << endl;
		int t;
		cin >> t;
		if (t == 1) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(500);
				if (score == 50) { cout << "You finished Level 1 successfully :)" << endl; break; }
			}
		}
		else if (t == 2) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(300);
				if (score == 100) { cout << "You finished Level 2 successfully :)"<<endl; break; }
			}
		}
		else if (t == 3) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(200);
				if (score == 150) { cout << "You finished Level 3 successfully :)"<<endl; break; }
			}
		}
		else if (t == 4) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(100);
				if (score == 200) {
					cout << "You finished Level 4 successfully :)"<<endl; break;
				}
			}
		}
		else if (t == 5) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(50);
				if (score == 250) { cout << "You finished Level 5 successfully :)"<<endl; break; }
			}
		}
		else if (t == 6) {
			cout << endl;
			system("CLS");
			Setup();
			while (!gameover) {
				draw();
				input();
				logic();
				Sleep(10);
				if (score == 350) { cout << "you have successfully completed all levels :)" << endl;  break; }
			}
		}
	}
	
}
void start() {
	cout << "Welcome to the game!" << endl << "Press 'S' key to start" << endl;
	char in;
	cin >> in;
	if (in == 's' || in == 'S') {
		system("CLS");
		cout << endl;
		menu();
	}
}
int main() {
	start();
	//Noha Maen Thaher          11819551
	//Mohammad Mustafa Khamlan  11819287
	//Aya Yahya Jammal          11820506
}