# Projeto PIC18F4550 - LCD e DS1302

Este repositório contém um projeto em linguagem C para um microcontrolador PIC18F4550 que utiliza um display LCD e um módulo de tempo real DS1302 para exibir a hora. Abaixo estão as informações necessárias para conectar fisicamente o LCD e o DS1302 ao PIC18F4550.

## Conexões do DS1302:

O módulo DS1302 é utilizado para fornecer informações de tempo real ao microcontrolador. A comunicação é feita por meio de três pinos principais:

1. **VCC (Alimentação):** Conectar a este pino ao fornecimento de energia de 5V.
2. **GND (Terra):** Conectar a este pino ao terra do sistema.
3. **DAT (Dados):** Conectar a este pino ao pino de dados do microcontrolador.

Lembre-se de verificar as necessidades específicas do seu módulo DS1302, pois as conexões podem variar.

## Conexões do LCD:

O display LCD é utilizado para exibir a hora obtida do DS1302. Conecte os seguintes pinos do LCD ao PIC18F4550:

1. **VCC (Alimentação):** Conectar a este pino ao fornecimento de energia de 5V.
2. **GND (Terra):** Conectar a este pino ao terra do sistema.
3. **RS (Register Select):** Conectar a este pino ao pino de controle RS do microcontrolador.
4. **RW (Read/Write):** Conectar a este pino ao pino de controle RW do microcontrolador.
5. **EN (Enable):** Conectar a este pino ao pino de controle EN do microcontrolador.
6. **D4-D7 (Dados):** Conectar estes pinos aos pinos de dados D4-D7 do microcontrolador.

Lembre-se de verificar as necessidades específicas do seu LCD, pois as conexões podem variar.

## Configurações do Microcontrolador (PIC18F4550):

Certifique-se de ajustar as configurações do seu compilador conforme necessário, especialmente as configurações relacionadas aos pinos do microcontrolador. No exemplo fornecido neste repositório, os pinos RC3 e RC4 são utilizados para a comunicação I2C com o DS1302, e os pinos do PORTD são utilizados para conectar ao LCD.

## Bibliotecas:

Certifique-se de incluir as bibliotecas necessárias para o LCD e a comunicação I2C no seu ambiente de desenvolvimento.

## Observações:

- Utilize resistores de pull-up de 4.7kΩ nos pinos SDA e SCL para o barramento I2C.
- Adapte as configurações conforme necessário para o seu ambiente de desenvolvimento e módulos específicos.

## Licença:

Este projeto é distribuído sob a licença [MIT](LICENSE). Sinta-se à vontade para adaptar e utilizar conforme necessário.
