#pragma once
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>


int f = 16; //file spacing

struct Flight
{
	std::string destination;
	long double price = 0.00;
	std::string departureTime;
	std::string flightCode;
};

struct Account
{
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string homeAddress;
	int age = 0;
	std::string password;

	Flight ticket;

	bool hasTicket = false;
	void SetTicket(Flight t)
	{
		if (hasTicket)
		{
			std::cout << "You are already going to " << ticket.destination << ".Please cancel your current ticket if you wish to change" << std::endl;
		}
		else
		{
			ticket = t;
			hasTicket = true;
			std::cout << "You are going to " + ticket.destination + "!" << std::endl;
		}
		
	}
	void GetTicket()
	{
		if (!hasTicket)
			std::cout << "You have not purchased a ticket" << std::endl;
		else
		{
			std::cout << std::setw(f) << std::left << "Destination" << std::setw(f) << std::left << "Price" << std::setw(f) << std::left << "Departure Time" << std::setw(f) << std::left << "Flight Code" << std::endl;
			std::cout << std::setw(f) << std::left << ticket.destination << std::setw(f) << std::left << std::to_string(ticket.price) << std::setw(f) << std::left << ticket.departureTime << std::setw(f) << std::left  << ticket.flightCode << std::endl;
			std::cout << "\n1. Cancel Ticket" << std::endl;
		}
	}
	void CancelTicket()
	{
		//ticket = Flight emptyTicket;
		hasTicket = false;
		std::cout << "Your trip to " << ticket.destination << " has been cancelled" << std::endl;
	}
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



