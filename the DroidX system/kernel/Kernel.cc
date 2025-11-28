// Kernel.cc
#include "Bateria.hpp"

// Cria a instância global do driver de bateria
PowerManager::Bateria g_bateria_driver;

// Rotina de interrupção (ISR) de bateria fraca
void BateriaFracaHandler() {
    // Log do kernel:
    // log_kernel("Aviso: Bateria Crítica. Iniciando desligamento...");
    
    // Sinaliza o escalonador para parar novos processos
    // scheduler_suspend(); 
    
    // Inicia a rotina de desligamento seguro
    // system_shutdown(); 
}

void inicializarGerenciamentoEnergia() {
    // Garante que o driver está pronto
    
    // Registra a função de emergência com o hardware
    g_bateria_driver.registrarISR(BateriaFracaHandler); 
}

void loopMonitoramentoEnergia() {
    uint8_t carga = g_bateria_driver.lerPorcentagemCarga();
    
    if (carga < 10 && g_bateria_driver.lerEstado() == 2) { 
        // Se a carga for menor que 10% E estiver descarregando
        
        // Reduz a frequência da CPU para modo de emergência
        // cpu_governor_set_frequency(CPU_LOW_POWER);
    }
    
    // O kernel executa esta checagem periodicamente
}