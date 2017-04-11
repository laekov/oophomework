#include "Matrix.h"
#include <iostream>
#include <fstream>

void Matrix::load(std::string filename) {
	std::ifstream fin(filename);
	int n, m, a;
	fin >> n >> m;
	this->rows.clear();
	for (int i = 0; i < n; ++ i) {
		this->rows.push_back(std::vector<int>());
		for (int j = 0; j < m; ++ j) {
			fin >> a;
			this->rows[i].push_back(a);
		}
	}
	fin.close();
}

template <class ostream_t>
void Matrix::__display(ostream_t& outf) const {
	if (this->rows.size() > 0) {
		outf << "Displaying a matrix with n = " << this->rows.size() << " m = " << this->rows[0].size() << std::endl;
		for (std::vector<std::vector<int>>::const_iterator ia = this->rows.begin(); ia != this->rows.end(); ++ ia) {
			for (std::vector<int>::const_iterator ib = ia->begin(); ib != ia->end(); ++ ib) {
				outf.setf(std::ios::fixed);
				outf.width(12);
				outf << *ib;
			}
			outf << std::endl;
		}
	} else {
		outf << "Error: This matrix is not initialized\n";
	}
}

void Matrix::display() const {
	this->__display(std::cout);
}

void Matrix::display_product() const {
	std::cout << "The product is shown below\n";
	this->__display(std::cout);
}

int involution(const std::vector<int> &a, const std::vector<int>& b) {
	if (a.size() != b.size()) {
		throw ERROR_LENGTH;
	}
	int res(0);
	for (std::vector<int>::const_iterator ia = a.begin(), ib = b.begin(); ia != a.end() && ib != b.end(); ++ ia, ++ ib) {
		res += *ia * *ib;
	}
	return res;
}

Matrix Matrix::transposer() const {
	std::vector<std::vector<int>> res;
	for (std::vector<std::vector<int>>::const_iterator ia = this->rows.begin(); ia != this->rows.end(); ++ ia) {
		for (std::vector<int>::const_iterator ib = ia->begin(); ib != ia->end(); ++ ib) {
			if (ia == this->rows.begin()) {
				res.push_back(std::vector<int>());
			}
			res[ib - ia->begin()].push_back(*ib);
		}
	}
	return Matrix(res);
}

Matrix Matrix::multiply(const Matrix& b) const {
	Matrix c(b.transposer());
	std::vector<std::vector<int>> res;
	for (std::vector<std::vector<int>>::const_iterator ia = this->rows.begin(); ia != this->rows.end(); ++ ia) {
		std::vector<int> newRow;
		for (std::vector<std::vector<int>>::const_iterator ic = c.rows.begin(); ic != c.rows.end(); ++ ic) {
			newRow.push_back(involution(*ia, *ic));
		}
		res.push_back(newRow);
	}
	return Matrix(res);
}

void Matrix::save_product(std::string filename) const {
	std::ofstream fout(filename);
	this->__display(fout);
	fout.close();
}
