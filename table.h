#ifndef TABLE_H
#define TABLE_H

#include "pager.h"
#include "row.h"
#include <stdint.h>
#include <stdbool.h>

#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4096
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

typedef struct {
  uint32_t num_rows;
  Pager *pager;
} Table;

typedef struct {
  Table *table;
  uint32_t row_num;
  bool end_of_table;
} Cursor;

void *cursor_value(Cursor *cursor);
void cursor_advance(Cursor *cursor);

Cursor *table_start(Table *table);
Cursor *table_end(Table *table);

Table *db_open(const char *filename);
void free_table(Table *table);
void db_close(Table *table);

#endif // !TABLE_H
