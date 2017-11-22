#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "judge.h"

using namespace std;

void menu();

int main(){
  int option, type;
  string name;
  Judge controller;
  while(true){
    menu();
    cin >> option;
    system("clear");
    switch(option){
      case 1:
        // nowa gra
		cout << "1. Player vs. Player \n";
        cout << "2. Player vs. Computer \n";        
		cin >> type;
        system("clear");
        controller.newGame(type);
	      break;
      case 2:
        // wczytaj grę
        controller.loadGame("last.sav");
        break;
      case 3:
        // statystyki
        controller.stats();
        break;
      case 4: {
          ifstream manual("manual.txt");
          string line;
          while(getline(manual, line)) cout << line << '\n';
          cout << "\n\nPress ENTER to continue...";
          cin.get();
          cin.get();
          system("clear");
        }
        break;
      case 5:
        return 0;
	      break;
      default:
        cout << "There is no such option! \n";
        continue;
    }
  }
  return 0;
}

void menu(){
cout << "======== SHIPS ======= \n";
  cout << "1. New game \n";
  cout << "2. Load the game \n";
  cout << "3. Statistics \n";
  cout << "4. Manual \n";
  cout << "5. Finish \n";
}
