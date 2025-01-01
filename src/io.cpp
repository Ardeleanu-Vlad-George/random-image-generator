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
  const char *msg = " of all pixels are the same value, default one, if value is not present";
  os<<"\tr <value> - reds  "<<msg<<'\n';
  os<<"\tg <value> - greens"<<msg<<'\n';
  os<<"\tb <value> - blues "<<msg<<'\n';
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
