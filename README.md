McEliece asymmetric encryption. This implementation is not current. Please refer to https://github.com/textbrowser/spot-on/blob/master/branches/trunk/Common/spot-on-mceliece.cc.

The implementation is based on the PKC Calculator by Marek Repka. Other reference papers included (papers.d).
Divisions by zero may occur. If this is a concern, please see mcnoodle_private_key::mcnoodle_private_key() and adjust the generator-discovery algorithm.

Tested on Debian AMD 64-bit, Debian ARM 32-bit, Debian PowerPC 32-bit, FreeBSD 32-bit, and Windows 7 with Cygwin.
