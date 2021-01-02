#ifndef MY_DLOG
#define MY_DLOG

#ifdef DEBUG
    #ifdef __cplusplus
    extern "C" void MyDebugLog(NSString *formatString, ...);
    #else
    extern void MyDebugLog(NSString *formatString, ...);
    #endif

    #define DLog(...) MyDebugLog(__VA_ARGS__)
#else
    #define DLog(...)
#endif

#ifdef DEBUG

#ifndef LOG_PATH
#define LOG_PATH @"/var/mobile/Library/Preferences/z_my_share.log"
#endif

void MyDebugLog(NSString *formatString, ...) {
    @autoreleasepool {
        va_list args;
        va_start(args, formatString);
#if __has_feature(objc_arc)
        NSString *string = [[NSString alloc] initWithFormat:formatString arguments:args];
#else
        NSString *string = [[[NSString alloc] initWithFormat:formatString arguments:args] autorelease];
#endif
        va_end(args);

        NSFileHandle *fileHandle = [NSFileHandle fileHandleForWritingAtPath:LOG_PATH];
        if (!fileHandle) {
            [[NSFileManager defaultManager] createFileAtPath:LOG_PATH contents:nil attributes:nil];
            fileHandle = [NSFileHandle fileHandleForWritingAtPath:LOG_PATH];
        }
        if (!fileHandle) {
            return;
        }

        if (![string hasSuffix:@"\n"]) {
            string = [string stringByAppendingString:@"\n"];
        }
        @try {
            [fileHandle seekToEndOfFile];
            [fileHandle writeData:[string dataUsingEncoding:NSUTF8StringEncoding]];
        } @catch (NSException *e) {
            NSLog(@"Failed to log to file! ━Σ(ﾟДﾟ|||)━ %@", e);
            return;
        }
        [fileHandle closeFile];
    }
}
#endif
#endif
