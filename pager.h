#ifndef PAGER_H
#define PAGER_H

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4096
typedef struct {
  int file_descriptor;
  uint32_t file_length;
  void *pages[TABLE_MAX_PAGES];
} Pager;

Pager *pager_open(const char *filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);



#endif // !PAGER_H
