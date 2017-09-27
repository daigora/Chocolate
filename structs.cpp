/**
 * Diego Alejandro Rodriguez Ayala - 20142020068
 * Practica para estudiar el uso de plantillas y estructuras (templates and structs).
 */

#include<iostream>

using namespace std;

template <class T, class S>
struct struct_uno {
  T x;
  S y;
};

// S (S1 - int) (S2 - char)
template <class S1, class S2>
struct struct_s {

  int **w;
  struct_uno<S1,S2> u;
};

// P (P1 - int) (P2 - char)
template <class P1, class P2>
struct struct_p {

  int t;
  struct_uno<P1,P2> u1;
};

// L (L1 - float) (L2 - int)
template <class L1, class L2>
struct struct_l {

  struct_uno<L1,L2> n;
  int *f;
};

// H (H1 - char) (H2 - float)
template <class H1, class H2>
struct struct_h {

  int k;
  struct_uno<H1,H2> m;
};

// O (O1 - float) (O2 - int) (O3 - char)
template <class O1, class O2, class O3>
struct struct_o {

  struct_l<O1,O2> l;
  struct_h<O3,O1> h;
};

// R (R1 - int) (R2 - char) (R3 - float)
template <class R1, class R2, class R3>
struct struct_r {

  struct_p<R1,R2> p;
  struct_o<R3,R1,R2> o;
};

// G (G1 - int)
template <class G1>
struct struct_g {

  struct_uno<G1,G1> *f1;
  int *e;
};

// C (C1 - float) (C2 - char)
template <class C1, class C2>
struct struct_c {

  struct_uno<C1,C2> *z;
  struct_uno<C2,C2> v;
};

// D (D1 - float) (D2 - char)
template <class D1, class D2>
struct struct_d {

  struct_uno<D1,D1> a;
  int b;
  struct_c<D1,D2> c;
};

// Q (Q1 - int) (Q2 - float) (Q3 - char)
template <class Q1, class Q2, class Q3>
struct struct_q {

  struct_g<Q1> g;
  struct_d<Q2,Q3> d;
};

// Estructura principal (I1 - int) (I2 - char) (I3 - float)
template <class I1, class I2, class I3>
struct struct_i {

  struct_s<I1,I2> s;
  struct_r<I1,I2,I3> r;
  struct_q<I1,I3,I2> q;
};

int main(int argc, char const *argv[]) {

  // Estructura principal
  struct_i<int,char,float> prueba;

  // S
  int **w;
  struct_uno<int, char> u;
  struct_s<int,char> S;

  w = new int *[3];
  for (int i = 1; i <= 3; i++) {
    w[i-1] = new int[3];
    for (int j = 1; j <= 3; j++) {
      w[i-1][j-1] = i*j;
    }
  }

  u.x = 1;
  u.y = 'a';

  S.w = w;
  S.u = u;

  prueba.s = S;

  cout << "s:" << endl;
  cout << "\tw: " << endl;
  for (int i = 0; i < 3; i++) {
    cout << "\t";
    for (int j = 0; j < 3; j++) {
      cout << prueba.s.w[i][j] << " ";
    }
    cout << endl;
  }
  cout << "\n\tu:" << endl;
  cout << "\tx: " << prueba.s.u.x << endl;
  cout << "\ty: " << prueba.s.u.y << endl;

  // R
  struct_r<int,char,float> R;

  // P
  int t = 2;
  struct_uno<int,char> u1;
  struct_p<int,char> P;

  u1.x = 3;
  u1.y = 'b';

  P.t = t;
  P.u1 = u1;

  R.p = P;

  // O
  struct_o<float,int,char> O;

  // L
  struct_uno<float,int> n;
  int *f;
  struct_l<float,int> L;

  n.x = 1.1234;
  n.y = 4;

  f = new int[2];
  for (int i = 1; i <= 2; i++) {
    f[i-1] = i;
  }

  L.n = n;
  L.f = f;

  O.l = L;

  // H
  int k = 5;
  struct_uno<char,float> m;
  struct_h<char,float> H;

  m.x = 'c';
  m.y = 2.1234;

  H.k = k;
  H.m = m;

  O.h = H;

  R.o = O;

  prueba.r = R;

  cout << "r:" << endl;
  cout << "\tp:" << endl;
  cout << "\t\tt: " << prueba.r.p.t << endl;
  cout << "\n\t\tu1:" << endl;
  cout << "\t\tx: " << prueba.r.p.u1.x << endl;
  cout << "\t\ty: " << prueba.r.p.u1.y << endl;

  cout << "\to:" << endl;
  cout << "\t\tl:" << endl;
  cout << "\t\t\tn:" << endl;
  cout << "\t\t\tx: " << prueba.r.o.l.n.x << endl;
  cout << "\t\t\ty: " << prueba.r.o.l.n.y << endl;
  cout << "\n\t\t\tf:" << endl;
  for (int i = 0; i < 2; i++) {
    cout << "\t\t\t" << prueba.r.o.l.f[i] << endl;
  }

  cout << "\t\th:" << endl;
  cout << "\t\t\tk: " << prueba.r.o.h.k << endl;
  cout << "\n\t\t\tm:" << endl;
  cout << "\t\t\tx: " << prueba.r.o.h.m.x << endl;
  cout << "\t\t\ty: " << prueba.r.o.h.m.y << endl;

  // Q
  struct_q<int,float,char> Q;

  // G
  struct_uno<int,int> *f1 = new struct_uno<int,int>;
  int *e;
  struct_g<int> G;

  f1->x = 6;
  f1->y = 7;

  e = new int[2];
  for (int i = 1; i <= 2; i++) {
    e[i-1] = i;
  }

  G.f1 = f1;
  G.e = e;

  Q.g = G;

  // D
  struct_uno<float,float> a;
  int b = 8;
  struct_d<float,char> D;

  a.x = 3.1234;
  a.y = 4.1234;

  D.a = a;
  D.b = b;

  // C
  struct_uno<float,char> *z = new struct_uno<float,char>;
  struct_uno<char,char> v;
  struct_c<float,char> C;

  z->x = 5.1234;
  z->y = 'd';

  v.x = 'e';
  v.y = 'f';

  C.z = z;
  C.v = v;

  D.c = C;

  Q.d = D;

  prueba.q = Q;

  cout << "q:" << endl;
  cout << "\tg:" << endl;
  cout << "\t\tf:" << endl;
  cout << "\t\tx: " << prueba.q.g.f1->x << endl;
  cout << "\t\ty: " << prueba.q.g.f1->y << endl;
  cout << "\n\t\te:" << endl;
  for (int i = 0; i < 2; i++) {
    cout << "\t\t" << prueba.q.g.e[i] << endl;
  }

  cout << "\td:" << endl;
  cout << "\t\ta:" << endl;
  cout << "\t\tx: " << prueba.q.d.a.x << endl;
  cout << "\t\ty: " << prueba.q.d.a.y << endl;

  cout << "\n\t\tb: " << prueba.q.d.b << endl;

  cout << "\n\t\tc:" << endl;
  cout << "\t\t\tz:" << endl;
  cout << "\t\t\tx: " << prueba.q.d.c.z->x << endl;
  cout << "\t\t\ty: " << prueba.q.d.c.z->y << endl;
  cout << "\n\t\t\tv:" << endl;
  cout << "\t\t\tx: " << prueba.q.d.c.v.x << endl;
  cout << "\t\t\ty: " << prueba.q.d.c.v.y << endl;

  return 0;
}
