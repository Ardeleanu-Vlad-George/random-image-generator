#include "io.hpp"
#include "defs_args.hpp"
#include <unistd.h>
#include <cstdlib>

std::ostream& log_help(std::ostream& os){
  os<<"First args must be the following three in the next order\nGive the following mandatory args in the next order\n";
  os<<"\t1. width  of image\n";
  os<<"\t2. height of image\n";
  os<<"\t3. name   of storage file\n";
  os<<"After that, the next options can be activated\n";
  os<<"\tr <hex_value> - reds   of all pixels are the same value, default one, if value is missing\n";
  os<<"\tg <hex_value> - greens of all pixels are the same value, default one, if value is missing\n";
  os<<"\tb <hex_value> - blues  of all pixels are the same value, default one, if value is missing\n";
  os<<"\ta <hex_value> - alphas of all pixels are the same, random values for each pixel, if value is missing\n";
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
  sf::Color clr(R_DEFAULT, G_DEFAULT, B_DEFAULT, A_OPAQUE);
  activ_mask = NULL_MASK;
  int opt;

  while((opt = getopt(cla_count, cla_args, "rgba")) != -1){
    switch (opt){
      case 'r':
        activ_mask|=R_FLAG; 
        !optarg ? '\0' : clr.r = atoi(optarg);
        break;
      case 'g':
        activ_mask|=G_FLAG; 
        !optarg ? '\0' : clr.g = atoi(optarg);
        break;
      case 'b':
        activ_mask|=B_FLAG; 
        !optarg ? '\0' : clr.b = atoi(optarg);
        break;
      case 'a':
        activ_mask|=A_FLAG; 
        !optarg ? '\0' : clr.a = atoi(optarg);
        break;
      default:
        break;
    }
  }

  return clr;
}
