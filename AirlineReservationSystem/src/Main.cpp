#include <iostream>
#include "Main.h"

#define print(x) std::cout << x << std::endl


int main()
{	
	WelcomeScreen();
	std::cin.get();
}

void WelcomeScreen()
{
	char choice;
	do
	{
		system("CLS");
		print("Welcome to XYZ Airlines \n");

		print("1. Sign Up");
		print("2. Login");
		print("0. Exit \n");

		choice = _getch();
		switch (choice)
		{
		case '0':
			print("Thank you for visiting XYZ Airlines!");
			break;

		case '1':
			system("CLS");
			SignUp();
			break;

		case '2':
			system("CLS");
			SignIn();
			break;

		default:
			print("[ERROR]: Unknown option selected.");
			break;
		}
	} while (choice != '0');
}

void SignUp()
{
	Account account;

	print("Welcome to the Sign Up Screen \n");

	print("Please Enter in your First name");
	std::cin >> account.firstName;
	print("Please Enter in your Last name");
	std::cin >> account.lastName;
	print("Please Enter in your Email Address");
	std::cin >> account.emailAddress;
	print("Please Enter in your Home Address");
	std::cin >> account.homeAddress;
	print("Please Enter in your Age");
	std::cin >> account.age;
	print("Please Enter in a Password");
	std::cin >> account.password;

	if (CreateAccount(account))
	{
		system("CLS");
		print("Your account has been succefully created");
		system("pause");
	}
	else
	{
		system("CLS");
		print("Your email address is already used");
		system("pause");
	}
}

void SignIn()
{
	bool signedIn = false;
	std::string checkEmail;
	std::string checkPassword;

	print("Enter email address:");
	std::cin >> checkEmail;
	print("Enter password");
	std::cin >> checkPassword;

	std::ifstream readFile;
	std::string strArr[6];
	std::string str;

	readFile.open("data.txt");
	while (!readFile.eof())
	{
		for (int i = 0; i < 6; i++)
		{
			std::getline(readFile, str, '|');
			strArr[i] = str;
		}
		if (checkEmail == strArr[2] && checkPassword == strArr[5])
		{
			currentAccount.firstName = strArr[0];
			currentAccount.lastName = strArr[1];
			currentAccount.emailAddress = strArr[2];
			currentAccount.homeAddress = strArr[3];
			currentAccount.age = std::stoi(strArr[4]);
			currentAccount.password = strArr[5];
			signedIn = true;
			MainMenu(currentAccount);
			break;
		}
	}
	if (!signedIn)
	{
		print("Incorrect email or password");
		system("pause");
	}
	readFile.close();
}

bool CreateAccount(Account account)
{
	std::string strArr[6];
	std::string str;

	std::ifstream readFile;
	readFile.open("data.txt");
	//Checks if the same account already exists
	while (!readFile.eof()) {
		for (int i = 0; i < 6; i++)
		{
			std::getline(readFile, str, '|');
			strArr[i] = str;
		}
		if (account.emailAddress == strArr[2])
		{
			return false;
		}
	}
	readFile.close();
	//Add the account details to the data file
	
	std::ofstream file;
	file.open("data.txt", std::ofstream::app);

	file << account.firstName;
	file << "|";
	file << account.lastName;
	file << "|";
	file << account.emailAddress;
	file << "|";
	file << account.homeAddress;
	file << "|";
	file << account.age;
	file << "|";
	file << account.password;
	file << "|";
	file << "\n";

	file.close();
	return true;

}

void MainMenu(Account account)
{
	char choice;
	do
	{
		system("CLS");
		print("Welcome " + account.firstName + "\n");
		LoadFlights(flights);
		print("1. Select a flight");
		print("2. View current tickets");
		print("0. Exit");

		choice = _getch();

		switch (choice)
		{
		case '0':
			system("CLS");
			print("Successfully logged out");
			system("pause");
			break;
		case '1':
			FlightScreen();
			break;
		case '2':
			TicketScreen();
			break;
		default:
			print("Unknown input, please select one of the options");
			break;
		}
	} while (choice != '0');
	
}

