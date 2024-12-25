#include "comp.hpp"
#include "defs_default.hpp"
#include "defs_mask.hpp"

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
    data[4*i+3] = def(a);
  }
  return res;
}

sf::Image rand_imag(int w, int h, int mask, sf::Color values){
  sf::Image res;
  res.create(w, h);
  sf::Uint8 *data = (sf::Uint8*) res.getPixelsPtr();
  int *data_int = (int*) res.getPixelsPtr();
  for(int i=0; i < w*h; i++){
    data_int[i] = rand();
    ifon(mask, r) ? data[4*i] = values.r : 0;
    ifon(mask, g) ? data[4*i+1] = values.g : 0;
    ifon(mask, b) ? data[4*i+2] = values.b : 0;
    ifon(mask, a_rnd) ? 0 : data[4*i+3] = ifon(mask, a) ? values.a : def(a);
  }
  return res;
}
