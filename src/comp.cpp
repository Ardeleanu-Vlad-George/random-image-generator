#include "comp.hpp"

void start_rand(){
  srand(time(NULL));
}

sf::Image rand_imag(int w, int h){
  sf::Image res;
  res.create(w, h);
  sf::Uint8 *data = (sf::Uint8*) res.getPixelsPtr();
  int *data_int = (int*) res.getPixelsPtr();
  for(int i=0; i < w*h; i++){
    data_int[i] = rand();
    data[4*i+3] = '\xff';
  }
  return res;
}
