#include "solution.hpp"

std::vector<int> RotateRight(const std::vector<int>& vect,
                             unsigned int no_rotations) {
  unsigned int n = vect.size();
  if (n == 0) {
    return {};
  }

  unsigned int r = no_rotations % n;
  if (r == 0) {
    return vect;
  }

  std::vector<int> rotated_vect(n);
  for (unsigned int i = 0; i < n; ++i) {
    rotated_vect[(i + r) % n] = vect[i];
  }
  return rotated_vect;
}

std::vector<int> RotateChunks(const std::vector<int>& vect,
                              unsigned int chunk_size,
                              unsigned int no_rotations) {
  unsigned int n = vect.size();
  if (n == 0 || chunk_size == 0) {
    return {};
  }

  std::vector<int> rotated_chunks;

  for (unsigned int start = 0; start < n; start += chunk_size) {
    unsigned int end = start + chunk_size;
    if (end > n) {
      end = n;
    }

    std::vector<int> chunk;
    for (unsigned int i = start; i < end; ++i) {
      chunk.push_back(vect[i]);
    }

    std::vector<int> rotated = RotateRight(chunk, no_rotations);
    for (unsigned int i = 0; i < rotated.size(); ++i) {
      rotated_chunks.push_back(rotated[i]);
    }
  }

  return rotated_chunks;
}