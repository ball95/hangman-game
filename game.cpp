#include <iostream>
#include <string>

int main()
{
#define DEFAULT // comment this out to choose lives at runtime otherwise default is 7
	
	int lives{ 7 };
	std::wstring word;

	std::wcout << "Enter the word: ";
	std::wcin >> word;

#ifndef DEFAULT
	std::wcout << "Enter the amount of lives you want: ";
	std::wcin >> lives;
#endif

	std::wstring displayedWord(word.size(), '*');

	while (true) {

		static bool correct; // static bool to check if input was correct or not
		static wchar_t input;
		correct = false;


		system("cls");
		std::wcout << " WORD: " << displayedWord << '\n';
		std::wcout << "LIVES: " << lives << '\n';

		// check if win
		if (displayedWord == word) {
			std::wcout << "Fuggoi you winned" << '\n';
			std::cin.get();
			break;
		}

		// check if lives are 0
		if (lives <= 0) {
			std::wcout << "You Lose" << '\n';
			std::wcout << "Word: " << word << '\n';
			std::cin.get();
			break;
		}

		// if lives are above 0 ask for input
		std::wcout << "Guess: ";
		std::wcin >> input;

		// loop through every letter in original word
		for (int i = 0; i < word.size(); ++i) {
			if (input == word[i]) {
				correct = true;
				displayedWord[i] = word[i];
			}
		}

		// clear istream so program doesn't loop again with the next characters in istream if the user input more than one character aye?
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!correct) {
			--lives; // if input did not match any of the letters take away a life
		}

	}

	return 0;
}