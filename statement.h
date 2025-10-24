#ifndef STATEMENT_H
#define STATEMENT_H

#include "row.h"
#include "input.h"

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT, PREPARE_SYNTAX_ERROR } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;


PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);

void execute_statement(Statement *statement);
#endif // !STATEMENT_H
