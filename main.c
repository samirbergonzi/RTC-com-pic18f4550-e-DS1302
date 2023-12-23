#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"
#include "i2c.h"

#define DS1307_ADDR 0b1101000 // Endereço I2C do DS1307

// Função para inicializar o I2C
void initI2C(void) {
    // Configurar os pinos SDA e SCL como entradas
    TRISC3 = 1; // SDA
    TRISC4 = 1; // SCL
    
    // Inicializar o módulo I2C
    SSPCON = 0b00101000; // SSPEN ativa o módulo I2C
    SSPADD = 49; // Freq = Fosc / (4 * (SSPADD + 1))
}

// Função para iniciar a comunicação I2C
void i2cStart(void) {
    SEN = 1; // Iniciar condição de start
    while (SEN); // Aguardar até que a condição de start seja concluída
}

// Função para parar a comunicação I2C
void i2cStop(void) {
    PEN = 1; // Iniciar condição de stop
    while (PEN); // Aguardar até que a condição de stop seja concluída
}

// Função para escrever um byte no barramento I2C
void i2cWrite(unsigned char data) {
    SSPBUF = data; // Colocar dado no buffer
    while (BF); // Aguardar até que o buffer esteja vazio
}

// Função para ler um byte do barramento I2C
unsigned char i2cRead(void) {
    RCEN = 1; // Habilitar recepção
    while (!SSPIF); // Aguardar até que a recepção esteja concluída
    SSPIF = 0; // Limpar a bandeira de interrupção
    return SSPBUF; // Retornar o dado lido
}

// Função principal
void main(void) {
    unsigned char sec, min, hour;
    char timeString[9]; // hh:mm:ss\0

    TRISD = 0x00; // Configurar o PORTD como saída
    initI2C(); // Inicializar o I2C
    lcd_init(); // Inicializar o LCD

    while (1) {
        // Iniciar a comunicação I2C com o DS1307
        i2cStart();
        i2cWrite(DS1307_ADDR << 1); // Endereço + bit de escrita
        i2cWrite(0x00); // Endereço do registro de segundos
        i2cStop();

        // Ler os dados do DS1307
        i2cStart();
        i2cWrite((DS1307_ADDR << 1) | 0x01); // Endereço + bit de leitura
        sec = bcdToDec(i2cRead() & 0x7F); // Descartar o bit CH
        min = bcdToDec(i2cRead());
        hour = bcdToDec(i2cRead() & 0x3F); // Modo de 24 horas
        i2cStop();

        // Formatar a hora como uma string
        sprintf(timeString, "%02u:%02u:%02u", hour, min, sec);

        // Exibir a hora no LCD
        lcd_clear();
        lcd_set_cursor(1, 1);
        lcd_write_string(timeString);

        __delay_ms(1000); // Aguardar 1 segundo
    }

    return;
}
