#include "cla.hpp"

#include "defs_mask.hpp"
#include "defs_default.hpp"
#include <unistd.h>
#include <cstdlib>

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
