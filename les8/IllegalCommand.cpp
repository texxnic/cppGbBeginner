#include "IllegalCommand.h"

IllegalCommand::IllegalCommand(std::string error)
	:m_error(error)
{

}

const char* IllegalCommand::getError()
{
	return m_error.c_str();
}