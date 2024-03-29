/* Snownews - A lightweight console RSS newsreader
 * $Id: config.h 1146 2005-09-10 10:05:21Z kiza $
 * 
 * Copyright 2003 Oliver Feiler <kiza@kcore.de>
 * http://kiza.kcore.de/software/snownews/
 *
 * config.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "version.h"
#include "netio.h"

struct feed {
	char *feedurl;							/* Non hashified URL */
	char *feed;								/* Raw XML */
	int content_length;
	char *title;
	char *link;
	char *description;
	char *lastmodified;						/* Content of header as sent by the server. */
	int lasthttpstatus;
	char *content_type;
	netio_error_type netio_error;			/* See netio.h */
	int connectresult;						/* Socket errno */
	char *cookies;							/* Login cookies for this feed. */
	char *authinfo;							/* HTTP authinfo string. */
	char *servauth;							/* Server supplied authorization header. */
	struct newsitem * items;
	struct feed *next_ptr, *prev_ptr;
	int problem;							/* Set if there was a problem downloading the feed. */
	char *override;							/* Custom feed title. */
	char *original;							/* Original feed title. */
	char *perfeedfilter;					/* Pipe feed through this program before parsing. */
	int execurl;							/* Execurl? */
	int smartfeed;							/* 1: new items feed. */
	struct feedcategories * feedcategories;
};

struct newsitem {
	struct newsdata *data;
	struct newsitem *next_ptr, *prev_ptr;	/* Pointer to next/prev item in double linked list */
};

struct newsdata {
	struct feed *parent;
	int readstatus;							/* 0: unread, 1: read */
	char *title;
	char *link;
	char *description;
	char *hash;
	int date;
};

/* Global program keybindings. Loaded from setup:Config() */
struct keybindings {
	char next;
	char prev;
	char prevmenu;
	char quit;
	char addfeed;
	char deletefeed;
	char markread;
	char markunread;
	char markallread;
	char dfltbrowser;
	char moveup;
	char movedown;
	char feedinfo;
	char reload;
	char forcereload;
	char reloadall;
	char urljump;
	char urljump2;
	char changefeedname;
	char sortfeeds;
	char pdown;
	char pup;
	char categorize;
	char filter;
	char filtercurrent;
	char nofilter;
	char help;
	char about;
	char perfeedfilter;
	char andxor;
	char home;
	char end;
	char enter;
	char newheadlines;
	char typeahead;
};

/* Color definitions */
struct color {
	int newitems;
	int newitemsbold;
	int urljump;
	int urljumpbold;
	int feedtitle;
	int feedtitlebold;
};

extern struct feed *first_ptr;

#ifdef LOCALEPATH
#	include <libintl.h>
#	include <locale.h>
#endif

#ifdef LOCALEPATH
#	define _(String) gettext (String)
#else
#	define _(String) (String)
# 	define ngettext(Singular, Plural, n) (Plural)
#endif

#ifdef SUN
#	include "os-support.h"
#endif

#endif
