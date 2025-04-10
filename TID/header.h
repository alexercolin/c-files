#ifndef HEADER_H
#define HEADER_H

 struct Values {
    int value;
};

void print_message(struct Values *value);
void read_values(struct Values *val);
void allocate(struct Values **value);



#endif // HEADER_H 