#include <stdlib.h>
#include <signal.h>
#include <Rinternals.h>

void sigQuitHandler(int signal) {

  SEXP e;
  int errorOccurred;

  PROTECT(Rf_lang2(Rf_install("sink"), Rf_lang1(Rf_install("stderr"))));
  PROTECT(e = Rf_lang2(Rf_install("print"), Rf_lang1(Rf_install("sys.calls"))));
  R_tryEval(e, R_GlobalEnv, &errorOccurred);
  if (errorOccurred) {
    // meh
  }  
  UNPROTECT(2);
  exit(EXIT_FAILURE);
}

extern SEXP registerSigQuitHandler(SEXP ignored) {
  signal(SIGQUIT, sigQuitHandler);
  return R_NilValue;
}
