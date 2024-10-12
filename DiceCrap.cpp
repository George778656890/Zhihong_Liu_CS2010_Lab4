//Dice game---Craps
#include <iostream>
#include<string>
#include<vector>
#include<iterator>
#include<type_traits>
#include<iterator>
#include<algorithm>
#include<utility>
#include<fstream>
#include<cstdlib>
#include <thread> // Required for sleep_for  
#include <chrono> // Required for milliseconds


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::ostream;
using std::pair;

//Function prototype
void playGame();
int die();
void checkBalance();
void continueRolling();

int diceSum = 0;
int balance = 100;
int wager = 0;
int point = 0;

const int winSum7 = 7, winSum11 = 11;
const int loseSum2 = 2, loseSum3 = 3, loseSum12 = 12;
const int pointSum4 = 4, pointSum5 = 5, pointSum6 = 6, pointSum8 = 8, pointSum9 = 9, pointSum10 = 10;
const int losePointSum7 = 7;


int main() {
    char ans;
    bool done = false;
    while (!done) {
        playGame();   
        cout << " Play again (y/n) ? ";
        cin >> ans;
        if (ans == 'n' || ans == 'N') done = true;
        else done = false;
    }
    
    return 0;
}



int die() {
    // Seed the random number generator  
    srand(static_cast<unsigned int>(time(0)));

    return (rand() % 6) + 1;

}

void playGame() {
    cout << "You have " << balance << " credits. How much do you wager?";
    cin >> wager;
    while (wager>balance) {
        cout << "your wager exceeds your balance. Try again.\nHow much do you wager ?";
        cin >> wager;
    }
    balance -= wager;

    int die1 = die();

    // Create a delay to generate two different random numbers  
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    int die2 = die();
    diceSum = die1 + die2;

    switch (diceSum) {
    case winSum7 : 
    case winSum11: {
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << endl << "player wins\n";
        balance = balance + wager + wager;
        cout << "you won " << wager << " credits. Your new balance is " << balance << " credits\n\n";
        break;
    }

    case loseSum2:
    case loseSum3:
    case loseSum12: {
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << endl << "player loses\n";
        cout << "you lost " << wager << " credits. ";
        checkBalance();
        cout<<"Your new balance is " << balance << " credits\n\n";
        break;
    }
    case pointSum4:{
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum << "\n\n";
        point = diceSum;
        continueRolling();
        break;
    }
    case pointSum5:{
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum << "\n\n";
        point = diceSum;
        continueRolling();
        break;
    }
    case pointSum6:{
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum << "\n\n";
        point = diceSum;
        continueRolling();
        break;
    }
    case pointSum8:{
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum << "\n\n";
        point = diceSum;
        continueRolling();
        break;
    }
    case pointSum9:{
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum<<"\n\n";
        point = diceSum;
        continueRolling();
        break;
    }
    case pointSum10: {
        cout << "player rolled " << die1 << "+" << die2 << "=" << diceSum << "\npoint is " << diceSum << "\n\n";
        point = diceSum;
        continueRolling();
        break;
    }

    }

}

void checkBalance() {
    if (balance == 0) {
        cout << "You are out of credits - gameover!";
        exit(0);
    }
}

void continueRolling() {
    int die3 = 0;
    int die4 = 0;
    int sum = 0;

    while (sum != point && sum != losePointSum7) {
        die3 = die();

        // Create a delay to generate two different random numbers  
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        die4 = die();
        sum = die3 + die4;
        cout << "player rolled " << die3 << "+" << die4 << "=" << sum << endl;
    }

    if (sum == point) {
        cout << "player wins\n";
        balance = balance + wager + wager;
        cout << "you won " << wager << " credits. Your new balance is " << balance << " credits\n\n";
        
    }
    else if (sum == losePointSum7) {
        cout << "player loses\n";
        cout << "you lost " << wager << " credits. ";
        checkBalance();
        cout << "Your new balance is " << balance << " credits\n\n";
        
    }
}
