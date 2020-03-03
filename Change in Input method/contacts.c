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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include"contacts.h"
#include"contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name) {
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%[^\n]s", name->middleInitial);
		clearKeyboard();
	}
	else {
		name->middleInitial[0] = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf("%[^\n]s", name->lastName);

}



// getAddress:
void getAddress(struct Address *address) {

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", address->street);
	
	printf("Do you want to enter an apartment number? (y or n): ");
        if (yes() == 1)
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		}
		else {
			address->apartmentNumber = '\0';
		}
     
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", address->postalCode);
   clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%[^\n]s", address->city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers) {
	
	printf("Please enter the contact's cell phone number: ");
	 getTenDigitPhone(numbers->cell);
	
	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		clearKeyboard();
	}
	else {
		numbers->home[0] = '\0';
	}
	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
		clearKeyboard();
	}
	else {
		numbers->business[0] = '\0';
	}
}



// getContact:
void getContact(struct Contact *contact) {
	getName(&(contact->name));
	getAddress(&(contact->address));
	getNumbers(&(contact->numbers));
}