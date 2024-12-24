#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <cstring>


int main(int argc, char *argv[]){
  if(4 != argc){
    std::cout<<"At least three arguments needed\n";
    std::cout<<"\tWidth, height and file name, needed as first args\n";
    std::cout<<"\tNext dash options are permited\n";
    std::cout<<"\t\tr <value> - all reds the same, random if not activated\n";
    std::cout<<"\t\tg <value> - all greens the sam, random if not activatede\n";
    std::cout<<"\t\tb <value> - all blues the sam, random if not activatede\n";
    std::cout<<"\t\ta <value> - all alphas the same, if no value is given, the alphas are random, if not activated, the alphas are opaque\n";
    return -1;
  }
  int x = atoi(argv[1]), y = atoi(argv[2]);
  char *name = new char[strlen(argv[3])];
  strcpy(name, argv[3]);

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
