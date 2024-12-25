#ifndef _IO_HPP_
#define _IO_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

std::ostream& log_help(std::ostream&);

std::ostream& log_cla_err(std::ostream&, int, int, int);

sf::Color color_from_cla(int, char*[], int&);

#endif//_IO_HPP_
