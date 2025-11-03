#include "List.h"


AirlinesTicket::AirlinesTicket() : destination("Invalid_info"), flight_number("Invalid_info"), full_name("Invalid_info"), des_dep_date("Invalid_info") {};
AirlinesTicket::AirlinesTicket(std::string destination, std::string flight_number, std::string full_name, std::string des_dep_date) {
	this->destination = destination;
	this->flight_number = flight_number;
	this->full_name = full_name;
	this->des_dep_date = des_dep_date;
}

const AirlinesTicket& AirlinesTicket::operator=(const AirlinesTicket& ticket) {
	if (&ticket == this) {
		return *this;
	}
	this->destination = ticket.destination;
	this->flight_number = ticket.flight_number;
	this->full_name = ticket.full_name;
	this->des_dep_date = ticket.des_dep_date;
	return *this;
}


AirlinesTicket::AirlinesTicket(AirlinesTicket&& ticket) : destination(std::move(ticket.destination)), flight_number(std::move(ticket.flight_number)), full_name(std::move(ticket.full_name)), des_dep_date(std::move(ticket.des_dep_date)) {}
AirlinesTicket::AirlinesTicket(AirlinesTicket& ticket) : destination(ticket.destination), flight_number(ticket.flight_number), full_name(ticket.full_name), des_dep_date(ticket.des_dep_date) {}


std::ostream& operator<< (std::ostream& out, const AirlinesTicket& ticket) {
	out << "\n\ndestination: " << ticket.destination;
	out << "\nflight_number: " << ticket.flight_number;
	out << "\nfull_name: " << ticket.full_name;
	out << "\ndes_dep_date: " << ticket.des_dep_date;
	return out;
}


///////////////////////////////////////////////////////////////////////////////////


TicketsDatabase::TicketsDatabase() {
	this->first = NULL;
}

TicketsDatabase::TicketsDatabase(const TicketsDatabase& l) {
	this->Clone(l);
}

TicketsDatabase::~TicketsDatabase() {
	this->Erase();
}

const TicketsDatabase& TicketsDatabase::operator=(const TicketsDatabase& l) {
	if (&l == this) {
		return *this;
	}
	Erase();
	Clone(l);
	return *this;
}

bool TicketsDatabase::InsertFirst(const AirlinesTicket& ticket) {
	if (ticket.destination == "Invalid_info" || ticket.flight_number == "Invalid_info" || ticket.full_name == "Invalid_info" || ticket.des_dep_date == "Invalid_info") {
		return false;
	}
	DataItem* Item = new DataItem;
	Item->info = ticket;
	Item->next = first;
	this->first = Item;
	return true;
}

bool TicketsDatabase::DeleteFirst() {
	if (first == NULL) {
		return false;
	}
	DataItem* curPtr = this->first;
	this->first = this->first->next;
	delete curPtr;
	return true;
}

const AirlinesTicket TicketsDatabase::LastRegistrated() const {
	if (first == nullptr) {
		throw std::runtime_error("Список пуст.");
	}
	return this->first->info;
}

void TicketsDatabase::DatabasePrint() const {
	DataItem* curPtr = first;
	if (curPtr == nullptr) {
		std::cout << "No tickets yet!\n";
	}
	else {
		while (curPtr != nullptr) {
			std::cout << curPtr->info << " ";
			curPtr = curPtr->next;
		}
	}
	std::cout << std::endl;
}

void TicketsDatabase::DatabasePrint(std::string flightNum, std::string desDepDate) const {
	DataItem* curPtr = first;
	if (curPtr == nullptr) {
		std::cout << "No tickets yet!\n";
	}
	else {
		while (curPtr != nullptr) {
			if (curPtr->info.flight_number == flightNum && curPtr->info.des_dep_date == desDepDate) {
				std::cout << curPtr->info;
			}
			curPtr = curPtr->next;
		}
	}
	std::cout << std::endl;
}