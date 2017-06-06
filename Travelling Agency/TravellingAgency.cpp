//============================================================================
// Name        : TravellingAgency.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
#include "Hotel.h"
#include "Transport.h"
#include "CombinedOffers.h"
#include "TravelKit.h"

int main(void) {

	Transport transp1("Travel by train", 50.0);
	Transport transp2("Travel by air", 50.0, true);

	Hotel hotel1("Hotel 3* : Les Amandiers ", 40.0, 5, 100.0);
	Hotel hotel2("Hotel 4* : Ambassador Plazza  ", 100.0, 2, 250.0);

	CombinedOffers combi("Hotel 4* : Ambassador Plazza and travel by air",
			100.0, 2, 250.0, true);

	TravelKit kit1("Zurich", "Paris");
	kit1.AddOption(transp1);
	kit1.AddOption(transp2);
	kit1.AddOption(hotel1);
	kit1.AddOption(hotel2);
	cout << kit1 << endl;



}
