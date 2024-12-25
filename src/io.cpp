#include "io.hpp"
#include "defs_mask.hpp"
#include "defs_default.hpp"
#include <unistd.h>
#include <cstdlib>

std::ostream& log_help(std::ostream& os){
  os<<"First args must be the following three in the next order\nGive the following mandatory args in the next order\n";
  os<<"\t1. width  of image\n";
  os<<"\t2. height of image\n";
  os<<"\t3. name   of storage file\n";
  os<<"After that, the next options can be activated\n";
  os<<"\tr <value> - reds   of all pixels are the same value, default one, if value is missing\n";
  os<<"\tg <value> - greens of all pixels are the same value, default one, if value is missing\n";
  os<<"\tb <value> - blues  of all pixels are the same value, default one, if value is missing\n";
  os<<"\ta <value> - alphas of all pixels are the same, random values for each pixel, if value is missing\n";
  os<<"If a color option is not activated, than the component is randomnly selected\n";
  os<<"If the alpha option is not activated, than it's opaque\n";
  return os;
}

std::ostream& log_cla_err(std::ostream& os, int err, int min, int max){
  os<<err<<" args were given\n";
  os<<"Give at least "<<min<<'\n';
  os<<"Give at most  "<<max<<'\n';
  return log_help(os);
}

sf::Color color_from_cla(int cla_count, char* cla_args[], int& activ_mask){
  sf::Color clr(def(r), def(g), def(b), def(a));
  const char r='r', g='g', b='b';//this line makes the 'case cmp:' one function properly
  full_off(activ_mask);

  #define comp_case(cmp)\
    case cmp:\
      on(activ_mask, cmp);\
      !optarg ? '\0' : clr.cmp = atoi(optarg);\
      break

  int opt;
  while((opt = getopt(cla_count, cla_args, "r:g:b:a::")) != -1){
    switch(opt){
      comp_case(r); comp_case(g); comp_case(b);

      case 'a':
        on(activ_mask, a);
        !optarg ? on(activ_mask, a_rnd) : clr.a = atoi(optarg);
        break;

      default:
        break;
    }
  }

  #undef comp_case

  return clr;
}
