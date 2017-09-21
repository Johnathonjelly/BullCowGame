#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "ant";
	constexpr int32 MAX_TRIES = 8;

	bGameIsWon = false;
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

void FBullCowGame::PrintGameSummary()
{
	if (IsGameWon())
	{
		std::cout << "Great job! You won the game!\n";
		std::cout << "You ended the game on try " << MyCurrentTry - 1 << ".\n";
	}
	else {
		std::cout << "Better luck next time.\n";
	}

}




//recieves valid guess increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

											  // loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter strings as IsoGrams
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup map
	for (auto Letter : Word) //for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed case words
		if (LetterSeen[Letter]) { return false; }
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word)
		 {
		if (!islower(Letter)) // if not a lowercase letter
			 {
			return false;
			}
		}
	return true;
	}




EGuessStatus FBullCowGame::CheckGuessValid(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	} 
	else if (Guess.length() != GetHiddenWordLength()) 
	{
		return EGuessStatus::Incorrect_Length;
	}
	else if (Guess.find('0') != std::string::npos ||
		Guess.find('1') != std::string::npos ||
		Guess.find('2') != std::string::npos ||
		Guess.find('3') != std::string::npos ||
		Guess.find('4') != std::string::npos ||
		Guess.find('5') != std::string::npos ||
		Guess.find('6') != std::string::npos ||
		Guess.find('7') != std::string::npos ||
		Guess.find('8') != std::string::npos ||
		Guess.find('`') != std::string::npos ||
		Guess.find('~') != std::string::npos ||
		Guess.find('!') != std::string::npos ||
		Guess.find('@') != std::string::npos ||
		Guess.find('#') != std::string::npos ||
		Guess.find('$') != std::string::npos ||
		Guess.find('%') != std::string::npos ||
		Guess.find('^') != std::string::npos ||
		Guess.find('&') != std::string::npos ||
		Guess.find('*') != std::string::npos ||
		Guess.find('(') != std::string::npos ||
		Guess.find(')') != std::string::npos ||
		Guess.find('-') != std::string::npos ||
		Guess.find('=') != std::string::npos ||
		Guess.find('+') != std::string::npos ||
		Guess.find('/') != std::string::npos ||
		Guess.find('*') != std::string::npos)
	{
		return EGuessStatus::No_Symbols_Or_Numbers;
	}
	else
	{
		return EGuessStatus::OK;
	}


}

