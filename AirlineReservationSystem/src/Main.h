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



struct Flight
{
	std::string destination;
	long double price = 0.00;
	std::string departureTime;
	std::string flightCode;
};

Account currentAccount;
Flight flights[50];
int numberOfFlights = 0;
void LoadFlights(Flight flights[]);
void WelcomeScreen();
void MainMenu(Account account);
void SortFlights(std::string destination);

void SignUp();
void SignIn();
bool CreateAccount(Account account);
void FlightScreen();
void TicketScreen();



