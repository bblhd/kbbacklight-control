// thanks to user 'Quasímodo' on stackoverflow on 5th July 2021 from
	// https://unix.stackexchange.com/questions/625144/how-to-write-a-script-that-edits-brightness-file-in-sys-class-backlight-ideapad

// controls keyboard backlight brightness on a t2linux macbookpro, may work on other apple devices

// if given not given input, prints the current brightness
// if given 1 numeric input beginning with a plus or minus, adds it to the current brightness
// if given 1 numeric input beginning without a plus or minus, sets the current brightness to it

#include <stdlib.h>
#include <stdio.h>
#define BUFSIZE 8

int main(int argc, char **argv) {
	int amount = 0;
	
	if (argc == 2 && (amount = strtol(argv[1], NULL, 10)) == 0) return 1;
	
	FILE *fp;
	char scurr[BUFSIZE];
	if ((fp = fopen("/sys/class/leds/apple::kbd_backlight/brightness", "r+")) && fgets(scurr, BUFSIZE, fp)) {
		if (argc == 1) {
			printf("%ld\n", strtol(scurr, NULL, 10));
		} else if (argc == 2) {
			if (*argv[1] == '-' || *argv[1] == '+') {
				amount += strtol(scurr, NULL, 10);
				if (amount < 0) amount = 0;
			}
			rewind(fp);
			fprintf(fp, "%ld\n", amount);
		}
		fclose(fp);
	} else return 2;
	
	return 0;
}
