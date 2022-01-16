#ifndef POST_MODULE_H_
#define POST_MODULE_H_

struct module {
  char title[64];
  char abbreviation[5];
  unsigned int workload, credits, semester, duration;
};

void print_format(int lines);
void print_module(struct module module);

#endif  // POST_MODULE_H_
