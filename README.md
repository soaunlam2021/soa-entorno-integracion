# SOA-Entorno-Integracion

Esta imagen de Docker pertenece al proyecto de Investigación de la Universidad Nacional de La Matanza denominado "Entorno de integración continua para validación de sistemas embebidos de tiempo real". Presenta adaptaciones y mejoras del proyecto de Beckus.

El código fuente de esta investigacion se encuentra en el siguiente  repositorio git

[https://github.com/soaunlam2021/soa-entorno-integracion](https://github.com/soaunlam2021/soa-entorno-integracion "https://github.com/soaunlam2021/soa-entorno-integracion")

Este repositorio se divide en los siguientes directorios:

- **Qemu:** -  Contiene el código fuente del emulador qemu para STM32
- **STM2-Demos:** -  Contiene el código fuente de varios ejemplos para ser ejecutados en qemu, emulando las placas stm32-p103, stm32-maple y la Bluepill

## Directorio STM32-Demos
Este directorio contiene los código fuentes de ejemplos para ser ejecutados en qemu emulando distintos sistemas embebidos. Por ese motivo este directorio contiene los siguientes subidrectorios

- **STM32-p103**: Contiene información sobre la placa STM32-p103 y  ejemplos configurados para poder ser ejecutados en qemu emulando la misma.
- **STM32-maple**: Contiene información sobre la placa STM32-maple y  ejemplos configurados para poder ser ejecutados en qemu emulando la misma.
- **Bluepill**: Contiene información sobre la placa Bluepill (STM32-f103c8t6) y  ejemplos configurados para poder ser ejecutados en qemu emulando la misma.

## Tutorial de utilización
En el siguiente enlace se encuentra un tutorial, que explica como se creo la imagen Docker de este proyecto, y como se debe utilizar para poder ejecutar cada uno de los ejemplos de código en qemu

https://github.com/soaunlam2021/soa-entorno-integracion/blob/master/Docker_qemu_STM32_tutorial.pdf