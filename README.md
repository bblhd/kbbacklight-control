# kbbacklight-control
Made to easily control keyboard backlight on t2 macbook pro running linux.

## How to compile
Compile using `make` or `make compile`, and then install it to /usr/local/bin by running `make install` as root.

## How to use
Run program with command `kbbacklightctl`.
- if not given input, prints the current brightness
- if given 1 numeric input beginning with a plus or minus, adds it to the current brightness
- if given 1 numeric input beginning without a plus or minus, sets the current brightness to it

## Thanks
Thanks to user 'Quasímodo' on stackoverflow for their
[solution](https://unix.stackexchange.com/a/625266/533187) to this problem for Lenovo ideapads.
