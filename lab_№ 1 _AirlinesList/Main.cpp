#include "List.h"

int main() {
	TicketsDatabase Dbase{};
	AirlinesTicket myTicket("Minsk", "6032", "Pylat Ilya Victorovich", "23.01.2025");
	AirlinesTicket hisTicket("Minsk", "6032", "Ivan Butzko Stepanovich", "23.01.2026");
	Dbase.InsertFirst(myTicket);
	Dbase.InsertFirst(hisTicket);
	Dbase.DatabasePrint(myTicket.flight_number, myTicket.des_dep_date);
	/*Dbase.DeleteFirst();*/
	Dbase.DatabasePrint();

	return 0;
}