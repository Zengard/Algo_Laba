#pragma once
#include <iostream>
#include <vector>
#include <fstream>
class Dice 
{
public:
	Dice(int numberOfDices, int diceFacet, int modifier);

	int getDiceThrowNumber() { return dice_ThrowNumber; }

	int getDiceFaces() { return dice_Face; }

	int getDiceModifire() { return dice_modifier; }



	int ThrowDice() {
		int result = 0;

		for (int i = 0; i <getDiceThrowNumber(); i++) {
			result += rand() % getDiceFaces() + 1;
		}

		result += getDiceModifire();
		return result;
	}

private:
	int dice_ThrowNumber;
	int dice_Face;
	int dice_modifier;
};

Dice::Dice(int numberOfThrow,int diceFace, int modifier = 0) : dice_ThrowNumber(numberOfThrow), dice_Face(diceFace), dice_modifier(modifier)
{

}

