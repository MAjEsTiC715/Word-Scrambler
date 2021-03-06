// Keywords.cpp : Defines the entry point for the console application.
// Documentation
/* Choose 10 single code words of your choice, and write down a hint for each word.
Create a new C++ project called Keywords
This Code Breaker Training Simulation Program should give the user directions and
Tell them what it is and how to use it based of the background description above.
Then your Code Breaker Training Simulation Program should randomly select 3 of 
The 10 words that are coded in your program.
Your code breaker will scramble each word on the fly and different each run randomly.
Now make the user try to solve each one of the three randomly picked coded word from your random list.
Each turn you should give your user feedback on if they got the guess correct or not.
You should also offer the user help.
At the end, you should display their stats and ask if they would like to try again.*/

#include "stdafx.h"
#include <iostream> // Allows for input and output
#include <string> // Allows the string object
#include <cstdlib> // Allows us to generate psuedo random numbers
#include <ctime> // Allows the object time

using namespace std;

int main()
{
	/* We declare and initialize a two-dimensional array with words and corrosponding hints.
	   The enumeration defines enumerators for accessing the array.
	   WORDS[x][WORD] is one of the words. WORDS[x][HINT] is the corrosponding hint.*/
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"connection", "If you have wifi then you are constantly checking this."},
		{"transfer", "Move from one place to another."},
		{"remember", "Keep digging into your brain, it will come to you."},
		{"friday", "This is the greatest day to a high schooler."},
		{"summary", "Keep it brief"},
		{"priority", "This should always come first."},
		{"waiver", "Hopefully you don't have to sign one of these."},
		{"transcript", "Super important that you get into a good college"},
		{"winter", "The coldest season."},
		{"registration", "This would show that you are accepted."}
	};

	cout << "\t\t\tWelcome to Word Jumble\n\n";
	cout << "unscramble the letters to make a word.\n";
	cout << "enter 'hint' for a hing.\n";
	cout << "enter 'skip' to skip.\n\n";

	int start = 1; // loop sentinel
	int answered = 0; // Counts the amount of answered scrambled words
	int guessCounter = 0; // Counts the amount of guesses the user tried

	while (start == 1)
	{
		/* We generate a random index based on the number of words
		   In the array. Then we assign both the random word at the 
		   Index and its corresponding hint to the variables theWord
		   And theHint.*/

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD]; // Word to guess
		string theHint = WORDS[choice][HINT]; // hint for word

		/* To jumble the words we generate two random positions in the
		   String object and swapped the characters at those positions.
		   We did this a number of times equal to the length of the word.*/ 

		string jumble = theWord; // Jumbled version of word
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "the jumble is: " << jumble;

		string guess;
		cout << "\n\nYour guess: "; // Ask user to answer, if wrong this starts the while loop
		cin >> guess;

		/* The loop continues to ask the player for a guess until the
		   Player either guesses the word or asks to skip.
		   Each guess is recorded by adding 1 to the variable guessCounter
		   Each time the player gets a word correct it is added to
		   The variable answered and once that equals 3 we then ask
		   The player if they like to play again. If so reset variables
		   Anything but 1 exits the loop*/

		while ((guess != theWord) && (guess != "skip"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, that's not it.";
				guessCounter++;
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "\nThat's it! You guessed it!\n";
			answered++;
		}

		if (answered == 3)
		{
			cout << "\nIt took you " << guessCounter << " tries to answer 3 scrambled words.";
			cout << "\nWould you like to play again? 1 to play again; 0 to leave";
			cin >> start;
			answered = 0;
			guessCounter = 0;
		}
	}
	cout << "\nThanks for playing.\n";

	return 0; // End
}