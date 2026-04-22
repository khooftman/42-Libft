STRLCPY(3bsd)                                   LOCAL                                   STRLCPY(3bsd)

NNAAMMEE
     ssttrrllccppyy, ssttrrllccaatt — size-bounded string copying and concatenation

LLIIBBRRAARRYY
     Utility functions from BSD systems (libbsd, -lbsd)

SSYYNNOOPPSSIISS
     ##iinncclluuddee <<ssttrriinngg..hh>>
     (See libbsd(7) for include usage.)

     _s_i_z_e___t
     ssttrrllccppyy(_c_h_a_r _*_d_s_t, _c_o_n_s_t _c_h_a_r _*_s_r_c, _s_i_z_e___t _s_i_z_e);

     _s_i_z_e___t
     ssttrrllccaatt(_c_h_a_r _*_d_s_t, _c_o_n_s_t _c_h_a_r _*_s_r_c, _s_i_z_e___t _s_i_z_e);

DDEESSCCRRIIPPTTIIOONN
     The ssttrrllccppyy() and ssttrrllccaatt() functions copy and concatenate strings respectively.  They are de‐
     signed to be safer, more consistent, and less error prone replacements for strncpy(3) and
     strncat(3).  Unlike those functions, ssttrrllccppyy() and ssttrrllccaatt() take the full size of the buffer
     (not just the length) and guarantee to NUL-terminate the result (as long as _s_i_z_e is larger than
     0 or, in the case of ssttrrllccaatt(), as long as there is at least one byte free in _d_s_t).  Note that a
     byte for the NUL should be included in _s_i_z_e.  Also note that ssttrrllccppyy() and ssttrrllccaatt() only oper‐
     ate on true “C” strings.  This means that for ssttrrllccppyy() _s_r_c must be NUL-terminated and for
     ssttrrllccaatt() both _s_r_c and _d_s_t must be NUL-terminated.

     The ssttrrllccppyy() function copies up to _s_i_z_e - 1 characters from the NUL-terminated string _s_r_c to
     _d_s_t, NUL-terminating the result.

     The ssttrrllccaatt() function appends the NUL-terminated string _s_r_c to the end of _d_s_t.  It will append
     at most _s_i_z_e - strlen(dst) - 1 bytes, NUL-terminating the result.

RREETTUURRNN VVAALLUUEESS
     The ssttrrllccppyy() and ssttrrllccaatt() functions return the total length of the string they tried to cre‐
     ate.  For ssttrrllccppyy() that means the length of _s_r_c.  For ssttrrllccaatt() that means the initial length
     of _d_s_t plus the length of _s_r_c.  While this may seem somewhat confusing, it was done to make
     truncation detection simple.

     Note, however, that if ssttrrllccaatt() traverses _s_i_z_e characters without finding a NUL, the length of
     the string is considered to be _s_i_z_e and the destination string will not be NUL-terminated (since
     there was no space for the NUL).  This keeps ssttrrllccaatt() from running off the end of a string.  In
     practice this should not happen (as it means that either _s_i_z_e is incorrect or that _d_s_t is not a
     proper “C” string).  The check exists to prevent potential security problems in incorrect code.

EEXXAAMMPPLLEESS
     The following code fragment illustrates the simple case:

           char *s, *p, buf[BUFSIZ];

           ...

           (void)strlcpy(buf, s, sizeof(buf));
           (void)strlcat(buf, p, sizeof(buf));

     To detect truncation, perhaps while building a pathname, something like the following might be
     used:

           char *dir, *file, pname[MAXPATHLEN];

           ...

           if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))
                   goto toolong;
           if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))
                   goto toolong;

     Since it is known how many characters were copied the first time, things can be sped up a bit by
     using a copy instead of an append:

           char *dir, *file, pname[MAXPATHLEN];
           size_t n;

           ...

           n = strlcpy(pname, dir, sizeof(pname));
           if (n >= sizeof(pname))
                   goto toolong;
           if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname) - n)
                   goto toolong;

     However, one may question the validity of such optimizations, as they defeat the whole purpose
     of ssttrrllccppyy() and ssttrrllccaatt().  As a matter of fact, the first version of this manual page got it
     wrong.

SSEEEE AALLSSOO
     snprintf(3), strncat(3), strncpy(3)

HHIISSTTOORRYY
     The ssttrrllccppyy() and ssttrrllccaatt() functions first appeared in OpenBSD 2.4, and made their appearance
     in FreeBSD 3.3.

BSD                                          May 31, 2007                                         BSD
