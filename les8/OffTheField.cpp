#include "OffTheField.h"

OffTheField::OffTheField(std::string error)
	:m_error(error)
{

}

const char* OffTheField::getError()
{
	return m_error.c_str();
}
