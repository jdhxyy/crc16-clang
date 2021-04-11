# crc16

## 介绍
查表法计算crc 16。模型是CRC-16/MODBUS，多项式是8005。

## 开源
- [github上的项目地址](https://github.com/jdhxyy/crc16-clang)
- [gitee上的项目地址](https://github.com/jdhxyy/crc16-clang)

## API
```c
// Crc16ReadByteFunc read byte for crc16 calculate
typedef uint8_t (*Crc16ReadByteFunc)(int offset);

// Checksum check sum.Module is CRC-16/MODBUS,polynomial is 8005
// return value is MSB
uint16_t Checksum(uint8_t* bytes, int size);

// ChecksumFromCallback check sum,read data from callback function then calculate
// This function can use calculate crc when data in flash or file
// Module is CRC-16/MODBUS,polynomial is 8005
// return value is MSB
uint16_t ChecksumFromCallback(Crc16ReadByteFunc readByte, int size);
```

## 测试
测试框架使用的是[适合于嵌入式系统的C语言单元测试框架:Scunit](https://blog.csdn.net/jdh99/article/details/100183066)

```c
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
```

输出:
```text
Suite:test crc16
-------------------->case:testCheckSum begin
testCheckSum tag:1 SCUNIT_ASSERT pass
testCheckSum tag:2 SCUNIT_ASSERT pass
-------------------->case:testCheckSum end

-------------------->case:testCheckSumFromCallback begin
testCheckSumFromCallback tag:2 SCUNIT_ASSERT pass
-------------------->case:testCheckSumFromCallback end
```
