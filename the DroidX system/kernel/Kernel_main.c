// Kernel_main.c
#include "sensor_cpu.h"
#include <stdio.h> // Para printf (em um SO real seria uma função de log)

// Assume que esta função é chamada durante a inicialização do kernel
void inicializar_sistema_de_sensores() {
    if (g_SensorCPU->inicializar() == 0) {
        // Inicialização bem-sucedida
        // O kernel pode agora usar o sensor
    } else {
        // Tratar erro
    }
}

// Assume que esta função é chamada por um processo de monitoramento
void monitorar_temperatura() {
    int32_t temp_mc = g_SensorCPU->ler_temperatura_mC();
    
    if (temp_mc != ERRO_LEITURA_SENSOR) {
        // Se a temperatura estiver acima de 80.000 mC (80°C), iniciar throttling
        if (temp_mc > 80000) {
            // Chamada para a função do Gerenciador de Energia da CPU
            // power_manager_set_throttling_level(2); 
        }
        
        // Converte mC para Celsius para log (temp_mc / 1000)
        printf("Temperatura da CPU: %d C\n", temp_mc / 1000); 
    }
}