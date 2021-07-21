#Este archivo es el archivo de compilacion base que se usa  para llamar a 
#a todos los Makefile de los ejemplos modificados de Beckus de las placas
#STM32-p103, BluePill y STM32-Mapple

#Macros
STM32-P103  = /soa-entorno-integracion/stm32_demos/stm32-p103/demos/
STM32-MAPLE = /soa-entorno-integracion/stm32_demos/stm32-maple/demos
BLUEPILL    = /soa-entorno-integracion/stm32_demos/BluePill/demos

.PHONY : all stm32-p103 stm32-maple bluepill clean 

#Reglas

all: 	
	cd $(STM32-P103) && make && \
	cd $(STM32-MAPLE) && make && \
	cd $(BLUEPILL) && make	 	
stm32-p103:
	cd $(STM32-P103) && make
stm32-maple:
	cd $(STM32-MAPLE) && make
bluepill:
	cd $(BLUEPILL) && make	
clean:
	cd $(STM32-P103) && make clean && \
	cd $(STM32-MAPLE) && make clean && \
	cd $(BLUEPILL) && make clean
