
#include <iostream>
#include <vector>
#include <fstream>
#include "Header.h"
#include "Laba4-Dice.h"

using namespace std;

int main()
{

    Dice dice1(1, 6, 0);
    vector<int> diceResult1(dice1.getDiceFaces() * dice1.getDiceThrowNumber() + dice1.getDiceModifire(), 0);

    for (size_t i = 0; i < 1000; i++) {
        diceResult1[dice1.ThrowDice() - 1]++;
    }

    cout<<dice1.getDiceThrowNumber()<<"d"<<dice1.getDiceFaces()<<"+"<<dice1.getDiceModifire()<<": ";
    cout << endl;

    for (int i = dice1.getDiceThrowNumber()+ dice1.getDiceModifire() -1; i < diceResult1.size(); i++) {
        cout << diceResult1[i] << endl;
    }

    cout << endl;

    
    Dice dice2(2, 6, 2);
    vector<int> diceResult2(dice2.getDiceFaces() * dice2.getDiceThrowNumber() + dice2.getDiceModifire(), 0);

    for (size_t i = 0; i < 1000; i++) {
        diceResult2[dice2.ThrowDice() - 1]++;
    }

    cout << dice2.getDiceThrowNumber() << "d" << dice2.getDiceFaces() << "+" << dice2.getDiceModifire() << ": ";
    cout << endl;

    for (int i = dice2.getDiceThrowNumber() + dice2.getDiceModifire() - 1; i < diceResult2.size(); i++) {
        cout << diceResult2[i] << endl;
    }

    cout << endl;


    Dice dice3(3, 6, 0);
    Dice dice4(1, 10, 0);

    vector<Dice> numberOfDices1{dice3, dice4};


    for (int i = 0; i < numberOfDices1.size(); i++) {

        vector<int> diceResult(numberOfDices1[i].getDiceFaces() * numberOfDices1[i].getDiceThrowNumber() + numberOfDices1[i].getDiceModifire());

        for (int j = 0; j < 1000; j++) {
            diceResult[numberOfDices1[i].ThrowDice() - 1]++;
        }

        cout << numberOfDices1[i].getDiceThrowNumber() << "d" << 
            numberOfDices1[i].getDiceFaces() << "+" << numberOfDices1[i].getDiceModifire() << ": ";
        cout << endl;

        for (int k = numberOfDices1[i].getDiceThrowNumber() + numberOfDices1[i].getDiceModifire() -1; 
            k < diceResult.size(); k++) {
            cout << diceResult[k] << endl;
        }

        diceResult.clear();

        cout << endl;

    }

    Dice dice5(2, 10, 3);
    Dice dice6(3, 10, 0);

    vector<Dice> numberOfDices2{ dice5, dice6 };


    for (int i = 0; i < numberOfDices2.size(); i++) {

        vector<int> diceResult(numberOfDices2[i].getDiceFaces() * numberOfDices2[i].getDiceThrowNumber() + numberOfDices2[i].getDiceModifire());

        for (int j = 0; j < 10000; j++) {
            diceResult[numberOfDices2[i].ThrowDice() - 1]++;
        }

        cout << numberOfDices2[i].getDiceThrowNumber() << "d" <<
            numberOfDices2[i].getDiceFaces() << "+" << numberOfDices2[i].getDiceModifire() << ": ";
        cout << endl;

        for (int k = numberOfDices2[i].getDiceThrowNumber() + numberOfDices2[i].getDiceModifire() - 1;
            k < diceResult.size(); k++) {
            cout << diceResult[k] << endl;
        }

        diceResult.clear();

        cout << endl;

    }

}


