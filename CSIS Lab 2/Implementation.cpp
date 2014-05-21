/*
	@Author  - John Allard
	@Date    - March 19th, 2014
	@Purpose - This is the implementation file for Laboratory #2 for CSIS 212 at Glendale Community College.
	This function generates a randomized set of 1,000 words or length 5 characters each. It then has this list sorted
	via RadixSort, and counts the operations that this takes.
	It then passes the same list of randomized words to the LinkedListSort function, which sorts the words and counts
	how many operations this takes. It outputs this information to the standard output for the user to see.
*/

#include <iostream>
#include <ctime>

#include "MyRadixSort.h"
#include "LinkedListSort.h"

std::string * generateWords(int numwords, int wordlength, int seed); // generates the random list of words
void printWords(std::string *, int length, bool onlyFirstAndLast10); // prints an array of strings
void printWords(std::vector<std::string>, bool onlyFirstAndLast10);  // prints a vector of strings

int main()
{
	const int NUM_WORDS = 1000;  // number of words to be sorted
	const int WORD_LENGTH = 5;   // length of each word
	int seed = time(NULL);		 //change the randomization seed here

	// this reference integer will be used to count the number of operations performed in the sorting functions
	int count = 0;
	int & mycount = count;

	//generate the list of random words
	std::string * unsortedList = generateWords(NUM_WORDS, WORD_LENGTH, seed);

	//print the unsorted list of words.
	std::cout << "\nUnsorted Word List : \n";
	printWords(unsortedList, NUM_WORDS, false);
	system("pause");

	// sort the list of words using radix sort
	std::vector<std::string> sortedListRadix;
	try
	{
		sortedListRadix = RadixSort(unsortedList, NUM_WORDS, 'a', 'z', count);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	
	//print the sorted list of words.
	std::cout << "\nRadixSort Sorted WordList : \n";
	printWords(sortedListRadix, false);

	//print the number of operations that RadixSort took to sort the list
	std::cout << "RadixSort Operation Count : " << mycount << "\n\n";
	system("pause");
	std::cout << "\n\n\n";


	count = 0; // reset the operation counter variable to zero to be used again in LinkedListSort

	//sort the list of words using the linked list sort method
	std::vector<std::string> sortedLinkedList = LinkedListSort(unsortedList, NUM_WORDS, count);

	// print out the sorted list of words
	std::cout << "\nLinkedListSort Sorted Word List : \n";
	printWords(sortedLinkedList,false);

	// print the number of operations that LinkedListSort took to sort the list
	std::cout << "\n\nLinkedListSort Operation Count : " << mycount << "\n\n";
	system("pause");


	delete [] unsortedList; // unsortedList is dynamically allocated inside generateWords, must be deallocated.
	return 0;
}

//@Param numwords - the number of random words you would like generated
//@Param wordlength - the length of each of those randomly generated words
//@Return - An array of strings that are randomly generated.
std::string * generateWords(int numwords, int wordlength, int seed = time(NULL))
{
	srand(seed); // seed the randomization engine

	std::string * wordlist = new std::string[numwords]; // is deallocated inside main()

	std::string word;
	//generate a vector of  numwords strings filled with a random sequence of wordlength chars
	for(int i = 0; i < numwords; i++)
	{
		for(int j = 0; j < wordlength; j++)
			word.push_back(rand()%('z'-'a')+'a');
		
		wordlist[i] = word;
		word.clear();
	}
	return  wordlist;
}

// @Param wordlist - the unsorted list of words to be printed to the screen, an array of strings.
// @Param numwords - the length of the array of strings
// @Param onlyFirstAndLastTen - if true this will only print the first and last 10 items of the word list. If false it will print all numwords of them
void printWords(std::string * wordlist, int numwords, bool onlyFirstAndLast10)
{
	if(!onlyFirstAndLast10)
	{
		for(int i = 0; i < numwords;i++)
		{
			std::cout << wordlist[i] << ", ";
			if(i%6 == 0)
				std::cout << "\n";
		}
	}
	else if(numwords >= 20)
	{
		for(int i = 0; i < 10; i++)
			std::cout << wordlist[i] << ", ";
		std::cout << "\n..............";
		for(int i = numwords-10; i < numwords; i++)
			std::cout << wordlist[i] << ", ";
	}

	std:: cout << "\n\n\n";
}

// @Param wordlist - the unsorted list of words to be printed to the screen, an array of strings.
// @Param onlyFirstAndLastTen - if true this will only print the first and last 10 items of the word list. If false it will print all numwords of them
void printWords(std::vector<std::string> wordlist, bool onlyFirstAndLast10)
{
	if(!onlyFirstAndLast10) // if this is false we print the entire array
	{
		for(int i = 0; i < wordlist.size();i++)
		{
			std::cout << wordlist[i] << ", ";
			if(i%6 == 0)
				std::cout << "\n";
		}
	}
	else if(wordlist.size() >= 20) // else we only print the first and last 10 items
	{
		for(int i = 0; i < 10; i++)
			std::cout << wordlist[i] << ", ";
		std::cout << "\n..............";
		for(int i = wordlist.size()-10; i < wordlist.size(); i++)
			std::cout << wordlist[i] << ", ";
	}

	std::cout << "\n\n\n";
}