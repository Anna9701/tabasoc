#include "assoc.h"

int main(){
  AssocTab t1, t2;

  t1["matrix"] = 87;
  t1["hubabuba"] = 991;

  cout << t1["matrix"] << endl << t1["hubabuba"] << endl << t1["haha"] << endl;

  t2 = t1;
  t2["matrix"] = 13;
  
  cout << t1["matrix"] << endl << t2["matrix"] << endl;

  return 0; 
}
