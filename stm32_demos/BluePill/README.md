# Directorio con demos para la placa BluePill.

Este directorio contiene un conjunto de ejemplos de código de Beckus, que fueron adaptados para que puedan funcionar con la placa BluePill en el simulador QEMU. Es importante mencionar que esta placa utiliza al micro SMT32F103C8T6, en consecuencia su pinout corresponde a dicha placa, que se muestra a continuacion:

![](./documentacion/images/pinout_BluePill.png "Pinout de la Placa BluePill")

Su datasheet se encuentra almacenada en el siguiente enlace web

[http://www.so-unlam.com.ar/wiki/index.php/PUBLICO:Tutoriales_b%C3%A1sicos_para_poder_utilizar_la_placa_STM32F103C8T6](http://www.so-unlam.com.ar/wiki/index.php/PUBLICO:Tutoriales_b%C3%A1sicos_para_poder_utilizar_la_placa_STM32F103C8T6)

 
  
**Listado de los ejemplos de còdigo que funcionan en Qemu con la placa BluePill**

1. adc_single
2. Blink_flash
3. FreeRTOS_Streambuffer
4. FreeRTOS_SingleThread
5. FreeRTOS_multithread
6. printf_demo
7. software_int
8. Systick
9. timer
10. uart_echo
11. uart_echo_int (funciona pero pierde caracteres)
12. uart_repeat_write
13. button
14. button_int