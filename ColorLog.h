#define KNORMAL  "\x1B[0m"
#define KRED     "\x1B[31m"
#define KGREEN   "\x1B[32m"
#define KYELLOW   "\x1B[33m"
#define KBLUE    "\x1B[34m"
#define KMAGENTA "\x1B[35m"
#define KCYAN    "\x1B[36m"
#define KWHITE   "\x1B[37m"
 
#define REDLog(fmt, ...) NSLog((@"%s" fmt @"%s"),KRED,##__VA_ARGS__,KNORMAL)
#define GREENLog(fmt, ...) NSLog((@"%s" fmt @"%s"),KGREEN,##__VA_ARGS__,KNORMAL)
#define YELLOWLog(fmt, ...) NSLog((@"%s" fmt @"%s"),KYELLOW,##__VA_ARGS__,KNORMAL)
#define BLUELog(fmt, ...) NSLog((@"%s" fmt @"%s"),KBLUE,##__VA_ARGS__,KNORMAL)
#define MAGENTALog(fmt, ...) NSLog((@"%s" fmt @"%s"),KMAGENTA,##__VA_ARGS__,KNORMAL)
#define CYANLog(fmt, ...) NSLog((@"%s" fmt @"%s"),KCYAN,##__VA_ARGS__,KNORMAL)
#define WHITELog(fmt, ...) NSLog((@"%s" fmt @"%s"),KWHITE,##__VA_ARGS__,KNORMAL)
