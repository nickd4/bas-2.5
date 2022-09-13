/* config.h.  Generated from config.h.in by configure.  */
/* The version string */
#define VERSION "2.5"

/* The package name. */
#define PACKAGE @PACKAGE@

/* Do you have tgetent()? */
#define HAVE_TGETENT 1

/* Should we need to include termcap.h? */
/* #undef HAVE_TERMCAP_H */

/* Should we need to include curses.h? */
/* #undef HAVE_CURSES_H */

/* Is there a tgmath.h? */
#define HAVE_TGMATH_H 1

/* Define this as 1 if your system has lrint(). */
/* #undef HAVE_LRINT */

/* Define this as 1 if your system has nanosleep(). */
/* #undef HAVE_NANOSLEEP */

/* What does tputs return? */
/* #undef TPUTS_RETURNS_VOID */

/* Define as 1 if you use dmalloc. */
/* #undef USE_DMALLOC */

/* Define either for large file support, if your OS needs them. */
/* #undef _FILE_OFFSET_BITS */
/* #undef _LARGE_FILES */

/* Define if you have the msgfmt(1) program and the gettext(3) function. */
/* #define HAVE_GETTEXT 1 */

/* Define if timeouts do not work in your termios (broken termios). */
#define USE_SELECT 1
