/* -------------------------------------------
Name: Anmol Singh
Student number: 147528178
Email: as51
Section: I
Date: 1 aug 2018
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include"contactHelpers.h"
#include"contacts.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):


#define MAXCONTACTS 5
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt:
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
// getIntInRange:
int getIntInRange(int numberOne, int numberTWO) {
	int num, help = 1;
	while (help == 1) {
		num = getInt();
		if (num >= numberOne && num <= numberTWO) {
			help = 0;
		}
		else {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", numberOne, numberTWO);
			help = 1;
		}
	}return num;


}


int yes(void) {
	char yes;
	int val, help = 1;
	char NL = 'x';
	
	while (help == 1) {	
	
		scanf(" %c%c", &yes, &NL);
		if ((yes == 'y' || yes == 'Y') && NL == '\n') {
			val = 1;
			help = 0;
		}
		 if ((yes == 'N' || yes == 'n') && NL == '\n') {
			val = 0;
			help = 0;
		
		}
		if (NL != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			help = 1;
			clearKeyboard();
		
		}
	}
	return (val);
}


// menu:
int menu(void) {
	int value;
	{

		printf("Contact Management System\n");
		printf("-------------------------\n");
		printf("1. Display contacts\n");
		printf("2. Add a contact\n");
		printf("3. Update a contact\n");
		printf("4. Delete a contact\n");
		printf("5. Search contacts by cell phone number\n");
		printf("6. Sort contacts by cell phone number\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Select an option:> "); 
		value = getIntInRange(0, 6); 
		return value;
		
	}printf("\n");
}


// ContactManagerSystem:

void ContactManagerSystem(void) {

	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
				{ "Sasha",{ '\0' }, "Williams" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9052223333", "9052223333", "9054445555" } }
	};
	int  help = 1;
	while (help == 1) {
		switch (menu())
		{
		case 1:
			displayContacts(contact, MAXCONTACTS);
			printf("\n");
			pause();
			break;
		case 2:
            addContact(contact, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();


			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
break;
		case 6:
			sortContacts( contact, MAXCONTACTS);
			pause();
			break;
		default:
			printf("\nExit the program? (Y)es/(N)o: ");

			if (yes() == 1) {
				printf("\nContact Management System: terminated");
				help = 0;
			}
			break;
		}
		printf("\n");
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[]) {
	
	int help = 1;
	while (help == 1) {
		scanf("%10s", telNum);
		if (strlen(telNum) == 10) {
			help = 0;
		}
		else {
			printf("Enter a 10-digit phone number: ");
			help = 1;
		}

	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, index = -1;

	for (i = 0; i < size; i++) {

		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
			index = i;
	}

	return index;
}
// displayContactHeader
void displayContactHeader() {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");


}


// displayContactFooter
void displayContactFooter(int total) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", total);
}

// displayContact:
void displayContact(const struct Contact *contact) {
	if (strcmp((*contact).name.middleInitial, "\0") == 0) {
		printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
		printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);
	}
	else {
		printf(" %s %s %s\n", (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);

		printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);
	}
	if ((*contact).address.apartmentNumber > 0) {
		printf("       %d %s, Apt# %d, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.apartmentNumber, (*contact).address.city, (*contact).address.postalCode);
	}
	else {
		printf("       %d %s, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.city, (*contact).address.postalCode);
	}
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size) {
	printf("\n");
	displayContactHeader();
	int i, contactCounter = 0;
	for (i = 0; i < size; i++) {
		if (strlen(contact[i].numbers.cell) > 0) {
			displayContact(&contact[i]);
			contactCounter++;
		}
	}
	displayContactFooter(contactCounter);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size) {
	char number[11];
	int contactIndex; printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	contactIndex = findContactIndex(contact, size, number);
	if (contactIndex > 0) {
printf("\n");
		displayContact(&contact[contactIndex]);
clearKeyboard();

	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
	
}

// addContact:
void addContact(struct Contact contact[], int size) {
	int i;
	int val = -1;
	for (i = 0; i < size; i++) {
		if (strlen(contact[i].numbers.cell) == 0) {
			val = i;
			break;
		}
	}
	if (val != -1) {
		printf("\n");
		getContact(&contact[val]);
		printf("--- New contact added! ---\n");
	}
	else {
                printf("\n");
		printf("*** ERROR: The contact list is full! ***");
		printf("\n");
	}
}


// updateContact:
void updateContact(struct Contact contact[], int size) {
	char number[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(number);
	int numberentered;
	numberentered = findContactIndex(contact, size, number);
	
		if (numberentered == -1) {
			printf("*** Contact NOT FOUND ***\n");

clearKeyboard();
		}
		else {
			printf("\n");
			printf("Contact found:\n");
			displayContact(&contact[numberentered]);
			printf("\n");

			printf("Do you want to update the name? (y or n): ");
			if (yes() == 1) {
				getName(&contact[numberentered].name);
			}
			printf("Do you want to update the address? (y or n): ");
			if (yes() == 1) {
				getAddress(&contact[numberentered].address);
			}
			printf("Do you want to update the numbers? (y or n): ");
			if (yes() == 1) {
				getNumbers(&contact[numberentered].numbers);
			}
			printf("--- Contact Updated! ---\n");
		}
	}


// deleteContact:
void deleteContact(struct Contact contact[], int size) {
	char number[11];
	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	int numberentered;
	numberentered = findContactIndex(contact, size, number);
		if (numberentered == -1) {
			printf("*** Contact NOT FOUND ***\n");
		}
		else {
			printf("\n");
			printf("Contact found:\n");
			displayContact(&contact[numberentered]); printf("\n");
			printf("CONFIRM: Delete this contact? (y or n): ");
			if (yes() == 1) {
				strcpy(contact[numberentered].numbers.cell, "\0");
				printf("--- Contact deleted! ---\n");
			}
		}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) {
	int i, j;
	struct Contact temp;
	int val = 0;
	for (i = 0; i < size; i++) {
		if (strlen((*contact).numbers.cell) != 0) {
			val = val + 1;
		}
	}
	for (i = 0; i < val - 1; i++) {
		for (j = i ; j < val; j++) {
			if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
				temp = contact[i];
				contact[i] = contact[j];
				contact[j] = temp;
			}
		}
	}printf("\n");
	printf("--- Contacts sorted! ---\n");
}