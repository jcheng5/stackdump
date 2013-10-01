init <- function(silent=FALSE) {
  .Call(registerSigQuitHandler)
  if (!isTRUE(silent)) {
    message("Stack dump handler attached.\nSend SIGQUIT to print stack trace and exit.")
  }
  invisible()
}
