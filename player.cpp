#include "player.h"
#include <cstdlib>
#include <ctime>

// zapisywanie danych gracza do strumienia
ostream & operator<<(ostream & os, const Player & p){
  os << p.name << ' ' << p.moves <<  ' ' <<
    p.hits << ' ' << p.misses << ' ' << p.ships << '\n';
  os << p.my << p.enemy;
  return os;
}

// wczytywanie danych gracza ze strumienia
istream & operator>>(istream & is, Player & p){
  is >> p.name >> p.moves >> p.hits >> p.misses >> p.ships;
  is >> p.my >> p.enemy;
  return is;
}

// ruch czlowieka
int HumanPlayer :: move () {
  int x, y;
  // show the player info
  cout << "Player's movement" + name << '\n';
  cout << "Hit:" << hits << ", losses =" << 20 - ships << "\n\n";
  cout << "Your ships: \n\n";
  cout << my << '\n';
  cout << "\n\nYour moves: \n\n";
  cout << enemy << '\n';
  // Ask for coherent fields
  do {
    cout << "Please enter the following (x y):";
    if (! (cin >> x >> y)) {// give a different character than the number
      cin.clear (); // we clean the stream
      cin.ignore (); // ignore the rest of the characters
      return -1; // information about game break
    }
    // Repeat this until the player enters the correct field
  } while (! (x <10 && x>= 0 && y <10 && y>= 0) || enemy.get (x * 10 + y) == '0' || enemy.get (x * 10 + y) == 'X');
  ++ moves; // increase the number of moves
  cout << '\n';
  return x * 10 + y; // return the field number
}

// ruch gracza komputerowego
int ComputerPlayer::move(){
  srand(time(0)); // nowe ziarno losowosci
  int x;
  std::cout << enemy << '\n';
  do {
    x = rand() % 100;
    // losuj az trafi na niesprawdzone pole
  } while(enemy.get(x) == '0' || enemy.get(x) == 'X');

  ++moves; // zwieksz liczbe ruchow
  return x; // zwroc numer pola
}

// sprawdzanie pola przeciwnika
bool Player::check(int t) {
  if(my.get(t) == '#'){ // jesli trafiono statek
    my.set(t, 'X'); // oznaczamy 'trafienie'
    --ships; // zmniejsz liczbe statkow
    return true; // true - trafiony
  } else {
    my.set(t, '0'); // oznaczamy 'pudlo'
  }
  return false; // false - pudlo
}
