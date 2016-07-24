#ifndef _mcnoodle_h_
#define _mcnoodle_h_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/nondet_random.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/random.hpp>

#ifdef MCNOODLE_OS_UNIX
#endif

class mcnoodle
{
 public:
  mcnoodle(const size_t k, const size_t n, const size_t t);
  ~mcnoodle();

  /*
  ** The contents of plaintext must be deallocated via delete [].
  */

  bool decrypt(const char *ciphertext, const size_t ciphertext_size,
	       char *&plaintext, size_t *plaintext_size);
  template<class T> bool deserialize(const char *buffer,
				     const size_t buffer_size,
				     boost::numeric::ublas::matrix<T> &m);

  /*
  ** The contents of ciphertext must be deallocated via delete [].
  */

  bool encrypt(const char *plaintext, const size_t plaintext_size,
	       char *&ciphertext, size_t *ciphertext_size);

  /*
  ** The contents of buffer must be deallocated via delete [].
  */

  template<class T> bool serialize(char *&buffer,
				   size_t *buffer_size,
				   const boost::numeric::ublas::matrix<T> &m);

  bool prepareG(void);
  bool prepareGcar(void);
  bool prepareP(void);
  bool prepareS(void);

 private:
  size_t m_k;
  size_t m_n;
  size_t m_t;

  size_t minimumK(const size_t k) const
  {
#ifdef MCNOODLE_ASSUME_SAFE_PARAMETERS
    return k;
#else
    return std::max(static_cast<size_t> (644), k);
#endif
  }

  size_t minimumN(const size_t n) const
  {
#ifdef MCNOODLE_ASSUME_SAFE_PARAMETERS
    return n;
#else
    return std::max(static_cast<size_t> (1024), n);
#endif
  }

  size_t minimumT(const size_t t) const
  {
#ifdef MCNOODLE_ASSUME_SAFE_PARAMETERS
    return t;
#else
    return std::max(static_cast<size_t> (38), t);
#endif
  }
};

#endif
