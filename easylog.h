/*
 * MIT License
 *
 * Copyright (c) 2021 Bjoern H. Geschka <bjoern@geschka.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __EASYLOG_H__
#define __EASYLOG_H__

#ifndef ELDEFAULTLOGDIR
#define ELDEFAULTLOGDIR "./logs"
#endif /* ifndef ELDEFAULTLOGDIR */

#ifndef LOGTIMEFORMAT
#define LOGTIMEFORMAT "%Y-%m-%d-%H"
// #define LOGTIMEFORMAT "%Y-%m-%d-%H" //creates a log file for every hour
// #define LOGTIMEFORMAT "%Y-%m-%d-%H-%M" //creates a log file for every minute
#endif /* ifndef LOGTIMEFORMAT */

#define LOGTIMEFORMATLEN 32
#define ELMAXPATH 1024

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>

FILE *easylog_getlogfd(const char *logname);

#define __FILENAME__                                                    \
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define easylog(logname, form,...)					\
do {                                                                    \
	FILE *fp = easylog_getlogfd(logname);				\
        fprintf(fp,							\
		"%s:%d %s() " form "\n" ,                               \
		__FILENAME__,                                           \
		 __LINE__,                                              \
		__func__,                                               \
		##__VA_ARGS__						\
	);								\
	if(fp != stderr) fclose(fp);					\
} while (0)

#endif /* ifndef __EASYLOG_H__ */
