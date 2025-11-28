// sensor_cpu.h
#include <stdint.h>

// Definição da estrutura do Driver de Sensor. 
// Isso é o 'pacote' de funções que o kernel usa.
typedef struct {
    // Inicializa o hardware (configura registradores, etc.)
    int (*inicializar)();

    // Lê o valor bruto do sensor e retorna em milicelsius (mC)
    int32_t (*ler_temperatura_mC)();
    
    // Desliga ou coloca o sensor em modo de baixo consumo
    void (*desligar)();
} DriverSensor;

// Ponteiro global para a instância do driver que está ativo
extern DriverSensor* g_SensorCPU; 

// Constante de erro de leitura
#define ERRO_LEITURA_SENSOR -1