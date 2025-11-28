// Bateria.hpp
#include <stdint.h>

// Endereço de Memória (MMIO) ou Porta de I/O Base para o Controlador da Bateria
#define BATERIA_MMIO_BASE 0xFD000000 

namespace PowerManager {

class Bateria {
public:
    // Construtor: usado para inicializar o driver
    Bateria(); 

    // Lê a porcentagem de carga atual (0-100)
    uint8_t lerPorcentagemCarga(); 

    // Lê o estado (carregando, descarregando, cheio)
    uint8_t lerEstado(); 

    // Registra uma Interrupção de Bateria (ex: bateria baixa)
    void registrarISR(void (*handler)());

private:
    // Mapeia os registradores específicos do hardware da bateria
    volatile uint32_t* REG_STATUS; 
    volatile uint32_t* REG_LEVEL;  
    volatile uint32_t* REG_TEMP;   

    // Funções internas para manipulação de registradores
    void configurarRegistradores();
};

} // namespace PowerManager