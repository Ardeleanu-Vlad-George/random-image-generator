#include "comp.hpp"
#include "defs_color.hpp"

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
    data[4*i+3] = A_OPAQUE;
  }
  return res;
}

sf::Image rand_imag(int w, int h, int activation_mask, sf::Color values){
  sf::Image res;
  res.create(w, h);
  sf::Uint8 *data = (sf::Uint8*) res.getPixelsPtr();
  int *data_int = (int*) res.getPixelsPtr();
  for(int i=0; i < w*h; i++){
    data_int[i] = rand();
    data[4*i+3] = A_OPAQUE;
    activation_mask & R_FLAG ? data[4*i] = values.r;
    activation_mask & G_FLAG ? data[4*i+1] = values.g;
    activation_mask & B_FLAG ? data[4*i+2] = values.b;
    activation_mask & A_FLAG ? data[4*i+3] = values.a;
  }
  return res;
}
