# Creación de Videojuegos ─ Tarea 1: Introducción a SDL2 y los motores de videojuegos
## Entrega
Fecha de entrega: 27 de octubre de 2024


## Descripción del juego
Es un juego de ciencia ficción en el que el jugador controla una nave espacial que debe esquivar asteroides y naves enemigas, mientras dispara a enemigos.
El juego cuenta con :
- un menú principal
- una pantalla de introducción para tener mas contexto sobre la historia
- tres niveles
- una pantalla de "muerte" donde llega el jugador si se muere que permite redirrecionar a los tres niveles
- una pantalla de "congratulation" que permite redirrecionar al menu principal
El juego cuenta con música de fondo y assets propios. 

## Controles
- W: Mover la nave hacia arriba
- S: Mover la nave hacia abajo
- A: Mover la nave hacia la izquierda
- D: Mover la nave hacia la derecha
- Espacio: Disparar
- P: Pausar el juego

## Historia del juego
El juego se desarrolla en un futuro muy lejano donde la humanidad ha colonizado otros sistemas solares y otras galaxias, tras milenios la humanidad se ha ido olvidando de su origen y de la tierra o "Terra" como se refiere en el juego.
Al pasar tanto tiempo los humanos olvidaron de donde venian, muchos creen que siempre han vivido en el espacio, pero hay una leyenda que habla de un pequeño planeta perdido en la inmensidad del espacio, un planeta que fue el origen de la humanidad, un planeta que se llama "Terra".
El/la jugador/a interpreta al Capitan Castellum, al encontrar un antiguo artefacto en una de las colonias, el capitan descubre que el artefacto es una especie de mapa que lo lleva a un portal que lo llevara a "Terra", el capitan decide seguir el mapa y descubrir la verdad sobre el origen de la humanidad.
Tras recolectar los artefactos necesarios, el capitan llega a "Terra", el juego termina con una pantalla de "congratulation", dejando al jugador con la duda de que descubrio el capitan en "Terra".

## Objetivos del juego
Para ir avanzando en el juego, el jugador debe:
- recolectar power ups que le permiten moverse mas rapido, a nivel de narrativa, estos items representan antiguas tecnologias que permite a la nave pasar a traves de los portales para llegar al siguiente nivel
- disparar a los enemigos para ganar tener el mayor score posible
- esquivar los asteroides y naves enemigas para no morir
- el jugador no puede pasar al siguiente nivel si no ha recolectado todos los artefactos necesarios

## 4 enemigos
En mi juego hay 4 enemigos:
- asteroides, no se pueden destruir, pero si se pueden esquivar
- enemigos arrañas, se pueden destruir con un disparo y dan 10 puntos, usualmente no se mueve muy rapido
- enemigos circulares azules, se pueden destruir con un disparo y dan 15 puntos, usualmente se mueve mas rapido que los enemigos arrañas y "rodan"
- enemigos circulares rojos, son muy grandes y no se pueden destruir




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

