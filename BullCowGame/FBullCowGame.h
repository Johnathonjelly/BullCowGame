#pragma once
#include <string>

using int32 = int;
using FString = std::string;


//all values init to 0
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	OK,
	Not_Isogram,
	Incorrect_Length,
	No_Symbols_Or_Numbers,
	Not_Lowercase,
	Invalid
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValid(FString) const;

	void Reset();
	void PrintGameSummary();
	//count bulls and cows and increase try # assuming valid guess
	FBullCowCount SubmitValidGuess(FString);




	


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsLowercase(FString) const;
	bool IsIsogram(FString) const;
};