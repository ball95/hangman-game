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

	while (lives > 0) {
		system("cls");
		std::wcout << " WORD: " << displayedWord << '\n';
		std::wcout << "LIVES: " << lives << '\n';

		static bool correct; // static bool to check if input was correct or not
		correct = false;

		static wchar_t input; 
		std::wcout << "Guess: ";
		std::wcin >> input;

		for (int i = 0; i < word.size(); ++i) {
			if (input == word[i]) {
				correct = true;
				displayedWord[i] = word[i];
			}
		}

		if (!correct) {
			--lives; // if input did not match any of the letters take away a life
		}

	}

	return 0;
}