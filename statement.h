#ifndef STATEMENT_H
#define STATEMENT_H

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* statement.c */
struct Value *stmt_CALL PARAMS((struct Value *value));
struct Value *stmt_CASE PARAMS((struct Value *value));
struct Value *stmt_CHDIR_MKDIR PARAMS((struct Value *value));
struct Value *stmt_CLEAR PARAMS((struct Value *value));
struct Value *stmt_CLOSE PARAMS((struct Value *value));
struct Value *stmt_CLS PARAMS((struct Value *value));
struct Value *stmt_COLOR PARAMS((struct Value *value));
struct Value *stmt_DATA PARAMS((struct Value *value));
struct Value *stmt_DEFFN_DEFPROC_FUNCTION_SUB PARAMS((struct Value *value));
struct Value *stmt_DEC_INC PARAMS((struct Value *value));
struct Value *stmt_DEFINT_DEFDBL_DEFSTR PARAMS((struct Value *value));
struct Value *stmt_DELETE PARAMS((struct Value *value));
struct Value *stmt_DIM PARAMS((struct Value *value));
struct Value *stmt_DISPLAY PARAMS((struct Value *value));
struct Value *stmt_DO PARAMS((struct Value *value));
struct Value *stmt_DOcondition PARAMS((struct Value *value));
struct Value *stmt_EDIT PARAMS((struct Value *value));
struct Value *stmt_ELSE_ELSEIFELSE PARAMS((struct Value *value));
struct Value *stmt_END PARAMS((struct Value *value));
struct Value *stmt_ENDIF PARAMS((struct Value *value));
struct Value *stmt_ENDFN PARAMS((struct Value *value));
struct Value *stmt_ENDPROC_SUBEND PARAMS((struct Value *value));
struct Value *stmt_ENDSELECT PARAMS((struct Value *value));
struct Value *stmt_ENVIRON PARAMS((struct Value *value));
struct Value *stmt_FNEXIT PARAMS((struct Value *value));
struct Value *stmt_COLON_EOL PARAMS((struct Value *value));
struct Value *stmt_QUOTE_REM PARAMS((struct Value *value));
struct Value *stmt_EQ_FNRETURN_FNEND PARAMS((struct Value *value));
struct Value *stmt_ERASE PARAMS((struct Value *value));
struct Value *stmt_EXITDO PARAMS((struct Value *value));
struct Value *stmt_EXITFOR PARAMS((struct Value *value));
struct Value *stmt_FIELD PARAMS((struct Value *value));
struct Value *stmt_FILES PARAMS((struct Value *value));
struct Value *stmt_FOR PARAMS((struct Value *value));
struct Value *stmt_GET_PUT PARAMS((struct Value *value));
struct Value *stmt_GOSUB PARAMS((struct Value *value));
struct Value *stmt_RESUME_GOTO PARAMS((struct Value *value));
struct Value *stmt_KILL PARAMS((struct Value *value));
struct Value *stmt_LET PARAMS((struct Value *value));
struct Value *stmt_LINEINPUT PARAMS((struct Value *value));
struct Value *stmt_LIST_LLIST PARAMS((struct Value *value));
struct Value *stmt_LOAD PARAMS((struct Value *value));
struct Value *stmt_LOCAL PARAMS((struct Value *value));
struct Value *stmt_LOCATE PARAMS((struct Value *value));
struct Value *stmt_LOCK_UNLOCK PARAMS((struct Value *value));
struct Value *stmt_LOOP PARAMS((struct Value *value));
struct Value *stmt_LOOPUNTIL PARAMS((struct Value *value));
struct Value *stmt_LSET_RSET PARAMS((struct Value *value));
struct Value *stmt_IDENTIFIER PARAMS((struct Value *value));
struct Value *stmt_IF_ELSEIFIF PARAMS((struct Value *value));
struct Value *stmt_IMAGE PARAMS((struct Value *value));
struct Value *stmt_INPUT PARAMS((struct Value *value));
struct Value *stmt_MAT PARAMS((struct Value *value));
struct Value *stmt_MATINPUT PARAMS((struct Value *value));
struct Value *stmt_MATPRINT PARAMS((struct Value *value));
struct Value *stmt_MATREAD PARAMS((struct Value *value));
struct Value *stmt_MATREDIM PARAMS((struct Value *value));
struct Value *stmt_MATWRITE PARAMS((struct Value *value));
struct Value *stmt_NAME PARAMS((struct Value *value));
struct Value *stmt_NEW PARAMS((struct Value *value));
struct Value *stmt_NEXT PARAMS((struct Value *value));
struct Value *stmt_ON PARAMS((struct Value *value));
struct Value *stmt_ONERROR PARAMS((struct Value *value));
struct Value *stmt_ONERRORGOTO0 PARAMS((struct Value *value));
struct Value *stmt_ONERROROFF PARAMS((struct Value *value));
struct Value *stmt_OPEN PARAMS((struct Value *value));
struct Value *stmt_OPTIONBASE PARAMS((struct Value *value));
struct Value *stmt_OPTIONRUN PARAMS((struct Value *value));
struct Value *stmt_OPTIONSTOP PARAMS((struct Value *value));
struct Value *stmt_OUT_POKE PARAMS((struct Value *value));
struct Value *stmt_PRINT_LPRINT PARAMS((struct Value *value));
struct Value *stmt_RANDOMIZE PARAMS((struct Value *value));
struct Value *stmt_READ PARAMS((struct Value *value));
struct Value *stmt_COPY_RENAME PARAMS((struct Value *value));
struct Value *stmt_RENUM PARAMS((struct Value *value));
struct Value *stmt_REPEAT PARAMS((struct Value *value));
struct Value *stmt_RESTORE PARAMS((struct Value *value));
struct Value *stmt_RETURN PARAMS((struct Value *value));
struct Value *stmt_RUN PARAMS((struct Value *value));
struct Value *stmt_SAVE PARAMS((struct Value *value));
struct Value *stmt_SELECTCASE PARAMS((struct Value *value));
struct Value *stmt_SHELL PARAMS((struct Value *value));
struct Value *stmt_SLEEP PARAMS((struct Value *value));
struct Value *stmt_STOP PARAMS((struct Value *value));
struct Value *stmt_SUBEXIT PARAMS((struct Value *value));
struct Value *stmt_SWAP PARAMS((struct Value *value));
struct Value *stmt_SYSTEM PARAMS((struct Value *value));
struct Value *stmt_TROFF PARAMS((struct Value *value));
struct Value *stmt_TRON PARAMS((struct Value *value));
struct Value *stmt_TRUNCATE PARAMS((struct Value *value));
struct Value *stmt_UNNUM PARAMS((struct Value *value));
struct Value *stmt_UNTIL PARAMS((struct Value *value));
struct Value *stmt_WAIT PARAMS((struct Value *value));
struct Value *stmt_WHILE PARAMS((struct Value *value));
struct Value *stmt_WEND PARAMS((struct Value *value));
struct Value *stmt_WIDTH PARAMS((struct Value *value));
struct Value *stmt_WRITE PARAMS((struct Value *value));
struct Value *stmt_XREF PARAMS((struct Value *value));
struct Value *stmt_ZONE PARAMS((struct Value *value));

#undef PARAMS

#endif
