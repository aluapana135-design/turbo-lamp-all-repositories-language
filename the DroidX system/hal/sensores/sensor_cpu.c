// sensor_cpu.c
#include "sensor_cpu.h" 

// Endereço de Memória (MMIO) hipotético do registrador do sensor
#define REG_STATUS 0xFE000000 
#define REG_LEITURA 0xFE000004 
#define REG_CONFIG 0xFE000008

// Funções de baixo nível que o SO precisa fornecer para I/O de hardware
// Em um SO real, estas seriam implementadas em Assembly ou C com otimizações
extern uint32_t ler_mmio(uint32_t endereco);
extern void escrever_mmio(uint32_t endereco, uint32_t valor);

// Funções de Implementação do Driver
static int sensor_inicializar() {
    // Exemplo: Escreve 0x01 no registrador de configuração para ligar o sensor
    escrever_mmio(REG_CONFIG, 0x01);
    
    // Verifica status para garantir que ligou (simplificado)
    if (ler_mmio(REG_STATUS) & 0x01) {
        return 0; // Sucesso
    }
    return -1; // Falha
}

static int32_t sensor_ler_temperatura_mC() {
    uint32_t raw_data;
    
    // Lê o registrador de dados do sensor
    raw_data = ler_mmio(REG_LEITURA); 

    // Assume-se que o hardware retorna um valor que precisa de conversão
    // Ex: Se o valor bruto é de 8 bits e representa Celsius * 10
    int32_t temperatura_celsius_x10 = (int32_t)raw_data * 10;
    
    // Converte para milicelsius (mC)
    return temperatura_celsius_x10 * 100;
}

static void sensor_desligar() {
    // Escreve 0x00 no registrador de configuração para desligar
    escrever_mmio(REG_CONFIG, 0x00);
}


// A instância real do driver, usando a estrutura definida no .h
static DriverSensor SensorCPU_Impl = {
    .inicializar = sensor_inicializar,
    .ler_temperatura_mC = sensor_ler_temperatura_mC,
    .desligar = sensor_desligar
};

// Define o ponteiro global para a implementação
DriverSensor* g_SensorCPU = &SensorCPU_Impl;