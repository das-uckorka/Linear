#pragma once

#include <vector>
#include <iostream>

  class matrix{
  private:
    unsigned int ROW;
    unsigned int COLUMN;
    int* VALUES;
  public:

    matrix();
    matrix(unsigned int, unsigned int);
    matrix(const matrix&);
    ~matrix();

    void set(std::vector<int>&);
    void print() const;
    unsigned int size() const;

  	matrix operator+ (const matrix&);
  	matrix operator- (const matrix&);
  	matrix operator* (const matrix&);

  };
