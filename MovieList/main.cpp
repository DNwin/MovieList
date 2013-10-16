#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct MovieNode
{
	string title;
	string actor1;
	string actor2;
	string genre1;
	string genre2;
	int year;
	int rating;
	string plot;
};


void WordWrap(string inputString);



int main()

{


	string title = "Pirates of the Caribbean 1: The Curse of the Black Pearl";
	string actor1 = "Johnny Depp";
	string actor2 = "Orlando Bloom";
	string genre1 = "Action";
	string genre2 = "Action";
	int year = 2003;
	int rating = 8;
	string plot = "This swash-buckling tale follows the quest of Captain Jack Sparrow, a savvy pirate, and Will Turner, a resourceful blacksmith, as they search for Elizabeth Swann. Elizabeth, the daughter of the governor and the love of Will's life, has been kidnapped by the feared Captain Barbossa. Little do they know, but the fierce and clever Barbossa has been cursed. He, along with his large crew, is under an ancient curse, doomed for eternity to neither live, nor die. That is, unless a blood sacrifice is made. Full of edge-of-the-seat action and swashbuckling adventures, this is a movie you won't want to miss!";

	int movieCnt = 10;

	// Line 1 - Horizonal line of asterisks
	cout << setfill('*') << setw(75) << '*' <<  setfill(' ') << endl;
	// Line 2 - Movie number and Title
	cout << "MOVIE #: " << left << setw(9) << movieCnt << "Title: ";
	// IF ELSE - Output "..." if title is longer than 50 chars.
	if (title.length() > 50)
	{
		cout << title.substr(0,44) << " ..." << endl;
	}
	else
	{
	cout << title << endl;
	}
	// Line 3 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 4 - Year and Rating
	cout << "Year: " << setw(12) << year << "Rating: " << rating << endl;
	// Line 5 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 6 & 7 - Actors and genres
	cout << setw(18) << "Leading Actor:" << setw(25) << actor1 
		 << "Genre 1: " << genre1 << endl;
	cout << setw(18) << "Supporting Actor:" << setw(25) << actor2 
		 << "Genre 2: " << genre2 << right << endl;
	// Line 8 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 9+ - Plot
	cout << "PLOT:" << endl;
	// WordWrap - Output formatted plot string followed by horizonal line
	WordWrap(plot);
	cout << setfill('*') << setw(75) << '*' <<  setfill(' ') << endl;
	




}


void WordWrap(string inputString)
{
	const int MAX_LENGTH = 75;
	string line;
	string word;
	int index;
	
	word = "";
	line = "";

	for (index = 0; index < inputString.length(); index++)
	{
		// Add each character to word if it is not a space.
		if (inputString[index] != ' ')
		{
			word += inputString[index];
		}

		// ELSE - Executes when a full word is stored.
		else
		{
			// OUT - Output if the line + word exceeds max length
			if (line.length() + word.length() > MAX_LENGTH)
			{
				cout << line << endl;
				line.clear();
			}

			// Add the word to the line if less than max length
			line += word + " ";
			word.clear();
		}
	}

	// OUT - Add very last word to the line and output the last line.
	line += word;
	cout << line << endl;

}