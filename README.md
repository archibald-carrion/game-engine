# Creación de Videojuegos ─ Tarea 1: Introducción a SDL2 y los motores de videojuegos
## Entrega
Fecha de entrega: 30 de agosto de 2024
Formato: Entregue el proyecto comprimido en un archivo zip. NO incluya archivos y carpetas generadas automáticamente (por ejemplo, /Debug, etc.).
Presentación: Debe presentar su programa en la siguiente clase después de la entrega.

## Especificación del Programa
Implemente un programa (pseudo motor de videojuegos) utilizando las bibliotecas SDL2 y GLM y el lenguaje de programación C++. El programa debe leer un archivo de configuración (config.txt) que posee las características de la ventana, la fuente y los elementos (entidades) que se dibujarán en la ventana. Los elementos deberan aparecer en el posición indicada en el archivo y moverse según su su velocidad. Cuando un elemento llega a algún borde de la ventana, este deberá "rebotar" y cambiar la dirección de la velocidad dependiendo del borde contra el que "impacte". Además, cada elemento cuenta con una etiqueta. La etiqueta debe de dibujarse de forma que el centro de la etiquea calce con el centro de la imagen del elemento.

### La ventana
El ancho, alto y color de fondo de la ventana se indican en el archivo de configuración
### Fuente
La fuente, tamaño y color del texto se indican en el archivo de configuración
### Entidades
Las entidades se implementa como class o struct y solo deben almacenan variables
Las características (datos) de cada entidad se indican en el archivo de configuración (config.txt)

Una entidad está compuesta por dos texturas de SDL (imagen y texto), sus dimensiones, la posición, la velocidad, el ángulo, la etiqueta y demás elementos necesarios para poder dibujar y mover la entidad por la ventana

La textura de la imagen y el texto deben de dibujarse en conjunto. La textura de la etiqueta debe estar centrada a la textura de la imagen

Clase Game
Expanda el código de la clase Game que implementó en los tutoriales para que pueda almacenar y dibujar varias entidades

El método encargado de dibujar la ventana debe "refrescarse" aproximadamente 60 frames por segundo

Trate de modularizar lo mejor posible la clase Game

Recuerde liberar la memoria solicitada por SDL

Teclas y eventos
Al presionar el botón de cerrar ventana (botón con signo de x) el programa debe terminar

Al presionar la tecla ESC debe cerrar la ventana y terminar el programa

Al presionar la tecla P el programa debe pausar el moviento de las entidades

## Guía de uso
Para compilar el programa, ejecute el siguiente comando:
```bash
make; make run
```
El proyecto fue desarrollado en Ubuntu 24.04 en WSL2, utilizando el compilador g++ 13.2.0

El makefile para funcionar con mi arquitectura de carpeta fue modificado.

### Archivo de configuración
El archivo de configuración config.txt sigue el mismo formate que el archivo dado por el profesor.

## Proceso de desarrollo
Para desarrollar el pseudo motor de videojuegos, se crearon se usaron los siguientes archivos:
- main.cpp, crea un juego y lo ejecuta
- game.hpp y game.cpp, implementan la clase Game donde tenemos las funciones de inicialización, leer eventos, actualización y renderizado, esa clase ademas de eso tiene una multitud de atributos para almacenar las entidades y las configuraciones de la ventana y fuente.
- entity.hpp y entity.cpp, implementan la clase Entity que representa una entidad con un id unico, similar a la clase "persona" visto en los videos de clase, esos archivos no se usaron en el programa final, pero probablemente se usen en futuras implementaciones.
- configuration.hpp y configuration.cpp, implementan los structs que contienen los datos de configuración de la ventana, fuente y entidades, además de un struct color que se usa para almacenar colores en formato RGB, el cual en futuras implementaciones se podra cambiar por SDL_Color. Ademas de esos structs se implementa la función de lectura de configuración que lee el archivo config.txt usado para configurar el juego.

El desarrollo del motor se llevo a cabo siguiendo los videos disponibles en la plataforma, y agregando poco a poco las funcionalidades requeridas por la tarea, como la lectura de configuración, personalización de la clase Game para que tenga un vector de entity y los structs mencionados anteriormente, la funcionalidad de tener tantos entidades como se requiere en el archivo de config, y otras funcionalidades como pausar el juego usando la tecla "p" o que las imagenes reboten en los angulos de la ventana.

Adjunto se agrego un screenshot del programa ejecutandose:
![screenshot pseudo motor](documentation/screenshot_basic_game.PNG)


## Instalación de las bibliotecas necesarias
Para instalar las bibliotecas necesarias en linux, ejecute el siguiente comando:
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev lua5.3 liblua5.3-dev
```

## Ressources used for the game
- [arcade classic font](https://www.1001fonts.com/arcadeclassic-font.html)


## TODO
- [ ] Implement the animation of the entities using the lua script