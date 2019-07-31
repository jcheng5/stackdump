# Very dangerous to pass quit=FALSE. Don't trust the process after that!
init <- function(silent=FALSE, quit=FALSE) {
  .Call(registerSigQuitHandler, quit)
  if (!isTRUE(silent)) {
    maybeExit <- ifelse(isTRUE(quit), " and exit", "")
    message("Stack dump handler attached.\nRun `kill -SIGQUIT ", Sys.getpid(), "` in a terminal to print a stack trace", maybeExit, ".")
  }
  invisible()
}
