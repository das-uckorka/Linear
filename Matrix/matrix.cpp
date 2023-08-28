#include "mult.h"

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
		unsigned int FLOOR = 1;
		for (unsigned int _ind_row{}; _ind_row < this->ROW; _ind_row++) {
			for (unsigned int _ind_column{}; _ind_column < this->COLUMN; _ind_column++) {
				this->VALUES[_ind_row][_ind_column] = array[_ind_row * FLOOR + _ind_column];
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

}
