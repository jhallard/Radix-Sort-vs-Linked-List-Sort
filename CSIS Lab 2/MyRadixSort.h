#ifndef MYRADIXSORT_H
#define MYRADIXSORT_H

/*
 @Author John Allard 
 @Date March 19th, 2014
 @Description - This is an implementation of Radix Sort that works on an array of strings to be sorted.
 The length of the alphabet is limited to 200 characters for memory reasons, which is more than enough to sort 'a' through 'z' 
*/

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>


/*
 --RadixSort--
 @param container - the container of objects to be sorted, is of dimensions lengthxdepth, with length being the words and depth being the number of characters in each word.
 @param length - the length of the object in words (the length of the groups of base data (characters)).
 @param alphabetBegin - An int that represents the starting value of your alphabet, ex - 97 for 'a', if it's a char just pass in that char.
 @param alphabetEnd   - An int that represent the ending value of your alphabet, ex - 122 for 'z'
 @param count - this int is passed by reference to count the number of operations.
 @return a Vector of the same words but in sorted order, from least to greated.
 */

std::vector<std::string> RadixSort(std::string *container, const int length, const int alphabetBegin, const int alphabetEnd, int & count)
{
    // the sorted list to be returned
    std::vector<std::string> sortedList;  

    // copy the container over to the sortedList vector of strings that we will be working with
    for(int i = 0; i < length; i++)          
        sortedList.push_back(container[i]);

    int alphabetLength = alphabetEnd - alphabetBegin;

    if(alphabetLength <= 0)
        throw std::logic_error("Error, alphabetLength < 1 (possibly in wrong order)");

    // allocate the bin via an array of vectors of strings. There are as many vectors in the array as there are characters in the given alphabet
    std::vector<std::string> * bin = new std::vector<std::string>[alphabetLength]; // each vector of strings represents a specific bin, with the idnex 
                                                                                   // being the numeric representation of that character in the given alphabet
    
    // main for-loop that goes through each character in the words from last to first
    for(int index = sortedList[0].length()-1; index >= 0; index--)
    {

        //inner for-loop, we go through each word in the list and dump it into the appropriate bin based on the character at @param index
        for(int word = 0; word < length; word++)
        {
            //the index of the bin that this word is going to go into, based off the current character in the word we are looking at,
            // normalized to the length of the alphabet.
            int binNum = char(sortedList[word][index]) - alphabetBegin;

            // insert into the bin at the index binNum
            bin[binNum].push_back(sortedList[word]);

            //increase the operation count
            count++;
        }

        // clear the list of words that we just copies into bin so we can refill it in a more sorted order
        sortedList.clear();

        // go through all of the bins
        for(int binNum = 0; binNum < alphabetLength; binNum++)
        {
            // go through each bin and unload the words back into the container in order
            for(int word = 0; word < bin[binNum].size(); word++)
            {
                //push the word from the bin onto our sortedList
                sortedList.push_back(bin[binNum][word]);

                //increase the operation count
                count++;
            }
            // clear the bin at index binNum after we have emptied it so it can be refilled
            bin[binNum].clear();
        }
        
    }// end main for loop that goes through each character from end to beginning

    delete [] bin;
    return sortedList;
}

#endif