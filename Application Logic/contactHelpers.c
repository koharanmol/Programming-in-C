/* -------------------------------------------
Name: Anmol Singh           
Student number: 147528178
Email: as51@myseneca.ca   
Section:   I     
Date:  23 july 2018         
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include"contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
	printf("Press Enter to continue");
	clearKeyboard();
}


// getInt function definition goes here:
int getInt(void) {
	char NL = 'x';
	int Value, help = 1;
	while (help == 1) {
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
			help = 1;
		}
		else {
			help = 0;
		}
	}
		return Value;


	
}

// getIntInRange function definition goes here:
int getIntInRange(int numberOne, int numberTWO) {
	int num, help = 1;
	while (help == 1) {
		num = getInt();
		if (num >= numberOne && num < numberTWO) {
			help = 0;
		}
		else {
			printf(">*** OUT OF RANGE *** <Enter a number between %d and %d>:", numberOne, numberTWO);
			help = 1;
		}
	}return num;
	
	
}


// yes function definition goes here:
int yes(void) {
	char yes;
	int val, help = 1;
	char NL = 'x';
	while (help == 1) {
		scanf("%c%c", &yes, &NL);
		if (NL != '\n') {
				clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		
			help = 1;
		}
		else if (yes == 'Y' || yes == 'y' && NL == '\n') {
			val = 1;
			help = 0;
			}
		else if(yes == 'N' || yes == 'n' && NL == '\n') {
			val = 0;
			help = 0;
			}

	}
	return (val);
}



// menu function definition goes here:
int menu(void) {
	int value ;
	 {

		printf("Contact Management System\n");
		printf("-------------------------\n");
		printf("1. Display contacts\n");
		printf("2. Add a contact\n");
		printf("3. Update a contact\n");
		printf("4. Delete a contact\n");
		printf("5. Search contacts by cell phone number\n");
		printf("6. Sort contacts by cell phone number\n");
		printf("0. Exit<\n");
		printf("\n");
		printf("Select an option:> ");
		value = getIntInRange(0, 6);
	}
}
// ContactManagerSystem function definition goes here:

void ContactManagerSystem(void) {
	int option, val;
	menu();
	option = getIntInRange(0, 6);
	switch (option)
	{
	case 1:
		printf("<<< Feature 1 is unavailable >>>\n\n");

		break;
	case 2:
		printf("<<< Feature 2 is unavailable >>>\n\n");

		break;
	case 3:
		printf("<<< Feature 3 is unavailable >>>\n\n");

		break;
	case 4:
		printf("<<< Feature 4 is unavailable >>>\n\n");

		break;
	case 5:
		printf("<<< Feature 5 is unavailable >>>\n\n");

		break;
	case 6:
		printf("<<< Feature 6 is unavailable >>>\n\n");

		break;
	default:
		printf("Exit the program? (Y)es/(N)o: ");
		val = yes();
		if (val == 1) {
			printf("Contact Management System: terminated");
		}
		break;
	}
}