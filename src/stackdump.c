#include <stdlib.h>
#include <signal.h>
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>

void sigQuitHandler(int signal) {

  char* cmd = "capture.output(print(sys.calls()), file=stderr())";

  SEXP cmdSexp, cmdexpr;
  ParseStatus status;
  PROTECT(cmdSexp = allocVector(STRSXP, 1));
  SET_STRING_ELT(cmdSexp, 0, mkChar(cmd));
  cmdexpr = PROTECT(R_ParseVector(cmdSexp, -1, &status, R_NilValue));
  if (status != PARSE_OK) {
    UNPROTECT(2);
    error("invalid call %s", cmd);
  }
  /* Loop is needed here as EXPSEXP will be of length > 1 */
  for(int i = 0; i < length(cmdexpr); i++)
    eval(VECTOR_ELT(cmdexpr, i), R_GlobalEnv);
  UNPROTECT(2);
  exit(EXIT_FAILURE);
}

extern SEXP registerSigQuitHandler(SEXP ignored) {
  signal(SIGQUIT, sigQuitHandler);
  return R_NilValue;
}
