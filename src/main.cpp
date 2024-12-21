#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cstddef>
#include <ctime>


int main(int argc, char *argv[]){
  if(4 != argc){
    std::cout<<"More arguments needed\n";
    return -1;
  }
  int x = atoi(argv[1]), y = atoi(argv[2]);
  srand(time(NULL));
  sf::Image img;
  img.create(x, y);
  sf::Uint8 *data = (sf::Uint8*) img.getPixelsPtr();
  int *data_int = (int*) img.getPixelsPtr();
  for(int i=0; i < x*y; i++){
    data_int[i] = rand();
    data[4*i+3] = '\xff';
  }
  img.saveToFile(argv[3]);
  return 0;
}
