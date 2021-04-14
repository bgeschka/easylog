#include "easylog.h"

static int easylog_timestamp(char *dest, int maxlen)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return strftime(dest, maxlen, EASYLOG_TIMEFORMAT, &tm);
}

static const char *easylog_getlogdir(){
	return getenv("EASYLOG_LOGDIR") ? getenv("EASYLOG_LOGDIR"):  EASYLOG_LOGDIR;
}

static const char *easylog_getlogfilepath(const char *logname)
{
	const char *logdir = easylog_getlogdir();
	mkdir(logdir, 0777);

	char timestamp[LOGTIMEFORMATLEN];
	easylog_timestamp(timestamp, LOGTIMEFORMATLEN);

	char path[ELMAXPATH];
	snprintf(path, ELMAXPATH, "%s/%s.%s.raw", logdir, logname, timestamp);

	return strdup(path);
}

FILE *easylog_getlogfd(const char *logname)
{
	FILE *fp = NULL;
	const char *logfilepath = easylog_getlogfilepath(logname);
	fp = fopen(logfilepath, "a");
	if(!fp) {
		fprintf(stderr, "could not open %s, using stderr(%s)\n", logfilepath, strerror(errno));
		return stderr;
	}

	return fp;
}

