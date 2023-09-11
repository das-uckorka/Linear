#include "matrixes.h"

// COMMON METHODS
matrix::matrix(){
  this->ROW = 2;
  this->COLUMN = 2;
  this->VALUES = new int[this->ROW * this->COLUMN];
  for (unsigned int i{}; i < this->size(); i++){
    this->VALUES[i] = 0;
  }
}
matrix::matrix(unsigned int ROW, unsigned int COLUMN){
  this->ROW = ROW;
  this->COLUMN = COLUMN;
  this->VALUES = new int[this->ROW * this->COLUMN];
  for (unsigned int i{}; i < this->size(); i++){
    this->VALUES[i] = 0;
  }
}
matrix::matrix(const matrix& other){
  this->ROW = other.ROW;
  this->COLUMN = other.COLUMN;


  this->VALUES = new int[this->ROW * this->COLUMN];
  for (unsigned int i{}; i < this->size(); i++){
    this->VALUES[i] = other.VALUES[i];
  }
}
matrix::~matrix(){
  delete[] this->VALUES;
}

// SETTING METHODS

void matrix::set(std::vector<int>& arr){
  if (arr.size() >= this->size()){
    for(unsigned int i = 0; i < this->size(); i++){
      this->VALUES[i] = arr[i];
    }
  }
}
unsigned int matrix::size() const{
  return this->ROW * this->COLUMN;
}
void matrix::print() const{
  for (unsigned int i{}; i < this->size(); i++){
    std::cout << this->VALUES[i] << ' ';
  }
  std::cout << std::endl;
}


// ARITHMETIC METHODS

matrix matrix::operator+ (const matrix& other){
  matrix NEW(this->ROW, this->COLUMN);
  for (unsigned int i{}; i < NEW.size(); i++){
    NEW.VALUES[i] = this->VALUES[i] + other.VALUES[i];
  }
  return NEW;
}

matrix matrix::operator- (const matrix& other){
  matrix NEW(this->ROW, this->COLUMN);
  for (unsigned int i{}; i < NEW.size(); i++){
    NEW.VALUES[i] = this->VALUES[i] - other.VALUES[i];
  }
  return NEW;
}

matrix matrix::operator* (const matrix& other){
  matrix NEW(other.ROW, this->COLUMN);
  for(unsigned int i{}; i < NEW.COLUMN; i++){
    for(unsigned int j{}; j < NEW.ROW; j++){
      for(unsigned int k{}; k < this->ROW; k++){
        NEW.VALUES[i * NEW.ROW + j] += this->VALUES[i * this->ROW + k]
                                      * other.VALUES[k * NEW.ROW + j];
      }
    }
  }
  return NEW;
}
