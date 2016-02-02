//  Eric Chu
//  main.cpp
//  Battleship
//  Final Project: BattleShip
#include "PointCollection.cpp"
#include "Ship.cpp"
#include "Board.cpp"
#include <iostream>

using namespace std;

int main() {
  srand(time(0)); // getting system time at runtime
  int oneOrTwo;
  char playAgain;
  do
  {
    cout << "Choose 1 or 2 player game: ";
    cin >> oneOrTwo;
  }while(oneOrTwo != 1 && oneOrTwo !=2);
  
  switch(oneOrTwo)
  {
    case 1:       
          playAgain = 'n';
          do
          {
           Board b = Board();
           int x, y;  
           cout << "\nWelcome to Battleship.\n";  
            do   
            {
             b.display();
             cout << "Enter coordinates ex. 5 7: ";
             cin >> x;
             cin >> y;
             b.fireShot(x,y)?cout << "You hit a ship!\n": cout << "Splashes...\n";
            } while(b.unsunkShipCount() < 4);
        
            cout << "All ships sunk. Good job Admiral.\n";
            cout << "Would you like to play again? (y/n): ";
            cin >> playAgain;
          }while(playAgain == 'y' || playAgain =='Y');
          break;
     case 2:
          playAgain ='n';
          do
          {
            Board player = Board();
            Board computer = Board();
            int x, y, xC, yC;
            cout << "\nWelcome to Battleship VS Computer!\n";
            do
            {
              cout << "Your board\n";
              player.display();
              cout << "\nThe computer's board.\n";
              computer.display();
              cout << "Enter coordinates ex. 5 7: ";
              cin >> x;
              cin >> y;
              player.fireShot(x,y)?cout << "You hit a ship!\n": cout << "Splashes...\n";
              xC = rand()%10;
              yC = rand()%10;
              computer.fireShot(xC,yC)?cout << "Your ship has been hit!\n": cout <<"Splashes...\n";
            } while(player.unsunkShipCount() < 4 && computer.unsunkShipCount() < 4 ); 
            (player.unsunkShipCount() > computer.unsunkShipCount())?cout << "You sank all his battleships! Congratulations Admiral!\n": cout <<"You have been defeated!\n";
             cout << "Would you like to play again? (y/n): ";
             cin >> playAgain;
           }while(playAgain=='y' || playAgain=='Y');   
  }            
              
//system("PAUSE");
return 0;
}





