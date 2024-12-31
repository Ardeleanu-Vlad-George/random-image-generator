#include "rnd_rgba_img.hpp"
#include "defs_mask.hpp"
#include "defs_cla.hpp"
#include "defs_default.hpp"
#include <cstdio>

void rnd_rgba_img::start_rand_gen(){
  srand(time(NULL));
}

rnd_rgba_img::rnd_rgba_img(int fs)
  :full_size(fs)
    {}

bool rnd_rgba_img::alloc(){
  data = new sf::Uint8[4*full_size];
  data_int = (int*)data;
  return true;
}

bool rnd_rgba_img::dealloc(){
  delete data;
  data = NULL;
  data_int = NULL;
  return true;
}
sf::Image rnd_rgba_img::operator()(int width){
  int height, reminder;

  height = full_size/width;
  reminder = full_size%width;
printf("\nDEBUG_rem=%d\n", reminder);
printf("\nDEBUG_size=%d\n", full_size);

  sf::Uint8 *src = data+4*reminder;
  int *src_int = (int*) src;

  for(int i=0; i < width * height; i++){
printf("\nDEBUG_idx=%d\n", i);
printf("\nDEBUG_ptr=%p\n", src_int);
    src_int[i] = rand();
    src[4*i+3] = '\xff';
  }

  sf::Image res;
  res.create(height, width, src);
  return res;
}

sf::Image rnd_rgba_img::operator()(int width, int mask, sf::Color clr){
  int height, reminder;

  height = full_size/width;
  reminder = full_size%width;

  sf::Uint8 *src = data+4*reminder;
  int *src_int = (int*) src;

  for(int i=0; i < width * height; i++){
    src_int[i] = rand();
    ifon(mask, r) ? src[4*i] = clr.r : 0;
    ifon(mask, g) ? src[4*i+1] = clr.g : 0;
    ifon(mask, b) ? src[4*i+2] = clr.b : 0;
    ifon(mask, a_rnd) ? 0 : src[4*i+3] = ifon(mask, a) ? clr.a : def(a);
  }

  sf::Image res;
  res.create(height, width, src);
  return res;
}

rnd_rgba_img::~rnd_rgba_img(){
  dealloc();
}
