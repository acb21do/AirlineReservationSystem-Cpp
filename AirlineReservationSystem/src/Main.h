#pragma once
#include <string>
#include <conio.h>
#include <fstream>

struct Account
{
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string homeAddress;
	int age = 0;
	std::string password;
};

Account currentAccount;

void WelcomeScreen();
void MainMenu(Account account);
void SignUp();
void SignIn();
bool CreateAccount(Account account);



