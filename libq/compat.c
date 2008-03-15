/* Solaris compatible code */
#ifdef __sun__

#include <string.h>
#include <ctype.h>
#include <alloca.h>
#include <sys/dklabel.h>

#define S_BLKSIZE DK_DEVID_BLKSIZE

/* strcasestr is a GNU extention */
static char* strcasestr(const char *big, const char *little) {
	char* b = alloca((strlen(big) + 1) * sizeof(char));
	char* l = alloca((strlen(little) + 1) * sizeof(char));
	char* off;
	size_t i;
	for (i = 0; big[i]; i++) b[i] = (char)tolower(big[i]);
	for (i = 0; little[i]; i++) l[i] = (char)tolower(little[i]);
	off = strstr(b, l);
	return(off == NULL ? off : (char*)(big + (off - b)));
}

#undef  xasprintf
#define xasprintf(strp, fmt, args...) \
	do { /* xasprintf() */ \
		char str[BUFSIZ]; \
		if ((snprintf(str, sizeof(str)-1, fmt , ## args)) == -1) \
			err("Out of stack space?"); \
		str[sizeof(str)-1] = '\0'; \
		*strp = xstrdup(str); \
	} while (0)


#else /* __sun__ */
# include <sys/dir.h>
#endif

