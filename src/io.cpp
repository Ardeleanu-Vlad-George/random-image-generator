#include "io.hpp"

std::ostream& log_help(std::ostream& os){
  os<<"\tWidth, height and file name, needed as first args\n";
  os<<"\tNext dash options are permited\n";
  os<<"\t\tr <value> - all reds the same, random if not activated\n";
  os<<"\t\tg <value> - all greens the sam, random if not activated\n";
  os<<"\t\tb <value> - all blues the sam, random if not activated\n";
  os<<"\t\ta <value> - all alphas the same, if no value is given, the alphas are random, if not activated, the alphas are opaque\n";
  return os;
}

std::ostream& log_cla_err(std::ostream& os, int err, int min, int max){
  os<<err<<" args were given\n";
  os<<"Give at least "<<min<<'\n';
  os<<"Give at most  "<<max<<'\n';
  return log_help(os);
}
