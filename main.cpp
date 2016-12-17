#include "assoc.h"

int main(){
  AssocTabR t1, t2;
 
  t1["MAtrix"] = 87;
  t1["hubabuba"] = 991;

  cout << t1["mAtrix"] << endl << t1["hubabuba"] << endl << t1["haha"] << endl;

  t2 = t1;
  t2["matrix"] = 13;
  
  cout << t1["matrix"] << endl << t2["matrix"] << endl;

  return 0; 
}
