/*
 * Copyright 2005 Gentoo Foundation
 * Distributed under the terms of the GNU General Public License v2
 * $Header: /var/cvsroot/gentoo-projects/portage-utils/applets.h,v 1.7 2005/11/06 18:07:17 solar Exp $
 *
 * Copyright 2005 Ned Ludd        - <solar@gentoo.org>
 * Copyright 2005 Mike Frysinger  - <vapier@gentoo.org>
 */

#ifndef _QAPPLETS_H_
#define _QAPPLETS_H_

/* applet prototypes */
int q_main(int, char **);
int qcheck_main(int, char **);
int qdepends_main(int, char **);
int qfile_main(int, char **);
int qlist_main(int, char **);
int qlop_main(int, char **);
int qsearch_main(int, char **);
int qsize_main(int, char **);
int qtbz2_main(int, char **);
int quse_main(int, char **);
int qxpak_main(int, char **);
int qpkg_main(int, char **);
int qgrep_main(int, char **);

typedef int (*APPLET)(int, char **);

/* applets we support */
typedef enum {
	FIRST_APPLET = 0,
	APPLET_Q = 0,
	APPLET_QCHECK = 1,
	APPLET_QDEPENDS = 2,
	APPLET_QFILE = 3,
	APPLET_QGREP = 4,
	APPLET_QLIST = 5,
	APPLET_QLOP = 6,
	APPLET_QPKG = 7,
	APPLET_QSEARCH = 8,
	APPLET_QSIZE = 9,
	APPLET_QTBZ2 = 10,
	APPLET_QUSE = 11,
	APPLET_QXPAK = 12,
	LAST_APPLET = 12
} applets_enum;

struct applet_t {
	const char *name;
	/* int *func; */
	APPLET func;
	const char *opts;
	const char *desc;
} applets[] = {
	/* q must always be the first applet */
	{"q",         q_main,         "<applet> <args>", "virtual applet"},
	{"qcheck",    qcheck_main,    "<pkgname>",       "verify mtimes/digests"},
	{"qdepends",  qdepends_main,  "<pkgname>",       "show dependency info"},
	{"qfile",     qfile_main,     "<filename>",      "list all pkgs owning files"},
	{"qgrep",     qgrep_main,     "<misc args>",     "grep in ebuilds"},
	{"qlist",     qlist_main,     "<pkgname>",       "list files owned by pkgname"},
	{"qlop",      qlop_main,      "<pkgname>",       "emerge log analyzer"},
	{"qpkg",      qpkg_main,      "<misc args>",     "manipulate Gentoo binpkgs"},
	{"qsearch",   qsearch_main,   "<regex>",         "search pkgname/desc"},
	{"qsize",     qsize_main,     "<pkgname>",       "calculate size usage"},
	{"qtbz2",     qtbz2_main,     "<misc args>",     "manipulate tbz2 packages"},
	{"quse",      quse_main,      "<useflag>",       "find pkgs using useflags"},
	{"qxpak",     qxpak_main,     "<misc args>",     "manipulate xpak archives"},


	/* aliases for equery capatability */
	{"belongs",   qfile_main,     NULL, NULL},
	/*"changes"*/
	{"check",     qcheck_main,    NULL, NULL},
	{"depends",   qdepends_main,  NULL, NULL},
	/*"depgraph"*/
	{"files",     qlist_main,     NULL, NULL},
	/*"glsa"*/
	{"hasuse",    quse_main,      NULL, NULL},
	/*"list"*/
	{"size",      qsize_main,     NULL, NULL},
	/*"stats"*/
	/*"uses"*/
	/*"which"*/

	/* alias for quickpkg */
	{"uickpkg",   qpkg_main,      NULL, NULL},

	{NULL, NULL, NULL, NULL}
};

#endif
