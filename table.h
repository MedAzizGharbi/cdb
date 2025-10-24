#ifndef TABLE_H
#define TABLE_H

#include "row.h"
#include <cstdint>

const uint32_t PAGE_SIZE = 4069;
#define TABLE_MAX_PAGES 100
const uint32_t ROW_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROW_PER_PAGE * TABLE_MAX_PAGES;

typedef struct {
  uint32_t num_rows;
  void *pages[TABLE_MAX_PAGES];
} Table;

#endif // !TABLE_H
