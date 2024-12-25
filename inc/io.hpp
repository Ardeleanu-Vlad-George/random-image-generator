#ifndef _IO_HPP_
#define _IO_HPP_

#include <iostream>

std::ostream& log_help(std::ostream&);

std::ostream& log_cla_err(std::ostream&, int, int, int);

sf::Color extract_masks(char**, int&);

#endif//_IO_HPP_
