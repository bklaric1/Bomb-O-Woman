#ifndef SIMPLEINPUT_H
#define SIMPLEINPUT_H

class SimpleInput
{

public:
	SimpleInput();
	~SimpleInput();
	static char getWASD(long interval);
	static char getArrow(long interval);
	static char getSteuerung(long interval);
};
#endif

