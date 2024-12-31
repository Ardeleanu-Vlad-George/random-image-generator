#ifndef _RND_RGBA_IMG_HPP_
#define _RND_RGBA_IMG_HPP_

#include <SFML/Graphics.hpp>

class rnd_rgba_img{
public:
  static void start_rand_gen();
private:
  int full_size;
public:
  rnd_rgba_img(int);
private:
  sf::Uint8 *data;
  int *data_int;
public:
  bool alloc();
  bool dealloc();
  sf::Image operator()(int);
  sf::Image operator()(int, int, sf::Color);
  ~rnd_rgba_img();
};

#endif//_RND_RGBA_IMG_HPP_
