#pragma once
#include <exception>

class BadLength : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};

