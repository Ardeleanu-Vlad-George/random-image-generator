#include <SFML/Graphics.hpp>
#include <iostream>
#include "defs.hpp"
#include "comp.hpp"
#include <cstring>
#include "io.hpp"


int main(int argc, char *argv[]){
  if(2 == argc && 0 == strcmp(HELP_STR, argv[1])){
    log_help(std::clog);
    return 1;
  }
  if(MIN_CLA_COUNT > argc-1 || argc-1 > MAX_CLA_COUNT){
    log_cla_err(std::clog, argc-1, MIN_CLA_COUNT, MAX_CLA_COUNT);
    return -1;
  }
  int x = atoi(argv[1]), y = atoi(argv[2]);
  char *name = new char[strlen(argv[3])];
  strcpy(name, argv[3]);
  int mask;
  sf::Color clr = color_from_cla(argc, argv, mask);

  start_rand();
  sf::Image img = NULL_MASK == mask ? rand_imag(x, y) : rand_imag(x, y, mask, clr);
  img.saveToFile(name);
  return 0;
}
