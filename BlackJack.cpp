#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
  int sum = 0;
  bool start = true; // starts the game
  int i = 0; // keeps track of Game number
  int wins = 0;
  int loss = 0;
  int ties = 0;


  while(start){
    int randomNum = 1 + (rand () % 13); // random number from 1-13
    bool fold = false;

    printf("START GAME # %d \n\n", ++i);
    if(randomNum == 1){
    printf("Your card is an ACE! \n" );
    sum = 1;
    printf("Your hand is: %d\n\n" , sum);
  }
  if(randomNum == 11){
  printf("Your card is a JACK! \n" );
  sum = 10;
  printf("Your hand is: %d\n\n" , sum);
  }
  if(randomNum == 12){
    printf("Your card is a QUEEN! \n" );
    sum = 10;
    printf("Your hand is: %d\n\n" , sum);
  }
  if(randomNum == 13){
    printf("Your card is a KING! \n" );
    sum = 10;
    printf("Your hand is: %d\n\n" , sum);
  }


    while(sum < 21 && !fold){
      int secRandNum = 1 + (rand () % 13); // random number from 1-13
      int dealerNum = 16 + (rand() % 11); // random number from 16 - 26
      int totalGames = wins + ties + loss;

      cout << "1. Get another card" << endl;
      cout << "2. Hold hand" << endl;
      cout << "3. Print statistics" << endl;
      cout << "4. Exit\n" << endl;

      cout << "Chose an option: " << endl;

      int option;

      cin >> option;
      if(cin.fail()){ // only enters loop if cin isn't an int
      while(!(cin >> option)){ // will loop until cin = a int
        cout << "ERROR: Please enter a valid integer!\n" << endl;
        cout << "Chose an option: " << endl;
        cin.clear();
        cin.ignore(132, '\n'); // skips to next line
      }
    }


      switch(option){
        case 1:
        if(secRandNum == 1){
          printf("Your card is a ACE! \n");
          sum += 1;
          printf("Your hand is: %d \n\n" , sum);
        }
        if(secRandNum == 11){
          printf("Your card is a JACK! \n");
          sum += 10;
          printf("Your hand is: %d \n\n" , sum);
        }
        if(secRandNum == 12){
          printf("Your card is a QUEEN! \n");
          sum += 10;
          printf("Your hand is: %d \n\n" , sum);
        }
        if(secRandNum == 13){
          printf("Your card is a KING! \n");
          sum += 10;
          printf("Your hand is: %d \n\n" , sum);
        }
        if(secRandNum != 1 && secRandNum < 11){
          printf("Your card is a %d! \n" , secRandNum);
          sum += secRandNum;
          printf("Your hand is: %d \n\n", sum);
        }
        if (sum == 21){
          printf("BLACK JACK YOU WIN!!! \n\n");
          wins++;
          fold = true;
        }
        if(sum > 21){
          printf("YOU EXCEEDED 21 YOU LOSE!!! \n\n");
          loss++;
          fold = true;
        }
        break;

        case 2:
        printf("Dealers hand: %d\n", dealerNum);
        printf("Your hand is: %d \n\n", sum);

        if(dealerNum == 21){
          printf("YOU LOSE!! \n\n");
        }

        if(dealerNum > 21){
          printf("YOU WIN!! \n\n");
          wins++;
        }
        if(dealerNum < 21 && dealerNum > sum){
          printf("YOU LOSE!! \n\n");
          loss++;
        }
        if(dealerNum == sum){
          printf("WHAT?!?! IT'S A TIE!!\n\n");
          ties++;
        }
        if (sum < 21 && sum > dealerNum){
          printf("NOICE YOU WIN! \n\n");
          wins++;
        }
        fold = true;
        break;

        case 3:
        printf("Number of Player wins: %d \n", wins);
        printf("Number of dealer wins: %d \n", loss);
        printf("Number of tie games: %d \n", ties);
        printf("Total # of games played is: %d \n", wins + ties + loss);
        printf("Precentage of Player wins: %f%% \n\n", ((double)(wins) /(double)(totalGames) * 100) );
        break;

        case 4:
        printf("Thanks for playing! \n");
        fold = true;
        start = false;
        break;

        default:
        printf("ERROR: Please enter a valid integer!\n\n");
        cin.clear();
        break;
      }
    }
  }

  return 0;
}
