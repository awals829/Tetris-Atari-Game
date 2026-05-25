#ifndef TYPE_H
#define TYPE_H

#define UINT32_SIZE_BITS 32
#define UINT16_SIZE_BITS 16
#define UINT8_SIZE_BITS 8

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

#define OFFSET_TO_UINT32(X,Y) (X >> 5) + (Y << 4) + (Y << 2) 
#define OFFSET_TO_UINT16(X,Y) (X >> 4) + (Y << 5) + (Y << 3)
#define OFFSET_TO_UINT8(X,Y)  (X >> 3) + (Y << 6) + (Y << 4)
/*
static inline UINT32 OFFSET_TO_UINT32(UINT32 X, UINT32 Y) {
    return (X >> 5) + (Y << 4) + (Y << 2);
}
static inline UINT32 OFFSET_TO_UINT16(UINT32 X, UINT32 Y) {
    return (X >> 4) + (Y << 5) + (Y << 3);
}
static inline UINT32 OFFSET_TO_UINT8(UINT32 X, UINT32 Y) {
    return (X >> 3) + (Y << 6) + (Y << 4);
}
*/ 
#endif