#pragma once

#include <stdint.h>

class TankAdaptee {
public:

	TankAdaptee();

	void Paint() const;

	bool isInRange(double x1, double x2) const;

	uint16_t GetScore() const; 

	void SetPos(double nx, double ny); 
	double GetY() const; 
	double GetX() const; 

	void SetWidth(uint16_t widthN); 
	uint16_t GetWidth() const; 

protected:

	double x, y;
	uint16_t width;
	const uint16_t score = 30;
};

