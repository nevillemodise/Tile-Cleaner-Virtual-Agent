
#include <iostream>

#include <stdlib.h>

#include <time.h>

using namespace std;
//The environment is a 2D grid. That's why there are rows and columns
char enviro[100][100];
int g_r, g_c,num_dirt;
void agent(int, int);

void direct(int do_now, int x, int y) {
  // Reports the movement of the cleaner.
  // The agent can go north, south, east, and west.
  // The cleaner chooses randomly the next move.
  switch (do_now) {
  case 1:
    x--;
    cout << "\nMoving North\n\n";
    break;
  case 2:
    y++;
    cout << "\nMoving East\n\n";
    break;
  case 3:
    y--;
    cout << "\nMoving West\n\n";
    break;
  case 4:
    x++;
    cout << "\nMoving South\n\n";
    break;
  }

  agent(x, y);
}
int moving(int do_now, int x, int y) {

  switch (do_now) {
  case 1:
    x--;
    break;
  case 2:
    y++;
    break;
  case 3:
    y--;
    break;
  case 4:
    x++;
    break;
  }
  if (x > 0 && x <= g_r && y > 0 && y <= g_c) {
    return true;
  }
  return false;
}
void show_tiles() {
  int a = 0;
  while (a < g_r) {
    a++;
    int b = 0;
    while (b < g_c) {
      b++;
      cout << "  " << enviro[a][b];
    }
    cout << endl;
  }
}

int clean_done() {
  int a = 0;
  while (a < g_r) {
    a++;
    int b = 0;
    while (b < g_c) {
      b++;
      if (enviro[a][b] == 'X')
        return false;
    }
  }
  //When the agent has done it's job and finished cleaning, this will be displayed.
  cout << "\nThe tiles are now fully cleaned.\n\n";
  return true;
}

void clean_up(int dirty, int x, int y) {
  //The agent can sense the environment and will clean the dirty tiles.
  if (enviro[x][y] == 'X') {
    cout << "\nCleaning the dirt\n\n";
    enviro[x][y] = 'O';
    agent(x, y);
  } else {
    int do_now = rand() % 4 + 1;

    while (!moving(do_now, x, y)) {
      do_now = rand() % 4 + 1;
    }
    //The agent will stop once all the tiles are spotless.
    if (!clean_done())
      direct(do_now, x, y);
  }
}

void agent(int x, int y) {
    //Agent can sense the evironment.
  int dirty = enviro[x][y] == 'X';
  show_tiles();
  //This reports the agent's location while it's moving around.
  cout << "\nThe cleaner is currently at row " << x << " and column " << y << endl;
  clean_up(dirty, x, y);
}
void create_layout() {
    //Initializes the tile environment.
  int loc_dirt = (g_r * g_c) / 2;
  cout << "\nThe tile layout is shown below\n\n";

  int a = 0;
  while (a < g_r) {
    a++;
    int b = 0;
    while (b < g_c) {
      b++;
      enviro[a][b] = 'O';
    }
  }

  // Randomly allots the position of the dirt in the tile layout

  while (loc_dirt > 0) {
    enviro[rand() % g_r + 1][rand() % g_c + 1] = 'X';
    loc_dirt--;
  }

}
int main() {
  char loc, A, B, C, D;
  int x, y,num_dirt;
  // The credentials
  cout << "Name - Neville Modise" << endl;
  cout << "Student number - 201802358" << endl;
  cout << "Programming Assignment " << endl;
  cout << "Tile Cleaner Implementation" << endl;

  cout << "============================" << endl;
  cout << "||  Tile Cleaner ||" << endl;
  cout << "============================" << endl;
  // Takes the user input about layout of the tiles i.e the row and column
  cout << "Enter the number of Rows : ";
  cin >> g_r;
  cout << "Enter the number of Columns : ";
  cin >> g_c;
  create_layout();
  show_tiles();
  cout << "\nO represents the clean tiles & X represents the dirty tiles" << endl;

  // Takes the user input about the starting location of the tile cleaner.
  //There are 4 starting locations namely A, B, C, D

  cout << "\nEnter your starting location to clean up the filthy tiles, A,B,C or D: ";
  cin >> loc;
  if (loc == 'A') {
    x = rand() % g_r + 1;
    y = rand() % g_c + 1;
  } else if (loc == 'B') {
    x = rand() % g_r + 1;
    y = rand() % g_c + 2;
  } else if (loc == 'C') {
    x = rand() % g_r + 2;
    y = rand() % g_c + 1;
  } else if (loc == 'D') {
    x = rand() % g_r + 2;
    y = rand() % g_c + 2;
  } else if (loc != 'A' && loc != 'B' && loc != 'C' && loc != 'D') {
    // If the user enters wrong input this will be displayed
    cout << "\nYou didn't read the instructions!";
    return false;
  };
  agent(x, y);
}
