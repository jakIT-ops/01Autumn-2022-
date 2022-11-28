# File iin systemiin event

## inotify

* hynax jagsaaltaa nemeh

* event unshih

## gurwan alhamttai

1. Create inotify instance (file descriptor)

2. Add watch item

3. Read and process events

## wd = inotify_add_watch(fd, path, mask)

fd = file diescriptor of intoify instance

path = name of file or dir to be watch

mask = bit mask specifying the events to be monitored



