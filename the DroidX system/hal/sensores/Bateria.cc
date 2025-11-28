// Bateria.cc
#include "Bateria.hpp"

// Funções de baixo nível (assumidas como existentes no SO)
extern uint32_t ler_mmio(uint32_t endereco);
extern void escrever_mmio(uint32_t endereco, uint32_t valor);

namespace PowerManager {

Bateria::Bateria() {
    // Inicializa os ponteiros dos registradores com o endereço base
    REG_STATUS = (volatile uint32_t*)(BATERIA_MMIO_BASE + 0x00);
    REG_LEVEL  = (volatile uint32_t*)(BATERIA_MMIO_BASE + 0x04);
    REG_TEMP   = (volatile uint32_t*)(BATERIA_MMIO_BASE + 0x08);

    configurarRegistradores();
}

void Bateria::configurarRegistradores() {
    // Exemplo: Escreve um valor para habilitar o monitoramento no hardware
    escrever_mmio((uint32_t)REG_STATUS, 0x01); 
}

uint8_t Bateria::lerPorcentagemCarga() {
    // Lê o valor bruto do registrador de nível. 
    // Assume que o hardware retorna um valor que precisa de uma máscara de bits
    uint32_t raw_level = ler_mmio((uint32_t)REG_LEVEL); 
    
    // Máscara para isolar os 8 bits de porcentagem (exemplo)
    uint8_t level = (raw_level >> 8) & 0xFF; 
    
    // Retorna a porcentagem (0-100)
    return level; 
}

uint8_t Bateria::lerEstado() {
    // Lê o registrador de status para verificar se está carregando ou descarregando
    uint32_t status = ler_mmio((uint32_t)REG_STATUS);
    
    // Exemplo: Retorna 1 se o 0º bit estiver ligado (indicando carregamento)
    if (status & 0x01) {
        return 1; // Carregando
    } else if (status & 0x02) {
        return 2; // Descarregando
    }
    return 0; // Desconhecido ou Completo
}

void Bateria::registrarISR(void (*handler)()) {
    // Em um SO real, esta função registraria o 'handler' (função) 
    // no Controlador de Interrupções (APIC/PIC) para que o hardware 
    // chame o código do driver em caso de bateria baixa, etc.
    // Ex: register_interrupt_handler(IRQ_BATERIA, handler);
}

} // namespace PowerManager