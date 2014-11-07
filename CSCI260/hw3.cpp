#include <iostream>
using namespace std;
main() {
                                                                               
  struct{
    int x[100];
    int var1;
    int y[10];
    } foo;
  int var2;
  long i;
  int *p, *q;
  short int *s;
  long int *l;
                                                                               
  for (i=0; i<100; i++) foo.x[i]=200+i;
  for (i=0; i<10; i++)  foo.y[i]=400+i;
  foo.var1 = 350;
                                                                               
  cout << sizeof(*s) << "\n";
  cout << sizeof(*p) << "\n";
  cout << sizeof(*l) << "\n";
  cout << sizeof(s) << "\n"; //MOD
  q = (int *) &foo;    cout << q << "\n";
  p=&(foo.x[5]);       cout << *p << "\n";

 cout << "variable addresses"<<endl;
 cout << "foo: " << &foo<<endl;
 cout << "x: " << &foo.x[0]<<endl;
 cout << "y: " << &foo.y[0]<<endl;
cout << "x[1]: " << &foo.x[1]<<endl;
 cout << "y[1]: " << &foo.y[1]<<endl;

 cout << "var1: " << &foo.var1<<endl;
 cout << "var2: " << &var2<<endl;
 cout << "i: " << &i<<endl;
 cout << "p: " << &p<<endl;
 cout << "q: " << &q<<endl;
 cout << "s: " << &s<<endl;
 cout << "l: " << &l<<endl;

  // POINT 1 
  q = (int *) &var2;   cout << q << "\n";
// cout << "q: " << &q<<endl;
  q = p+16;            cout << *q << "\n";
  i = ((long) p) + 16;
  q = (int *) i;       cout << *q << "\n";
  s = (short *) i;     cout << *s << "\n";
  l = (long *) i;      cout << *l << "\n";
  q = p+95;            cout << *q << "\n";
  q = p+98;            cout << *q << "\n";
  i = ((long) p) + 17;
  q = (int *) i;       cout << *q << "\n";
  q = p + 104;     cout << *q << "\n";
//  q = (int *) (((int) p) + 1);  cout << *q << "\n";
//i kept getting errors trying to run the above line

 int *z;
 int test = 20;
 z = &test;
 cout << "z: " << z <<endl;
 cout << "test: " << &test<<endl;
 z = z+1;
 cout << "z: " << z <<endl;

}
