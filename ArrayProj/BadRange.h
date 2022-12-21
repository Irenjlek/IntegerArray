#pragma once
#include <exception>

class BadRange : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};

