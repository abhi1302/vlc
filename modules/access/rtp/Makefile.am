# RTP plugin
access_LTLIBRARIES += librtp_plugin.la
librtp_plugin_la_SOURCES = \
	access/rtp/input.c \
	access/rtp/session.c \
	access/rtp/xiph.c \
	access/rtp/rtp.c access/rtp/rtp.h
librtp_plugin_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(srcdir)/access/rtp
librtp_plugin_la_CFLAGS = $(AM_CFLAGS)
librtp_plugin_la_LIBADD = $(SOCKET_LIBS) $(LIBPTHREAD)

# Secure RTP library
libvlc_srtp_la_SOURCES = access/rtp/srtp.c access/rtp/srtp.h
libvlc_srtp_la_CPPFLAGS = -I$(srcdir)/access/rtp
libvlc_srtp_la_CFLAGS = $(GCRYPT_CFLAGS)
libvlc_srtp_la_LDFLAGS = -static
libvlc_srtp_la_LIBADD = $(GCRYPT_LIBS) $(LIBPTHREAD)
srtp_test_recv_SOURCES = access/rtp/srtp-test-recv.c
srtp_test_recv_LDADD = libvlc_srtp.la
srtp_test_aes_SOURCES = access/rtp/srtp-test-aes.c
srtp_test_aes_LDADD = $(GCRYPT_LIBS)

librtp_plugin_la_DEPENDENCIES =
if HAVE_GCRYPT
noinst_LTLIBRARIES += libvlc_srtp.la

check_PROGRAMS += srtp-test-aes srtp-test-recv
TESTS += srtp-test-aes srtp-test-recv

librtp_plugin_la_CPPFLAGS += -DHAVE_SRTP
librtp_plugin_la_CFLAGS += $(GCRYPT_CFLAGS)
librtp_plugin_la_LIBADD += libvlc_srtp.la $(GCRYPT_LIBS)
librtp_plugin_la_DEPENDENCIES += libvlc_srtp.la
endif

#lcov-run:
#	rm -Rf *.gcda lcov
#	$(MAKE) $(AM_MAKEFLAGS) check
#
#lcov-pre.out:
#	lcov -c -d . -o lcov.tmp
#
#lcov.out: lcov-pre.out
#	lcov -r lcov.tmp '*test*' > lcov.out
#
#lcov: lcov.out
#	genhtml lcov.out -o lcov
#
#.PHONY: lcov-run
