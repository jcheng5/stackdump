# Very dangerous to pass quit=FALSE. Don't trust the process after that!
init <- function(silent=FALSE, quit=TRUE) {
  .Call(registerSigQuitHandler, quit)
  if (!isTRUE(silent)) {
    maybeExit <- ifelse(isTRUE(quit), " and exit", "")
    message("Stack dump handler attached.\nSend SIGQUIT to print stack trace", maybeExit, ".")
  }
  invisible()
}
