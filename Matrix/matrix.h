#include <iostream>
#include <vector>

namespace linear {
	class matrix {
	private:
		unsigned int ROW;
		unsigned int COLUMN;
		int** VALUES;
	public:
		matrix();
		matrix(unsigned int, unsigned int);
		matrix(const matrix&);

		void set(const std::vector < std::vector<int>>&);
		void set(const int*);
		void print() const;

		matrix operator+ (const matrix&);
		matrix operator- (const matrix&);

		~matrix();
	};


}