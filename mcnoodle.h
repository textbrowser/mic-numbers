#ifndef _mcnoodle_h_
#define _mcnoodle_h_

#include <boost/numeric/ublas/matrix.hpp>

typedef int mcnoodle_matrix_element_type_t;

class mcnoodle
{
 public:
  mcnoodle(const size_t k, const size_t n, const size_t t);
  mcnoodle
    (const boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> &Gcar,
     const size_t k,
     const size_t n,
     const size_t t);
  ~mcnoodle();
  bool decrypt(const char *ciphertext, const size_t ciphertext_size,
	       char *plaintext, size_t *plaintext_size);
  bool encrypt(const char *plaintext, const size_t plaintext_size,
	       char *ciphertext, size_t *ciphertext_size);

  size_t pSize(void) const
  {
    return m_P.size1(); // Square matrix.
  }

  size_t sSize(void) const
  {
    return m_S.size1(); // Square matrix.
  }

  void prepareP(void);
  void prepareS(void);
  void serializeGcar(char *buffer, const size_t buffer_size);
  void serializePinv(char *buffer, const size_t buffer_size);
  void serializeSinv(char *buffer, const size_t buffer_size);

 private:
  boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> m_Gcar;
  boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> m_P;
  boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> m_Pinv;
  boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> m_S;
  boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> m_Sinv;
  size_t m_k;
  size_t m_n;
  size_t m_t;
  void serialize
    (char *buffer,
     const size_t buffer_size,
     const boost::numeric::ublas::matrix<mcnoodle_matrix_element_type_t> &m);
};

#endif
