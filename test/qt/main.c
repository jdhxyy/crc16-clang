#include <stdio.h>
#include "crc16.h"
#include "scunit.h"

static void testCheckSum(void);
static void testCheckSumFromCallback(void);
static uint8_t readData(int offset);

int main() {
    ScunitLoad((ScunitPrintFunc)printf);
    ScunitAddSuite("test crc16");
    ScunitAddTest("testCheckSum", testCheckSum);
    ScunitAddTest("testCheckSumFromCallback", testCheckSumFromCallback);
    return 0;
}

static void testCheckSum(void) {
    uint8_t arr1[] = {1, 2, 3};
    uint16_t crc = Checksum(arr1, 3);
    ScunitAssert(crc == 0x6161, "1");

    uint8_t arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    crc = Checksum(arr2, 9);
    ScunitAssert(crc == 0x0eb2, "2");
}

static void testCheckSumFromCallback(void) {
    uint16_t crc = ChecksumFromCallback(readData, 9);
    ScunitAssert(crc == 0x0eb2, "2");
}

static uint8_t readData(int offset) {
    static uint8_t arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    return arr[offset];
}