## Puntos extras
Para obtener puntos extras, implemente las siguientes características:
- [x] Se implemento el audio manager para reproducir música de fondo y efectos de sonido, ademas se usaron audios hechos propios por [Namlin] (https://github.com/namlin)
- [x] Todos los assets graficos, salvo las fuentes y el background fueron hechos por mi usando el programa [GIMP](https://www.gimp.org/)

## UML del motor de videojuegos
```mermaid
classDiagram

    class Game {
        -window: SDL_Window*
        -camera: SDL_Rect
        -isRunning: bool
        -mPreviousFrame: int
        -isPaused: bool
        -map_height: int
        -map_width: int
        -player_location: std::tuple<int, int>
        -player_score: int
        -WINDOW_WIDTH: int
        -WINDOW_HEIGHT: int
        -renderer: SDL_Renderer*
        -registry: std::unique_ptr<Registry>
        -scene_manager: std::unique_ptr<SceneManager>
        -assets_manager: std::unique_ptr<AssetsManager>
        -events_manager: std::unique_ptr<EventManager>
        -controller_manager: std::unique_ptr<ControllerManager>
        -audio_manager: std::unique_ptr<AudioManager>
        -lua: sol::state
        +Game()
        +~Game()
        +processInput()
        +update()
        +render()
        +setup()
        +run_scene()
        +init()
        +run()
        +destroy()
        +print_game_data()
        +get_instance(): Game&
    }
    class SceneManager{
        -std::map<std::string, std::string> scenes
        -std::string next_scene
        -bool is_scene_running
        -std::unique_ptr<SceneLoader> scene_loader

        +get_next_scene()
        +load_scene_from_script()
        +load_scene()
        +set_next_scene()
        +is_current_scene_running()
        +start_scene()
        +stop_scene()
    }
    class AssetsManager {
        -textures: std::map<std::string, SDL_Texture*>
        -fonts: std::map<std::string, TTF_Font*>
        +AssetsManager()
        +~AssetsManager()
        +clear_assets()
        +add_texture(SDL_Renderer*, std::string, std::string)
        +get_texture(std::string): SDL_Texture*
        +add_font(std::string, std::string, int)
        +get_font(std::string): TTF_Font*
    }
    class EventManager {
        -subscribers: std::map<std::type_index, std::unique_ptr<handler_list>>
        +EventManager()
        +~EventManager()
        +reset()
        +subscribe_to_event<TEvent, TOwner>(TOwner*, void (TOwner::*)(TEvent&))
        +emit_event<TEvent, TArgs>(TArgs...)
    }

    class ControllerManager {
        -action_key_name: std::map<std::string, int>
        -key_state: std::map<int, bool>
        -mouse_buttons_name: std::map<std::string, int>
        -mouse_button_state: std::map<int, bool>
        -mouse_position_x: int
        -mouse_position_y: int
        +ControllerManager()
        +~ControllerManager()
        +clear()
        +add_key(std::string, int)
        +is_key_pressed(std::string): bool
        +update_key(std::string, bool)
        +update_key(int, bool)
        +set_key_to_pressed(int)
        +set_key_to_pressed(std::string)
        +set_key_to_up(int)
        +set_key_to_up(std::string)
        +add_mouse_button(std::string, int)
        +is_mouse_button_pressed(std::string): bool
        +update_mouse_button(int, bool)
        +set_mouse_position(int, int)
        +get_mouse_position(): std::tuple<int, int>
        +set_mouse_button_to_pressed(int)
        +set_mouse_button_to_up(int)
    }

    class AudioManager {
        -music_tracks: std::map<std::string, Mix_Music*>
        -sound_effects: std::map<std::string, Mix_Chunk*>
        +AudioManager()
        +~AudioManager()
        +add_music(std::string, std::string)
        +get_music(std::string): Mix_Music*
        +add_sound_effect(std::string, std::string)
        +get_sound_effect(std::string): Mix_Chunk*
        +play_music(std::string, int)
        +play_sound_effect(std::string, int)
        +stop_music(std::string)
        +stop_sound_effect(std::string)
        +stop_all_sounds()
        +clear_audio()
    }

    class Registry {
        -componentsPools: std::vector<std::shared_ptr<IPool>>
        -entityComponentSignatures: std::vector<Signature>
        -systems: std::unordered_map<std::type_index, std::shared_ptr<System>>
        -entities_to_be_added: std::set<Entity>
        -entities_to_be_killed: std::set<Entity>
        -free_ids: std::deque<int>
        +num_entities: int
        +Registry()
        +~Registry()
        +update()
        +create_entity(): Entity
        +kill_entity(Entity)
        +add_component<TComponent, TArgs>(Entity, TArgs...)
        +remove_component<TComponent>(Entity)
        +has_component<TComponent>(Entity): bool
        +get_component<TComponent>(Entity): TComponent&
        +add_system<TSystem, TArgs>(TArgs...)
        +remove_system<TSystem>(Entity)
        +has_system<TSystem>(Entity): bool
        +get_system<TSystem>(): TSystem&
        +add_entity_to_system(Entity)
        +remove_entity_from_system(Entity)
        +clear_all_entities()
    }
     class Entity {
        -id: int
        -registry: Registry*
        +Entity(int)
        +~Entity()
        +get_id(): int
        +kill()
        +operator==(const Entity& other) const: bool
        +operator!=(const Entity& other) const: bool
        +operator>(const Entity& other) const: bool
        +operator<(const Entity& other) const: bool   

        +add_component<TComponent, TArgs>(TArgs...)
        +remove_component<TComponent>()
        +has_component<TComponent>(): bool
        +get_component<TComponent>(): TComponent&
    }

    class System {
        -componentSignature: Signature
        -entities: std::vector<Entity>
        +System()
        +~System()
        +add_entity_to_system(Entity)
        +remove_entity_from_system(Entity)
        +get_entities(): std::vector<Entity>
        +get_signature(): const Signature&
        +RequireComponent<TComponent>()
    }


    class Component {
        +get_id() int
    }

    class SceneLoader {
        +SceneLoader()
        +~SceneLoader()
        +load_scene(std::string, sol::state&, std::unique_ptr<AssetsManager>&, std::unique_ptr<ControllerManager>&, std::unique_ptr<AudioManager>&, std::unique_ptr<Registry>&, SDL_Renderer*)
        -load_sounds(sol::table&, std::unique_ptr<AudioManager>&)
        -load_music(sol::table&, std::unique_ptr<AudioManager>&)
        -load_sprites(SDL_Renderer*, sol::table&, std::unique_ptr<AssetsManager>&)
        -load_fonts(sol::table&, std::unique_ptr<AssetsManager>&)
        -load_buttons(sol::table&, std::unique_ptr<ControllerManager>&)
        -load_keys_actions(sol::table&, std::unique_ptr<ControllerManager>&)
        -load_entities(sol::state&, sol::table&, std::unique_ptr<Registry>&)
    }


    SceneLoader "1" -- "1" SceneManager
    Game "1" -- "1" Registry
    Game "1" -- "1" SceneManager
    Game "1" -- "1" AssetsManager
    Game "1" -- "1" EventManager
    Game "1" -- "1" ControllerManager
    Game "1" -- "1" AudioManager
    Game "1" -- "1" Registry
    Registry "1" -- "*" Entity
    Registry "1" -- "*" System
    Entity "1" -- "0..*" Component
    System "*" -- "*" Entity

```

## Ressources used for the game
- [arcade classic font](https://www.1001fonts.com/arcadeclassic-font.html)
- [background generator](https://deep-fold.itch.io/space-background-generator)
- Music made by game developer [Namlin] (https://github.com/namlin)


## TODO
- [ ] Implement new scene introducing the characters after intro scene in some sort of "cinematic"