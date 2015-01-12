#ifndef VISITOR_HEADER
#define VISITOR_HEADER


class PassengerShip;
class PleasureCraft;
class MilitaryShip;
class FishingBoat;

class Visitor
{

public:

	void display(PassengerShip* a);
	void display(PleasureCraft* b);
	void display(MilitaryShip* c);
	void display(FishingBoat* d);

};

#endif

