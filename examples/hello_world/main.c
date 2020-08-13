//
// Created by Markiian Benovskyi on 10/08/2020.
//

#include <cassowary_6502.h>

int main() {
    lcd_init();
    while (1) {
        lcd_send_char();
    }

    return (0); // Should never get here
}
