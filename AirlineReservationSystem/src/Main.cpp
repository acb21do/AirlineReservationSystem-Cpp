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
			print("LOGIN SCREEN");
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
			
			MainMenu(currentAccount);
		}
		else
		{
			print("Incorrect email or password");
		}
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
	system("CLS");
	print("Welcome " + account.firstName + "\n");

	print("1. Select a flight");
	print("2. View current tickets");
	print("0. Exit");
}