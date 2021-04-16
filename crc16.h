// Copyright 2019-2021 The jdh99 Authors. All rights reserved.
// Look-up tables to implement crc16.Module is CRC-16/MODBUS,polynomial is 8005
// Authors: jdh99 <jdh821@163.com>

#ifndef CRC16_H
#define CRC16_H

#include <stdint.h>

// Crc16ReadByteFunc read byte for crc16 calculate
typedef uint8_t (*Crc16ReadByteFunc)(int offset);

// Crc16Checksum check sum.Module is CRC-16/MODBUS,polynomial is 8005
// return value is MSB
uint16_t Crc16Checksum(uint8_t* bytes, int size);

// Crc16ChecksumFromCallback check sum,read data from callback function then calculate
// This function can use calculate crc when data in flash or file
// Module is CRC-16/MODBUS,polynomial is 8005
// return value is MSB
uint16_t Crc16ChecksumFromCallback(Crc16ReadByteFunc readByte, int size);

#endif
