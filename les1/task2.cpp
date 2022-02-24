#include <iostream>

using namespace std;

class RGBA
{
private:
	uint8_t m_red = 0x00;
	uint8_t m_green = 0x00;
	uint8_t m_blue = 0x00;
	uint8_t m_alpha = 0xFF;

public:
	RGBA()
	{
	}
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}
	void print()
	{
		cout << "Red = " << static_cast<int>(m_red) << endl;
		cout << "Green = " << static_cast<int>(m_green) << endl;
		cout << "Blue = " << static_cast<int>(m_blue) << endl;
		cout << "Alpha = " << static_cast<int>(m_alpha) << endl;
	}
};

int main(int argc, char **args)
{
	RGBA def;
	def.print();
	cout << endl;

	RGBA white(0xFF, 0xFF, 0xFF, 0xFF);
	white.print();
	cout << endl;

	return 1;
}