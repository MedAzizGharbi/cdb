#ifndef STATEMENT_H
#define STATEMENT_H

#include "row.h"
#include "input.h"
#include "table.h"

typedef enum {EXECUTE_SUCCESS, EXECUTE_TABLE_FULL} ExecuteResult;
typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT, PREPARE_SYNTAX_ERROR } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);
ExecuteResult execute_insert(Statement *statement, Table *table); 
ExecuteResult execute_select(Statement *statement, Table *table);
ExecuteResult execute_statement(Statement *statement, Table *table);
#endif // !STATEMENT_H
