#ifndef TABLE_H
#define TABLE_H

#include "row.h"

#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4069
#define ROWS_PER_PAGE ( PAGE_SIZE / ROW_SIZE )
#define TABLE_MAX_ROWS ( ROWS_PER_PAGE * TABLE_MAX_PAGES )

typedef struct {
  uint32_t num_rows;
  void *pages[TABLE_MAX_PAGES];
} Table;

void *row_slot(Table *table, uint32_t row_num);

Table* new_table();
void free_table(Table* table);

#endif // !TABLE_H
