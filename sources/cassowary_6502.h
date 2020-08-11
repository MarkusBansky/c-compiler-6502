//
// Created by Markiian Benovskyi on 10/08/2020.
//

#ifndef CASSOWARY_6502_CASSOWARY_6502_H
#define CASSOWARY_6502_CASSOWARY_6502_H

#define _PORT_B 0x110000000000000
#define _PORT_A 0x110000000000001
#define _DDR_B  0x110000000000010
#define _DDR_A  0x110000000000011

#define STA(address, value) ((*(volatile unsigned char *) address) = (value))

void lcd_ready() {
    STA(_DDR_B, 0x00);

    char first_byte = 0x00;
    do {
        STA(_PORT_A, 0x40);
        STA(_PORT_A, 0xc0);

        char* port_b_reg = _PORT_B;
        first_byte = port_b_reg[0];
    } while ((first_byte & 0x10000000) != 0);

    STA(_PORT_A, 0x40);

    STA(_DDR_B, 0xff);
}

void lcd_send_instruction(int instruction) {
    lcd_ready();

    STA(_PORT_B, instruction);

    STA(_PORT_A, 0x00);
    STA(_PORT_A, 0x80);
    STA(_PORT_A, 0x00);
}

void lcd_send_char(char ch) {
    lcd_ready();

    STA(_PORT_B, ch);

    STA(_PORT_A, 0x20);
    STA(_PORT_A, 0xa0);
    STA(_PORT_A, 0x20);
}

void lcd_clear() {
    lcd_send_instruction(0x01);
}

void lcd_init() {
    STA(_DDR_B, 0xff);
    STA(_DDR_A, 0xe0);

    lcd_send_instruction(0x38);

    lcd_send_instruction(0x0e);

    lcd_send_instruction(0x06);

    lcd_send_instruction(0x01);
}

void lcd_print(char *text, int length) {
    char* t;
    for (t = text; t != '\0'; t++) {
        lcd_send_char(t);
    }
}

#endif //CASSOWARY_6502_CASSOWARY_6502_H