void LoadFlights(Flight emptyFlights[])
{
	std::string str;
	std::string strArr[4];
	std::ifstream readFile;
	readFile.open("flights.txt");

	do {
		for (int i = 0; i < 4; i++)
		{
			std::getline(readFile, str, '|');
			strArr[i] = str;
		}
		emptyFlights[numberOfFlights].destination = strArr[0];
		emptyFlights[numberOfFlights].price = std::stold(strArr[1]);
		emptyFlights[numberOfFlights].departureTime = strArr[2];
		emptyFlights[numberOfFlights].flightCode = strArr[3];

		readFile.peek();
	} while (!readFile.eof());
	readFile.close();
}

void FlightScreen()
{
	

	char choice;
	do
	{
		system("CLS");

		print("View flights for these destinations: \n");

		print("1. London");
		print("2. New York");
		print("3. Paris");
		print("4. Sydney");
		print("5. Los Angeles");
		print("6. Dubai");
		print("7. Beijing\n");
		print("0. Exit");
		
		choice = _getch();

		switch (choice)
		{
		case '0':
			system("CLS");
			print("Going back to Main Menu");
			system("pause");
			break;
		case '1':
			SortFlights("London");
			break;
		case '2':
			SortFlights("New York");
			break;
		case '3':
			SortFlights("Paris");
			break;
		case '4':
			SortFlights("Sydney");
			break;
		case '5':
			SortFlights("Los Angeles");
			break;
		case '6':
			SortFlights("Dubai");
			break;
		case '7':
			SortFlights("Beijing");
			break;
		default:
			print("Unknown input, please select one of the options");
			break;
		}
	} while (choice != '0');
}

void SortFlights(std::string destination)
{
	system("CLS");
	Flight currentFlights[50];
	int inc = 0;
	std::string str;
	std::string strArr[4];
	std::ifstream readFile;
	readFile.open("flights.txt");

	while (!readFile.eof()) {
		bool destinationMatch = false;
		for (int i = 0; i < 4; i++)
		{
			std::getline(readFile, str, '|');

			if (str[0] == '\n')
				str.erase(0, 1);

			if (i == 0 && destination == str)
				destinationMatch = true;
			if (destinationMatch)
			{
				
				strArr[i] = str;
			}
		}
		if (destinationMatch)
		{
			currentFlights[inc].destination = strArr[0];
			currentFlights[inc].price = std::stold(strArr[1]);
			currentFlights[inc].departureTime = strArr[2];
			currentFlights[inc].flightCode = strArr[3];
			inc++;
		}
		readFile.peek();
	}
	readFile.close();

	std::cout << "   " << std::setw(f) << std::left << "Destination" << std::setw(f) << std::left << "Price" << std::setw(f) << std::left << "Departure Time" << std::setw(f) << std::left << "Flight Code" << std::endl;

	for (int i = 0; i < inc; i++)
	{
		std::cout << i + 1 << ". " << std::setw(f) << std::left << currentFlights[i].destination << std::setw(f) << std::left << std::to_string(currentFlights[i].price) << std::setw(f) << std::left << currentFlights[i].departureTime << std::setw(f) << std::left << currentFlights[i].flightCode << std::endl;
	}
	print("0. Exit");
	int choice;
	do
	{
		choice = (int)_getch() - 48;
		if (choice <= inc && choice > 0)
		{
			system("CLS");
			currentAccount.SetTicket(currentFlights[choice - 1]);
			system("pause");
			break;
		}
	} while (choice != 0);
	

	//std::cin.get();
}

void TicketScreen()
{
	char choice;
	do
	{	
		system("CLS");
		currentAccount.GetTicket();
		print("0. Exit");
		choice = _getch();
		
		switch (choice)
		{
		case '0':
			system("CLS");
			print("Going back to Main Menu");
			system("pause");
			break;
		case '1':
			if (currentAccount.hasTicket)
			{
				system("CLS");
				currentAccount.CancelTicket();
				system("pause");
				break;
			}
			else
			{
				print("Unknown input, please select one of the options");
				break;
			}
		default:
			print("Unknown input, please select one of the options");
			system("pause");
			break;
		}
	} while (choice != '0');
	
}