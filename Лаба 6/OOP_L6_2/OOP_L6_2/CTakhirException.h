#include <string>
#include <stdexcept>

// В заголовочных файлах не пишем using namespace std

//using namespace std;

class CTakhirException : public exception                                 \
{
public:
	explicit CTakhirException(const char *msg) : exception(msg) {}        \
};

//DeclareException(CTakhirException, exception);

//class CTakhirException : public exception
//{
//public:
//	explicit CTakhirException(const string & what_arg);
//	explicit CTakhirException(const char what_arg);
//};


//struct CTakhirException
//{
//	string msg;
//	CTakhirException(const string& msg):
//		msg(msg)
//	{}
//};

