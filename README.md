### kernel_modules_tests

* Testing Linux device drivers. It currently implements read/write access to devices - communication between user and kernel space.
* scull - sample device driver that is based on the textbook 'J. Hartman, A. Rubini G. Kroah - Linux Device Drivers - O'Reilly Media 2005'
* scull_tests - number of tests for scull.ko that are useful to be run with [strace](https://linux.die.net/man/1/strace)
* scull/scull_load, scull_unload - utiliy scripts that load/unload module and create/remove corresponding devices.
