#ifndef COMMON_H
#define COMMON_H

#include <string.h>
#include <stdio.h>
#include <time.h>

#define __APP_VERION__ "AFT10C-V1.0-2021/9/3"


#define BIN_DIR "/home/root/"



#define PRINT(fmt, ...) do { \
                            struct timespec tv; clock_gettime(CLOCK_MONOTONIC, &tv); \
                            printf("[%ld.%03ld][%s][F:%s][L:%d] >> ", tv.tv_sec, tv.tv_nsec/1000000, strrchr(__FILE__, '/')+1, __FUNCTION__, __LINE__); printf(fmt, ##__VA_ARGS__); \
                        }while(0)

#define ENTER(fmt, ...) do { \
                            struct timespec tv; clock_gettime(CLOCK_MONOTONIC, &tv); \
                            printf("[%ld.%03ld][%s][F:%s][L:%d] >> Enter\n", tv.tv_sec, tv.tv_nsec/1000000, strrchr(__FILE__, '/')+1, __FUNCTION__, __LINE__); \
                        }while(0)
#define LEAVE(fmt, ...) do { \
                            struct timespec tv; clock_gettime(CLOCK_MONOTONIC, &tv); \
                            printf("[%ld.%03ld][%s][F:%s][L:%d] >> Leave\n", tv.tv_sec, tv.tv_nsec/1000000, strrchr(__FILE__, '/')+1, __FUNCTION__, __LINE__); \
                        }while(0)

#define ERROR(fmt, ...) do { \
                            struct timespec tv; clock_gettime(CLOCK_MONOTONIC, &tv); \
                            printf("[%ld.%03ld][%s][F:%s][L:%d] ERROR!! >> ", tv.tv_sec, tv.tv_nsec/1000000, strrchr(__FILE__, '/')+1, __FUNCTION__, __LINE__); printf(fmt, ##__VA_ARGS__); \
                        }while(0)



typedef struct _pos
{
    int x;
    int y;
}Point;

typedef struct _size
{
    int width;
    int height;
}Size;


#define MSG_TYPE_KEY 1




#endif // COMMON_H
