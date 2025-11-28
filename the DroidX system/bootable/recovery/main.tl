#import "ui/one_ui.tl"
#import "io/button_input.tl"

if BUTTON == DOWN:
NAVEGATE(DOWN);
if BUTTON == UP:
NAVEGATE(UP);
if BUTTON == POWER:
SELECT(POWER);
menu = {
"Reboot",
"Reboot to BOOTLOOADER",
"update",
"factory reset",
"wipe cache",
"Power off"
}