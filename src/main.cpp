#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main(){
    bn::core::init();
    bn::backdrop::set_color(bn::color(31,24,24));

    while(true){
        bn::core::update();

        if(bn::keypad::a_pressed()){
            bn::backdrop::set_color(bn::color(24,24,31));
        }

        if(bn::keypad::b_pressed()){
            bn::backdrop::set_color(bn::color(24,31,24));
        }

        if(bn::keypad::a_pressed() && bn::keypad::b_pressed()){
            bn::backdrop::set_color(bn::color(31,24,24));
        }
    }
}