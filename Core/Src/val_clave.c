
#include "ring_buffer.h"

/*
 * @brief Esta funcion valida un buffer que se ingrese si coincide con la clave que está predefinida
 *
 * @param data: Recibe el nombre de la variable tipo "ring_buffer_t" (estructura creada).
 *
 * @retval: 1 si la clave NO coincide, 0 si la clave coincide
 */

uint8_t validar_clave(ring_buffer_t *buffer) {
	char clave_correcta[] = "122334";
    uint8_t tamano = ring_buffer_size(buffer);

    if (tamano != (sizeof(clave_correcta)-1)) {
        return 1; // Tamaño no coincide
    }

    for (uint8_t i = 0; i < tamano; i++) {
        uint8_t clave_val;
        if(ring_buffer_read(buffer, &clave_val) == 0){
        	return 1;//buffer vacio
        }

        if (clave_val != clave_correcta[i]) {
            return 1; // Clave incorrecta
        }
    }
    return 0; // Clave correcta
}
