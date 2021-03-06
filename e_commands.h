/*
 * Copyright (c) 2010, 2011 Ryan Flannery <ryan.flannery@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef E_COMMANDS_H
#define E_COMMANDS_H

#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>

#include "meta_info.h"
#include "medialib.h"
#include "playlist.h"

#include "compat.h"

/* from vitunes.c */
extern char *vitunes_dir;
extern char *playlist_dir;
extern char *db_file;

/* "main" functions for each command */
int ecmd_init(int argc, char *argv[]);
int ecmd_add(int argc, char *argv[]);
int ecmd_addurl(int argc, char *argv[]);
int ecmd_flush(int argc, char *argv[]);
int ecmd_check(int argc, char *argv[]);
int ecmd_rmfile(int argc, char *argv[]);
int ecmd_tag(int argc, char *argv[]);
int ecmd_update(int argc, char *argv[]);
int ecmd_help(int argc, char *argv[]);

/* help functions */
void ecmd_help_init(void);
void ecmd_help_add(void);
void ecmd_help_addurl(void);
void ecmd_help_check(void);
void ecmd_help_rmfile(void);
void ecmd_help_update(void);
void ecmd_help_flush(void);
void ecmd_help_tag(void);

/* e-command struct and set of commands */
struct ecmd {
   char *name;
   int   (*func)(int argc, char *argv[]);
   void  (*help)(void);
};

extern const struct ecmd ECMD_PATH[];
extern const int ECMD_PATH_SIZE;

#endif
