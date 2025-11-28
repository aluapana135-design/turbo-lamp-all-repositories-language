module VideoDriver;

// Enum para profundidade de cor
enum ColorDepth {
    DEPTH_8BIT,
    DEPTH_16BIT,
    DEPTH_32BIT
};

// Funções que chamam o código de baixo nível (C/Assembly)
extern function setupVideoMode(w: Integer, h: Integer, d: ColorDepth);
extern function writePixel(x: Integer, y: Integer, color: Integer);
extern function swapDisplayBuffers();

// Funções de driver para o programador TL
function initialize() {
    // Inicializa o hardware
    setupVideoMode(800, 600, ColorDepth.DEPTH_32BIT);
}

function render(x: Integer, y: Integer, color: Integer) {
    // Desenha o pixel
    writePixel(x, y, color);
}

function refreshScreen() {
    // Atualiza a tela após desenhar
    swapDisplayBuffers();
}