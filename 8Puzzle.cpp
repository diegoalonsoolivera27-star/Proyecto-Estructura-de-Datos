#include <iostream>
#include <cstring>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
using namespace std;

void menu(ALLEGRO_DISPLAY *, int, int, ALLEGRO_FONT *);
void modoManual();
void modoInteligente();

struct {
    ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
} color;

#include "Titulo.h"
#include "Menu.h"

int realmain(){
    //Set-up inicial
    srand(time(NULL));
    al_init(); //Inicia Allegro
    al_install_keyboard(); // Iniciar teclado
    al_install_mouse(); // Iniciar mouse
    al_init_native_dialog_addon(); // Iniciar cuadros de diálogo 
    al_init_primitives_addon(); // Iniciar primitivas (líneas, círculos, rectángulos, etc.)
    al_init_font_addon(); // Iniciar función de fuentes
    al_init_ttf_addon();  // Iniciar soporte para archivos TTF
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW); // Establece modo de pantalla completa
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);

    //fuentes
    ALLEGRO_FONT *font = al_load_font("Fresco Stamp.ttf", 500, 0);
    ALLEGRO_FONT *font2 = al_load_font("APOLLO.otf", 100, 0);

    int realWidth = al_get_display_width(display);
    int realHeight = al_get_display_height(display);
    titulo(display, realWidth, realHeight, font, font2);
    return 0;
}

int main(int argc, char **argv){
    return realmain();
}


void modoManual(){

}

void modoInteligente(){

}