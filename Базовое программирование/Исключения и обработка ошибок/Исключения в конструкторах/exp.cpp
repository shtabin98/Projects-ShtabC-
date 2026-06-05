#include "exp.h"

expection::expection(std::string expect)
	: std::domain_error(expect), expect(expect){}

std::string expection::get_expect() const { return expect; };
