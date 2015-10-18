#include <stdexcept>

class CTakhirException : public std::exception                                 
{
public:
	explicit CTakhirException(const char *msg) : std::exception(msg) {}       
};


