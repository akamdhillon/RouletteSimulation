//
//  main.cpp
//  Roulette Simulation
//
//  Created by Akam Dhillon on 2023-03-16.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_BET             60 //Maximum bet based on personal courage
#define MAX_BALANCE_GOAL    400 //Goal to walk out with
#define MAX_LOSS            -50

/*
 Objective:
 - Doubling strategy optimization for roulette casino game
 - Double bet after every loss starting at 5 dollars (minimum in some casino games)
 - Stop playing after reaching desired balance goal
 - Quit playing if balance reaches MAX_LOSS dollars.
 - If current bet reaches the MAX_BET value, then stop doubling it and try to recover
 
 Simulation will try all combinations of what the balance goal should be along with
 what the max bet should be.
 */

int main()
{
    /*
     Seed the rand() function in order to generate a different set of integers each
     time the program is run.
     Using time(NULL), the current time is used for the seed.
     */
    srand(time(NULL));
    
    int randomNum = 0; //random number generated
    int maxWins = 0; //To keep track of max wins for each simulation
    int bestBalanceGoal = 0; //best balance tracker
    int bestMaxBet = 0; //best max bet tracker
    int overallBalance = 0;

    /*
     Simulation uses nested for loops to attempt all combinations of maxBets and
     balance goals
     */
    //starting from minimum bet of 20 dollars to MAX_BET value in increments of 1.
    for (int maxBet = 20; maxBet < MAX_BET; maxBet++) {
        //starting from balance goal of 20 dollars to MAX_BALANCE_GOAL in increments of 1
        for (int balanceGoal = 20; balanceGoal < MAX_BALANCE_GOAL; balanceGoal++) {
            
            uint32_t winCount = 0; //to keep track of wins out of 100
            //Simulate 100 times
            for (int count = 0; count < 100; count++) {
                int balance = 0; // Start at 0 dollars each simulation
                int bet = 5; //Start at 5 dollar bet

                //For while loop
                bool finishedFlag = false;

                while (!finishedFlag) {
                    //Generate number from 0 to 36.
                    randomNum = rand() % 36;
                    //bet current bet value and deduct from balance
                    balance -= bet;

                    //Balance reached worst balance, quit game
                    if (balance < -50) {
                        finishedFlag = true;
                    } else {
                        if (randomNum > 18) { //If number 19-36 then win bet.
                            balance += (bet * 2); //won doubled bet due to odds.
                            bet = 5; //reset bet

                            if (balance > balanceGoal) { //Reached balance goal, cash out
                                winCount++; //win tracker
                                finishedFlag = true; //quit simulation
                            }
                        } else { //Lost bet, double bet
                            bet *= 2;
                            if (bet > maxBet) { //reached maxBet to avoid losing too much
                                bet = maxBet;
                            }
                        }
                    }
                }
                overallBalance += balance;
            }

            //After 100 simulations, check if maxWins is less than current.
            if (winCount > maxWins) {
                //Store best values
                maxWins = winCount;
                bestBalanceGoal = balanceGoal;
                bestMaxBet = maxBet;
            }
        }
    }

    cout << "Max wins: " << maxWins << endl;
    cout << "Best Balance Goal: " << bestBalanceGoal << endl;
    cout << "Best MaxBet: " << bestMaxBet << endl;
    cout << "Overall balance: " << overallBalance << endl;
}

/*
 Console Output:
 Max wins: 65
 Best Balance Goal: 20
 Best MaxBet: 20
 Overall balance: -73871441
 Program ended with exit code: 0
 */

/*
 Casino games are impossible to beat mathematically
 with the max wins of 65, we see a 65% chance of 'winning' where:
 the balance goal should be to walk out with $2 and never betting higher than $20.
 */
