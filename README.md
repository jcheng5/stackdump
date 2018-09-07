# stackdump

Simple utility for R on Linux or Mac, that handles the SIGQUIT event by dumping the R call stack to stderr and exiting. This is a helpful way to see what your R process is doing when it appears to be hung.

To initialize:

```r
stackdump::init(quit = FALSE)
```

Then while your R code is running, you can run this from a shell:

```sh
kill -SIGQUIT <pid>
```

This should cause your R console (or app log, if you're running a Shiny app on a server) to print a call stack.

If the `quit` argument is `TRUE` (the default), then the R process will exit after printing the call stack. This is because stackdump works by executing a bunch of R code in a signal handler, and that's not technically a very safe thing to do. If you'd rather be safe than risk a subtly corrupted process, it's better to quit.
