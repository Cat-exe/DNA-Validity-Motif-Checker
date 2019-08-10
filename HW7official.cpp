/*Homework Assignment 7
Author: Carol Pignato
Date: December 5, 2016
Comments: This program determines validity of a strand of DNA and finds the positions of a
          particular motif within the DNA. This program only accepts DNA written in capital letters.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
bool isvaliddna(string);
void print_occurs(string, string);

int main() {
    cout << "This program finds the validity of a strand of DNA,"
         << "and finds the positions of a particular motif within the DNA."
         << endl << "This program is case sensitive; only accepts caps."
         << endl;

    //Reads in data from file and concatenates each new line
    //into a string that holds all previous lines in a single line.
    string singleLine, newline;
    ifstream data("data.txt");
    if (data)
        while (getline(data, newline))
            singleLine += newline;
    cout << "Original string for DNA sequence: " << endl << singleLine << endl;

    //Check if sequence is valid DNA via isvaliddna function.
    isvaliddna(singleLine);

    //Read in a character string representing a DNA motif.
    string motif;
    cout << "Enter a motif: ";
    getline (cin, motif);
    cout << "Original string for DNA motif: " << motif << endl;


    //Check if motif is a valid strand of DNA; call isvaliddna function.
    isvaliddna(motif);

    //Print positions of each occurrence of the motif
    //in the DNA sequence via print_occurs function.
    print_occurs(singleLine, motif);


    return 0;
}

// Function that tells whether or not the DNA is valid.
// Valid DNA can contain the characters A, C, G, T or N.
bool isvaliddna (string str) {
    size_t n = str.length();
	for(size_t i=0; i<n; ++i) {
		if(str[i]!='A' && str[i]!='C' && str[i]!='G' && str[i]!='T' && str[i]!='N') {
            cout << "This is not valid DNA." << endl;
			exit(0);
		}
	}
	cout << "String contains valid DNA." << endl;
	return true;
}

//Function that counts how many times the motif
//appears in the DNA sequence.
void print_occurs(string singleLine, string motif) {
    int occ=0;
    size_t found = singleLine.find(motif, 0);
    while (found!=string::npos) {
        occ++;
        cout << "Occurrence found in position: " << found << endl;
        found = singleLine.find(motif, found+1);
    }
    cout << "Number of occurrences: " << occ << endl;
    return;
}
