# Control Remoto de LEDs

Este repositorio contiene el código fuente para un proyecto que permite encender y apagar LEDs de forma remota a través de una interfaz web. El proyecto utiliza un Arduino con conexión Wi-Fi para controlar los LEDs y una página web simple para enviar comandos de encendido y apagado.

## Contenido del Repositorio
- `main.ino`: Este archivo contiene el código para el Arduino. Establece la conexión Wi-Fi, configura los pines de los LEDs y crea un servidor web para recibir comandos de la interfaz web.

- `index.html`: Esta página HTML sirve como la interfaz web para controlar los LEDs. Proporciona botones para encender y apagar cada uno de los siete LEDs.

## Instrucciones de Uso
1. Conecta tu Arduino al circuito con los LEDs.
2. Sube el código `main.ino` al Arduino.
3. Asegúrate de configurar correctamente el nombre de la red Wi-Fi (`ssid`) y la contraseña (`pass`) en el código.
4. Abre el Monitor Serie en el entorno de desarrollo Arduino para ver la dirección IP asignada al Arduino por el router.
5. Abre un navegador web y visita la dirección IP del Arduino para acceder a la interfaz de control de LEDs.
6. Selecciona el LED que deseas controlar y utiliza los botones para encender y apagar.

## Estructura del Proyecto
- El código en `main.ino` establece la conexión Wi-Fi, configura los pines de los LEDs y crea un servidor web.
- La interfaz web en `index.html` utiliza Bootstrap para presentar botones desplegables para cada LED.

## Notas Adicionales
- Este proyecto es un ejemplo básico y puede ser ampliado para controlar más dispositivos o para agregar características adicionales.
- Asegúrate de tener las bibliotecas necesarias instaladas, como `WiFi101` para la conexión Wi-Fi.
- La página web está diseñada de manera simple utilizando Bootstrap para facilitar la expansión y personalización.

¡Disfruta controlando tus LEDs de forma remota!