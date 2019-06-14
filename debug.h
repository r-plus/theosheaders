#ifndef __DEBUG_H
#define __DEBUG_H

#ifndef DEBUG_TAG
#define DEBUG_TAG "MyTweak"
#endif

#if DEBUG
# define Log(...) NSLog(@ DEBUG_TAG "! %s:%d: %@", __FILE__, __LINE__, [NSString stringWithFormat:__VA_ARGS__])
#else
# define Log(...)
#endif

#endif
