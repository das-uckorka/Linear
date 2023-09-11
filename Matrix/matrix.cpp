<<<<<<< HEAD
#include "matrixes.h"
=======
#include "matrix.h"

namespace linear {
	matrix::matrix(){
		this->ROW = 2;
		this->COLUMN = 2;
		this->VALUES = new int* [this->ROW];
		for (unsigned int _ind{}; _ind < this->ROW; _ind++) {
			this->VALUES[_ind] = new int[this->COLUMN];
		}
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = 0;
			}
		}
	}
	matrix::matrix(unsigned int size_row, unsigned int size_column) {
		this->ROW = size_row;
		this->COLUMN = size_column;
		this->VALUES = new int* [this->ROW];
		for (unsigned int _ind{}; _ind < this->ROW; _ind++) {
			this->VALUES[_ind] = new int[this->COLUMN];
		}
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = 0;
			}
		}
	}

	matrix::matrix(const matrix& other){
		this->ROW = other.ROW;
		this->COLUMN = other.COLUMN;
		this->VALUES = new int* [this->ROW];
		for (unsigned int _ind{}; _ind < this->ROW; _ind++) {
			this->VALUES[_ind] = new int[this->COLUMN];
		}
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = 0;
			}
		}
	}

	void matrix::set(const std::vector<std::vector<int>>& array) {
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = array[_ind_row][_ind_column];
			}
		}
	}

	void matrix::set(const int* array){
		// Сделать проверку по длине массива
		unsigned int FLOOR = 0;
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = array[_ind_column * FLOOR + _ind_column];
			}
			FLOOR++;
		}
	}

	void matrix::print() const
	{
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				std::cout << this->VALUES[_ind_row][_ind_column] << '\t';
			}
			std::cout << '\n';
		}
	}

	matrix matrix::operator+(const matrix& other){
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] += other.VALUES[_ind_row][_ind_column];
			}
		}
		return *this;
	}

	matrix matrix::operator-(const matrix& other){
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] -= other.VALUES[_ind_row][_ind_column];
			}
		}
		return *this;
	}

	matrix::~matrix(){
		for (unsigned int _ind_row{}; _ind_row < ROW; _ind_row++) {
			delete[] this->VALUES[_ind_row];
		}
		delete[] this->VALUES;
	}
>>>>>>> a94c546330faf10ea48aa722872f1c88bd18afc6

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
