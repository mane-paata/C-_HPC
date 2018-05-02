//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//
#ifndef COO_HPP
#define COO_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Vector.hpp"

class COOMatrix {
private:
  typedef std::vector<double>::size_type size_type;

public:
  COOMatrix(size_type M, size_type N) : num_rows_(M), num_cols_(N) {}

  void push_back(size_type i, size_type j, double val) {
    assert(i < num_rows_ && i >= 0);
    assert(j < num_cols_ && j >= 0);

    row_indices_.push_back(i);
    col_indices_.push_back(j);
    storage_.push_back(val);
  }

  void clear() {
    row_indices_.clear();
    col_indices_.clear();
    storage_.clear();
  }
    
  void reserve(size_type n) {
    assert(n >= 0);

    row_indices_.reserve(n);
    col_indices_.reserve(n);
    storage_.reserve(n);
  }

  size_type num_rows()     const { return num_rows_; }
  size_type num_cols()     const { return num_cols_; }
  size_type num_nonzeros() const { return storage_.size(); }

  void matvec(const Vector& x, Vector& y) const {
    for (size_type k = 0; k < storage_.size(); ++k) {
      y(col_indices_[k]) += storage_[k] * x(col_indices_[k]);
    }
  }

  void trMatvec(const Vector& x, Vector& y) const {
    for (size_type k = 0; k < storage_.size(); ++k) {
      y(row_indices_[k]) += storage_[k] * x(col_indices_[k]);
    }
  }

  void streamMatrix(std::ostream& outputFile) const {
    assert(storage_.size() == row_indices_.size() && storage_.size() == col_indices_.size());

    outputFile << "AMATH 583 COOMATRIX" << std::endl;
    outputFile << num_rows_ << std::endl;
    outputFile << num_cols_ << std::endl;

    // Write data
    for (size_type i = 0; i < storage_.size(); ++i) {
      outputFile << row_indices_[i] << " ";
      outputFile << col_indices_[i] << " ";
      outputFile << std::setprecision(15) << std::scientific << storage_[i] << " ";
      outputFile << std::endl;
    }
  
    // Write tailer
    outputFile << "THIS IS THE END" << std::endl;
  }

private:
  size_type num_rows_, num_cols_;
  std::vector<size_type> row_indices_, col_indices_;
  std::vector<double> storage_;
};

#endif // COO_HPP
