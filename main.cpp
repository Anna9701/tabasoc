#include "assoc.h"

int main(){
  AssocTabN t1;
  AssocTabR t2;
 
  t2["MAtrix"] = 87;
  t2["matrix"] = 10;
  cout << t2["MAtrix"] << endl;
  /*t1["hubabuba"] = 991;
  t2["MaM"] = 13;
  t2["kotek"] = 7;
  cout << "Bez: \n" << t1["mAtrix"] << endl << t1["hubabuba"] << endl << t1["haha"] << endl;
  cout << "Z rozroznianiem: \n" << t2["MAM"] << endl << t2["kotek"] << endl;
  t2 = t1;
  t2["matrix"] = 13;
  
  cout << t1["matrix"] << endl << t2["matrix"] << endl;
*/
  return 0; 
}
