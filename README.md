# easylog
A simple flat-file logging library for C

Easylog creates logfiles in a designated log directory(./logs or LOGDIR environment variable)

    easylog("DEBUG", "%s", "Testing the debug messages");
    easylog("INFO", "%s", "Testing the info messages");

will result in two logfiles beeing created: ./logs/DEBUG-21-04-14-21-29.raw ./logs/INFO-21-04-14-21-29.raw

    example.c:9 main() Testing the debug messages
    example.c:10 main() Testing the info messages

By changing the LOGTIMEFORMAT in easylog.h you can change the timeframes that will end up in a single file:

    #define LOGTIMEFORMAT "%Y-%m-%d-%H-%M"
    // #define LOGTIMEFORMAT "%Y-%m-%d-%H" //creates a log file for every hour
    // #define LOGTIMEFORMAT "%Y-%m-%d" //creates a log file for every day
