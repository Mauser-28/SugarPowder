#ifndef LIST_H
#define LIST_H
#include <iostream>

struct AirlinesTicket{
	std::string destination;
	std::string flight_number;
	std::string full_name;
	std::string des_dep_date;

	AirlinesTicket();
	AirlinesTicket(std::string, std::string, std::string, std::string);
	const AirlinesTicket& operator=(const AirlinesTicket&);
	AirlinesTicket(AirlinesTicket&&);
	AirlinesTicket(AirlinesTicket&);
	friend std::ostream& operator<< (std::ostream&, const AirlinesTicket&);
};

struct DataItem {
	AirlinesTicket info;
	DataItem* next;
};

class TicketsDatabase {
private:
	DataItem* first;
public:
	TicketsDatabase();
	TicketsDatabase(const TicketsDatabase&);
	~TicketsDatabase();
	bool InsertFirst(const AirlinesTicket&);
	/*void InsertByAlph();*/
	bool DeleteFirst();
	const AirlinesTicket LastRegistrated() const;
	void DatabasePrint() const;
	void DatabasePrint(std::string, std::string) const;
	void ForEach(void(int)) const;
	void ForEach(void(int&));
	const TicketsDatabase& operator=(const TicketsDatabase&);
	void Erase();
	void Clone(const TicketsDatabase&);
};




#endif