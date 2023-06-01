
#ifndef POSITION_H_
#define POSITION_H_

#include <string>

class Position
{
protected:
	int x;
	int y;

public:
	int getX();
	void setX(int x);

	int getY();
	void setY(int y);


	std::string to_string() const; //Position: x=5, y=6

	Position operator+ (const Position& rhs);
	Position operator- (const Position& rhs);

	int distanceManhattan(const Position& p);//Distanz zwischen aufrufender Instanz und p

	Position();

	Position(int x, int y);

	~Position();
};

std::ostream& operator<<(std::ostream& os, const Position& rhs);

#endif /* POSITION_H_ */
