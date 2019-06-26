#ifndef MEM_LAYOUT_H
#define MEM_LAYOUT_H

#define REGION_CODE_S_START 0x10000000
#define REGION_CODE_S_SIZE  0xFE00
#define REGION_VENEER_START 0x1000FE00
#define REGION_VENEER_SIZE  0x200
#define REGION_DATA_S_START 0x30000000
#define REGION_DATA_S_SIZE  0x8000
#define REGION_CONFIG_START 0x9DE00
#define REGION_CONFIG_SIZE  0x2000
#define REGION_CODE_NS_START 0x10000
#define REGION_CODE_NS_SIZE  0x72000
#define REGION_DATA_NS_START 0x20008000
#define REGION_DATA_NS_SIZE  0x3C000

#endif
