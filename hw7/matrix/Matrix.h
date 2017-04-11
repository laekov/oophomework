#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <string>
class Matrix {
	private:
		std::vector<std::vector<int>> rows;
		template <class ostream_t>
			void __display(ostream_t&) const;
		/* get the transposer of a matrix */
		Matrix transposer() const;
	public:
		Matrix() {}
		Matrix(std::string filename) {
			this->load(filename);
		}
		Matrix(std::vector<std::vector<int>> _rows): rows(_rows) {}
		Matrix(const Matrix& m) {
			this->rows = m.rows;
		}
		void load(std::string);
		void display() const;
		void display_product() const;
		Matrix multiply(const Matrix&) const;
		void save_product(std::string) const;
};

#define ERROR_LENGTH 0x38882992
#endif
