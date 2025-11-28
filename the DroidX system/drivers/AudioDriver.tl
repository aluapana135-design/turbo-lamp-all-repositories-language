module AudioDriver;

// Define um tipo de dado para a estrutura do buffer de áudio
struct AudioBuffer {
    data: Pointer;
    size: Integer;
};

// Funções que chamam o código de baixo nível (C/Assembly)
extern function initAudio(rate: Integer);
extern function sendBuffer(buffer: AudioBuffer);

// Funções de driver para o programador TL
function init(sampleRate: Integer) {
    // Inicializa o hardware de áudio
    initAudio(sampleRate);
}

function play(buffer: AudioBuffer) {
    // Envia o áudio para o kernel processar
    sendBuffer(buffer);
}
Audio.init(samplerate)
Audio.playStream(buffer)
Audio.setVolume(level)
Audio.shutdown()