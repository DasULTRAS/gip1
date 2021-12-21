#ifndef POST_MODUL_H_
#define POST_MODUL_H_

struct modul {
  char titel[64];
  char abkuerzung[5];
  unsigned int workload, credits, semester, dauer;
};

void print_format(int zeilen);
void print_modul(struct modul modul);

#endif  // POST_MODUL_H_
